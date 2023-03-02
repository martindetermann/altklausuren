/*
 * File: waijung_hwdrvlib.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model Wischer_Sensorbox.
 *
 * Model version                        : 1.3
 * Real-Time Workshop file version      : 8.13 (R2017b) 24-Jul-2017
 * Real-Time Workshop file generated on : Sun Dec  3 20:04:08 2017
 * TLC version                          : 8.13 (Jul 25 2017)
 * C/C++ source code generated on       : Sun Dec  3 20:04:08 2017
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "waijung_hwdrvlib.h"

/* ########################################################################
 * CAN
 * ########################################################################
 */
uint32_t CANx_Transmit(CAN_TypeDef* CANx, CanTxMsg* TxMessage, uint8_t blocking,
  float timeout_sec)
{
  SYS_TIMER_uS_STRUCT timer;
  uint32_t timeout_us;
  uint8_t mailbox;
  uint8_t status;

  /* Transmit */
  mailbox = CAN_Transmit(CANx, TxMessage);
  status = CAN_TransmitStatus(CANx, mailbox);

  /* Blocking ? */
  if (blocking) {
    timeout_us = (uint32_t)((float)timeout_sec*1000000);
    SysTimer_uS_Start(&timer, timeout_us);
    while ((status == CAN_TxStatus_Pending) && !SysTimer_uS_IsTimeout(&timer)) {
      status = CAN_TransmitStatus(CANx, mailbox);
    }
  }

  /* Remap status */
  switch (status) {
   case CAN_TxStatus_Ok:
    return CAN_STA_SUCCESS;

   case CAN_TxStatus_Pending:
    return CAN_STA_PENDING;

   case CAN_TxStatus_NoMailBox:
    return CAN_STA_NOSLOT;

   case CAN_TxStatus_Failed:
   default:
    return CAN_STA_FAILED;
  }
}

/* ########################################################################
 * Name: <S5>/CAN Transmit
 * Id: CANTransmit
 * ########################################################################
 */
CanTxMsg CANTransmitTxMsg;
void enable_CANTransmit(void)
{
  // Initial the module
  WAIJUNG_CAN1_INIT ();

  /* Transmit Structure */
  CANTransmitTxMsg.StdId = 32;
  CANTransmitTxMsg.ExtId = 0;
  CANTransmitTxMsg.RTR = CAN_RTR_DATA;
  CANTransmitTxMsg.IDE = CAN_Id_Standard;
  CANTransmitTxMsg.DLC = 2;
}

void disable_CANTransmit(void)
{
}

/* ########################################################################
 * Name: <Root>/UART Setup
 * Id: UARTSetup
 * ########################################################################
 */

/* Tx buffer */
uint8_t UART2_Tx_Buffer[UTX2_BUFFER_SIZE];
UART_TX_STATE UARTSetup_Tx_State;

/* Rx buffer */
uint8_t UART2_Rx_Buffer[URX2_BUFFER_SIZE];
uint8_t UART2_Temp_Buffer[URX2_BUFFER_SIZE];

/* DMA Init struct */
DMA_InitTypeDef UARTSetup_DMA_Init;

/* Init buffer read */
void UART2_RestoreBytes(UARTRX_BUFFER_READ_STRUCT *read_struct, uint16_t count)
{
  uint16_t roll_count = count;

  /* Remove overflow buffer */
  while (roll_count > URX2_BUFFER_SIZE)
    roll_count -= URX2_BUFFER_SIZE;

  /* Return bytes back into buffer */
  if (roll_count > read_struct->index) {
    read_struct->index = URX2_BUFFER_SIZE - roll_count + read_struct->index;
  } else {
    read_struct->index -= roll_count;
  }
}

/* Read buffer from DMA
 ** Return value: Number of bytes vaiable.
 */
void UART2_Read(UARTRX_BUFFER_READ_STRUCT *read_struct)
{
  __IO uint16_t dma_curr_ndtr;
  __IO uint16_t dma_curr_index;
  uint16_t data_index = 0;
  uint16_t data_count = 0;

  /* Get current NDTR */
  if ((dma_curr_ndtr = DMA1_Stream5->NDTR) == 0) {/* Not initialize or turn-around state*/
    read_struct->count = 0;
    return;
  }

  /* Get current data indexs */
  dma_curr_index = URX2_BUFFER_SIZE - dma_curr_ndtr;
  if (read_struct->index < dma_curr_index) {
    /* Data is available */
    data_index = read_struct->index;
    data_count = dma_curr_index - read_struct->index;
    read_struct->index += data_count;
    read_struct->index &= (URX2_BUFFER_SIZE-1);
  } else if (read_struct->index > dma_curr_index) {
    /* Data is available with overlap */
    data_index = read_struct->index;
    data_count = URX2_BUFFER_SIZE-read_struct->index;
    read_struct->index = 0;
  } else {                             /* No new data */
  }

  /* Return the reading */
  if (data_count > 0) {
    read_struct->buffer = &UART2_Rx_Buffer[data_index];
    read_struct->count = data_count;
  } else {
    read_struct->count = 0;
  }
}

void UART2_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count)
{
  uint16_t bytes_to_read, data_read_index;
  bytes_to_read = buffer_size;         /* Tracking count of data readings */
  data_read_index = 0;                 /* Increment buffer index */
  do {
    UART2_Read(read_struct);
    if (read_struct->count <= bytes_to_read) {
      memcpy(&buffer[data_read_index], read_struct->buffer, read_struct->count);
      data_read_index += read_struct->count;
      bytes_to_read -= read_struct->count;
    } else {
      /* Return some byte back to buffer */
      //read_struct->index -= (read_struct->count - bytes_to_read);
      UART2_RestoreBytes(read_struct, (read_struct->count - bytes_to_read));/* Fixed: Waijung 14.05a */

      /* Return reading data */
      memcpy(&buffer[data_read_index], read_struct->buffer, bytes_to_read);
      bytes_to_read = 0;
    }
  } while ((bytes_to_read > 0) && (read_struct->count > 0));

  /* Number of reading bytes */
  *reading_count = buffer_size - bytes_to_read;
}

/* Read Ascii packet
 * Return char count, exclude NULL
 * Terminator: "\n", "\r", "\r\n"
 */
uint16_t UART2_ReadLine(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *terminator, uint16_t terminator_count, uint8_t *buffer, uint16_t buffer_size)
{
  uint16_t count, packet_len = 0, receive_count = 0;
  uint16_t i;
  uint16_t terminator_found = 0;

  /* Determine maximum number of bytes to read */
  count = buffer_size - 1;
  if (count >= URX2_BUFFER_SIZE)
    count = URX2_BUFFER_SIZE-1;

  /* Ignore terminator is invalid */
  if (terminator_count < 1)
    return 0;

  /* Read packet */
  do {
    terminator_found = 0;
    UART2_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Search terminator */
    i = 0;
    while (!(terminator_found == terminator_count) && (i < read_struct->count))
    {
      if (read_struct->buffer[i] == (uint8_t)terminator[terminator_found/*terminator_count - 1*/
          ])
        terminator_found ++;
      i++;
    }

    packet_len += i;
    if (terminator_found == terminator_count) {
      terminator_found = 0;

      /* Roll-back buffer index */
      if ((packet_len > count) || (packet_len < terminator_count)) {/* Packet count is invalid, drop it */
        UART2_RestoreBytes(read_struct, (receive_count-packet_len));

        /* Reset */
        packet_len = 0;
        receive_count = 0;
      } else {
        UART2_RestoreBytes(read_struct, receive_count);

        /* Load data into buffer */
        UART2_ReadEx(read_struct, buffer, packet_len, &i);
        buffer[packet_len] = '\0';     /* Append NULL */

        /* Validate terminator */
        if (!strncmp((char *)&buffer[packet_len-terminator_count], terminator,
                     terminator_count)) {
          return packet_len;           /* packet reading success, return number of received bytes */
        } else {
          /* Invalid terminator */
          packet_len = 0;
          receive_count = 0;
        }
      }
    }
  } while (read_struct->count > 0);

  /* Could not find the packet terminator, reset reading struct to its original position */
  if (receive_count > 0) {
    UART2_RestoreBytes(read_struct, receive_count);
  }

  /* No byte receive */
  return 0;
}

/* Read Binary packet
 * 0: Not ready, 1: Data is ready
 */
uint8_t UART2_ReadBinary(UARTRX_BUFFER_READ_STRUCT *read_struct, const char
  *header, uint16_t header_count, const char *terminator, uint16_t
  terminator_count, uint8_t *buffer, uint16_t data_count)
{
  uint16_t receive_count = 0, drop_count = 0, binary_state = 0, binary_index = 0;
  uint16_t i;
  do {
    UART2_Read(read_struct);           /* Check DMA buffer */
    receive_count += read_struct->count;/* Total number of data received */

    /* Binary packet processing */
    for (i=0; i<read_struct->count; i++) {
      switch ( binary_state ) {
       case 0:                         /* Search for header */
        if (binary_index < header_count) {
          if (read_struct->buffer[i] == header[binary_index]) {
            binary_index ++;
          } else {
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
          break;
        } else {                       /* Change to DATA state */
          binary_index = 0;
          binary_state ++;
        }

       case 1:                         /* Wait for data */
        /* Wait for DATA */
        if (binary_index < data_count) {
          buffer[binary_index] = read_struct->buffer[i];
          binary_index ++;

          /* Check if ready (No terminator) */
          if ((binary_index >= data_count) && (terminator_count == 0)) {
            UART2_RestoreBytes(read_struct, (read_struct->count - i - 1));/* Restore some bytes */
            return 1;                  /* Return success status */
          }
          break;
        } else {                       /* Change to Terminator state */
          binary_index = 0;
          binary_state ++;
        }

       case 2:                         /* Scan for terminator */
        if (binary_index < terminator_count) {
          if (read_struct->buffer[i] == terminator[binary_index]) {
            binary_index ++;
          } else {
            binary_state = 0;
            binary_index = 0;
            drop_count = receive_count - (read_struct->count - i - 1);/* Drop packet */
          }
        }

        if (binary_index >= terminator_count) {/* Success */
          /* Restore some bytes */
          UART2_RestoreBytes(read_struct, (read_struct->count - i - 1));
          return 1;                    /* Return success status */
        }
        break;
      }
    }
  } while (read_struct->count > 0);

  /* Restore bytes */
  UART2_RestoreBytes(read_struct, (receive_count - drop_count));
  return 0;
}

/* Wait for DMA transfer to completion */
UART_TX_STATE UART2_FlushTxBuffer(void)
{
  if (UARTSetup_Tx_State != txIdle) {
    /* Chehck last DMA transmit */
    while ((DMA_GetFlagStatus(DMA1_Stream6, DMA_FLAG_TCIF6) == RESET)
           || (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)) {
    }

    /* Clear DMA Streams flags */
    DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_HTIF6 | DMA_FLAG_TCIF6);

    /* Disable the DMA Streams */
    DMA_Cmd(DMA1_Stream6, DISABLE);

    /* Disable the USART Tx DMA request */
    USART_DMACmd(USART2, USART_DMAReq_Tx, DISABLE);

    /* Update state */
    UARTSetup_Tx_State = txIdle;
  }

  return UARTSetup_Tx_State;
}

/* Write to DMA buffer */
void UART2_Write(uint8_t* data, uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART2_FlushTxBuffer();

    /* Setup */
    memcpy(UART2_Tx_Buffer, data, count);

    /* Update */
    UART2_TxUpdate(count);
  }
}

/* Update transmit buffer */
void UART2_TxUpdate(uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UART2_FlushTxBuffer();
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA1_Stream6, &UARTSetup_DMA_Init);

    /* Enable */
    USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART2, USART_FLAG_TC);
    DMA_Cmd(DMA1_Stream6, ENABLE);

    /* Tx is busy */
    UARTSetup_Tx_State = txBusy;
  }
}

static uint8_t waijung_usart2_ready = 0;
void waijung_usart2_initial(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  if (!waijung_usart2_ready) {
    waijung_usart2_ready = 1;

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* Enable UART clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    /* Enable the DMA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

    /* Connect PXx to USARTx_Tx*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

    /* Connect PXx to USARTx_Rx*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

    /* Configure USART pin as alternate function  */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

    /* Configure USART Tx */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Configure USART Rx */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* USART Configuration */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl =
      USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    /* Over sampling x8 */
    USART_OverSampling8Cmd(USART2, ENABLE);

    /* USART configuration */
    USART_Init(USART2, &USART_InitStructure);

    /* Enable USART */
    USART_Cmd(USART2, ENABLE);

    /* DMA init struct configuration */
    UARTSetup_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART2->DR);
    UARTSetup_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    UARTSetup_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
    UARTSetup_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    UARTSetup_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    UARTSetup_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
    UARTSetup_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    UARTSetup_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    UARTSetup_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

    /* Configure DMA controller to manage RX DMA request */
    UARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
    UARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART2_Rx_Buffer;
    UARTSetup_DMA_Init.DMA_DIR = DMA_DIR_PeripheralToMemory;
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)URX2_BUFFER_SIZE;
    UARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Circular;
    UARTSetup_DMA_Init.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_Init(DMA1_Stream5, &UARTSetup_DMA_Init);

    /* Enable the USART Rx DMA requests */
    USART_DMACmd(USART2, USART_DMAReq_Rx , ENABLE);

    /* Enable the DMA Stream */
    DMA_Cmd(DMA1_Stream5, ENABLE);

    /* Configure DMA controller to manage TX DMA request */
    UARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
    UARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART2_Tx_Buffer;
    UARTSetup_DMA_Init.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)UTX2_BUFFER_SIZE;
    UARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Normal;
    UARTSetup_DMA_Init.DMA_Priority = DMA_Priority_High;

    /* Init Tx state */
    UARTSetup_Tx_State = txIdle;
  }
}

/* Enable UART-DMA module */
void enable_UARTSetup(void)
{
  WAIJUNG_USARt2_INIT();
}

/* ########################################################################
 * Timer
 * ########################################################################
 */

/* Low precision non-Blocking delay timer.
 ** Relolution of timer is one TICK step interrupt.
 */
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms)
{
  /* Calculate amount of tick count */
  timer->length = (uint32_t)((float)ms/(1000*SYS_TICKSTEP));

  /* Capture current tick */
  timer->start = (uint32_t)systick_count;
}

int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer)
{
  uint32_t Capture;

  /* Capture current tick */
  Capture = (uint32_t)systick_count;

  /* Check */
  if (Capture >= timer->start) {
    if ((Capture - timer->start) >= timer->length)
      return 1;
  } else {
    if (((0xFFFFFFFF - timer->start)+Capture) >= timer->length)
      return 1;
  }

  return 0;
}

/* Improved precision non-Blocking delay timer.
 ** Relolution of timer is 1uS.
 */
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us)
{
  /* Tick */
  timer->tick = SYS_CURRENT_TICK;

  /* Tick overflow count */
  timer->tid = (uint32_t)systick_count;

  /* Target */
  timer->target_us = us*((uint32_t)HCLK/1000000);
}

int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer)
{
  uint32_t curr_tick;
  uint32_t curr_tid;

  /* Already timeout ? */
  if (timer->target_us == 0) {
    return 1;
  }

  /* Capture current tick */
  curr_tick = SYS_CURRENT_TICK;
  curr_tid = systick_count;

  /* Processing TID*/
  while (timer->tid != curr_tid) {
    if (timer->target_us > timer->tick) {
      timer->target_us -= timer->tick;
      timer->tid ++;
      timer->tick = SYSTICKRELOADVALUE-1;
    } else {
      timer->target_us = 0;
      return 1;                        /* Timeout */
    }
  }

  /* Processing Tick */
  if ((timer->tick > curr_tick) && ((timer->tick - curr_tick) > timer->target_us))
  {
    timer->target_us = 0;
    return 1;                          /* Timeout */
  }

  /* Need wait */
  return 0;
}

/* Blocking delay, uS */
void SysTimer_delay_us(uint32_t us)
{
  SYS_TIMER_uS_STRUCT timer;
  SysTimer_uS_Start(&timer, us);
  while (SysTimer_uS_IsTimeout(&timer) == 0) ;
}

/* Blocking delay, mS */
void SysTimer_delay_ms(uint32_t ms)
{
  SYS_TIMER_STRUCT timer;
  SysTimer_Start(&timer, ms);
  while (SysTimer_IsTimeout(&timer) == 0) ;
}

/* ########################################################################
 * Handles CAN1 RX0 request
 * ########################################################################
 */
/* Filter list, number 0-13 */
CAN_FILTER_STRUCT CAN1_FilterList[CAN_FILTER_COUNT] = {
  { (void*)0 }, { (void*)0 }, { (void*)0 }, { (void*)0 }, { (void*)0 }, { (void*)
    0 }, { (void*)0 }, { (void*)0 }, { (void*)0 }, { (void*)0 }, { (void*)0 }, {
    (void*)0 }, { (void*)0 }, { (void*)0 }
};

uint8_t CAN1_Filter_Hook(CAN_FILTER_CALLBACK callback)
{
  uint8_t i;

  /* Find an available filter number */
  for (i=0; i<CAN_FILTER_COUNT; i++) {
    if (CAN1_FilterList[i].CallBack == (void*)0) {
      CAN1_FilterList[i].CallBack = callback;
      return i;
    }
  }

  /* No slot available */
  return 0xFF;
}

void CAN1_Filter_Free(uint8_t filter_index)
{
  if (filter_index < CAN_FILTER_COUNT)
    CAN1_FilterList[filter_index].CallBack = (void*)0;/* NULL */
}

void CAN1_RX0_IRQHandler(void)
{
  static CanRxMsg msg;
  while (CAN_MessagePending(CAN1, CAN_FIFO0) > 0) {
    /* Get message */
    CAN_Receive(CAN1, CAN_FIFO0, &msg);

    /* Check message filter index */
    if (msg.FMI < CAN_FILTER_COUNT) {
      /* Call back */
      if (CAN1_FilterList[msg.FMI].CallBack != (void*)0)
        CAN1_FilterList[msg.FMI].CallBack(&msg);
    }
  }
}

/* ########################################################################
 * Name: <Root>/CAN Receive
 * Id: CANReceive
 * ########################################################################
 */
CAN_FilterInitTypeDef CANReceive_FilterInitStructure;
uint8_t CANReceive_filter_number;      /*Filter matched index */
CANReceive_DATA_STRUCT *CANReceive_data;
CanRxMsg CANReceive_Msg;               /* Temporary message */
CanRxMsg CANReceive_Msg_Buffer[8];     /* Size must be a number of 2^N */
volatile uint16_t CANReceive_Msg_Buffer_RIndex = 0;
volatile uint16_t CANReceive_Msg_Buffer_WIndex = 0;
uint16_t CANReceive_Msg_Buffer_Count(void)
{
  volatile uint16_t read_index;
  volatile uint16_t write_index;

  /* Get index to local variable, due to global will also access by ISR */
  read_index = CANReceive_Msg_Buffer_RIndex;
  write_index = CANReceive_Msg_Buffer_WIndex;
  if (write_index >= read_index) {
    return (write_index - read_index);
  } else {
    return ((8-read_index) + write_index);/* Max count is 8-1 */
  }
}

uint16_t CANReceive_GetMsg(CanRxMsg* pMsg)
{
  uint16_t msg_pending;
  __disable_irq();
  msg_pending = CANReceive_Msg_Buffer_Count();
  if (msg_pending > 0) {               //CANReceive_Msg_Buffer_RIndex != CANReceive_Msg_Buffer_WIndex) {
    memcpy(pMsg, &CANReceive_Msg_Buffer[CANReceive_Msg_Buffer_RIndex], sizeof
           (CanRxMsg));
    CANReceive_Msg_Buffer_RIndex ++;
    CANReceive_Msg_Buffer_RIndex &= (8-1);
  }

  __enable_irq();

  /* Number of pending message, include a reading */
  return msg_pending;
}

void CANReceive_filter_isr(CanRxMsg* pMsg)
{
  if (pMsg->IDE == CAN_Id_Standard) {  /* Accept only ID Standard */
    memcpy(&CANReceive_Msg_Buffer[CANReceive_Msg_Buffer_WIndex] ,pMsg, sizeof
           (CanRxMsg));
    CANReceive_Msg_Buffer_WIndex ++ ;
    CANReceive_Msg_Buffer_WIndex &= (8-1);
    if (CANReceive_Msg_Buffer_WIndex == CANReceive_Msg_Buffer_RIndex) {/* Buffer overflow, Flush an oldest queue */
      CANReceive_Msg_Buffer_RIndex ++;
      CANReceive_Msg_Buffer_RIndex &= (8-1);
    }
  }
}

void enable_CANReceive(void)
{
  // Initial the module
  WAIJUNG_CAN1_INIT ();

  /* Enable CAN clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

  /* Get available filter number */
  CANReceive_filter_number = CAN1_Filter_Hook(CANReceive_filter_isr);
  if (CANReceive_filter_number < CAN_FILTER_COUNT) {
    /* CAN filter init:
       ID Type: Standard, Filter: Specific
     */
    CANReceive_FilterInitStructure.CAN_FilterNumber = CANReceive_filter_number;
    CANReceive_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CANReceive_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CANReceive_FilterInitStructure.CAN_FilterIdHigh = 0x220;
    CANReceive_FilterInitStructure.CAN_FilterIdLow = 0x0;
    CANReceive_FilterInitStructure.CAN_FilterMaskIdHigh = 0xFFE0;
    CANReceive_FilterInitStructure.CAN_FilterMaskIdLow = 0x4;
    CANReceive_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
    CANReceive_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CANReceive_FilterInitStructure);
  } else {
    /* Error: No filter avalable, All (0-13) already acquired */
  }

  /* Initial buffer */
  CANReceive_Msg_Buffer_RIndex = 0;
  CANReceive_Msg_Buffer_WIndex = 0;
}

void disable_CANReceive(void)
{
  /* Disable filter */
  CANReceive_FilterInitStructure.CAN_FilterActivation = DISABLE;
  CAN_FilterInit(&CANReceive_FilterInitStructure);

  /* Release hook */
  CAN1_Filter_Free(CANReceive_filter_number);

  /* Free buffer */
  CANReceive_Msg_Buffer_RIndex = 0;
  CANReceive_Msg_Buffer_WIndex = 0;
}

/* ########################################################################
 * Name: <Root>/CAN Receive1
 * Id: CANReceive1
 * ########################################################################
 */
CAN_FilterInitTypeDef CANReceive1_FilterInitStructure;
uint8_t CANReceive1_filter_number;     /*Filter matched index */
CANReceive1_DATA_STRUCT *CANReceive1_data;
CanRxMsg CANReceive1_Msg;              /* Temporary message */
CanRxMsg CANReceive1_Msg_Buffer[8];    /* Size must be a number of 2^N */
volatile uint16_t CANReceive1_Msg_Buffer_RIndex = 0;
volatile uint16_t CANReceive1_Msg_Buffer_WIndex = 0;
uint16_t CANReceive1_Msg_Buffer_Count(void)
{
  volatile uint16_t read_index;
  volatile uint16_t write_index;

  /* Get index to local variable, due to global will also access by ISR */
  read_index = CANReceive1_Msg_Buffer_RIndex;
  write_index = CANReceive1_Msg_Buffer_WIndex;
  if (write_index >= read_index) {
    return (write_index - read_index);
  } else {
    return ((8-read_index) + write_index);/* Max count is 8-1 */
  }
}

uint16_t CANReceive1_GetMsg(CanRxMsg* pMsg)
{
  uint16_t msg_pending;
  __disable_irq();
  msg_pending = CANReceive1_Msg_Buffer_Count();
  if (msg_pending > 0) {               //CANReceive1_Msg_Buffer_RIndex != CANReceive1_Msg_Buffer_WIndex) {
    memcpy(pMsg, &CANReceive1_Msg_Buffer[CANReceive1_Msg_Buffer_RIndex], sizeof
           (CanRxMsg));
    CANReceive1_Msg_Buffer_RIndex ++;
    CANReceive1_Msg_Buffer_RIndex &= (8-1);
  }

  __enable_irq();

  /* Number of pending message, include a reading */
  return msg_pending;
}

void CANReceive1_filter_isr(CanRxMsg* pMsg)
{
  if (pMsg->IDE == CAN_Id_Standard) {  /* Accept only ID Standard */
    memcpy(&CANReceive1_Msg_Buffer[CANReceive1_Msg_Buffer_WIndex] ,pMsg, sizeof
           (CanRxMsg));
    CANReceive1_Msg_Buffer_WIndex ++ ;
    CANReceive1_Msg_Buffer_WIndex &= (8-1);
    if (CANReceive1_Msg_Buffer_WIndex == CANReceive1_Msg_Buffer_RIndex) {/* Buffer overflow, Flush an oldest queue */
      CANReceive1_Msg_Buffer_RIndex ++;
      CANReceive1_Msg_Buffer_RIndex &= (8-1);
    }
  }
}

void enable_CANReceive1(void)
{
  // Initial the module
  WAIJUNG_CAN1_INIT ();

  /* Enable CAN clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

  /* Get available filter number */
  CANReceive1_filter_number = CAN1_Filter_Hook(CANReceive1_filter_isr);
  if (CANReceive1_filter_number < CAN_FILTER_COUNT) {
    /* CAN filter init:
       ID Type: Standard, Filter: Specific
     */
    CANReceive1_FilterInitStructure.CAN_FilterNumber = CANReceive1_filter_number;
    CANReceive1_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
    CANReceive1_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
    CANReceive1_FilterInitStructure.CAN_FilterIdHigh = 0x320;
    CANReceive1_FilterInitStructure.CAN_FilterIdLow = 0x0;
    CANReceive1_FilterInitStructure.CAN_FilterMaskIdHigh = 0xFFE0;
    CANReceive1_FilterInitStructure.CAN_FilterMaskIdLow = 0x4;
    CANReceive1_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
    CANReceive1_FilterInitStructure.CAN_FilterActivation = ENABLE;
    CAN_FilterInit(&CANReceive1_FilterInitStructure);
  } else {
    /* Error: No filter avalable, All (0-13) already acquired */
  }

  /* Initial buffer */
  CANReceive1_Msg_Buffer_RIndex = 0;
  CANReceive1_Msg_Buffer_WIndex = 0;
}

void disable_CANReceive1(void)
{
  /* Disable filter */
  CANReceive1_FilterInitStructure.CAN_FilterActivation = DISABLE;
  CAN_FilterInit(&CANReceive1_FilterInitStructure);

  /* Release hook */
  CAN1_Filter_Free(CANReceive1_filter_number);

  /* Free buffer */
  CANReceive1_Msg_Buffer_RIndex = 0;
  CANReceive1_Msg_Buffer_WIndex = 0;
}

/* ########################################################################
 * Name: <Root>/Digital Output
 * Id: DigitalOutput
 * ########################################################################
 */
void enable_DigitalOutput(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* Configure PC in output Push Pull mode for DigitalOutput Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 |
    GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;/* Waijung 14.xx */
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* ########################################################################
 * Name: <Root>/Digital Input1
 * Id: DigitalInput1
 * ########################################################################
 */
void enable_DigitalInput1(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  /* Configure PC in input None mode for DigitalInput1 Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

/* ########################################################################
 * Name: <Root>/Regular ADC
 * Id: RegularADC
 * ########################################################################
 */
ADC_InitTypeDef RegularADC_ADC_InitStructure;
ADC_CommonInitTypeDef RegularADC_ADC_CommonInitStructure;
DMA_InitTypeDef RegularADC_DMA_InitStructure;

/* RegularADC */
uint16_t RegularADC_ConvertedValue[1];
void enable_RegularADC(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable ADCx, DMA and GPIO clocks ****************************************/
  /* ADC1 */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /* Configure ADCx using channel pins as analog input ******************************/
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* ADC pin A0*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* DMA2 Stream channel configuration **************************************/
  RegularADC_DMA_InitStructure.DMA_Channel = RegularADC_DMA_CHANNEL;
  RegularADC_DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  RegularADC_DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  RegularADC_DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  RegularADC_DMA_InitStructure.DMA_PeripheralDataSize =
    DMA_PeripheralDataSize_HalfWord;
  RegularADC_DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  RegularADC_DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  RegularADC_DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  RegularADC_DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
  RegularADC_DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  RegularADC_DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  RegularADC_DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  RegularADC_DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)
    RegularADC_ADC_DR_ADDRESS;
  RegularADC_DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&
    RegularADC_ConvertedValue;
  RegularADC_DMA_InitStructure.DMA_BufferSize = 1;

  /* ADC Common Init **********************************************************/
  RegularADC_ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  RegularADC_ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
  RegularADC_ADC_CommonInitStructure.ADC_DMAAccessMode =
    ADC_DMAAccessMode_Disabled;
  RegularADC_ADC_CommonInitStructure.ADC_TwoSamplingDelay =
    ADC_TwoSamplingDelay_5Cycles;

  /* ADCx Init ****************************************************************/
  RegularADC_ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  RegularADC_ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  RegularADC_ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  RegularADC_ADC_InitStructure.ADC_ExternalTrigConvEdge =
    ADC_ExternalTrigConvEdge_None;
  RegularADC_ADC_InitStructure.ADC_ExternalTrigConv =
    ADC_ExternalTrigConv_Ext_IT11;     // avoid assert_fail
  RegularADC_ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  RegularADC_ADC_InitStructure.ADC_NbrOfConversion = 1;
}

void RegularADCStartConversion(void)
{
  /* DMA */
  DMA_DeInit(RegularADC_DMA_STREAM);
  DMA_Init(RegularADC_DMA_STREAM, &RegularADC_DMA_InitStructure);
  DMA_Cmd(RegularADC_DMA_STREAM, ENABLE);

  /* ADC Common */
  ADC_CommonInit(&RegularADC_ADC_CommonInitStructure);

  /* ADC */
  ADC_Init(ADC1, &RegularADC_ADC_InitStructure);

  /* ADCx regular channel1 configuration *************************************/
  ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_3Cycles);

  /* Enable DMA request after last transfer (Single-ADC mode) */
  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);

  /* Enable ADC1 DMA */
  ADC_DMACmd(ADC1, ENABLE);

  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);

  /* Start ADC Software Conversion */
  ADC_SoftwareStartConv(ADC1);

  /* Wait for ADA1-DMA transfer complete */
  while (!DMA_GetFlagStatus(RegularADC_DMA_STREAM, RegularADC_DMA_TC_FLAG)) ;

  /* Clear */
  DMA_ClearFlag(RegularADC_DMA_STREAM, RegularADC_DMA_TC_FLAG);
}

void disable_RegularADC(void)
{
}

/* ########################################################################
 * Name: <Root>/CAN Setup
 * Id: CANSetup
 * ########################################################################
 */
static uint8_t waijung_can1_ready = 0;
void waijung_can1_initial(void)
{
  CAN_InitTypeDef CAN_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  if (!waijung_can1_ready) {
    waijung_can1_ready = 1;            // Set ready status

    /* Enable GPIO clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Connect CAN pins to AF */
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_CAN1);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_CAN1);

    /* Configure CAN RX and TX pins */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* Enable CAN clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

    /* Configures the NVIC for CAN */
    NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* CAN cell init */
    CAN_InitStructure.CAN_TTCM = DISABLE;
    CAN_InitStructure.CAN_ABOM = ENABLE;
    CAN_InitStructure.CAN_AWUM = DISABLE;
    CAN_InitStructure.CAN_NART = ENABLE;//ENABLE;
    CAN_InitStructure.CAN_RFLM = DISABLE;
    CAN_InitStructure.CAN_TXFP = DISABLE;
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;

    /* CAN Baudrate = 125000 bps */
    CAN_InitStructure.CAN_BS1 = CAN_BS1_14tq;
    CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
    CAN_InitStructure.CAN_Prescaler = 16;
    CAN_Init(CAN1, &CAN_InitStructure);

    /* Enable FIFO 0 message pending Interrupt */
    CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
  }
}

void enable_CANSetup(void)
{
  // Initial the module
  WAIJUNG_CAN1_INIT ();
}

void disable_CANSetup(void)
{
}

/* [EOF] */

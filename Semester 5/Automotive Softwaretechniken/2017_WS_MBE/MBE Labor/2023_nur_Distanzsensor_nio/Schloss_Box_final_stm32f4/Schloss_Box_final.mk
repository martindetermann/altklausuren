# Make file generated with Waijung Blockset

PROJECT = Schloss_Box_final
DEBUG = 0
TOOLCHAIN = C:\Users\labuser\Desktop\waijung17_03a\utils\gnu_tools_arm_embedded\bin\arm-none-eabi-
STACK_SIZE = 0x2000
HEAP_SIZE = 0x2000
LD_SCRIPT = stm32f4xx_flash.ld

ELF = $(PROJECT).elf
HEX = $(PROJECT).hex
BIN = $(PROJECT).bin
LST = $(PROJECT).lss
DMP = $(PROJECT).dmp
MAP = $(PROJECT).map

# Tool chain definition
CXX = "$(TOOLCHAIN)g++"
CC = "$(TOOLCHAIN)gcc"
AS = "$(TOOLCHAIN)gcc" -x assembler-with-cpp
OBJCOPY = "$(TOOLCHAIN)objcopy"
OBJDUMP = "$(TOOLCHAIN)objdump"
SIZE = "$(TOOLCHAIN)size"

# Compiler and linker flags
CFLAGS = $(patsubst %, -I%, .) -mcpu=cortex-m4 -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffast-math -Wall -Wextra -Ofast
AFLAGS = $(patsubst %, -I%, .) -mcpu=cortex-m4 -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffast-math -Wall -Wextra -Ofast -Wa,-amhls=$(<:.s=.lst) -D__STACK_SIZE=$(STACK_SIZE) -D__HEAP_SIZE=$(HEAP_SIZE)
LFLAGS = -T$(LD_SCRIPT) -g -Wl,-Map=$(MAP),--cref,--no-warn-mismatch -mcpu=cortex-m4 -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 -specs=nosys.specs

AS_SRCS = $(wildcard *.s)
AS_OBJS = $(AS_SRCS:.s=.o)
C_SRCS = $(wildcard *.c)
C_OBJS = $(C_SRCS:.c=.o)

OBJS = $(AS_OBJS) $(C_OBJS)

ifeq ($(DEBUG), 1)
	AFLAGS += -g -ggdb3
	CFLAGS += -g -ggdb3
	LFLAGS += -g -ggdb3
endif

LFLAGS += -nostartfiles
LIBS = 

##############################################
# Make all
##############################################
all : $(ELF) $(HEX) $(BIN) $(LST) $(DMP) report

%.o : %.s
	@echo Assembling file: $<
	$(AS) -c $(AFLAGS) $< -o $@

%.o : %.c
	@echo Compiling: $<
	$(CC) -c $(CFLAGS) $< -o $@

$(ELF) : $(OBJS)
	@echo Linking target: $(ELF)
	$(CXX) $(OBJS) $(LFLAGS) $(LIBS) -o $@

$(HEX) : $(ELF)
	@echo Creating HEX: $(HEX)
	$(OBJCOPY) -O ihex $< $@

$(BIN) : $(ELF)
	@echo Creating binary image: $(BIN)
	$(OBJCOPY) -O binary $< $@

$(LST) : $(ELF)
	@echo Creating listing: $(LST)
	$(OBJDUMP) -S $< > $@

$(DMP) : $(ELF)
	@echo Creating memory dump: $(DMP)
	$(OBJDUMP) -x --syms $< > $@

report :
	@echo.
	@echo ===================================================================
	@echo Target size:
	$(SIZE) -B $(ELF)
	@echo.
	@echo Objects size:
	$(SIZE) -B -t --common $(OBJS) $(USER_OBJS)
	@echo ===================================================================

clean :
	del /Q /F *.o
	del /Q /F *.lst

clean-obj:
	del /Q /F *.o
	del /Q /F *.lst


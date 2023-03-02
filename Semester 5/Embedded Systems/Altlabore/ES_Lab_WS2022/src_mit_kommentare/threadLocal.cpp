#include "threadLocal.h"

threadLocal::threadLocal()
{

}

/*
-Speicherauslastung: current size allocated pre compilatation divided by the max size in Datenblatt
-Zykluszeiten messen inkl. Pause
*/
double threadLocal::get_stack_stats()
{
    double sum_reserved;
    double heap_auslastung;
    this->stack_count = osThreadGetCount();
    mbed_stats_stack_t *stats = (mbed_stats_stack_t*) malloc(this->stack_count * sizeof(mbed_stats_stack_t));
    this->stack_count = mbed_stats_stack_get_each(stats, this->stack_count);
    for (int i=0; i<stack_count+1; i++)
    {
        sum_reserved += (double)stats->reserved_size;
    }
    free(stats);
    //use sum of heap and thread auslastung
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    heap_auslastung = (double)heap_stats.current_size;
    heap_auslastung += sum_reserved;
    heap_auslastung = 100*heap_auslastung/64000;
    return heap_auslastung;
}
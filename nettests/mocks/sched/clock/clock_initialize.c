#include <nuttx/clock.h>

#ifndef CONFIG_SCHED_TICKLESS
#ifdef CONFIG_SYSTEM_TIME64
volatile uint64_t g_system_timer = INITIAL_SYSTEM_TIMER_TICKS;
#else
volatile uint32_t g_system_timer = INITIAL_SYSTEM_TIMER_TICKS;
#endif
#endif

#include "sched/sched.h"

static bool g_idletask = false;

bool sched_idletask(void)
{
  return g_idletask;
}

/****************************************************************************
 * Name: mock_sched_idletask
 *
 * Description:
 *   Set a value returned by sched_idletask function
 *
 ****************************************************************************/

void mock_sched_idletask(bool value)
{
  g_idletask = value;
}

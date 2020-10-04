#include "semaphore/semaphore.h"

#include <sys/types.h>

int nxsem_timedwait(sem_t *sem, const struct timespec *abstime)
{
    (void) sem;
    return -ENOSYS;
}

int nxsem_timedwait_uninterruptible(sem_t *sem, const struct timespec *abstime)
{
    (void) sem;
    return -ENOSYS;
}

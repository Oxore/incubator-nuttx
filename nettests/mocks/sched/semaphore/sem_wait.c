#include "semaphore/semaphore.h"

#include <sys/types.h>

int nxsem_wait(sem_t *sem)
{
    (void) sem;
    return -ENOSYS;
}

int nxsem_wait_uninterruptible(sem_t *sem)
{
    (void) sem;
    return -ENOSYS;
}

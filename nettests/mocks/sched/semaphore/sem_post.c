#include "semaphore/semaphore.h"

#include <sys/types.h>

int nxsem_post(sem_t *sem)
{
    (void) sem;
    return -ENOSYS;
}

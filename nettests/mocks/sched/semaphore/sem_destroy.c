#include "semaphore/semaphore.h"

#include <sys/types.h>

int nxsem_destroy(sem_t *sem)
{
    (void) sem;
    return -ENOSYS;
}

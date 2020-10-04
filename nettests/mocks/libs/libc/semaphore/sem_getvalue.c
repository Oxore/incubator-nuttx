#include <nuttx/semaphore.h>

#include <sys/types.h>

int nxsem_get_value(sem_t *sem, int *sval)
{
    (void) sem;
    (void) sval;
    return -ENOSYS;
}

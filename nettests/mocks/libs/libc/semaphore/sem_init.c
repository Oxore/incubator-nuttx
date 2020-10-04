#include <nuttx/semaphore.h>

#include <sys/types.h>

int nxsem_init(sem_t *sem, int pshared, unsigned int value)
{
    (void) sem;
    (void) pshared;
    (void) value;
    return -ENOSYS;
}

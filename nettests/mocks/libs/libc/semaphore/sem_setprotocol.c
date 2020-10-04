#include <nuttx/semaphore.h>

#include <sys/types.h>

int nxsem_set_protocol(FAR sem_t *sem, int protocol)
{
    (void) sem;
    (void) protocol;
    return -ENOSYS;
}

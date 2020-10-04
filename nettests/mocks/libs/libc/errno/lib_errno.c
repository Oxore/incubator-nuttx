#include <errno.h>

static int errno_value = -ENOSYS;

int *__errno(void)
{
    return &errno_value;
}

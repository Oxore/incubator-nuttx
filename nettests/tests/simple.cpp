#include <doctest/doctest.h>

#include <nuttx/compiler.h>
#include <nuttx/net/net.h>

TEST_CASE("Simple setup and teardown") {
    net_initialize();
}

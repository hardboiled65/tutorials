#include "foo.h"

#include <stdio.h>

namespace foo {

void Foo::say_hello() const
{
    printf("Hello, world!\n");
}

} // namespace foo

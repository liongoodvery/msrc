//
// Created by lion on 17-7-17.
//
#include "mytest.h"
#include "mytest.h"
void mydestory(void *data) {
    Foo *foo = (Foo *) (data);
    printf("destory foo.a=%d,foo.b=%d\n", foo->a, foo->b);
    free(foo);
}

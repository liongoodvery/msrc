#include <stdio.h>
#include <assert.h>
#include "bitree.h"
#include "mytest.h"
#include <limits.h>

#define TEST_COUNT 10

void mdestory(void *data) {
    Foo *foo = (Foo *) (data);
    printf("destory foo.a=%d,foo.b=%d\n", foo->a, foo->b);
    free(foo);
}

void myPrint(void *data) {
    Foo *foo = (Foo *) data;
    fprintf(stdout, "foo.a=%d,foo.b=%d\n", foo->a, foo->b);
}

int main() {
    BiTree biTree;
    bitree_init(&biTree, mdestory, myPrint);
    Foo *foos[TEST_COUNT];
    Foo *foo;
    for (int i = 0; i < TEST_COUNT; ++i) {
        foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        foos[i] = foo;
    }

//    free(foos[9]);
    bitree_fill(&biTree, foos, sizeof(Foo), TEST_COUNT);

    bitree_traverse(&biTree);
    bitree_destroy(&biTree);
    return 0;
}
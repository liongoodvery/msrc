#include <assert.h>
#include "mytest.h"
#include "stack.h"

#define TEST_COUNT 10

int main() {
    Stack stack;
    stack_init(&stack, mydestory);
    assert(stack_size(&stack) == 0);

    for (int i = 0; i < TEST_COUNT; ++i) {
        Foo *foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        stack_push(&stack, foo);
    }

    assert(stack_size(&stack) == TEST_COUNT);

    for (int i = 0; i < TEST_COUNT; ++i) {
        Foo *foo;
        stack_pop(&stack, (void **) &foo);
        assert(foo->a == TEST_COUNT - i - 1);
        assert(foo->b == i - TEST_COUNT + 1);
        mydestory(foo);
    }

    stack_destroy(&stack);
}
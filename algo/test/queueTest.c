#include <assert.h>
#include "mytest.h"
#include "queue.h"

#define TEST_COUNT 10

int main() {
    Queue queue;
    queue_init(&queue, mydestory);
    assert(queue_size(&queue) == 0);

    for (int i = 0; i < TEST_COUNT; ++i) {
        Foo *foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        queue_enqueue(&queue, foo);
    }

    assert(queue_size(&queue) == TEST_COUNT);

    Foo *foo;
    for (int i = 0; i < TEST_COUNT; ++i) {
        queue_dequeue(&queue, (void **) &foo);
        assert(foo->a == i);
        assert(foo->b == -i);
        mydestory(foo);
    }

    assert(queue_peek(&queue) == NULL);

    queue_destroy(&queue);
}
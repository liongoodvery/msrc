#include <stdio.h>
#include <assert.h>
#include "dlist.h"
#include "mytest.h"




int main() {
    DList dList;
    dlist_init(&dList, mydestory);
    assert(dList.size == 0);
    assert(dList.head->next == dList.tail);
    assert(dList.tail->prev == dList.head);

    for (int i = 0; i < 10; ++i) {
        Foo *foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        dlist_ins_next(&dList, dList.head, foo);
    }

    for (int i = 0; i < 10; ++i) {
        Foo *foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        dlist_ins_prev(&dList, dList.tail, foo);
    }

    assert(dList.size == 20);

    int i = 10;
    DListElmt *start = dList.head;
    DListElmt *end = dList.tail;

    while (--i) {
        start = start->next;
        end = end->prev;
        assert(((Foo *) dlist_data(start))->a == i);
        assert(((Foo *) dlist_data(start))->b == -i);

        assert(((Foo *) dlist_data(end))->a == i);
        assert(((Foo *) dlist_data(end))->b == -i);
    }

    void *data;
    dlist_remove(&dList, dList.head->next, (void **) &data);
    mydestory(data);
    dlist_remove(&dList, dList.tail->prev, (void **) &data);
    mydestory(data);

    dlist_destroy(&dList);
    return 0;
}
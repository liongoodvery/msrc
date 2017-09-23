#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "mytest.h"

int main() {
    List list;
    list_init(&list, mydestory);
    assert(list.head == NULL);
    assert(list.tail == NULL);
    assert(list_size(&list) == 0);

    Foo *foo = (Foo *) malloc(sizeof(Foo));
    foo->a = -1;
    foo->b = -1;

    list_ins_next(&list, NULL, foo);
    assert(list.head->data == foo);
    assert(list.tail->data == foo);
    assert(list_size(&list) == 1);
    assert(list_data(list.head) == foo);

    for (int i = 0; i < 10; ++i) {
        Foo *bar = (Foo *) malloc(sizeof(Foo));
        bar->a = i;
        bar->b = -i;
        list_ins_next(&list, NULL, bar);
    }
    assert(list_size(&list) == 11);
    assert(((Foo *) list_data(list.head))->a == 9);
    assert(((Foo *) list_data(list.head))->b == -9);
    assert(((Foo *) list_data(list.tail))->a == -1);
    assert(((Foo *) list_data(list.tail))->b == -1);


    Foo *e;

    assert(list_rem_next(&list, NULL, (void **) &e) == 0);
    assert(list_size(&list) == 10);
    assert(((Foo *) list_data(list.head))->a == 8);
    assert(((Foo *) list_data(list.head))->b == -8);
    assert(((Foo *) list_data(list.tail))->a == -1);
    assert(((Foo *) list_data(list.tail))->b == -1);
    assert(e->a == 9);
    assert(e->b == -9);
    list.destroy(e);
    list_destroy(&list);

    return 0;
}
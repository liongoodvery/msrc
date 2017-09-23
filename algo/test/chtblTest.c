#include <assert.h>
#include "mytest.h"
#include "chtbl.h"
#include "hashpjw.h"

#define TEST_COUNT 10

int match(Foo *a, Foo *b) {
    return a->a == b->a && a->b == b->b ? 1 : 0;
}

int main() {
    CHTbl table;
    chtbl_init(&table, 101, hashpjw, match, mydestory);

    int ret;
    Foo *foo;

    for (int i = 0; i < TEST_COUNT; ++i) {
        foo = (Foo *) malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        ret = chtbl_insert(&table, foo);
        assert(ret == 0);
    }

    Foo *const bar = (Foo *) malloc(sizeof(Foo));
    Foo *r;
    r = NULL;
    for (int j = 0; j < TEST_COUNT; ++j) {

        bar->a = j;
        bar->b = -j;
        ret = chtbl_lookup(&table, bar, (void **) &r);
        assert(ret == 0);
        assert(bar->a == r->a);
        assert(bar->b == r->b);

    }
    bar->a = TEST_COUNT;
    bar->b = -TEST_COUNT;
    ret = chtbl_lookup(&table, bar, (void **) r);
    assert(ret == -1);

    r = NULL;
    for (int j = 0; j < TEST_COUNT; ++j) {

        bar->a = j;
        bar->b = -j;
        ret = chtbl_remove(&table, bar, (void **) &r);
        assert(ret == 0);
        assert(r != NULL);
        assert(bar->a == r->a);
        assert(bar->b == r->b);
        free(r);
        r = NULL;
    }

    free(bar);
    chtbl_destroy(&table);
}
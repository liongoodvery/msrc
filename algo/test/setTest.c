#include <assert.h>
#include "mytest.h"
#include "set.h"

#define TEST_COUNT 10

int match(Foo *a, Foo *b) {
    return a->a == b->a && a->b == b->b ? 1 : 0;
}

int main() {
    Set set;
    set_init(&set, match, mydestory);
    int ret;
    for (int i = 0; i < TEST_COUNT; ++i) {
        Foo *foo = malloc(sizeof(Foo));
        foo->a = i;
        foo->b = -i;
        ret = set_insert(&set, (void *) foo);
        assert(ret == 0);
    }
    assert(set_size(&set) == TEST_COUNT);
    Foo *foo = malloc(sizeof(Foo));
    void *data = foo;
    foo->a = 0;
    foo->b = -0;
    ret = set_insert(&set, (void *) foo);
    assert(ret == 1);
    assert(set_is_member(&set, foo));

    ret = set_remove(&set, &data);
    assert(ret == 0);

    free(data);
    assert(set_size(&set) == TEST_COUNT - 1);

    ret = set_insert(&set, (void *) foo);
    assert(ret == 0);
    assert(set_size(&set) == TEST_COUNT);


    Set set2;
    set_init(&set2, match, mydestory);
    for (int i = 0; i < TEST_COUNT; ++i) {
        Foo *foo = malloc(sizeof(Foo));
        foo->a = i + TEST_COUNT - 2;
        foo->b = -(i + TEST_COUNT - 2);
        set_insert(&set2, (void *) foo);
    }
    assert(set_size(&set2) == TEST_COUNT);


    Set *psetd = (Set *) malloc(sizeof(Set));
    Set *pseti = (Set *) malloc(sizeof(Set));
    Set *psetu = (Set *) malloc(sizeof(Set));
    set_difference(psetd, &set, &set2);
    set_intersection(pseti, &set, &set2);
    set_union(psetu, &set, &set2);

    assert(set_size(psetd) == TEST_COUNT - 2);
    assert(set_size(pseti) == 2);
    assert(set_size(psetu) == 18);

    Foo *testFoo = (Foo *) malloc(sizeof(Foo));
    for (int i = 0; i < TEST_COUNT - 2; ++i) {
        testFoo->a = i;
        testFoo->b = -i;
        ret = set_is_member(psetd, testFoo);
        assert(ret == 1);

        ret = set_is_member(pseti, testFoo);
        assert(ret == 0);

        ret = set_is_member(psetu, testFoo);
        assert(ret == 1);

        ret = set_is_member(&set, testFoo);
        assert(ret == 1);

        ret = set_is_member(&set2, testFoo);
        assert(ret == 0);
    }

    for (int i = TEST_COUNT - 2; i < TEST_COUNT; ++i) {
        testFoo->a = i;
        testFoo->b = -i;
        ret = set_is_member(psetd, testFoo);
        assert(ret == 0);

        ret = set_is_member(pseti, testFoo);
        assert(ret == 1);

        ret = set_is_member(psetu, testFoo);
        assert(ret == 1);

        ret = set_is_member(&set, testFoo);
        assert(ret == 1);

        ret = set_is_member(&set2, testFoo);
        assert(ret == 1);
    }

    for (int i = TEST_COUNT; i < 2 * TEST_COUNT - 2; ++i) {
        testFoo->a = i;
        testFoo->b = -i;
        ret = set_is_member(psetd, testFoo);
        assert(ret == 0);

        ret = set_is_member(pseti, testFoo);
        assert(ret == 0);

        ret = set_is_member(psetu, testFoo);
        assert(ret == 1);

        ret = set_is_member(&set, testFoo);
        assert(ret == 0);

        ret = set_is_member(&set2, testFoo);
        assert(ret == 1);
    }


    free(psetd);
    free(pseti);
    free(psetu);
    free(testFoo);
    set_destroy(&set2);
    set_destroy(&set);
    return 0;
}
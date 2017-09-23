#include "set.h"
#include "string.h"

void set_init(Set *set, int (*match)(const void *key1, const void *key2),
              void (*destroy)(void *data)) {

    list_init(set, destroy);
    set->match = match;
}

int set_insert(Set *set, const void *data) {
    if (set_is_member(set, data)) {
        return 1;
    }
    return list_ins_next(set, NULL, data);
}

int set_remove(Set *set, void **data) {
    ListElmt *prev;
    ListElmt *elmt;

    prev = NULL;
    for (elmt = list_head(set); elmt != NULL; elmt = list_next(elmt)) {
        if (set->match(list_data(elmt), *data)) {
            break;
        }
        prev = elmt;
    }

    if (elmt == NULL) {
        return -1;
    }
    return list_rem_next(set, prev, data);
}


int set_is_member(const Set *set, const void *data) {
    ListElmt *li;
    for (li = list_head(set); li != NULL; li = list_next(li)) {
        if (set->match(list_data(li), data)) {
            return 1;
        }
    }

    return 0;
}


int set_difference(Set *setd, const Set *set1, const Set *set2) {
    set_init(setd, set1->match, NULL);

    ListElmt *elmt;
    int ret;
    for (elmt = list_head(set1); elmt != NULL; elmt = list_next(elmt)) {
        if (!set_is_member(set2, list_data(elmt))) {
            if (set_insert(setd, list_data(elmt))) {
                return -1;
            }
        }
    }
    return 0;
}


int set_intersection(Set *seti, const Set *set1, const Set *set2) {
    set_init(seti, set1->match, NULL);
    ListElmt *elmt;
    void *data;
    for (elmt = list_head(set1); elmt != NULL; elmt = list_next(elmt)) {
        data = list_data(elmt);
        if (set_is_member(set2, data)) {
            if (set_insert(seti, data)) {
                return -1;
            };
        }
    }
    return 0;
}

int set_union(Set *setu, const Set *set1, const Set *set2){
    set_init(setu, set1->match, NULL);
    ListElmt *elmt;
    void *data;
    for (elmt = list_head(set1); elmt != NULL; elmt = list_next(elmt)) {
        data = list_data(elmt);
        if (set_insert(setu, data)) {
            return -1;
        }
    }

    for (elmt = list_head(set2); elmt != NULL; elmt = list_next(elmt)) {
        data = list_data(elmt);
        if (!set_is_member(setu, data)) {
            if (set_insert(setu, data)) {
                return -1;
            }
        }
    }
    return 0;
}
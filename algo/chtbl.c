//
// Created by lion on 17-7-20.
//

#include "chtbl.h"
#include <string.h>

int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), int
(*match)(const void *key1, const void *key2), void (*destroy)(void *data)) {
    htbl->size = 0;
    htbl->match = match;
    htbl->destroy = destroy;
    htbl->buckets = buckets;
    htbl->h = h;
    htbl->table = (List *) malloc(sizeof(List) * buckets);
    if (htbl->table == NULL) {
        return -1;
    }
    for (int i = 0; i < buckets; ++i) {
        list_init(htbl->table + i, destroy);
    }
}


void chtbl_destroy(CHTbl *htbl) {
    int buckets = htbl->buckets;
    for (int i = 0; i < buckets; ++i) {
        list_destroy(htbl->table + i);
    }
    free(htbl->table);
    memset(htbl, 0, sizeof(CHTbl));
}


int chtbl_insert(CHTbl *htbl, const void *data) {
    int i = htbl->h(data) % htbl->buckets;

    ListElmt *elmt;
    List *pList = htbl->table + i;
    for (elmt = list_head(pList); elmt != NULL; elmt = list_next(elmt)) {
        if (htbl->match(data, list_data(elmt))) {
            return 1;
        }
    }

    if (elmt == NULL) {
        int ret = list_ins_next(pList, NULL, data);
        if (ret == 0) {
            htbl->size++;
            return ret;
        }
    }
    return -1;
}

int chtbl_remove(CHTbl *htbl, const void *com_data, void **data) {
    int i = htbl->h(com_data) % htbl->buckets;
    ListElmt *elmt, *prev;
    prev=NULL;
    List *pList = htbl->table + i;
    for (elmt = list_head(pList); elmt != NULL; elmt = list_next(elmt)) {
        if (htbl->match(com_data, list_data(elmt))) {
            return list_rem_next(pList, prev, data);
        }
        prev = elmt;
    }


    return 0;
}

int chtbl_lookup(const CHTbl *htbl, const void *com_data, void **data) {
    int i = htbl->h(com_data) % htbl->buckets;
    ListElmt *elmt;
    List *pList = htbl->table + i;
    for (elmt = list_head(pList); elmt != NULL; elmt = list_next(elmt)) {
        if (htbl->match(com_data, list_data(elmt))) {
            *data = list_data(elmt);
            return 0;
        }
    }

    return -1;
}
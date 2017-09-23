#include "dlist.h"


void dlist_init(DList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    DListElmt *head = calloc(1, sizeof(DListElmt));
    DListElmt *tail = calloc(1, sizeof(DListElmt));

    head->next = tail;
    tail->prev = head;
    list->head = head;
    list->tail = tail;
}

void dlist_destroy(DList *list) {
    void *data;

    while (dlist_remove(list, list->head->next, (void **) &data) == 0 && list->destroy != NULL) {
        list->destroy(data);
    }

    list->head->next = NULL;
    list->tail->prev = NULL;
    free(list->head);
    free(list->tail);
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data) {
    if (list->tail == element) {
        return -1;
    }
    DListElmt *newElmt = (DListElmt *) calloc(1, sizeof(DListElmt));
    newElmt->data = (void *) data;
    element->next->prev = newElmt;
    newElmt->next = element->next;
    element->next = newElmt;
    newElmt->prev = element;
    list->size++;
    return 0;
}

int dlist_ins_prev(DList *list, DListElmt *element, const void *data) {
    if (list->head == element) {
        return -1;
    }
    DListElmt *newElmt = (DListElmt *) calloc(1, sizeof(DListElmt));
    newElmt->data = (void *) data;

    element->prev->next = newElmt;
    newElmt->prev = element->prev;
    element->prev = newElmt;
    newElmt->next = element;
    list->size++;
    return 0;
}

int dlist_remove(DList *list, DListElmt *element, void **data) {
    if (list->head == element || list->tail == element || element->next == NULL || element->prev == NULL) {
        return -1;
    }
    *data = element->data;
    element->prev->next = element->next;
    element->next->prev = element->prev;
    free(element);
    list->size--;
    return 0;
}
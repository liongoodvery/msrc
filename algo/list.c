#include "list.h"
#include "string.h"

void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void list_destroy(List *list) {
    void *data;
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **) &data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(List));
}

int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *newElem = malloc(sizeof(ListElmt));
    if (newElem == NULL) {
        return -1;
    }
    newElem->data = (void *) data;

    if (element == NULL) {
        if (list_size(list) == 0) {
            list->tail = newElem;
        }
        newElem->next = list->head;
        list->head = newElem;
    } else {
        if (element->next == NULL) {
            list->tail = newElem;
        }
        newElem->next = element->next;
        element->next = newElem;
    }

    list->size++;
    return 0;
}


int list_rem_next(List *list, ListElmt *element, void **data) {


    ListElmt *old;
    if (list_size(list) == 0) {
        return -1;
    }

    if (element == NULL) {

        *data = list->head->data;
        old = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }

    } else {
        if (element->next == NULL) {
            return -1;
        }

        *data = element->next->data;
        old = element->next;
        element->next = element->next->next;

        if (element->next == NULL) {
            list->tail = element;
        }

    }



    free(old);

    list->size--;
    return 0;

}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"
#include "value.h"
#include "talloc.h"

// Create a new NULL_TYPE value node.
Value *makeNull() {
    Value *value = (Value *)talloc(sizeof(Value));
    value->type = NULL_TYPE;
    return value;
}

// Create a new CONS_TYPE value node.
Value *cons(Value *newCar, Value *newCdr) {
    Value *value =  (Value *)talloc(sizeof(Value));
    value->type = CONS_TYPE;
    value->c.car = newCar;
    value->c.cdr = newCdr;
    return value;
}

// Display the contents of the linked list to the screen in some kind of
// readable format
void display(Value *list) {
    Value *curr = list;
    while (curr->type != NULL_TYPE) {
        switch (curr->c.car->type) {
            case INT_TYPE:
            printf("%i ", curr->c.car->i);
            break;
            case DOUBLE_TYPE:
            printf("%f ", curr->c.car->d);
            break;
            case STR_TYPE:
            printf("%s ", curr->c.car->s);
            break;
            default:
            break;
        }
        curr = curr->c.cdr;
    }
    printf("\n");
};

// Return a new list that is the reverse of the one that is passed in. All
// content within the list should be duplicated; there should be no shared
// memory whatsoever between the original list and the new one.
//
// FAQ: What if there are nested lists inside that list?
// ANS: There won't be for this assignment. There will be later, but that will
// be after we've got an easier way of managing memory.
Value *reverse(Value *list) {
    Value *curr = list;
    Value *next = makeNull();
    while (curr->type != NULL_TYPE) {
        Value *prev = (Value *)talloc(sizeof(Value));
        prev->type = curr->c.car->type;
        prev = curr->c.car;
        next = cons(prev, next);
        curr = curr->c.cdr;
    }
    return next;
};

// Utility to make it less typing to get car value. Use assertions to make sure
// that this is a legitimate operation.
Value *car(Value *list) {
    assert(list != NULL);
    assert(list->type == CONS_TYPE);
    return list->c.car;
};

// Utility to make it less typing to get cdr value. Use assertions to make sure
// that this is a legitimate operation.
Value *cdr(Value *list) {
    assert(list != NULL);
    assert(list->type == CONS_TYPE);
    return list->c.cdr;
};

// Utility to check if pointing to a NULL_TYPE value. Use assertions to make sure
// that this is a legitimate operation.
bool isNull(Value *value) {
    assert(value != NULL);
    return (value->type == NULL_TYPE);
};

// Measure length of list. Use assertions to make sure that this is a legitimate
// operation.
int length(Value *value) {
    int length = 0;
    Value *curr = value;
    while (curr->type != NULL_TYPE) {
        length++;
        curr = curr->c.cdr;
    }
    return length;
};

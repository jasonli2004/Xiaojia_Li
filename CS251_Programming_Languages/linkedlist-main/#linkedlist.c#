#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"
#include "value.h"

// Create a new NULL_TYPE value node.
Value *makeNull(){
    Value *node = malloc(sizeof(Value));
    node->type = NULL_TYPE;
    return node;
}

// Create a new CONS_TYPE value node.
Value *cons(Value *newCar, Value *newCdr){
    Value *node = malloc(sizeof(Value));
    node->type = CONS_TYPE;
    node->c.car = newCar;
    node->c.cdr = newCdr;
    return node;
}

// Display the contents of the linked list to the screen in some kind of
// readable format
void display(Value *list){
    while (list->type != NULL_TYPE){
        switch (list->c.car->type) {
            case INT_TYPE:
                printf("%d,",list->c.car->i);
                break;
            case DOUBLE_TYPE:
                printf("%f,",list->c.car->d);
                break;
            case STR_TYPE:
                printf("%s,",list->c.car->s);
                break;
            default:
                break;
        }
        list = list->c.cdr;
    }
}


// Return a new list that is the reverse of the one that is passed in. All
// content within the list should be duplicated; there should be no shared
// memory whatsoever between the original list and the new one.
//
// FAQ: What if there are nested lists inside that list?
// ANS: There won't be for this assignment. There will be later, but that will
// be after we've got an easier way of managing memory.
Value *reverse(Value *list){
    Value *tail = makeNull();
    while (list->type != NULL_TYPE){
        Value *temp = malloc(sizeof(Value));
        switch (list->c.car->type) {
            case INT_TYPE:
                temp->i = list->c.car->i;
                temp->type = INT_TYPE;
                break;
            case DOUBLE_TYPE:
                temp->d = list->c.car->d;
                temp->type = DOUBLE_TYPE;
                break;
            case STR_TYPE:
                char *text = list->c.car->s;
                temp->s = malloc(sizeof(char)*(strlen(text) + 1));
                strcpy(temp->s,text);
                temp->type = STR_TYPE;

                // temp->s = malloc(sizeof(char)*(strlen( list->c.car->s) + 1));
                // strcpy(temp->s, list->c.car->s);
                // temp->type = STR_TYPE;

                break;
            default:
                break;
        }
        tail = cons(temp,tail);
        list = list->c.cdr;
        
    }
    return tail;
}

// Frees up all memory directly or indirectly referred to by list. This includes strings.
//
// FAQ: What if a string being pointed to is a string literal? That throws an
// error when freeing.
//
// ANS: Don't put a string literal into the list in the first place. All strings
// added to this list should be able to be freed by the cleanup function.
//
// FAQ: What if there are nested lists inside that list?
//
// ANS: There won't be for this assignment. There will be later, but that will
// be after we've got an easier way of managing memory.
void cleanup(Value *list){
    while (list->type != NULL_TYPE){
        if (list->c.car->type == STR_TYPE){
            free(list->c.car->s);
        }
        free(list->c.car);
        Value *temp = list->c.cdr;
        free(list);
        list = temp;
    }
    free(list);
}



// Utility to make it less typing to get car value. Use assertions to make sure
// that this is a legitimate operation.
Value *car(Value *list){
    assert(list != NULL);
    assert(list->type == CONS_TYPE);
    return (list->c.car);
}

// Utility to make it less typing to get cdr value. Use assertions to make sure
// that this is a legitimate operation.
Value *cdr(Value *list){
    assert(list != NULL);
    assert(list->type == CONS_TYPE);
    return (list->c.cdr);
}

// Utility to check if pointing to a NULL_TYPE value. Use assertions to make sure
// that this is a legitimate operation.
bool isNull(Value *value){
    
    assert(value != NULL);
    return (value->type == NULL_TYPE);
}

// Measure length of list. Use assertions to make sure that this is a legitimate
// operation.
int length(Value *value){
    int cnt = 0;
    while (value->type != NULL_TYPE){
        cnt++;
        value = value->c.cdr;
    }
    return cnt;
}


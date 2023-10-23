#include <stdio.h>
#include <assert.h>
#include "tokenizer.h"
#include "value.h"
#include "linkedlist.h"
#include "parser.h"
#include "talloc.h"

// Takes a list of tokens from a Scheme program, and returns a pointer to a
// parse tree representing that program.
Value *parse(Value *tokens) {
    Value *tree = makeNull();
    int depth = 0;

    Value *current = tokens;
    assert(current != NULL && "Error (parse): null pointer");
    while (current->type != NULL_TYPE) {
        Value *token = car(current);
        if (token->type == OPEN_TYPE) {
            // Add depth and the open bracket to generate subtree and check for bracket imbalance
            depth += 1;
            tree = cons(token, tree);
        } else if (token->type == CLOSE_TYPE) {
            // Throw an error as there is too many close parentheses
            if (depth == 0) {
                printf("Syntax error: too many close parentheses\n");
                texit(1);
            } else {
                // Concatenate tokens until you reach an open bracket into a subtree
                depth -= 1;
                Value *head = makeNull();
                while (car(tree)->type != OPEN_TYPE) {
                    head = cons(car(tree), head);
                    tree = cdr(tree);
                }
                // Skip the open bracket and add the subtree back to the tree
                tree = cons(head, cdr(tree));
            }
        } else {
            // Add the token to the tree (stack)
            tree = cons(token, tree);
        }
        current = cdr(current);
    }
    if (depth != 0) {
        printf("Syntax error: too many open parentheses\n");
        texit(1);
    }
    // Reverse the tree as the last token is at the top (stack implementation)
    return reverse(tree);
}


// Prints the tree to the screen in a readable fashion. It should look just like
// Scheme code; use parentheses to indicate subtrees.
void printTree(Value *tree) {
    Value* curr;
    while (tree->type != NULL_TYPE) {
        if (tree->type != CONS_TYPE){
            printf(" . ");
            switch (tree->type) {
            case INT_TYPE:
            printf("%i ", tree->i);
            break;
            case DOUBLE_TYPE:
            printf("%f ", tree->d);
            break;
            default:
            printf("%s ", tree->s);
            break;
            }
            return;
        }
        curr = car(tree);
        if (curr->type != CONS_TYPE && curr->type != NULL_TYPE) {
            // Print out singular token based on the type of tokens stored
            switch (curr->type) {
            case INT_TYPE:
            printf("%i ", curr->i);
            break;
            case DOUBLE_TYPE:
            printf("%f ", curr->d);
            break;
            default:
            printf("%s ", curr->s);
            break;
            }
        } else {
            // Print out sub tree inside a bracket by recursively go in until reaching a single token
            printf("(");
            printTree(curr);
            printf(") ");
        }
    tree = cdr(tree);

    }
    printf("\n");
}


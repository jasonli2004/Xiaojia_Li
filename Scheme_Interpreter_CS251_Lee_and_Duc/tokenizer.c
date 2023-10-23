#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "value.h"
#include "linkedlist.h"
#include "talloc.h"

int isSpecial(char c){
    if (c=='\n' || c == ' ' || c == '(' || c == ')' || c == ';' || c == EOF){
        return 1;
    }
    return 0;
}

void synErr(){
    printf("Syntax error \n");
    texit(1);
}

// Read all of the input from stdin, and return a linked list consisting of the
// tokens.
Value *tokenize() {
    char charRead;
    Value *list = makeNull();
    charRead = (char)fgetc(stdin);

    while (charRead != EOF) {
   
        if (charRead == '('){
            Value *temp = talloc(sizeof(Value));
            temp->type = OPEN_TYPE;
            temp->s = "(";
            list = cons(temp, list);
        } 
        else if (charRead == ')'){
            Value *temp = talloc(sizeof(Value));
            temp->type = CLOSE_TYPE;
            temp->s = ")";
            list = cons(temp, list);
        } 
        else if (charRead == '#'){
            charRead = (char)fgetc(stdin);
            char *b = talloc(sizeof(char)*3);
            b[0]='#';
            if (charRead == 't' || charRead == 'f'){
                char tmp = charRead;
                charRead = (char)fgetc(stdin);
                if (isSpecial(charRead)){
                    Value *temp = talloc(sizeof(Value));
                    temp->type = BOOL_TYPE;
                    b[1] = tmp;
                    b[2] = '\0';
                    temp->s = b;
                    list = cons(temp, list);
                    ungetc(charRead, stdin);
                }
                else{
                    synErr();
                }
            }
            else{
                synErr();
            }
        } 
        else if (charRead == '"') {
            charRead = (char)fgetc(stdin);
            char *b = talloc(sizeof(char)*300);
            b[0] = '"';
            int pos = 1;
            while (charRead != '"') {
                if (charRead != EOF) {
                    b[pos] = charRead;
                    charRead = (char)fgetc(stdin);
                    pos += 1;   
                } else {
                    synErr();
                }
            }
            b[pos] = '"';
            b[pos+1] = '\0';
            Value *temp = talloc(sizeof(Value));
            temp->type = STR_TYPE;
            temp->s = b;
            list = cons(temp, list);
        }
    
        else if (charRead == ';') {
            while (charRead != '\n'){
                if (charRead == EOF){
                    return list;
                }
       
                charRead = (char)fgetc(stdin);
            }
        } 
        else if (isdigit(charRead) || charRead == '.') {
            char *b = talloc(sizeof(char)*300);
            int pos = 0;
            bool dot = false;
            while (isdigit(charRead) || charRead == '.') {
                if (charRead == '.' && dot) {
                    synErr();
                } else if (charRead == '.' && !dot){
                    dot = true;
                }
                b[pos] = charRead;
                charRead = (char)fgetc(stdin);
                pos += 1;
            }
            b[pos] = '\0';
            if (isSpecial(charRead)) {
                if (dot) {
                    Value *temp = talloc(sizeof(Value));
                    temp->type = DOUBLE_TYPE;
                    char *ptr;
                    temp->d = strtod(b,&ptr);
                    list = cons(temp, list);
                } else {
                    Value *temp = talloc(sizeof(Value));
                    temp->type = INT_TYPE;
                    char* ptr;
                    temp->i = (int) strtol(b,&ptr,10);
                    list = cons(temp, list);
                }
                ungetc(charRead,stdin);
            } else {
                synErr();
            }
        }
        else if (charRead == '+' || charRead == '-') {
            char *b = talloc(sizeof(char)*300);
            b[0] = charRead;
            charRead = (char)fgetc(stdin);
            if (isSpecial(charRead)) {
                Value *temp = talloc(sizeof(Value));
                temp->type = SYMBOL_TYPE;
                b[1] = '\0';
                temp->s = b;
                list = cons(temp, list);
                ungetc(charRead,stdin);
            }
            else if (isdigit(charRead) || charRead == '.') {
                int pos = 1;
                bool dot = false;
                while (isdigit(charRead) || charRead == '.') {
                    if (charRead == '.' && dot) {
                        synErr();
                    } else if (charRead == '.' && !dot){
                        dot = true;
                    }
                    b[pos] = charRead;
                    charRead = (char)fgetc(stdin);
                    pos += 1;
                }
                b[pos] = '\0';
                if (isSpecial(charRead)) {
                    if (dot) {
                        Value *temp = talloc(sizeof(Value));
                        temp->type = DOUBLE_TYPE;
                        char *ptr;
                        temp->d = strtod(b,&ptr);
                        list = cons(temp, list);
                    } else {
                        Value *temp = talloc(sizeof(Value));
                        temp->type = INT_TYPE;
                        char* ptr;
                        temp->i = (int) strtol(b,&ptr,10);
                        list = cons(temp, list);
                    }
                    ungetc(charRead,stdin);
                } else {
                    synErr();
                }
            }
            else{
                synErr();
            }
        }
        else if (isalpha(charRead) || charRead == '!' || charRead == '$' || charRead == '%' || charRead == '&' ||
                                    charRead =='*' || charRead == '/' || charRead == ':' || charRead == '<' || 
                                    charRead == '=' || charRead == '>' || charRead == '?' || charRead == '~' || 
                                    charRead == '_' || charRead == '^') {
            char *b = talloc(sizeof(char)*300);
            b[0] = charRead;
            charRead = (char)fgetc(stdin);    
            int pos = 1;                        
            while(isalpha(charRead) || isdigit(charRead) || charRead == '.' || charRead == '+' || charRead =='-' || 
                                    charRead == '!' || charRead == '$' || charRead == '%' || charRead == '&' ||
                                    charRead =='*' || charRead == '/' || charRead == ':' || charRead == '<' || 
                                    charRead == '=' || charRead == '>' || charRead == '?' || charRead == '~' || 
                                    charRead == '_' || charRead == '^'){
                b[pos] = charRead;
                charRead = (char)fgetc(stdin);
                pos += 1;
            }
            b[pos] = '\0';
            if (isSpecial(charRead)){
                    Value *temp = talloc(sizeof(Value));
                    temp->type = SYMBOL_TYPE;
                    temp->s = b;
                    list = cons(temp, list);
                    ungetc(charRead, stdin);
                }
            else{
                synErr();
            }
            
        
        } 
        else if (isSpecial(charRead)) {
        } 


       else {
           synErr();
       }
        charRead = (char)fgetc(stdin);
   
    }


    Value *revList = reverse(list);
    return revList;
}
// Displays the contents of the linked list as tokens, with type information
void displayTokens(Value *list){

    while(list->type != NULL_TYPE ){
        if (list->c.car->type == INT_TYPE){
            printf("%d",list->c.car->i);
            printf(":integer \n");
        }
        if (list->c.car->type == DOUBLE_TYPE){
            printf("%f",list->c.car->d);
            printf(":double \n");
        }
        else if (list->c.car->type == OPEN_TYPE){
            printf("%s",list->c.car->s);
            printf(":open \n");
        }
        else if (list->c.car->type == CLOSE_TYPE){
            printf("%s",list->c.car->s);
            printf(":close \n");
        }
        else if (list->c.car->type == BOOL_TYPE){
            printf("%s",list->c.car->s);
            printf(":boolean \n");
        }
        else if (list->c.car->type == STR_TYPE){
            printf("%s",list->c.car->s);
            printf(":string \n");  
        }
        else if (list->c.car->type == SYMBOL_TYPE){
            printf("%s",list->c.car->s);
            printf(":symbol \n");
        }
        list = list->c.cdr;
    }
}







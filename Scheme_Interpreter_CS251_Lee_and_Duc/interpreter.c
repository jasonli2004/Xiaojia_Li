#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "linkedlist.h"
#include "parser.h"
#include "talloc.h"
#include "interpreter.h"
#include "value.h"
#include <assert.h>

void evaluationError(){
    printf("Evaluation error \n");
    texit(1);
}

Value *lookUpSymbol(Value *tree, Frame *frame){
    if (frame == NULL) {
        evaluationError();
    }
    Value *curr = frame->bindings;
    while (curr->type != NULL_TYPE) {
        if (!strcmp(car(car(curr))->s, tree->s)) {
            return car(cdr(car(curr)));
        }
        curr = cdr(curr);
    }
    return lookUpSymbol(tree, frame->parent);
}

void bind(char *name, Value *(*function)(struct Value *), Frame *frame) {
    // Add primitive functions to top-level bindings list
    Value *value = talloc(sizeof(Value));
    value->type = PRIMITIVE_TYPE;
    value->pf = function;
    Value *end = makeNull();
    Value *fname = talloc(sizeof(Value));
    fname->type = SYMBOL_TYPE;
    fname->s = name;
    frame->bindings = cons(cons(fname ,cons(value, end)), frame->bindings);
}

bool symbolExist(Value *tree, Frame *frame){
    Value *curr = frame->bindings;
    while (curr->type != NULL_TYPE) {
        if (!strcmp(car(car(curr))->s, tree->s)) {
            return true;
        }
        curr = cdr(curr);
    }
    return false;
}

Value *primitiveAdd(Value *args) {
    Value *result = talloc(sizeof(Value));
    result->type = INT_TYPE; 
    result->i = 0;
    Value *temp = args;
    while (temp->type != NULL_TYPE) {
        Value *val = car(temp);
        if (val->type != DOUBLE_TYPE && val->type != INT_TYPE) {
            evaluationError();
        }
        if (val->type == DOUBLE_TYPE) {
            if (result->type == DOUBLE_TYPE){
                result->d += val->d;
            } else {
                result->d = result->i + val->d;
            }
            result->type = DOUBLE_TYPE;
        } 
        else {
            if (result->type == DOUBLE_TYPE){
                result->d += val->i;
            } else {
                result->i += val->i;
            }
        }
        temp = cdr(temp);
    }
    return result;
}

Value *primitiveMinus(Value *args) {
    Value *result = talloc(sizeof(Value));
    Value *temp = args;
    Value *val = car(temp);
    if (val->type != DOUBLE_TYPE && val->type != INT_TYPE) {
        evaluationError();
    }
    result->type = val->type;
    if (val->type == DOUBLE_TYPE) {
        result->d = val->d;
    }
    else{
        result->i = val->i;
    }
    temp = cdr(temp);
    while (temp->type != NULL_TYPE) {
        Value *val = car(temp);
        if (val->type != DOUBLE_TYPE && val->type != INT_TYPE) {
            evaluationError();
        }
        if (val->type == DOUBLE_TYPE) {
            if (result->type == DOUBLE_TYPE){
                result->d = result->d - val->d;
            } else {
                result->d = result->i - val->d;
            }
            result->type = DOUBLE_TYPE;
        } else {
            if (result->type == DOUBLE_TYPE){
                result->d -= val->i;
            } else {
                result->i -= val->i;
            }
        }
        temp = cdr(temp);
    }
    return result;
}

Value *primitiveTime(Value *args) {
    Value *result = talloc(sizeof(Value));
    result->type = INT_TYPE; 
    result->i = 1;
    Value *temp = args;
    while (temp->type != NULL_TYPE) {
        Value *val = car(temp);
        if (val->type != DOUBLE_TYPE && val->type != INT_TYPE) {
            evaluationError();
        }
        if (val->type == DOUBLE_TYPE) {
            if (result->type == DOUBLE_TYPE){
                result->d *= val->d;
            } else {
                result->d = result->i * val->d;
            }
            result->type = DOUBLE_TYPE;
        } else {
            if (result->type == DOUBLE_TYPE){
                result->d *= val->i;
            } else {
                result->i *= val->i;
            }
        }
        temp = cdr(temp);
    }
    return result;
}

Value *primitiveDivide(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    Value *first = car(args);
    double f;
    double s;
    if (first->type == INT_TYPE){
        f = (double) first->i;
    }
    else if (first->type == DOUBLE_TYPE){
        f = first->d;
    }
    else{
        evaluationError();
    }
    Value *second = car(cdr(args));
    if (second->type == INT_TYPE){
        s = (double) second->i;
    }
    else if (second->type == DOUBLE_TYPE){
        s = second->d;
    }
    else{
        evaluationError();
    }
    double r = f/s;
    if (r == (int) r) {
        result->type = INT_TYPE;
        result->i = (int) r;
    } else {
        result->type = DOUBLE_TYPE;
        result->d = r;
    }
    return result;
}

Value *primitiveModulo(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    Value *first = car(args);
    int f;
    int s;
    if (first->type == INT_TYPE){
        f = first->i;
    }
    else{
        evaluationError();
    }
    Value *second = car(cdr(args));
    if (second->type == INT_TYPE){
        s = second->i;
    }
    else{
        evaluationError();
    }
    result->type = INT_TYPE;
    result->i = f % s;

    return result;
}

Value *primitiveNull(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type != NULL_TYPE){
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    result->type = BOOL_TYPE;
    char *b = talloc(sizeof(char)*3);
    b[0]='#';
    if (car(args)->type == NULL_TYPE || (car(args)->type == CONS_TYPE && car(car(args))->type== NULL_TYPE)){
        b[1] = 't';
    }
    else{
        b[1] = 'f';
    }
    b[2] = '\0';
    result->s = b;
    return result;
}


Value *primitiveCar(Value *args) {
    if (args->type == NULL_TYPE ||  car(args)->type != CONS_TYPE ||cdr(args)->type != NULL_TYPE ){
        evaluationError();
    }
    Value *end = makeNull();
    Value *result = car(car(car(args)));
    return cons(result,end);
}

Value *primitiveCdr(Value *args) {
    if (args->type == NULL_TYPE ||  car(args)->type != CONS_TYPE  || cdr(args)->type != NULL_TYPE){
        evaluationError();
    }
    Value *end = makeNull();
    Value *result = cdr(car(car(args)));
    return cons(result, end);
}

Value *primitiveCons(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *end = makeNull();
    Value *first = car(args);
    if (first->type == CONS_TYPE){
        first = car(first);
    }
    Value *second = car(cdr(args));
    if (second->type == CONS_TYPE){
        second = car(second);
    }
    return cons(cons(first, second),end);
}

Value *primitiveSmaller(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    result->type = BOOL_TYPE;
    char *b = talloc(sizeof(char)*3);
    b[0]='#';
    Value *end = makeNull();
    Value *first = car(args);
    double f;
    double s;
    if (first->type == INT_TYPE){
        f = (double) first->i;
    }
    else if (first->type == DOUBLE_TYPE){
        f = first->d;
    }
    else{
        evaluationError();
    }
    Value *second = car(cdr(args));
    if (second->type == INT_TYPE){
        s = (double) second->i;
    }
    else if (second->type == DOUBLE_TYPE){
        s = (double) second->d;
    }
    else{
        evaluationError();
    }

    if (f < s){
        b[1] = 't';
    }
    else{
        b[1] = 'f';
    }
    b[2] = '\0';
    result->s = b;
    return result;
}

Value *primitiveLarger(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    result->type = BOOL_TYPE;
    char *b = talloc(sizeof(char)*3);
    b[0]='#';
    Value *end = makeNull();
    Value *first = car(args);
    double f;
    double s;
    if (first->type == INT_TYPE){
        f = (double) first->i;
    }
    else if (first->type == DOUBLE_TYPE){
        f = first->d;
    }
    else{
        evaluationError();
    }
    Value *second = car(cdr(args));
    if (second->type == INT_TYPE){
        s = (double) second->i;
    }
    else if (second->type == DOUBLE_TYPE){
        s = (double) second->d;
    }
    else{
        evaluationError();
    }

    if (f > s){
        b[1] = 't';
    }
    else{
        b[1] = 'f';
    }
    b[2] = '\0';
    result->s = b;
    return result;
}

Value *primitiveEqual(Value *args) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type != NULL_TYPE)
    {
        evaluationError();
    }
    Value *result = talloc(sizeof(Value));
    result->type = BOOL_TYPE;
    char *b = talloc(sizeof(char)*3);
    b[0]='#';
    Value *end = makeNull();
    Value *first = car(args);
    double f;
    double s;
    if (first->type == INT_TYPE){
        f = (double) first->i;
    }
    else if (first->type == DOUBLE_TYPE){
        f = first->d;
    }
    else{
        evaluationError();
    }
    Value *second = car(cdr(args));
    if (second->type == INT_TYPE){
        s = (double) second->i;
    }
    else if (second->type == DOUBLE_TYPE){
        s = (double) second->d;
    }
    else{
        evaluationError();
    }

    if (f == s){
        b[1] = 't';
    }
    else{
        b[1] = 'f';
    }
    b[2] = '\0';
    result->s = b;
    return result;
}

void interpret(Value *tree){
    Value *curr = tree;
    Frame *frame = talloc(sizeof(Frame));
    frame->bindings = makeNull();
    frame->parent = NULL;
    bind("+", primitiveAdd, frame);
    bind("-", primitiveMinus, frame);
    bind("*", primitiveTime, frame);
    bind("/", primitiveDivide, frame);
    bind("modulo", primitiveModulo, frame);
    bind("null?",primitiveNull, frame);
    bind("car", primitiveCar, frame);
    bind("cdr", primitiveCdr, frame);
    bind("cons", primitiveCons, frame);
    bind("<", primitiveSmaller, frame);
    bind(">", primitiveLarger, frame);
    bind("=", primitiveEqual, frame);
    while (curr->type != NULL_TYPE) {
        Value *result = eval(car(curr), frame);
        if(result->type != NULL_TYPE ){
            switch (result->type) {
                case VOID_TYPE:
                    break;
                case INT_TYPE: 
                    printf("%d\n",result->i);
                    break;
                case DOUBLE_TYPE: 
                    printf("%f\n",result->d);
                    break;
                case CONS_TYPE:
                        printTree(result);
                    break;
                case CLOSURE_TYPE:
                    printf("#<procedure>\n");
                    break;
                default: 
                    printf("%s\n",result->s);
                    break;
            }
        }
        curr = cdr(curr);
    }
}



Value *evalIf(Value *args, Frame *frame) {
    Value *condition = eval(car(args),frame);
    if (cdr(args)->type == NULL_TYPE || cdr(cdr(args))->type == NULL_TYPE){
            evaluationError();
    }
    if (!strcmp(condition->s,"#t")) {
        return eval(car(cdr(args)),frame);
    } 
    else {
        return eval(car(cdr(cdr(args))),frame);
    }
}

Value *evalCond(Value *args, Frame *frame) {
    Value *pair = args;
    while(pair->type != NULL_TYPE){
        
        if ((car(car(pair))->type == SYMBOL_TYPE && !strcmp(car(car(pair))->s,"else")) || 
            ((eval(car(car(pair)),frame)->s)[1] == 't')){
            return eval(car(cdr(car(pair))),frame);
        }
        pair = cdr(pair);
    }
    Value *function = talloc(sizeof(Value));
    function->type = VOID_TYPE;
    return function;
}


Value *evalLet(Value *args, Frame *frame) {
    if (cdr(args)->type == NULL_TYPE){
        evaluationError();
    }

    Frame *newF = talloc(sizeof(Frame));
    newF->bindings = makeNull();
    newF->parent = frame;
    Value *current = car(args);

    if (current->type != CONS_TYPE && current->type != NULL_TYPE) {
            evaluationError();
    }
    while (current->type != NULL_TYPE){
        if (car(current)->type != CONS_TYPE) {
            evaluationError();
        }
        Value *var = car(car(current));
        if (var->type != SYMBOL_TYPE) {
            evaluationError();
        }
        if (cdr(car(current))->type != CONS_TYPE) {
            evaluationError();
        }
        if (symbolExist(var, newF)) {
            evaluationError();
        }
        Value *val = eval(car(cdr(car(current))),frame);
        Value *end = makeNull();
        newF->bindings = cons(cons(var,cons(val, end)),newF->bindings);
        current = cdr(current);
    }
    Value *temp = cdr(args);
    while (cdr(temp)->type != NULL_TYPE) {
        eval(car(temp),newF);
        temp = cdr(temp);
    }
    return eval(car(temp), newF);
}

Value *evalLetStar(Value *args, Frame *frame) {
    if (cdr(args)->type == NULL_TYPE){
        evaluationError();
    }
    Value *current = car(args);

    if (current->type != CONS_TYPE && current->type != NULL_TYPE) {
            evaluationError();
    }

    Frame *tmpframe = frame;
    while (current->type != NULL_TYPE){
        if (car(current)->type != CONS_TYPE) {
            evaluationError();
        }
        Value *var = car(car(current));
        if (var->type != SYMBOL_TYPE) {
            evaluationError();
        }
        if (cdr(car(current))->type != CONS_TYPE) {
            evaluationError();
        }
        Frame *newF = talloc(sizeof(Frame));
        newF->bindings = makeNull();
        newF->parent = tmpframe;

        Value *val = eval(car(cdr(car(current))), tmpframe);
        Value *end = makeNull();
        newF->bindings = cons(cons(var,cons(val, end)),newF->bindings);

        current = cdr(current);
        tmpframe = newF;
    }
    Value *temp = cdr(args);
    while (cdr(temp)->type != NULL_TYPE) {
        temp = cdr(temp);
    }
    return eval(car(temp), tmpframe);
}

Value *evalLetRec(Value *args, Frame *frame) {
    if (cdr(args)->type == NULL_TYPE){
        evaluationError();
    }

    Frame *newF = talloc(sizeof(Frame));
    newF->bindings = makeNull();
    newF->parent = frame;
    Value *current = car(args);

    if (current->type != CONS_TYPE && current->type != NULL_TYPE) {
            evaluationError();
    }
    while (current->type != NULL_TYPE){
        if (car(current)->type != CONS_TYPE) {
            evaluationError();
        }
        Value *var = car(car(current));
        if (var->type != SYMBOL_TYPE) {
            evaluationError();
        }
        if (cdr(car(current))->type != CONS_TYPE) {
            evaluationError();
        }
        if (symbolExist(var, newF)) {
            evaluationError();
        }
        Value *val = talloc(sizeof(Value));
        val->type = UNSPECIFIED_TYPE;
        Value *end = makeNull();
        newF->bindings = cons(cons(var,cons(val, end)),newF->bindings);
        current = cdr(current);
    }


    current = car(args);
    Value *valList = makeNull();
    while (current->type != NULL_TYPE){

        Value *val = eval(car(cdr(car(current))),newF);
        if (val->type == UNSPECIFIED_TYPE) {
            evaluationError();
        }
        valList = cons(val, valList);
 
        current = cdr(current);
    }
    Value *cell = newF->bindings;
    while (cell->type != NULL_TYPE){
        Value *end = makeNull();
        car(cell)->c.cdr = cons(car(valList), end);
        cell = cdr(cell);
        valList = cdr(valList);
    }

    Value *temp = cdr(args);
    while (cdr(temp)->type != NULL_TYPE) {
        eval(car(temp),newF);
        temp = cdr(temp);
    }
    return eval(car(temp), newF);
}


Value *evalQuote(Value *args, Frame *frame) {
    if (args->type == NULL_TYPE || cdr(args)->type != NULL_TYPE){
        evaluationError();
    }
    return args;
}

Value *evalAnd(Value *args, Frame *frame) {
    Value *curr =args;
    Value *val;
    while (curr->type != NULL_TYPE){
        val = eval(car(curr),frame);
        if (val->type == BOOL_TYPE && !strcmp(val->s, "#f")){
            return val;
        }
        curr = cdr(curr);
    }
    return val;
}

Value *evalOr(Value *args, Frame *frame) {
    Value *curr = args;
    Value *val;

    while (curr->type != NULL_TYPE){
        val = eval(car(curr),frame);
        if (val->type == BOOL_TYPE && !strcmp(val->s, "#t")){
            return val;
        }
        curr = cdr(curr);
    }
    return val;
}

Value *evalDefine(Value *args, Frame *frame){
    if (frame->parent != NULL || args->type ==NULL_TYPE ||car(args)->type != SYMBOL_TYPE || cdr(args)->type == NULL_TYPE){
        evaluationError();
    }
    Value *end = makeNull();
    Value *val = eval(car(cdr(args)),frame);
    frame->bindings = cons(cons(car(args),cons(val,end)),frame->bindings);
    Value *function = talloc(sizeof(Value));
    function->type = VOID_TYPE;
    return function;
}

Value *evalSet(Value *args, Frame *frame){
    if (frame == NULL || args->type ==NULL_TYPE ||car(args)->type != SYMBOL_TYPE || cdr(args)->type == NULL_TYPE){
        evaluationError();
    }
    Value *end = makeNull();
    Value *var = car(args);
    Frame *tempframe = frame;
    while (tempframe != NULL){
        Value *temp = tempframe->bindings;
        while (temp->type != NULL_TYPE){
            if (!strcmp(car(car(temp))->s,var->s)){
                car(temp)->c.cdr = cons(eval(car(cdr(args)),frame),end);
                Value *function = talloc(sizeof(Value));
                function->type = VOID_TYPE;
                return function;
            }
            temp = cdr(temp);
        }
        tempframe = tempframe->parent;
    }
    evaluationError();
    return end;
}

Value *evalBegin(Value *args, Frame *frame){
    if (args->type == NULL_TYPE) {
        Value *function =  talloc(sizeof(Value));
        function->type = VOID_TYPE;
        return function;
    }
    Value *temp = args;
    while (cdr(temp)->type != NULL_TYPE) {
        eval(car(temp),frame);
        temp = cdr(temp);
    }
    return eval(car(temp), frame);
}

Value *evalLambda(Value *args, Frame *frame) {
    if (args->type == NULL_TYPE || cdr(args)->type == NULL_TYPE){
        evaluationError();
    }
    if (car(args)->type != NULL_TYPE){
        if (car(args)->type != CONS_TYPE){
            evaluationError();
        }
        if (car(car(args))->type != SYMBOL_TYPE){
            evaluationError();
        }
    }
    Value *lambda = talloc(sizeof(Value));
    lambda->type = CLOSURE_TYPE;
    lambda->cl.paramNames = car(args);
    Value *temp = car(args);
    Value *list = makeNull();
    while(temp->type != NULL_TYPE){
        Value *ptr = list;
        while (ptr->type != NULL_TYPE){
            if (!strcmp(car(temp)->s, car(ptr)->s)) {
                evaluationError();
            }
            ptr = cdr(ptr);
        } 
        list = cons(car(temp),list);
        temp = cdr(temp);
    }
    lambda->cl.functionCode = car(cdr(args));
    lambda->cl.frame = frame;
    return lambda;
}

Value *evalEach(Value *args, Frame *frame) {
    Value *exprs = makeNull();
    Value *temp = args;
    while (temp->type != NULL_TYPE) {
        exprs = cons(eval(car(temp), frame), exprs);
        temp = cdr(temp);
    }
    return reverse(exprs);
}

Value *apply(Value *function, Value *args) {
    if (function->type == PRIMITIVE_TYPE){
        return (function->pf)(args);
    }
    Frame* new = talloc(sizeof(Frame));
    new->parent = function->cl.frame;
    new->bindings = makeNull();
    Value *temp = args;
    Value *names = function->cl.paramNames;
    while (temp->type != NULL_TYPE) {
        Value *end = makeNull();
        Value *pair = cons(car(names), cons(car(temp),end));
        new->bindings = cons(pair ,new->bindings);
        names = cdr(names);
        temp = cdr(temp);
    }
    return eval(function->cl.functionCode,new);
}


Value *eval(Value *tree, Frame *frame) {
    switch (tree->type) {
        case SYMBOL_TYPE: {
            return lookUpSymbol(tree, frame);
            break;
        }  
        case CONS_TYPE: {
            Value *first = car(tree);
            Value *args = cdr(tree);
            if (!strcmp(first->s,"if")) {
                return evalIf(args,frame);
            }
            else if (!strcmp(first->s,"let")) {
                return evalLet(args,frame);
            }
            else if (!strcmp(first->s,"let*")) {
                return evalLetStar(args,frame);
            }
            else if (!strcmp(first->s,"letrec")) {
                return evalLetRec(args,frame);
            }
            else if (!strcmp(first->s,"quote")) {
                return evalQuote(args,frame);
            }
            else if (!strcmp(first->s,"define")) {
                return evalDefine(args,frame);
            }
            else if (!strcmp(first->s,"lambda")) {
                return evalLambda(args,frame);
            }
            else if (!strcmp(first->s,"and")) {
                return evalAnd(args,frame);
            }
            else if (!strcmp(first->s,"or")) {
                return evalOr(args,frame);
            }
            else if (!strcmp(first->s,"set!")) {
                return evalSet(args,frame);
            }
            else if (!strcmp(first->s,"begin")) {
                return evalBegin(args,frame);
            }
            else if (!strcmp(first->s,"cond")) {
                return evalCond(args,frame);
            }
            // .. other special forms here...

            else {
                // If not a special form, evaluate the first, evaluate the args, then
                // apply the first to the args.
                Value *evaledOperator = eval(first, frame);
                Value *k = talloc(sizeof (Value));
                Value *evaledArgs = evalEach(args, frame);
                return apply(evaledOperator,evaledArgs);
            }
            break;
        }
        default:
            return tree;
            break;
    }    
    return tree;
}


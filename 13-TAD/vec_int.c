#include <stdlib.h>

#include "vec_int.h"

typedef struct _vec_int {
    int *data;
    int size;
    int capacity;
} vec_int;


vec_int *vec_int_create() {
    vec_int *vec = malloc(sizeof(vec_int));
    vec->capacity = 2;
    vec->size = 0;
    return vec; 
}

void vec_int_destroy(vec_int **_v) {
    vec_int *v = *_v;
    free(v->data);
    free(v);
    *_v =  NULL;
}

int vec_int_size(vec_int *v) {
    return v->size;
}

int vec_int_at(vec_int *v, int pos, int *val) {
    return 0;
}

int vec_int_insert(vec_int *v, int pos, int val) {
    return 0;
}

int vec_int_remove(vec_int *v, int pos) {
    return 0;    
}

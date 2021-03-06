#include <stdbool.h>

#include "key.h"
#include "value.h"

#ifndef KV_H
#define KV_H

typedef struct kv kv;
struct kv {
    key* k;
    value* v;
};

/*
    create a new key value pair
    returns null if key or value too long
    note that caller must validate k and v pointers are malloc()'d
*/
kv* kv_new(key* k, value* v);
kv* kv_new_raw(unsigned char* kb, unsigned short kl, unsigned char* vb, unsigned short vl);

/*
    compare two kv (by value)
*/
bool kv_compare(kv* kv0, kv* kv1);

/*
    getter functions
*/
key* kv_key(kv* x);
value* kv_value(kv* x);

#endif //KV_H

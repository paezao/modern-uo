#include "vector.h"
#include <stdlib.h>

void vector_init(struct vector *v)
{
    v->capacity = 4;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int vector_total(struct vector *v)
{
    return v->total;
}

static void vector_resize(struct vector *v, int capacity)
{
    void **items = realloc(v->items, sizeof(void *) * capacity);
    if(items)
    {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(struct vector *v, void *item)
{
    if(v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(struct vector *v, int index, void *item)
{
    if(index >= 0 && index < v->total)
        v->items[index] = item;
}

void *vector_get(struct vector *v, int index)
{

    if(index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void vector_delete(struct vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for(int i=0; i < v->total - 1; i++)
    {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if(v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(struct vector *v)
{
    free(v->items);
}

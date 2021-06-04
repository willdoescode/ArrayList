#ifndef ARRAYLIST
#define ARRAYLIST

#include <stdio.h>
#include <stdlib.h>

struct ArrayList
{
  int *elements;
  int length;
  void (*deinit)(struct ArrayList *);
  void (*push)(struct ArrayList *, int);
  int (*at)(struct ArrayList, int);
};

void deinit(struct ArrayList *arraylist)
{
  free(arraylist->elements);
}

void push(struct ArrayList *arraylist, int el)
{
  arraylist->elements = realloc(arraylist->elements, arraylist->length * sizeof(int));
  arraylist->elements[arraylist->length] = el;
  arraylist->length++;
}

int at(struct ArrayList arraylist, int el)
{
  return arraylist.elements[el];
}

struct ArrayList init()
{
  return (struct ArrayList){
      .elements = malloc(0 * sizeof(int)),
      .length = 0,
      .deinit = &deinit,
      .push = &push,
      .at = &at,
  };
}

#endif // !ARRAYLIST

#pragma once
#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <stdio.h>
#include <stdlib.h>

struct ArrayList
{
  int *elements;
  int length;
  int capacity;
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
  if (arraylist->length < arraylist->capacity)
  {
    arraylist->elements[arraylist->length] = el;
    arraylist->length++;
    return;
  }
  // arraylist->elements = realloc(arraylist->elements, arraylist->length * sizeof(int));

  arraylist->elements = realloc(arraylist->elements, arraylist->capacity * 2 * sizeof(int));
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
      .elements = malloc(10 * sizeof(int)),
      .length = 0,
      .capacity = 10,
      .deinit = &deinit,
      .push = &push,
      .at = &at,
  };
}

#endif // !_ARRAYLIST_H_

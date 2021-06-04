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

void deinit(struct ArrayList *self)
{
  free(self->elements);
}

void push(struct ArrayList *self, int el)
{
  if (self->length < self->capacity)
  {
    self->elements[self->length] = el;
    self->length++;
    return;
  }
  // arraylist->elements = realloc(arraylist->elements, arraylist->length * sizeof(int));

  self->elements = realloc(self->elements, self->capacity * 2 * sizeof(int));
  self->elements[self->length] = el;
  self->length++;
}

int at(struct ArrayList self, int el)
{
  return self.elements[el];
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

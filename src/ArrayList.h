#pragma once

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
  int (*pop)(struct ArrayList *);
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

int pop(struct ArrayList *self)
{
  self->length--;
  return self->elements[self->length];
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
      .pop = &pop,
  };
}

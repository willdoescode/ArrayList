#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main()
{
  struct ArrayList x = init();

  x.push(&x, 4);
  x.push(&x, 5);
  for (int i = 0; i < x.length; i++)
    printf("%d, %d\n", x.elements[i], x.elements[i]);

  x.deinit(&x);

  return 0;
}
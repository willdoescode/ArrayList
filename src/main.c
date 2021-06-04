#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main()
{
  struct ArrayList x = init();

  x.push(&x, 4);
  x.push(&x, 5);
  x.push(&x, 6);
  for (int i = 0; i < x.length; i++)
    printf("%d\n", x.at(x, i));

  x.deinit(&x);

  return 0;
}

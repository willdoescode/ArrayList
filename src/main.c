#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main()
{
  struct ArrayList x = init();

  for (int i = 0; i < 20; i++)
    x.push(&x, i);

  // for (int i = 0; i < x.length; i++)
  //   printf("%d\n", x.at(x, i));

  for (int i = 0; i < 20; i++)
    printf("%d\n", x.pop(&x));

  x.deinit(&x);

  return 0;
}

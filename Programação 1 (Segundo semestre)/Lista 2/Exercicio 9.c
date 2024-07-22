#include <stdio.h>
main ()
{
  int a;
  printf ("digite um numero: ");
  scanf ("%d", &a);
  if ((a % 3 == 0) && (a % 7 == 0))
    {
      printf ("divisivel por 3 e 7");
    }
  else
    {
      printf ("nao é");
    }
}


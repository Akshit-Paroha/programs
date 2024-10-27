#include <stdio.h>
int main(void)
{
  int repeat = 0;
  printf("How strong are you:");
  scanf("%d", &repeat);
  printf("You are ");
  if (repeat < 5)
    printf("weak");
  else
  {
    while (repeat > 5)
    {
      printf("very ");
      repeat--;
    };
    printf("strong");
    return 0;
  };
}
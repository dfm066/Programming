#include <stdio.h>
/* echo command-line arguments; 1st version */
int main(int argc, char *argv[])
{
  int i;
  while(argc--)
    printf("%s%s",*++argv,(argc>1)?" ":"");
  printf("\n");
  return 0;
}

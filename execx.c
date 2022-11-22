#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argument[])
{
  char *write_arg[4];
  write_arg[0] = argument[3];
  write_arg[1] = argument[4];
  write_arg[2] = argument[5];
  write_arg[3] = NULL;

  char strcheck[] = "-t";
  int check = strcmp(argument[1], strcheck);
  for (int i = 0; i < 6; i++)
  {
    if (argument[i] == NULL || check != 0)
    {
      printf("\n Wrong input\n");
      return 1;
    }
  }

  int i = 0;
  int v;
  pid_t forka;
  while (i < atoi(argument[2]))
  {
    forka = fork();
    if (forka == 0)
    {
      v = execve("writef", write_arg, NULL);
    }
    else
    {
      wait(&v);
    }
    i = i + 1;
  }

  return 0;
}
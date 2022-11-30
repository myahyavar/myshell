#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argument[])
{
  char *write_arg[4];//argumalari writef icin hazirlama
  write_arg[0] = argument[3];
  write_arg[1] = argument[4];
  write_arg[2] = argument[5];
  write_arg[3] = NULL;

  char strcheck[] = "-t";
  int check = strcmp(argument[1], strcheck);//dogru input kontrol
  for (int i = 0; i < 6; i++)
  {
    if (argument[i] == NULL || check != 0)
    {
      printf("\n Wrong input, please try again\n");
      return 1;
    }
  }

  int i = 0;
  int v;
  pid_t forka;
  while (i < atoi(argument[2]))//inputta verilen tekrar sayisi kadar tekrar
  {
    forka = fork();// fork islemi
    if (forka == 0)
    {
      v = execve("writef", write_arg, NULL);//alt islem cagirma
    }
    else
    {
      wait(&v);//process bitene kadar bekle
    }
    i = i + 1;
  }

  return 0;
}

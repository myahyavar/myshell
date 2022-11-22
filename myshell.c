#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BOYUT 500

void shell(char **x);

int main(void)
{
    while (1)
    {
        printf("Myshell>>");

        char x[BOYUT];
        fgets(x, BOYUT, stdin);

        if (strncmp(x, "exit", 4) == 0)
        {
            printf("\n *** Goodbye **** \n");
            exit(0);
        }
        else if (strncmp(x, "bash", 4) == 0)
        {
            system("/bin/bash");
        }
        else if (strncmp(x, "clear", 5) == 0)
        {
            system("clear");
        }
        else if (strncmp(x, "ls", 2) == 0)
        {
            system("/bin/ls");
        }
        else
        {
            char **arguments = ((char **)malloc(BOYUT * sizeof(char **)));
            x[strlen(x) - 1] = NULL; // error avoider

            int i = 0;
            char **space = strtok(x, " ");
            while (space != NULL)
            {
                arguments[i] = (char **)malloc((strlen(space)) * sizeof(char **));
                strcpy(arguments[i], space);
                space = strtok(NULL, " ");
                i++;
            }

            int argumentctr = 0;
            while (arguments[argumentctr] != NULL)
            {
                argumentctr++;
            }
            for (int i = 0; i < argumentctr; i++)
            {
                if (i = argumentctr - 1)
                {
                    shell(arguments);
                }
            }
        }
    }
    return 0;
}

void shell(char **x)
{
    int argumentctr = 0;
    while (x[argumentctr] != NULL)
    {
        argumentctr++;
    }
    pid_t forka;
    int v;
    if (strncmp(x[0], "tekrar", 6) == 0)
    {
        forka = fork();
        if (forka == 0)
        {
            v = execve("tekrar", x, NULL);
        }
        else
        {
            wait(&v);
        }
    }
    else if (strcmp(x[0], "writef") == 0)
    {
        forka = fork();
        if (forka == 0)
        {
            v = execve("writef", x, NULL);
        }
        else
        {
            wait(&v);
        }
    }
    else if (strncmp(x[0], "bash", 4) == 0)
    {
        system("/bin/bash");
    }
    else if (strncmp(x[0], "cat", 3) == 0)
    {
        printf("\n cat : %s \n", x[1]);
    }
    else if (strncmp(x[0], "clear", 5) == 0)
    {
        system("clear");
    }
    else if (strncmp(x[0], "ls", 2) == 0)
    {
        system("/bin/ls");
    }
    else
    {
        printf("wrong input");
    }
}

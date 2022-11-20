#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int length(char *input[]);
void divideSpace(char *input, char **str);

int main()
{

    char input[100];
    char *str[100];

    int e;

    while (1)
    {
        printf("myshell>>");

        fgets(input, 100, stdin);
        char *temp;
        for (int i = 0; i < length(input); i++)
        {
            divideSpace(input[i], str);
            if (strcmp(str[0], "exit") == 0)
            {

                exit(0);
            }
            else if (strcmp(str[0], "execx") == 0)
            {

                pid_t f = fork();
                if (f == 0)
                {
                    e = execv("execx", str);
                }

                else
                {
                    wait(&e);
                }
            }
            else if (strcmp(str[0], "ls") == 0)
            {
                system("/bin/ls");
            }
            else if (strcmp(str[0], "clear") == 0)
            {
                system("clear");
            }
            else if (strcmp(str[0], "cat") == 0)
            {
                // update needed
                execv("/bin/cat");
            }
            else if (strcmp(input, "bash") == 0)
            {
                system("/bin/bash");
            }
            else
            {
                // run commmand
            }
        }
        if (exit)
        {
            break;
        }
    }
    return 0;
}

int length(char *input[])
{
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }
    return length;
}

void divideSpace(char *input, char **str)
{

    for (int i = 0; i < 100; i++)
    {
        str[i] = strsep(&input, " ");
        if (str[i] == NULL)
            break;
        if (strlen(str[i]) == 0)
            i--;
    }
}
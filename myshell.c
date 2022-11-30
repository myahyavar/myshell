#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 500

void shell(char **x);

int main(void)
{
    while (1)
    {
        printf("Myshell>>");//surekli basilan shell

        char x[SIZE];
        fgets(x, SIZE, stdin);
	//basit shell komutlari icin input karsilastirmasi
        if (strncmp(x, "exit", 4) == 0)//cikis
        {
            printf("\n **** Goodbye **** \n");
            exit(0);
        }
        else if (strncmp(x, "bash", 4) == 0)//bash islemi
        {
            system("/bin/bash");
        }
        else if (strncmp(x, "clear", 5) == 0)//shell temizleme
        {
            system("clear");
        }
        else if (strncmp(x, "ls", 2) == 0)//dosya gosterimi
        {
            system("/bin/ls");
        }
        else
        {
            char **arguments = ((char **)malloc(SIZE * sizeof(char **)));
            x[strlen(x) - 1] = NULL; // error avoider

            int i = 0;
            char **space = strtok(x, " ");//argumanlari bosluk karakyterine gore ayirip baska bir arrayda tutma
            while (space != NULL)
            {
                arguments[i] = (char **)malloc((strlen(space)) * sizeof(char **));
                strcpy(arguments[i], space);
                space = strtok(NULL, " ");
                i++;
            }

            int argumentctr = 0;
            while (arguments[argumentctr] != NULL)//total arguman sayisini alma
            {
                argumentctr++;
            }
            for (int i = 0; i < argumentctr; i++)
            {
                if (i = argumentctr - 1)
                {
                    shell(arguments);//karmasik islemler icin argumanlari shell metoduna yollama
                }
            }
        }
    }
    return 0;
}

void shell(char **x)
{
    pid_t forka;
    int v;
    if (strncmp(x[0], "execx", 5) == 0)//tekrar fonkisyonu
    {
        forka = fork();//fork islemi
        if (forka == 0)
        {
            v = execve("execx", x,NULL);//alt program cagirma
        }
        else
        {
            wait(&v);//process bitene kadar bekleme
        }
    }
    else if (strcmp(x[0], "writef") == 0)//dosyaya yazma fonksiyonu
    {
        forka = fork();//fork islemi
        if (forka == 0)
        {
            v = execve("writef", x, NULL);//alt program cagirma
        }
        else
        {
            wait(&v);//process bitene kadar bekleme
        }
    } else if (strncmp(x[0], "cat",3) == 0)//cat
    {
        printf("\n cat: %s \n",x[1]);//verilen arguman girdisini ekrana yazdirir
    }
    else
    {
        printf("\n Wrong input, pelase try again\n");//yanlis input verildiginde
    }
}

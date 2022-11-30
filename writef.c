#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argument[])
{
    char strcheck[]="-f";
    int check=strcmp(argument[1],strcheck);//input check 

    if (check!=0 || argument[2] == NULL || argument[1] == NULL )
    {
        printf("\n Wrong input, please try again\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(argument[2], "a");//argumanda verilen dosyayi append modunda acar ya da olusturur
    if (fp == NULL)
        printf("Error Occurred while Opening/Creating the File");
    else
    {
        int p_id;//process id
        int pp_id;//parent process id
        p_id=getpid();
        pp_id=getppid();
        char Spi_id[30];
        char Sppi_id[30];
        sprintf(Spi_id,"%d",p_id);//idleri char a donusturme
        sprintf(Sppi_id,"%d",pp_id);
        time_t t;
        time(&t);//date time
        fputs(Spi_id, fp);// dosyaya yazma
        fputs(" ", fp);
        fputs(Sppi_id, fp);
        fputs(" ", fp);
        fputs(ctime(&t), fp);
    }
    fclose(fp);
    printf("saved successfully\n");

    return 0;
}

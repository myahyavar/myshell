#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argument[])
{
    char strcheck[]="-f";
    int check=strcmp(argument[1],strcheck); 

    if (check!=0 || argument[2] == NULL || argument[1] == NULL )
    {
        printf("\n Wrong input\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(argument[2], "a");
    if (fp == NULL)
        printf("Error Occurred while Opening/Creating the File!");
    else
    {
        int p_id;
        int pp_id;
        p_id=getpid();
        pp_id=getppid();
        char Spi_id[30];
        char Sppi_id[30];
        sprintf(Spi_id,"%d",p_id);
        sprintf(Sppi_id,"%d",pp_id);
        time_t t;
        time(&t);
        fputs(Spi_id, fp);
        fputs(" ", fp);
        fputs(Sppi_id, fp);
        fputs(" ", fp);
        fputs(ctime(&t), fp);
    }
    fclose(fp);
    printf("File created and saved successfully. :) \n");

    return 0;
}

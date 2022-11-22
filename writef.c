#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// Gelen komut değişkeninde şöyle bir değer var islem topla 1 2  
//wrief -f myfile
int main(int argc, char *argument[])
{
    if (argument[1] == NULL || argument[2] == NULL)
    {
        printf("\n Eksik veya Hatalı bir komut girdininiz.Tekrar Deneyiniz!.\n");
    }

    FILE *fp;
    fp = fopen(argument[2], "w");
    if (fp == NULL)
        printf("Error Occurred while Opening/Creating the File!");
    else
    {
        int p_id;
        int pp_id;
        p_id=getpid();
        pp_id=getppid();
        time_t t;
        time(&t);
        fputs("%d",ctime(&t), fp);
        fputs(p_id, fp);
        fputs(pp_id, fp);
        fputs("\n", fp);
    }
    fclose(fp);
    printf("File created and saved successfully. :) \n");

    return 0;
}

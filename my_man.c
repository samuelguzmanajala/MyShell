//
// Created by samuelguzman on 3/5/21.
//

#include "my_man.h"
// man.c

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>

int myMan(int argc, char* argv[])
{
    FILE *fptr;
    char filename[100], c;

    if (argc != 2) {
        write(2, "Usage: man [COMMAND]\n", 22);
        exit(1);
    }
    const char *dir="";
    strcat(dir,"home/samuelguzman/CLionProjects/MyShell/Man/");

    strcat(filename, dir); //Creamos una carpeta en esta direccion y hacemos hay la explicación de cada comando
    strcat(filename, argv[1]);
    printf("&%s",filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        write(2, "Cannot open man file.\n", 23);
        exit(1);
    }

    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);

    return 0;
}
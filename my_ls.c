//
// Created by samuelguzman on 3/5/21.
//

#include "my_ls.h"
//Falta el modo -l que muestra mas informacion como los permisos
//my_ls.c
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

myLs(int argc, char* argv[]){
    if (argc != 2){
        write(1, "USAGE: my_ls [directory].\n", 28);
        exit(1);
    }

    else{
        struct dirent *dt;
        DIR *directory;
        directory = opendir(argv[1]);

        if(directory==NULL){
            write(1, "There has been a problem opening the directory given.\n", 56);
            exit(1);
        }
        else{
            write(1, "The directory has been opened successfully.\n", 46);
            while((dt = readdir(directory)) != NULL){
                printf("\n%s\n%d\n",  dt->d_name, dt->d_ino);

            }
            if(closedir(directory) == -1){
                write(1, "There has been a problem closing the directory.\n", 49);
            }
            exit(1);
        }

    }
}
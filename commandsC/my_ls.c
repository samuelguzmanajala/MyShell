//
// Created by samuelguzman on 3/5/21.
//

#include "../commandsH/my_ls.h"
//Falta el modo -l que muestra mas informacion como los permisos
//my_ls.c
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
//myls

void getPermissions(struct stat sb, char* permissionString) {

    //determine the filetype and add the corresponding character
    permissionString[0] = '-';
    if (S_ISDIR(sb.st_mode)) {
        permissionString[0] = 'd';
    }
    if (S_ISCHR(sb.st_mode)) {
        permissionString[0] = 'r';
    }
    if (S_ISBLK(sb.st_mode)) {
        permissionString[0] = 'b';
    }
    if (S_ISFIFO(sb.st_mode)) {
        permissionString[0] = 'p';
    }
    if (S_ISLNK(sb.st_mode)) {
        permissionString[0] = 'l';
    }
    if (S_ISSOCK(sb.st_mode)) {
        permissionString[0] = 's';
    }


    //check each permission and set the appropriate character
    if ((sb.st_mode & S_IRUSR) == S_IRUSR) {
        permissionString[1] = 'r';
    } else{
        permissionString[1] = '-';
    }
    if ((sb.st_mode & S_IWUSR) == S_IWUSR) {
        permissionString[2] = 'w';
    } else{
        permissionString[2] = '-';
    }
    if ((sb.st_mode & S_IXUSR) == S_IXUSR ) {
        permissionString[3] = 'x';
    } else{
        permissionString[3] = '-';
    }
    if ((sb.st_mode & S_IRGRP) == S_IRGRP  ) {
        permissionString[4] = 'r';
    } else{
        permissionString[4] = '-';
    }
    if ((sb.st_mode & S_IWGRP) == S_IWGRP  ) {
        permissionString[5] = 'w';
    } else{
        permissionString[5] = '-';
    }
    if ((sb.st_mode & S_IXGRP) == S_IXGRP  ) {
        permissionString[6] = 'x';
    } else{
        permissionString[6] = '-';
    }
    if ((sb.st_mode & S_IROTH) == S_IROTH  ) {
        permissionString[7] = 'r';
    } else{
        permissionString[7] = '-';
    }
    if ((sb.st_mode & S_IWOTH) == S_IWOTH  ) {
        permissionString[8] = 'w';
    } else{
        permissionString[8] = '-';
    }
    if ((sb.st_mode & S_IXOTH) == S_IXOTH  ) {
        permissionString[9] = 'x';
    } else{
        permissionString[9] = '-';
    }

    permissionString[10] = '\0';
}


int myLs(int argc, char* argv[]){

    if (argc < 2){
        write(1, "USAGE: my_ls [directory].\n", 28);
        exit(1);
    }

    else{
        if (strcmp(argv[1],"-l")==0){
            struct stat sb;
            struct dirent *dt;
            DIR *directory;
            directory = opendir(argv[2]);
            printf("\n");

            while((dt = readdir(directory)) != NULL){
                char permissionString[11];
                if(stat(dt->d_name, &sb) == -1){
                    printf("error getting permissions");
                }
                getPermissions(sb, permissionString);
                printf("%s %i",permissionString, (int)sb.st_nlink);
                printf(" %s\n",  dt->d_name);

            }
            if(closedir(directory) == -1){
                write(1, "There has been a problem closing the directory.\n", 49);
            }
            exit(1);


        }else{
            //struct dirent *dt;
            DIR *directory;
            directory = opendir(argv[1]);

            if(directory==NULL){
                write(1, "There has been a problem opening the directory given.\n", 56);
                exit(1);
            }
            else{
                struct dirent *dt;
                //DIR *directory;
                directory = opendir(argv[1]);
                printf("\n");

                while((dt = readdir(directory)) != NULL){
                    printf("%s\n%lu\n\n",  dt->d_name, dt->d_ino);

                }
                if(closedir(directory) == -1){
                    write(1, "There has been a problem closing the directory.\n", 49);
                }
                exit(1);
            }
        }
    }
}
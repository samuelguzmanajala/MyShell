//
// Created by samuelguzman on 20/4/21.
//

#include <stdio.h>
#include "../commandsH/my_mv.h"

#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>


int myMv(int argc, char* argv[]){

    char newLocation[100];

    char *file= argv[1];
    char *location= argv[2];


    if(argc!=3){
        printf("Error: Wrong number of arguments\n");
        return -1;
    }else{
        if(location[0]=='/'){

            strcat(location,"/");					//If argument is a Full Path
            strcat(location,file);

            if(rename(file, location)== 0){
                link(file, location);
                printf("Successful\n");
                return 0;
            }else{
                printf("Error: Unfound Directory \n");
                return -1;
            }

        }else{
            DIR *isDirectory;
            isDirectory = opendir(location); 		//Check if argument is a directory

            if(isDirectory==NULL){

                if(rename(file,location)!= 0){
                    printf("Error: Unmoved File \n");
                    return -1;
                }else {
                    printf("Successful\n");
                    return 0;
                }

            }else{
                char *path;
                path = getcwd(newLocation, 100);//Current working directory path
                strcat(newLocation,"/");
                strcat(newLocation,location);		//Concat mv location to the path
                strcat(newLocation,"/");
                strcat(newLocation, file);          //Keeping the original file name
                //printf("directorio: \n%s\n",path);

                //rename(file,path)

                if(rename(file,path)!=-1){
                   // printf("directorio: \n%s\n",file);
                    printf("Successful\n");
                    link(file, location);
                    unlink(location);
                }else{
                    //printf("ha llegado al else:\n");
                    printf("Error: Unfound Directory \n");
                    return -1;
                }
                closedir(isDirectory);
            }
        }
    }
    return 0;
}
//
// Created by samuelguzman on 27/3/21.
//

#include "../commandsH/my_grep.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define MAXSIZE 500

int getLine(char *pattern, FILE *file){
    int numberOfMatches=0;
    int i=0;
    char archivo[500];
    int line=1;

    while(fgets(archivo,500,file) != NULL){

        if(strstr(archivo,pattern) != NULL){
            printf("%s ",pattern);
            printf("match on the following line: %i\n", line);
            //printf("%s",archivo);
        }
        line++;
    }

}

int executeGrep(int argc, char* argv[])
{

    if(argc<3){
        printf("To use grep command you need two arguments, the pattern and the file where you want to search\n");
    }

    char *pattern = argv[1];

    //printf(argv[1]);
    FILE *file= fopen(argv[2], "r+");

    if(file==NULL){
        printf("can't read the file \n");
    }else{
        //printf("leido correctamente\n");
    }

    getLine(pattern,file);


}
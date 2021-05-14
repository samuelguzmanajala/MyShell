//
// Created by samuelguzman on 27/3/21.
//

#include "../commandsH/my_grep.h"
#include <stdio.h>
#include <string.h>


#define MAXSIZE 500

int main(char *pattern, FILE *file){
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
    return 0;

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
    
    return 0;

}
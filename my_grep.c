//Our own version of the command grep.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 500

int getLine(chat *pattern, FILE *file){
    int numberOfMatches=0;
    int i=0;
    char archivo[500];
    int line=1;

    while(fgets(archivo,500,file) != null){
        if(strstr(archivo,pattern) != null){
            printf("match on the following line: /n", line);
        }
        line++;
    }

}

main(int argc, char* argv[])
{



}
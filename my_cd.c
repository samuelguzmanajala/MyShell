include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 500

char actualDirectory[MAXSIZE];
char futureDirectory[MAXSIZE];

int changeDirectory(char *actualDirectory){
    chdir(actualDirectory);
}
int main(int argc, char* argv[]){
    if(argc<2){
        printf("To use grep command you need two arguments, the pattern and the file where you want to search");
    }

    char option[MAXSIZE];
    option=argv[2];
    char *prev;
    prev=getcwd(prev,0);
    
    switch (option) {
        case '..':
            chdir(prev);
    }
}
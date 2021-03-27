#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

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

    char *actual;
    actual=getcwd(actual, 0);


    if(!strcmp(argv[1], "..")){
        printf("ha entrado en el if y se cambiara al directorio anterior\n");
        chdir("..");
        printf("despues de ir al directorio anterior\n");
    }

    /*
    int option;

    while((option = getopt(argc, argv, "..:c:n")) != -1)
    {
        switch (option)
        {
            case '.' :
                printf("fldsjlfkasjd");
                break;

            case 'c' :
                printf("fldsjlfkasjd");
                break;

            case 'n' :
                printf("fldsjlfkasjd");
                break;

            case '?' :
                printf("Unknown option %c. \n", optopt);
                break;

            default :
                printf("fldsjlfkasjd");
                break;

        }
    }
     */

}
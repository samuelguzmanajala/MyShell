//
// Created by samuelguzman on 30/3/21.
//
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int exHelp(int argc, char *argv[]){

    if (strcmp(argv[1], "cd")==0){
        printf("\ncd: Change the current directory.\n\n");
    }

    else if (strcmp(argv[1], "ls")==0){
        printf("\nls -l: Read the contents of a directory (just the name or more information).\n\n");
        printf("List directory contents.\n");
    }

    else if (strcmp(argv[1], "pwd")==0){
        printf("\npwd: Look at the location. This command prints the current working directory.\n\n");
    }
    else if (strcmp(argv[1], "cat")==0){
        printf("\ncat : Read from file or stdin and print in standard output.\n");
        printf("Read the text or the code of a FILE and write it on the standard output.\n");
        printf("Without a FILE, reads the standard input and writes in the standard output.\n\n");
    }
    else if (strcmp(argv[1], "touch")==0){
    printf("\ntouch: Create a new file.\n\n");
    }

else if (strcmp(argv[1], "mv")==0){
printf("\nmv: Move a file.\n\n");
}

else if (strcmp(argv[1], "cp")==0){
printf("\ncp: Copy a file.\n\n");
}

else if (strcmp(argv[1], "grep")==0){
printf("\ngrep: Search a file’s contents.\n\n");
}

else if (strcmp(argv[1], "man")==0){
printf("\nman: Read the manual file of a command.\n\n");
}
else{
printf("\n Unknown command.\n\n");
}

}//Cierre del ma
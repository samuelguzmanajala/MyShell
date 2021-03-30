//
// Created by samuelguzman on 27/3/21.
//

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_grep.h"

char *getInput(char *str) {
    char *line;
    line = readline("$");
    //printf("%s\n",line);
}


void parseSpace(char *str, char **parsed, int argc) {
    int i;
    argc = 0;

    for (i = 0; i < 100; i++) {
        parsed[i] = strsep(&str, " ");
        argc++;

        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }

}
void execute2(int numberOfArgs,char **parsed){
    if(strcmp(parsed[0], "grep") == 0){
        executeGrep(numberOfArgs, parsed);
    }
    if (strcmp(parsed[0],"cp")==0){
        printf("pegar comando copy");
    }

}



void execute(char *str, char **parsed) {


    //parsed es un array de strings que tiene el input del teclado
    int argc;

    parseSpace(str, parsed, argc);

    if (strcmp(parsed[0], "cd") == 0) {
        chdir(parsed[1]);
    }

    pid_t pid = fork();

    //parseSpace(str, parsed, argc)


    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        execute2(argc,parsed);
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
    free(argc);
}
//exit(0);



int showDir() {
    char dir[1000];
    getcwd(dir, 1000);
    printf("\nuser: %s", dir);
}


int main() {
    char input[1000];
    char *parsedArgs[100];
    char *input2;
    while (1) {
        showDir();
        input2 = getInput(input);
        execute(input2, parsedArgs);
    }

}
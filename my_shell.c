//
// Created by samuelguzman on 27/3/21.
//

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my_grep.h"

char* getInput(char *str){
    char *line;
    line=readline("$");
    //printf("%s\n",line);
}


void parseSpace(char* str, char** parsed,int args)
{
    int i;
    args=0;

    for (i = 0; i < 100; i++) {
        parsed[i] = strsep(&str, " ");
        args++;

        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}



void execute(char *str,char** parsed){


    //parsed es un array de strings que tiene el input del teclado
    int args=0;
    parseSpace(str, parsed,args);
    pid_t pid;
    if(strcmp(parsed[0],"cd")==0){
        pid=0;
    }else if((parsed[0],"cd")==1){
        pid=fork();
    }


    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {

        //programs execution
        if(strcmp(parsed[0],"cd")==0){
            chdir(parsed[1]);
        }else{
            //otros programas que no necesiten estar en el proceso padre;
            if(strcmp(parsed[0],"grep")==0){
                executeGrep(args,parsed);
                printf("has usado grep");
            }


        }
        //exit(0);
    } else {

    }

}
int showDir(){
    char dir[1000];
    getcwd(dir,1000);
    printf("\nuser: %s",dir);
}



int main(){
    char input[1000];
    char *parsedArgs[100];
    char *input2;
    while(1){
        showDir();
        input2=getInput(input);
        execute(input2,parsedArgs);
    }

}
//
// Created by samuelguzman on 7/5/21.
//

#include "myShell0.h"
// myShell0
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <pwd.h>
#include "my_grep.h"
#include "my_help.h"
#include "my_mv.h"
#include "my_cat.h"
#include "my_ls.h"
#include "my_man.h"
#include "my_cp2.h"
#include "game.h"

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20

/////////// reading commands:

int read_args(int* argcp, char* args[], int max, int* eofp)
{
    static char cmd[MAXLINE];
    char* cmdp;
    int ret,i;

    *argcp = 0;
    *eofp = 0;
    i=0;
    while ((ret=read(0,cmd+i,1)) == 1) {
        if (cmd[i]=='\n') break;  // correct line
        i++;
        if (i>=MAXLINE) {
            ret=-2;        // line too long
            break;
        }
    }
    switch (ret)
    {
        case 1 : cmd[i+1]='\0';    // correct reading
            break;
        case 0 : *eofp = 1;        // end of file
            return 0;
            break;
        case -1 : *argcp = -1;     // reading failure
            fprintf(stderr,"Reading failure \n");
            return 0;
            break;
        case -2 : *argcp = -1;     // line too long
            fprintf(stderr,"Line too long -- removed command\n");
            return 0;
            break;
    }
    // Analyzing the line
    cmdp= cmd;
    for (i=0; i<max; i++) {  /* to show every argument */
        if ((args[i]= strtok(cmdp, " \t\n")) == (char*)NULL) break;
        cmdp= NULL;
    }
    if (i >= max) {
        fprintf(stderr,"Too many arguments -- removed command\n");
        return 0;
    }
    *argcp= i;
    return 1;
}

///////////////////////////////////////

void execute2(int numberOfArgs,char **parsed){
    if(strcmp(parsed[0], "grep") == 0){
        executeGrep(numberOfArgs, parsed);
    }
    if (strcmp(parsed[0],"cp")==0){

        myCp(numberOfArgs,parsed);
        //printf("pegar comando copy");
    }
    if (strcmp(parsed[0],"help")==0){
        exHelp(numberOfArgs,parsed);
        printf("pegar comando copy");
    }
    if (strcmp(parsed[0],"mv")==0){
        myMv(numberOfArgs,parsed);
        //printf("pegar comando copy");
    }
    if(strcmp(parsed[0],"cat")==0){
        myCat(numberOfArgs,parsed);
    }
    if(strcmp(parsed[0],"ls")==0){
        myLs(numberOfArgs,parsed);
    }
    if(strcmp(parsed[0],"man")==0){
        myMan(numberOfArgs,parsed);
    }
    if(strcmp(parsed[0],"pwd")==0){
        char dir[1000];
        getcwd(dir, 1000);
        printf("\ndirectory: %s\n", dir);
    }

}

int execute(int argc, char *argv[])
{
    if (strcmp(argv[0], "cd") == 0) {
        chdir(argv[1]);

    }
    if (strcmp(argv[0], "game") == 0) {
        struct passwd *pw = getpwuid(getuid());
        const char *dir = pw->pw_dir;
        strcat(dir,"/CLionProjects/MyShell/Game/street/house");
        chdir(dir);
        setup();
        myGame();
    }

    pid_t pid = fork();

    //parseSpace(str, parsed, argc)


    if (pid == -1) {
        printf("\nFailed forking child..");

    } else if (pid == 0) {

        execute2(argc,argv);
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
    }
    //...
}

main ()
{
    char * Prompt = "myShell0> ";
    int eof= 0;
    int argc;
    char *args[MAXARGS];

    while (1) {
        write(0,Prompt, strlen(Prompt));
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if (eof) exit(0);
    }
}
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
#include "commandsH/my_grep.h"
#include "commandsH/my_help.h"
#include "commandsH/my_mv.h"
#include "commandsH/my_cat.h"
#include "commandsH/my_ls.h"
#include "commandsH/my_man.h"
#include "commandsH/my_cp2.h"
#include "commandsH/game.h"
#include "commandsH/test.h"

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20

/////////// reading commandsC:

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
    if (strcmp(parsed[0], "cp")==0){
        printf("Ha usado el comando cp\n");
        myCp(numberOfArgs,parsed);

        //printf("pegar comando copy");
    }
    if (strcmp(parsed[0],"help")==0){
        exHelp(numberOfArgs,parsed);
        //printf("pegar comando copy");
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
    if(strcmp(parsed[0],"man")==0){
        myMan(numberOfArgs,parsed);
    }
}

int execute(int argc, char *argv[])
{
    if (strcmp(argv[0], "cd") == 0) {

        if(argc<2){
            printf("\nyou need more parameters\n");
        }else{
            int x=chdir(argv[1]);
            if(x==-1){
                printf("\ndirectory don't exist\n");
            }
        }

    }
    if (strcmp(argv[0], "game") == 0) {
        struct passwd *pw = getpwuid(getuid());
        const char *dir = pw->pw_dir;
        chdir(dir);
        setup();
        myGame();
    }
    if (strcmp(argv[0], "test") == 0) {
        struct passwd *pw = getpwuid(getuid());
        const char *dir = pw->pw_dir;
        chdir(dir);
        setup();
        myTest();
    }

    pid_t pid = fork();

    //parseSpace(str, parsed, argc)


    if (pid == -1) {
        printf("\nFailed forking child..");

    } else if (pid == 0) {
        if(argc<2 && strcmp(argv[0],"pwd")!=0 && strcmp(argv[0],"bag")!=0){
            printf("\nfew arguments\n");
            exit(0);
        }else if (strcmp(argv[0],"pwd")==0){
            char dir[1000];
            getcwd(dir, 1000);
            printf("\ndirectory: %s\n", dir);
            exit(0);
        }else if(strcmp(argv[0],"bag")==0){
            char *buffer=malloc(sizeof(char) * 1024);
            struct passwd *pw = getpwuid(getuid());
            const char *homedir = pw->pw_dir;
            strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/.hero'sBag");
            const char *comm="cat ";


            //malloc(buffer);

            strcat(strcpy(buffer, comm), homedir);
            //printf("%s\n", buffer);


            pid_t pid = fork();
            if(pid==-1){
                printf("");
            }else if(pid==0){
                int i;
                for (i=0; i<10; i++) {  /* to show every argument */
                    if ((argv[i]= strtok(buffer, " \t\n")) == (char*)NULL) break;
                    buffer= NULL;
                }

                myCat(2,argv);

            }
            exit(0);
        }
        else{
            execute2(argc,argv);
            exit(0);
        }
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
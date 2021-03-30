//
// Created by samuelguzman on 30/3/21.
//

#include "my_help.h"
#include<stdio.h>
#include<unistd.h>
#include<string.h>

int exHelp(int argc, char **argv)
{
    if(argc<2){
        printf("Not enougth parameters");
        return -1;
    }else{
        if(strcmp(argv[1], "--help")==0){

            if(strcmp(argv[2], "ls")==0){
                printf("ls Read the contents of a directory \n");
            }
            if(strcmp(argv[3], "man")==0){
                printf("man Read the manual file of a command  \n");
            }

            if(strcmp(argv[4], "grep")==0){
                printf("grep Search a file’s contents  \n");
            }

            if(strcmp(argv[5], "cd")==0){
                printf("cd Change the current directory  \n");
            }

            if(strcmp(argv[6], "pwd")==0){
                printf("pwd Look the location  \n");
            }

            if(strcmp(argv[7], "cat")==0){
                printf("cat Read from file or stdin and print 				 in stdout \n");
            }

            if(strcmp(argv[8], "touch")==0){
                printf("touch Create a new file  \n");
            }

            if(strcmp(argv[9], "mv")==0){
                printf("mv Move a file  \n");
            }

            if(strcmp(argv[10], "cp")==0){
                printf("cp Copy a file –  \n");
            }

        }

    }
    return 0;
}
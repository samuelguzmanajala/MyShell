//
// Created by samuelguzman on 3/5/21.
//

#include "../commandsH/my_cat.h"
//Our own version of the command cat.


//Functions of the command cat:
// If there's a file as a parameter it will display the content in the stdout.
// If there's no parameter it will display what has been typed in the stdin.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 500

myCat(int argc, char* argv[])
{

    int fd, o, p;
    char usa[] = "USAGE: my_cat [file_name] OR  my_cat [].\n";
    char err[] = "ERROR: couldn't open the file.\n";
    char fil[MAXSIZE];
    char std[MAXSIZE];
    size_t n1 = sizeof(err);
    size_t n2;



    //Handling the valid amount of parameters
    if (argc != 2 && argc != 1) {
        write(1, usa, n1);
        exit(1);
    }

    else
    {
        //Handling of the command when there's 0 parameters
        if(argc == 1)
        {
            o = read(0, std, MAXSIZE);
            write(1, std, o);
            exit(1);
        }

        if(argc == 2)
        {
            //Handling of the command when there's 1 parameter
            if ((fd = open(argv[1], O_RDWR)) == -1)
            {
                write(1, err, n1);
                exit(1);
            }

            p = read(fd, fil, MAXSIZE);
            write(1, fil, p);
            exit(1);
        }
    }



}
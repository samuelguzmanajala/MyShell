//
// Created by samuelguzman on 30/3/21.
//

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_cp.h"

#define BUFFERSIZE 1024
#define COPYMORE 0644

void errExit(char *s1, char *s2)
{
    fprintf(stderr, "Error: %s ", s1);
    perror(s2);
    exit(1);
}

int copyFile(char *source, char *destination)
{
    int in_fd, out_fd, n_chars;
    char buf[BUFFERSIZE];


    /* open files */
    if( (in_fd=open(source, O_RDONLY)) == -1 )
    {
        errExit("Cannot open ", source);
    }


    if( (out_fd=creat(destination, COPYMORE)) == -1 )
    {
        errExit("Cannot create ", destination);
    }

    /* copy files */
    while( (n_chars = read(in_fd, buf, BUFFERSIZE)) > 0 )
    {
        if( write(out_fd, buf, n_chars) != n_chars )
        {
            errExit("Write error to ", destination);
        }


        if( n_chars == -1 )
        {
            errExit("Read error from ", source);
        }
    }


    /* close files */
    if( close(in_fd) == -1 || close(out_fd) == -1 )
    {
        errExit("Error closing files", "");
    }


    return 1;
}
int ms_cp(char **args) {

    if (args[1] == NULL) {

        fprintf(stderr, "ms: expected argument to \"cp\"\n");

    } else if (args[3] != NULL) {
        char *src = args[1];
        char *dest = args[2];


        if (src[0] != '/' && dest[0] != '/')//cp2 file1.txt file2.txt
        {
            copyFile(src, dest);
        } else if (src[0] != '/' && dest[0] == '/')//cp2 file1.txt /dir
        {
            int i;
            for (i = 1; i <= strlen(dest); i++) {
                dest[(i - 1)] = dest[i];
            }
            strcat(dest, "/");
            strcat(dest, src);
            copyFile(src, dest);
        } else {
            if (chdir(args[1] != 0)) {
                perror("ms_cp");
            }
        }
        return 1;
    }
}
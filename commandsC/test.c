//
// Created by samuelguzman on 11/5/21.
//

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include "../commandsH/test.h"
#include "../myShell0.h"
#include "../commandsH/my_cat.h"
#include "../commandsH/game.h"

#define MAXARGS 20
#define MAXLINE 200
struct passwd *pw ;
int myTest(){
    int eof= 0;
    int argc;
    char *args[MAXARGS];
    char str[100];
    bool loop=true;


 //Apartir de aqui empiezan las pruebas

    chdir("/home/samuelguzman//CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet");


    printf("\n*Make use of the command 'mv spiderwebs Trash' to clean up the sword*\n");
    printf("\033[0m"); //Resets the text to default color

    loop=true;

    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"mv")==0 && strcmp(args[1],"spiderwebs")==0 && strcmp(args[2],"Trash")==0){



            //DeleteLine//
            FILE *srcFile;
            FILE *tempFile;

            char path[1000];

            int line;


            /* Input file path and line number */
            //printf("Enter file path: ");
            //scanf("%s", path);
            pw = getpwuid(getuid());
            const char *homedir = pw->pw_dir;
            strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/.hero'sBag");


            strcpy(path,homedir);
            line=1;



            /* Try to open file */
            srcFile  = fopen(path, "r");
            tempFile = fopen("delete-line.tmp", "w");


            /* Exit if file not opened successfully */
            if (srcFile == NULL || tempFile == NULL)
            {
                printf("Unable to open file.\n");
                printf("Please check you have read/write previleges.\n");

                exit(EXIT_FAILURE);
            }



            //printf("\nFile contents before removing line.\n\n");
            //printFile(srcFile);


            // Move src file pointer to beginning
            rewind(srcFile);

            // Delete given line from file.
            deleteLine(srcFile, tempFile, line);



            /* Close all open files */
            fclose(srcFile);
            fclose(tempFile);


            /* Delete src file and rename temp file as src */
            remove(path);
            rename("delete-line.tmp", path);


            //printf("\n\n\nFile contents after removing %d line.\n\n", line);

            // Open source file and print its contents
            srcFile = fopen(path, "r");
            //printFile(srcFile);
            fclose(srcFile);

            //DeleteLine//

            //AddLine//
            srcFile  = fopen(path, "w+");
            fputs("sword\n", srcFile);
            fclose(srcFile);
            //AddLine//


            loop=false;
        }
    }



    printf("\ncompletado\n");

}
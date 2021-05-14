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

    chdir("/home/samuelguzman//CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse/SecondFloor");

    printf("\033[0;31m");
    printf("\n*Make use of command mv in order to move the steak closer to the dragon*\n");
    printf("\033[0m"); //Resets the text to default color

    loop=true;
    while (loop) {
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if (strcmp(args[0], "mv") == 0 && strcmp(args[1], "steak") == 0  && strcmp(args[2], "Dragon") == 0) {
            loop=false;
        }
    }



    printf("\ncompletado\n");

}
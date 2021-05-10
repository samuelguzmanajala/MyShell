//
// Created by samuelguzman on 6/5/21.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "my_cp2.h"
#include "myShell0.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <stdbool.h>
#include <pwd.h>

#define MAXARGS 20
#define MAXLINE 200
#define MAXC 1024
char name[20];


void execs(int argc, char *argv[]){
    pid_t pid = fork();

    //parseSpace(str, parsed, argc)


    if (pid == -1) {
        printf("\nFailed forking child..");

    } else if (pid == 0) {

        execvp(argv[0],argv);
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
    }
}

int myGame (void) {
    int eof= 0;
    int argc;
    char *args[MAXARGS];
    char str[100];
    bool loop=true;





    printf("\033[0;36m");
    printf("Welcome to the Digital World, in this adventure you will have to learn how to use ten\n"
           "basic commands in order to defeat the ruthless dragon that has been tormenting our\n"
           "town for thousands of years. Do you have what it takes to save our town?\n");

    sleep(0);

    printf("\nFirst of all, we need you to identify yourself young hero:\n");
    fgets(name, 100, stdin);

    printf("\033[0;31m");
    printf("use man in order to know the commands that will be used");

    sleep(0);
    printf("\033[0;31m");
    printf("Quick reminder, you can use help whenever you want if you don’t remember how\n"
           "the commands work.\n");

    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"man")==0){
            //printf("ha llegado");
            loop=false;
        }

    }

    printf("\033[0;36m");
    printf("\n*Narrator*: A new day awakes in our hero’s beloved town Mitochondria\n");
    printf("\033[0;32m");
    printf("\nMom: Mijo/a, listen up! %s, I told you to listen to me pinche vago/a! Our\n");
    printf("\ntown is in danger, come take a look outside the window. But be careful, Iberdrola\n");
    printf("\ndisconnected our energy supply!\n");
    printf("\033[0;31m");
    printf("\n*Make use of the flashlight with the command ls to get close to mom*\n");

    loop=true;
    //while (loop){

    if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
        execs(argc, args);
    }
    if(strcmp(args[0],"ls") && strcmp(args[1],".")==0){
        loop=false;
    }
    //}

    printf("\033[0;36m");
    printf("\nThe town is entirely covered by ashes which reduces visibility indoors and outdoors\n");
    printf("\033[0;31m");
    printf("\nMake use of the command ls in order to find the window\n");
    loop=true;

    if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
        execs(argc, args);
    }



    printf("\nMake use of the command cd in order to enter the directory window\n");

    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/game2/street/house/window");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Our hero takes a look outside the window, a massive dragon is attacking the town\n"
           "spitting burning hot fire from its mouth*\n");
    printf("\033[0;32m");
    printf("\nMom screams dramatically: Oh nooooo, uncle Yayo el Muyayo’s house!\n");
    printf("\033[0;36m");
    printf("\n*While our hero’s mom is desperately screaming, uncle Yayo el Muyayo seems not\n"
           "to hear it and is peacefully watering his lovely sunflowers*\n");
    printf("\n*Both mom and son/daughter look at each other with a distressed look in their faces*\n");
    printf("\033[0;32m");
    printf("Mom: Stop looking at me, move your culo and take grandpa’s secret chest, I think it’s "
           "time for you to make the Ramirez family proud!");
    printf("\033[0;31m");
    printf("\n*Make use of the command cd in order to enter the directory stairs and exit the "
           "directory window*\n");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/game2/street/house/stairs");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }
    printf("\n*%s goes upstairs to the second floor*\n",name);
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/game2/street/house/stairs/secondfloor");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }
    printf("\n*Narrator*: Oh no, it looks like grandpa didn't sort out his room, it’s a mess full of chests!!\n");
    printf("\n%s thinks to himself: What mom said keeps resonating in my head.\n",name);
    printf("\nMom’s voice inside %s's head: Grandpa Ricardo’s room is dark, you’ll\n"
           "have to light it up somehow. But remember, grandpa hates it when people sniff\n"
           "around his stuff.\n",name);
    printf("\n*Make use of the command ls in order to see what’s in the room*\n");
    if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
        execs(argc, args);
    }

    printf("\n%s: Great, I can clearly see what’s here!\n",name);
    printf("\n%s thinks to himself/herself: I clearly remember grandpa Ricardo telling me\n"
           "to stay away from the chest labeled “maths”.\n",name);
    printf("\n%s says out loud: Come on %s, uncle Yayo el Muyayo’s in\n"
           "danger, you can’t afford to waste time opening the chest just to check what’s inside.\n",name,name);
    printf("\n%s says excited: But wait, I think I got an idea!\n"
           "*Make use of the command cat in order to see what’s inside without opening it*\n",name);

    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"cat")==0 && strcmp(args[1],"chest")==0){
            loop=false;
        }
    }

    printf("\n%s says energetically: Yes we got this, it’s exactly what I was hoping for,\n"
           "the Master Sword, grandpa Ricardo talked so much about this damn sword!\n",name);
    printf("\n%s says surprised: Holy crap, this chest is too heavy, I can’t bring it with\n"
           "me, I gotta open it and take the sword.\n",name);
    printf("\n*Make use of the command cat in order to access the sword from the chest*\n");

    printf("\n*Narrator dramatically states*: Chop chop hero, uncle Yayo el Muyayo’s screams are\n"
           "clearly audible from across the street.\n");
    printf("\n*Make use of the command cd with full path in order to move to the directory street*\n");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/game2/street/");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }
    printf("\033[0;36m");
    printf("\n*Our hero successfully got out of the house and is outside in the middle of the street*\n");
    printf("\033[0;35m");
    printf("PlayerName thinks to himself/herself: Oh shit, the sword is full of spiderwebs, I gotta clean it up!\n");
    printf("\033[0;31m"); //Set the text to the color red (Commands = RED)
    printf("*Make use of the command rm in order to clean up the sword*");
    printf("\033[0m"); //Resets the text to default color
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execs(argc, args);
        }
        if(strcmp(args[0],"rm")==0 && strcmp(args[1],"spiderwebs")==0){
            loop=false;
        }
    }
    /////////////////////////////////////////// HISTORIA MAT A PARTIR DE AQUI (ARRIBA REVISAR Y APLICAR COLORES)
    printf("\033[0;35m");
    printf("\nPlayerName says confidently: Oh yeah, now I’m ready to kick some ass!\n");
    printf("\033[0;36m");
    printf("\nNarrator*: Our naive hero thought that he had everything under control, but an uncertain destiny awaits him/her.\n");
    printf("\nThe ruthless dragon flies over the Ain’tNobodyGotTimeForThat street where our brave hero is and knocks down one of the main towers of the town’s cathedral, unfortunately knocking out our hero with some rocks that fell off the towers.*\n");
    printf("\n*Our brave hero lies unconscious on the ground*\n");
    printf("\n *Eventually, our brave hero opens up his/her eyes while a bit confused and disoriented*\n");
    printf("\033[0m"); //Resets the text to default color


}





int setup(){
    struct stat st = {0};
    //char dir[1000];
    char au[1000];

    struct passwd *pw = getpwuid(getuid());
    const char *dir = pw->pw_dir;

    //getcwd(dir, 1000);
    strcpy(au,dir);
    //printf("\n%s\n",au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);

    }
    strcpy(dir,au);
    //printf("\n%s\n",dir);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria");
    //printf("\n%s\n",dir);

    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN1");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN2");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN3");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN3");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN4");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OkinawaStreet/HouseN5");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }


    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Mat'sHouse");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Ainara'sHouse");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Asi'sHouse");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/DiositoCathedral");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/HouseN1");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/HouseN2");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/HouseN2");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    //chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN1");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN2");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN3");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN4");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN5");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN6");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/OX-VisimStreet/HouseN7");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }


    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }


    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/FirstFloor");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/Basement");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/FirstFloor/Window");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }



    //copiamos archivos desde storage
    char buffer[1024];
    ssize_t count;
    int fp;
    int target;

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/chest1");

    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\nfp\n");
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor/chest1");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }
    chmod(dir,7000);

    close(fp);
    close(target);




    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/chest2");

    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\nfp\n");
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor/chest2");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    close(fp);
    close(target);


    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/chest3");
    printf(dir);


    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor/chest3");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    chmod(dir,7000);

    close(fp);
    close(target);







    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/hero'sBag");

    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/.hero'sBag");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    close(fp);
    close(target);



    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/maths");

    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor/maths");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    chmod(dir,7000);

    close(fp);
    close(target);


}

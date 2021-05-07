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






    printf("Welcome to the Digital World, in this adventure you will have to learn how to use ten\n"
           "basic commands in order to defeat the ruthless dragon that has been tormenting our\n"
           "town for thousands of years. Do you have what it takes to save our town?\n");

    sleep(0);

    printf("\nFirst of all, we need you to identify yourself young hero:\n");
    fgets(name, 100, stdin);

    printf("use man in order to know the commands that will be used");

    sleep(0);
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


    printf("\n*Narrator*: A new day awakes in our hero’s beloved town Mitochondria\n");
    printf("\nMom: Mijo/a, listen up! %s, I told you to listen to me pinche vago/a! Our\n",name);
    printf("\ntown is in danger, come take a look outside the window. But be careful, Iberdrola\n");
    printf("\ntown is in danger, come take a look outside the window. But be careful, Iberdrola\n");
    printf("\ndisconnected our energy supply!\n");
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


    printf("\nThe town is entirely covered by ashes which reduces visibility indoors and outdoors\n");
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

    printf("\n*Our hero takes a look outside the window, a massive dragon is attacking the town\n"
           "spitting burning hot fire from its mouth*\n");
    printf("\nMom screams dramatically: Oh nooooo, uncle Yayo el Muyayo’s house!\n");
    printf("\n*While our hero’s mom is desperately screaming, uncle Yayo el Muyayo seems not\n"
           "to hear it and is peacefully watering his lovely sunflowers*\n");
    printf("\n*Both mom and son/daughter look at each other with a distressed look in their faces*\n");
    printf("Mom: Stop looking at me, move your culo and take grandpa’s secret chest, I think it’s "
           "time for you to make the Ramirez family proud!");
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
    printf("\n*Narrator*: Oh no, it looks like grandpa didn’t sort out his room, it’s a mess full of chests!!\n");
    printf("\n%s thinks to himself: What mom said keeps resonating in my head.\n",name);
    printf("\nMom’s voice inside %s's head: Grandpa Ricardo’s room is dark, you’ll\n"
           "have to light it up somehow. But remember, grandpa hates it when people sniff\n"
           "around his stuff.\n",name);
    printf("\n*Make use of the command ls -l in order to see what’s in the room*\n");
    if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
        execs(argc, args);
    }

    printf("\n%s: Great, I can clearly see what’s here!\n",name);
    printf("\n%s thinks to himself/herself: I clearly remember grandpa Ricardo telling me\n"
           "to stay away from the chest labeled “Maths”.\n",name);
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
    printf("\n*Our hero successfully got out of the house and is outside in the middle of the street*\n"
           "PlayerName thinks to himself/herself: Oh shit, the sword is full of spiderwebs, I gotta\n"
           "clean it up!\n");
    printf("*Make use of the command rm in order to clean up the sword*");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execs(argc, args);
        }
        if(strcmp(args[0],"rm")==0 && strcmp(args[1],"chest")==0){
            loop=false;
        }
    }


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
    strcat(dir,"/CLionProjects/MyShell/Game/street");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);

    }
    strcpy(dir,au);
    //printf("\n%s\n",dir);
    strcat(dir,"/CLionProjects/MyShell/Game/street/CasaYayoElMuyayo");
    //printf("\n%s\n",dir);

    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/CasaYayoElMuyayo/cocina");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/CasaYayoElMuyayo/sotano");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/ladder");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/window");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/ladder/secondfloor");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }

    //copiamos archivos desde storage
    char buffer[1024];
    ssize_t count;
    int fp;
    int target;

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/bolsa");

    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\nfp\n");
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/stairs/secondfloor/bolsa");

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
    strcat(dir,"/CLionProjects/MyShell/storage/chest1");
    fp=open(dir,O_RDONLY);
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/ladder/secondfloor/chest1");
    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/chest2");
    fp=open(dir,O_RDONLY);
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/street/house/ladder/secondfloor/chest2");
    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

}

//
// Created by samuelguzman on 6/5/21.
//
//COLORS OF STORY SCRIPT
    //COMMANDS = RED -----  EJEMPLO--> printf("\033[0;31m"); PONER COLOR
    //printf("Hello\n"); MENSAJE A PRINTEAR
    // printf("\033[0m"); RESTABLECER A COLOR PREDETERMINADO
    //PLAYER = PURPLE ----- EJEMPLO--> printf("\033[0;35m"); PONER COLOR
    // printf("Hello\n"); MENSAJE A PRINTEAR
    // printf("\033[0m"); RESTABLECER A COLOR PREDETERMINADO
    //NARRATOR = CYAN ----- EJEMPLO--> printf("\033[0;36m"); PONER COLOR
    // printf("Hello\n"); MENSAJE A PRINTEAR
    // printf("\033[0m"); RESTABLECER A COLOR PREDETERMINADO
    //REST OF CHARACTERS = GREEN ----- EJEMPLO--> printf("\033[0;32m"); PONER COLOR
    // printf("Hello\n"); MENSAJE A PRINTEAR
    // printf("\033[0m"); RESTABLECER A COLOR PREDETERMINADO

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../commandsH/game.h"
#include "../commandsH/my_cp2.h"
#include "../myShell0.h"c
#include "../commandsH/my_cat.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <pwd.h>
#include <dirent.h>

#define MAXARGS 20
#define MAXLINE 200
#define BUFFER_SIZE 1000

char name[20];


void replaceAllString(char *buf, const char *orig, const char *replace)
{
    int olen, rlen;
    char *s, *d;
    char *tmpbuf;

    if (!buf || !*buf || !orig || !*orig || !replace)
        return;

    tmpbuf = malloc(strlen(buf) + 1);
    if (tmpbuf == NULL)
        return;


    olen = strlen(orig);
    rlen = strlen(replace);

    s = buf;
    d = tmpbuf;

    while (*s) {
        if (strncmp(s, orig, olen) == 0) {
            strcpy(d, replace);
            s += olen;
            d += rlen;
        }
        else
            *d++ = *s++;
    }

    *d = '\0';

    strcpy(buf, tmpbuf);
    free(tmpbuf);
}

void deleteLine(FILE *srcFile, FILE *tempFile, const int line)
{
    char buffer[BUFFER_SIZE];
    int count = 1;

    while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
    {

        if (line != count)
            fputs(buffer, tempFile);

        count++;
    }
}


int myGame (void) {
    int eof= 0;
    int argc;
    char *args[MAXARGS];
    char str[100];
    bool loop=true;





    printf("\033[0;36m");
    printf("\nWelcome to the Digital World, in this adventure you will have to learn how to use ten\n"
           "basic commandsC in order to defeat the ruthless dragon that has been tormenting our\n"
           "town for thousands of years. Do you have what it takes to save our town?\n");

    sleep(0);

    printf("\nFirst of all, we need you to identify yourself young hero: \n");
    printf("\033[0m");
    fgets(name, 100, stdin);

    printf("\033[0;31m");
    printf("\n*Use man in order to know the commandsC that will be used*\n");


    sleep(0);
    printf("\033[0;31m");
    printf("\nQuick reminder, you can use help whenever you want if you don’t remember how the commandsC work.\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"man")==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Narrator*: A new day awakes in our hero’s beloved town Mitochondria.\n");
    //printf("\033[0;32m");
    printf("\nMom: Mijo/a, listen up! %s, I told you to listen to me pinche vago/a! Our town is in danger, come \n"
           " take a look outside the window. But be careful, Iberdrola disconnected our energy supply!\n");
    printf("\033[0;31m");
    printf("\n*Make use of the flashlight with the command ls -l . to get close to mom*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"ls")==0){
            loop=false;
        }
    }


    printf("\033[0;36m");
    printf("\nThe town is entirely covered by ashes which reduces visibility indoors and outdoors.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command ls . in order to find the window*\n");
    printf("\033[0m");
    loop=true;

    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"ls")==0){
            loop=false;
        }
    }


    printf("\033[0;31m");
    printf("\n*Make use of the command cd in order to enter the directory window*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"cd window") && strcmp(args[1],".")==0){
            loop=false;
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/FirstFloor/Window");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Our hero takes a look outside the window, a massive dragon is attacking the town spitting burning hot\n"
           " fire from its mouth*\n");
    printf("\033[0;32m");
    printf("\nMom screams dramatically: Oh nooooo, uncle Yayo el Muyayo’s house!\n");
    printf("\033[0;36m");
    printf("\n*While our hero’s mom is desperately screaming, uncle Yayo el Muyayo seems not to hear it and is peacefully\n"
           "watering his lovely sunflowers*\n");
    printf("\n*Both mom and son/daughter look at each other with a distressed look in their faces*\n");
    printf("\033[0;32m");
    printf("\nMom: Stop looking at me, move your culo and take grandpa’s secret chest. I think it’s time for you to make\n"
           "the Ramirez family proud!");
    printf("\033[0;31m");
    printf("\n*Make use of the command cd in order to enter the directory stairs and exit the directory window*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }
    printf("\033[0;36m");
    printf("\n*Our young hero goes upstairs to the second floor*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }
    printf("\033[0;36m");
    printf("\n*Narrator*: Oh no, it looks like grandpa didn't sort out his room, it’s a mess full of chests!!\n");
    printf("\033[0;35m");
    printf("\nOur young hero thinks to himself/herself: What mom said keeps resonating in my head.\n");
    printf("\033[0;32m");
    printf("\nMom’s voice inside our young hero's head: Grandpa Ricardo’s room is dark, you’ll have to light it up somehow.\n"
           "But remember, grandpa hates it when people sniff.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command ls -l . in order to see what’s in the room*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"ls")==0){
            loop=false;
        }
    }

    printf("\033[0;35m");
    printf("\nOur young hero says excited: Great, I can clearly see what’s here!\n");
    printf("\nOur young hero thinks to himself/herself: I clearly remember grandpa Ricardo telling me to stay away from\n"
           "the chest labeled “maths”.\n");
    printf("\nOur young hero says out loud: Come on, uncle Yayo el Muyayo’s in danger, you can’t afford to waste time\n"
           "opening the chest just to check what’s inside.\n");
    printf("\nOur young hero says excited: But wait, I think I got an idea!\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cat in order to see what’s inside without opening it*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"cat")==0){
            loop=false;
        }
    }

    printf("\033[0;35m");
    printf("\nOur young hero says energetically: Yes we got this, it’s exactly what I was hoping for, the Master Sword,\n"
           "grandpa Ricardo talked so much about this damn sword!\n");
    printf("\nOur young hero says surprised: Holy crap, this chest is too heavy, I can’t bring it with me, I gotta open\n"
           "it and take the sword.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cat in order to access the sword from the chest*\n");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"cat")==0 &&strcmp(args[1],"chest2")==0 ){


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
            fputs("sword with spiderwebs\n", srcFile);
            fclose(srcFile);
            //AddLine//



            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Narrator dramatically states*: Chop chop hero, uncle Yayo el Muyayo’s screams are clearly audible from\n"
           "across the street.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cd with full path in order to move to the directory MainStreet*\n");
    printf("\033[0m");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Our hero successfully got out of the house and is outside in the middle of the street*\n");
    printf("\033[0;35m");
    printf("\n %s thinks to himself/herself: Oh shit, the sword is full of spiderwebs, I gotta clean it up!\n",name);
    printf("\033[0;31m"); //Set the text to the color red (Commands = RED)
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

    printf("\033[0;35m");
    printf("\n%s says confidently: Oh yeah, now I’m ready to kick some ass!\n",name);
    printf("\033[0;36m");
    printf("\nNarrator*: Our naive hero thought that he had everything under control, but an uncertain destiny awaits him/her.\n");
    printf("\nThe ruthless dragon flies over the Ain’tNobodyGotTimeForThat street where our brave hero is and knocks down one\n"
           "of the main towers of the town’s cathedral, unfortunately knocking out our hero with some rocks that fell off the\n"
           "towers.*\n");
    printf("\n*Our brave hero lies unconscious on the ground*\n");
    printf("\n*Eventually, our brave hero opens up his/her eyes while a bit confused and disoriented*\n");
    printf("\033[0m"); //Resets the text to default color

    printf("\033[0;35m");
    printf("\nOur brave hero says seemingly confused and in pain: What the heck am I doing here? What was I\n"
           "up to? What in the hell happened here?\n");
    printf("\nOur brave hero still disoriented and in pain recalls out loud: Last thing I remember, I was\n"
           "about to kick Mario el Sicario’s ass in a ranked match of League of Legends.\n");
    printf("\033[0;32m");
    printf("\nAn unknown voice resonates in %s’s head: Save your uncle... He’s in danger...\n",name);
    printf("\033[0;35m");
    printf("\nOur brave hero asks himself/herself incredulously: Uncle? I got an uncle?\n");
    printf("\033[0;32m");
    printf("\nUnknown voice inside %s’s head: Yes... Dragon... Home...\n",name);
    printf("\033[0;35m");
    printf("\nOur brave hero says with a face of enlightenment: Oh yeah, now I remember it all, I gotta save my\n"
           "uncle!\n");
    printf("\nOur brave hero subsequently says in pain but furiously: Ouchhhhhhhhh, crap, my head hurts so much,\n"
           "I wonder how the hell I got in this situation!\n");
    printf("\033[0;36m");
    printf("\n*Our hero’s mom is looking out the window with a face of disappointment*\n");
    printf("\033[0;32m");
    printf("\nMom screams: Mijo/a, use the command grep you pinche tonto/a, I don’t remember uncle’s address,\n"
           "that way you’ll find his house!\n");
    printf("\nMom keeps screaming from the window: Oh and here you go, ‘cause as usual you can’t do anything\n"
           "without your pinche mama!\n");
    printf("\033[0;36m");
    printf("\n*Our hero’s mom throws a bag fully packed that radiates a delicious smell of homemade Mexican\n"
           "food*\n");
    printf("\n*Our brave hero still disoriented and confused catches the bag and proceeds to save his uncle\n"
           "Yayo el Muyayo*\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command ls . in order to find uncle’s home*\n");
    printf("\033[0m"); //Resets the text to default color

    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"ls")==0){
            loop=false;
        }
    }

    //////////AÑADIR CONDICIONES////////

    printf("\033[0;35m");
    printf("\nYoung hero: Oh yeah, I remember where he lives now, crystal clear, it’s just going\n"
           "straight until I reach the end of the street Ain’tNobodyGotTimeForThat.\n");
    printf("\033[0;36m");
    printf("\n*Our hero gets up and starts running towards the end of the street*\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cd in order to enter the directory “Yayo'sHouse”*\n");
    printf("\033[0m"); //Resets the text to default color

    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*Narrator*: Once our brave hero reaches uncle’s house, he/she proceeds to fight the ruthless\n"
           "dragon which is on the second floor.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cd in order to access the second floor*\n");
    printf("\033[0m"); //Resets the text to default color

    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        char dir[1000];
        getcwd(dir, 1000);
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        strcat(homedir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse/SecondFloor");
        if(strcmp(dir,homedir)==0){
            loop=false;
        }
    }

    printf("\033[0;35m");
    printf("\nOur brave hero says excited: Finally, I found the goddamn dragon!\n");
    printf("\nOur brave hero subsequently says: But I gotta find a way to distract it somehow...\n");
    printf("\033[0;31m");
    printf("\n*Make use of command bag in order to take out of the bag a big steak that is next to all the\n"
           "tacos mom carefully cooked*\n");
    printf("\033[0m"); //Resets the text to default color

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
    fputs("sword\nsteak\n", srcFile);
    fclose(srcFile);
    //AddLine//


    loop=true;

    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"bag")==0){
            loop=false;
        }
    }


    printf("\033[0;36m");
    printf("\n*Our brave hero throws the huge and juicy steak towards the dragon*\n");
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
    //////////AÑADIR CONDICIONES////////

    printf("\033[0;36m");
    printf("\n*Narrator*: The dragon blindly follows the scent of the juicy steak thrown by our brave hero\n"
           "releasing uncle Yayo el Muyayo from its gigantic and sharp claws.\n");
    printf("\033[0;32m");
    printf("\nDragon thinks to itself: Finally, a proper meal and not a shitty ass human!\n");
    printf("\033[0;35m");
    printf("\nOur brave hero thinks to himself/herself: It’s now or never, I gotta take this chance and take\n"
           "down the dragon!\n");
    printf("\033[0;36m");
    printf("\n*Our brave hero stabs the dragon with the Master Sword in the back*\n");
    printf("\n*The dragon is interrupted from enjoying the juicy steak and while in pain and still alive\n"
           "furiously turns around facing the hero*\n");
    printf("\n*Our brave hero sighs loudly, clearly disappointed by the fact that the dragon isn’t dead yet\n*");
    printf("\033[0;32m");
    printf("\nUnknown voice resonates inside %s’s head: Remember, if one sword isn’t enough, two will\n"
           "make it!\n",name);
    printf("\033[0;35m");
    printf("\nYoung hero: Oh yeah, makes sense, it must be related to that paper in grandpa Ricardo’s room\n"
           "talking about the command cp.\n");
    printf("\033[0;31m");
    printf("\n*Make use of the command cp in order to duplicate the Master Sword*\n");
    printf("\033[0m"); //Resets the text to default color
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            //execute(argc, args);
        }
        if(strcmp(args[0],"cp")==0 && strcmp(args[1],"sword")==0){
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
            fputs("Master sword\n", srcFile);
            fclose(srcFile);
            //AddLine//



            loop=false;
        }
    }

    //////////AÑADIR CONDICIONES////////
    printf("\033[0;36m");
    printf("\nView your bag*\n");
    loop=true;
    while (loop){
        if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
            execute(argc, args);
        }
        if(strcmp(args[0],"bag")==0){
            loop=false;
        }
    }

    printf("\033[0;36m");
    printf("\n*The resulting swords are called Enma and Wado Ichimonji thanks to the increased power obtained\n"
           "thanks to the duplication of the Master Sword.*\n");
    printf("\n*Narrator*: While our brave hero was trying to take the new and more powerful swords, the dragon\n"
           "leaped on the hero trying to reach its neck.\n");
    printf("\033[0;35m");
    printf("\nOur brave hero screams energetically: Too many lives were taken by you, die already, you goddamn\n"
           "dragon! AHHHHHHHH!\n");
    printf("\033[0;36m");
    printf("\n*Narrator*: Our brave hero manages to take the swords on time and beheads the dragon with Enma\n"
           "and Wado Ichimonji, the powerful swords.\n");
    printf("\n*The dragon disappears into thin air leaving a dense cloud of black smoke*\n");
    printf("\n*Narrator*: Congratulations hero, you managed to save your beloved town Mitochondria and also\n"
           "your uncle Yayo el Muyayo. Thanks to this game you should be able to face the real adventure,\n"
           "which is the tough life of an Operating Systems developer. Never give up, with much effort and\n"
           "perseverance anything is possible!\n");
    printf("\\033[0;33m");
    printf("\nTHE END\n");
    printf("");


}


int remove_directory(const char *path) {
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;

    if (d) {
        struct dirent *p;

        r = 0;
        while (!r && (p=readdir(d))) {
            int r2 = -1;
            char *buf;
            size_t len;

            /* Skip the names "." and ".." as we don't want to recurse on them. */
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
                continue;

            len = path_len + strlen(p->d_name) + 2;
            buf = malloc(len);

            if (buf) {
                struct stat statbuf;

                snprintf(buf, len, "%s/%s", path, p->d_name);
                if (!stat(buf, &statbuf)) {
                    if (S_ISDIR(statbuf.st_mode))
                        r2 = remove_directory(buf);
                    else
                        r2 = unlink(buf);
                }
                free(buf);
            }
            r = r2;
        }
        closedir(d);
    }

    if (!r)
        r = rmdir(path);

    return r;
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
    strcat(dir,"//CLionProjects/MyShell/Game/DigitalWorld");
    remove_directory(dir);




    strcpy(dir,au);
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
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Trash");
    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700);
    }
    //chmod(dir,7000);

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
    //chmod(dir,7000);

    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse/SecondFloor");
    if (stat(dir, &st) == -1) {
        int x=mkdir(dir, 0700);
        if(x==-1){
            printf("no se ha podido crear el directorio\n");
        }
    }
    //chmod(dir,7000);
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse/SecondFloor/Dragon");
    if (stat(dir, &st) == -1) {
        int x=mkdir(dir, 0700);
        if(x==-1){
            printf("no se ha podido crear el directorio\n");
        }
    }



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
    //printf(dir);


    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/SecondFloor/chest3");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        //printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    chmod(dir,7000);

    close(fp);
    close(target);







    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/.hero'sBag");

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








    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/spiderwebs");
    printf(dir);


    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/spiderwebs");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    //chmod(dir,7000);

    close(fp);
    close(target);


    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/storage/steak");
    printf(dir);


    fp=open(dir,O_RDONLY);

    if(fp==-1){
        printf("\n%s\n",dir);
    }
    strcpy(dir,au);
    strcat(dir,"/CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Yayo'sHouse/SecondFloor/steak");

    target = open(dir, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(target==-1){
        printf("\ntarget\n");
    }

    while ((count = read(fp, buffer, sizeof(buffer))) != 0){
        write(target, buffer, count);
    }

    //chmod(dir,7000);

    close(fp);
    close(target);





    strcpy(dir,au);
    strcat(dir,"//CLionProjects/MyShell/Game/DigitalWorld/Mitocondria/MainStreet/Hero'sHouse/Stairs/FirstFloor");
    chdir(dir);
    //printf("\ndirectorio final %s\n",dir);


}

//
// Created by samuelguzman on 20/4/21.
//

#include <stdio.h>
#include "../commandsH/my_cp.h"


int myCp(int argc, char *argv[]){
    FILE *fp;
    FILE *target;
    fp=fopen(argv[1],"r");

    if(fp==-1){
        printf("the file doesn't exits");
        return -1;
    }
    char c;
    target=fopen(argv[2],"a");
    if (target==-1){
        printf("the directory doesn't exits");
    }


    while ((c=getc(fp))!=EOF){
        fputc(c,target);
    }
    fclose(fp);
    fclose(target);
    return 0;

}
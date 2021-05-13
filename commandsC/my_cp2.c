//
// Created by samuelguzman on 20/4/21.
//

#include <stdio.h>
#include "../commandsH/my_cp2.h"


int myCp(int argc, char *argv[]){
    FILE *fp;
    FILE *fp2;
    FILE *target;

    fp=fopen(argv[1],"r");
    fp2=fopen(argv[2],"r");
    target=fopen(argv[3],"a");

    if(fp==NULL){
        printf("the file doesn't exits");
        return -1;
    }

    if(fp !=NULL && fp2 != NULL && target == NULL){
        char c;
        target=fopen(argv[2],"a");
        while ((c=getc(fp))!=EOF){
            fputc(c,target);
        }
        fclose(fp);
        fclose(target);
        return 0;
    }

    if(fp != NULL && fp2 != NULL && target != NULL){
        char c;
        target=fopen(argv[3],"a");
        while ((c=getc(fp))!=EOF){
            fputc(c,target);
        }
        while ((c=getc(fp2))!=EOF){
            fputc(c,target);
        }
        fclose(fp);
        fclose(fp2);
        fclose(target);
        return 0;
    }
}
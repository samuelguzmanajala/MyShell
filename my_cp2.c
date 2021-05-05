//
// Created by samuelguzman on 20/4/21.
//

#include <stdio.h>
#include "my_cp2.h"


int myCp(int argc, char *argv[]){
    FILE *fp;
    FILE *target;
    fp=fopen(argv[1],"r");
    if(fp==NULL){
        printf("the file doesn't exits");
        return -1;
    }
    char c;
    target=fopen(argv[2],"a");
    while ((c=getc(fp))!=EOF){
        fputc(c,target);
    }
    fclose(fp);
    fclose(target);
    return 0;

}
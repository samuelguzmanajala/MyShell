//
// Created by samuelguzman on 30/3/21.
//

#ifndef MYSHELL_MYSHELL0_H
#define MYSHELL_MYSHELL0_H
int read_args(int* argcp, char* args[], int max, int* eofp);
void execute2(int numberOfArgs,char **parsed);
int execute(int argc, char *argv[]);
#endif //MYSHELL_MYSHELL0_H

//
// Created by samuelguzman on 6/5/21.
//

#ifndef MYSHELL_GAME_H
#define MYSHELL_GAME_H
int myGame(void);
int setup();
void replaceAllString(char *buf, const char *orig, const char *replace);
void deleteLine(FILE *srcFile, FILE *tempFile, const int line);
#endif //MYSHELL_GAME_H

// myShell0
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <wait.h>

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20

/////////// reading commands:

int read_args(int* argcp, char* args[], int max, int* eofp)
{
   static char cmd[MAXLINE];
   char* cmdp;
   int ret,i;

   *argcp = 0;
   *eofp = 0;
   i=0;
   while ((ret=read(0,cmd+i,1)) == 1) {
      if (cmd[i]=='\n') break;  // correct line
      i++;
      if (i>=MAXLINE) {
         ret=-2;        // line too long
         break;
      }
   }
   switch (ret)
   {
     case 1 : cmd[i+1]='\0';    // correct reading 
              break;
     case 0 : *eofp = 1;        // end of file
              return 0;
              break;
     case -1 : *argcp = -1;     // reading failure
              fprintf(stderr,"Reading failure \n");
              return 0;
              break;
     case -2 : *argcp = -1;     // line too long
              fprintf(stderr,"Line too long -- removed command\n");
              return 0;
              break;
   }
   // Analyzing the line
   cmdp= cmd;
   for (i=0; i<max; i++) {  /* to show every argument */
      if ((args[i]= strtok(cmdp, " \t\n")) == (char*)NULL) break;
      free(cmdp);
   }
   if (i >= max) {
      fprintf(stderr,"Too many arguments -- removed command\n");
      return 0;
   }
   *argcp= i;
   return 1;
}

///////////////////////////////////////

/*
	List of commands to be built in
*/
char *builtin_str = {
	"cp",
	"mv",
	"pwd",		//Asier
	"cat",
	"touch",
	"ls",		//Matheus
	"grep",
	"cd",		//Samu
	"man",
	"help"		//Ainara
};
/*
int (*builtin_str[]) (char **) = {
	&ms_cp,
	&ms_mv,
	&ms_pwd,
	&ms_cat,
	&ms_touch,
	&ms_ls,
	&ms_grep,
	&ms_cd,
	&ms_man,
	&ms_help
};
 */

int ms_num_builtins(){
	return sizeof(builtin_str) / sizeof(char *);
}
	
/*
	Function declarations for commands
*/

int ms_cp(char **args);
int ms_mv(char **args);
int ms_pwd(char **args);
int ms_cat(char **args);
int ms_touch(char **args);
int ms_ls(char **args);
int ms_grep(char **args);
int ms_cd(char **args);
int ms_man(char **args);
int ms_help(char **args);

int execute(int argc, char *argv[])
{

    printf("Executing command...");
    pid_t pid, wpid;
    int status;

    pid = fork();
    switch(pid){

	//child process
	case 0 :
		if(execvp(args[0],args) == -1){
			perror("Argument error");
		}
		 
		exit(-1);

	//Error forking
	case -1 :
		perror("Error focking");
	
	//Parent Process
	default:
		while(!WIFEXITED(status) && !WIFSIGNALED(status)){
			wpid = waitpid(pid,&status,WUNTRACED);
		}
		return 1;
    }
   
}
/*
	Implemented Functions
*/

int ms_cp(char **args){
	
	if(args[1] == NULL){
		fprintf(stderr,"ms: expected argument to \"cp\"\n");
	}else{
		if(chdir(args[1] != 0)){
			perror("ms_cp");
		}
	}
	return 1;
}

int ms_mv(char **args){
    return 0;
}
int ms_mv(char **args);
int ms_pwd(char **args);
int ms_cat(char **args);
int ms_touch(char **args);
int ms_ls(char **args);
int ms_grep(char **args);
int ms_cd(char **args);
int ms_man(char **args);
int ms_help(char **args);


/*
	MAIN
*/
main ()
{
   char * Prompt = "myShell0> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];

   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         execute(argc, args);
      }
      if (eof) exit(0);
   }
}

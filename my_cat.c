//Our own version of the command cat.


//Functions of the command cat:
// If there's a file as a parameter it will display the content in the stdout.
// If there's no parameter it will display what has been typed in the stdin.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAXSIZE 500

main(int argc, char* argv[])
{

   int fd;
   char usa[] = "USAGE: cat [file_name] OR  cat [].";
   char err[] = "ERROR: couldn't open the file.";
   char fil[500];
   char std[500];
   size_t n1 = sizeof(err);
   size_t n2;
   size_t n3;
   


   if (argc != 2 && argc != 1) {
      write(1, usa, n1);
      exit(1);
   }

   else
   		if(argc == 2)
   		{
   			if ((fd = open(argv[1], O_RDWR)) == -1) 
   			{
      		write(1, err, n1);
     		exit(1);
     		}

     		read(fd, *fil, MAXSIZE);
     		n2 = sizeof(fil);
     		write(1, fil, n2);
     		exit(1);
   		}

   		else
   			read(0, *std, MAXSIZE);
   			n3 = sizeof(std);
   			write(1, std, n3);
   			exit(1);

   		
}

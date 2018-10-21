#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 128   /* buffer size */
#define FIFO "fifo"   /* fifo  */

main(int argc, char *argv[])
{
    int fd,i;
    char buffer[SIZE];

    /*fifo open*/

    if((fd=open(FIFO,O_WRONLY)) == -1) {
        perror("open failed");
        exit(1);

    }

    /*commamd line num2 - num 3*/

    for(i=1 ; i<argc ; i++) {
        strcpy(buffer, argv[i]);


        /*fifo file write */

        if(write(fd,buffer,SIZE) == -1) {
            perror("write failed");
            exit(1);
        }
    }
    exit(0);
}


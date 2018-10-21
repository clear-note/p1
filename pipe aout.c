#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 128   /* buffer leng */
#define FIFO "fifo"   /* fifo is */


/* a.out */

main(int argc, char *argv[])
{
    int fd;
    char buffer[SIZE];

    /* access code 0666    creation'fifo' named pipe FIFO */


    if(mkfifo(FIFO, 0666) == -1) {
       perror("mkfifo failed");
       exit(1);
    }
    /* FIFo file open */
    /* FIFO를 이용한 읽기 전용 프로세스와 쓰기 전용 프로세스가 실행되면 쓰기 전용 프로세스가 FIFO에 데이터를 쓸때 까지 읽기 전용 프로세스는 기다린다. 그러므로 FIFO에 데이터가 쓰여져야 read 호출이 동작한다. 이때 스기 전용 프로세스가 종료되어 FIFO에 데이터를 쓸 프로세스가 없는 상황에서 읽기 전용 프로세스가 read 호출을 하면 바로 0을 반환한다. 결국 불필요한 반복 실행을 하게 된다. 그러나 rw로 설정하면 쓰기 전용 프로세스가 종료하더라도 FIFO에 데이터를 쓸 프로세스가 있다고 인식하므로 read호출은 FIFO에 데이터가 전달될 때 까지는 기다리게 되어 불필요한 반복을 을 하지 않게 된다. */
    if((fd=open(FIFO, O_RDWR)) == -1) { 
       perror("open failed");
       exit(1);
    }

    /* loop */

    while(1) {
       /* fifo read */
       if(read(fd, buffer, SIZE) == -1) {
          perror("read failed");
          exit(1);
       }
       /* if data is quit = exit */
       if(!strcmp(buffer, "quit"))

          exit(0);



       /* receive massage print */
       printf("receive message: %s\n", buffer);
    }
}


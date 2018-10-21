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
    /* FIFO�� �̿��� �б� ���� ���μ����� ���� ���� ���μ����� ����Ǹ� ���� ���� ���μ����� FIFO�� �����͸� ���� ���� �б� ���� ���μ����� ��ٸ���. �׷��Ƿ� FIFO�� �����Ͱ� �������� read ȣ���� �����Ѵ�. �̶� ���� ���� ���μ����� ����Ǿ� FIFO�� �����͸� �� ���μ����� ���� ��Ȳ���� �б� ���� ���μ����� read ȣ���� �ϸ� �ٷ� 0�� ��ȯ�Ѵ�. �ᱹ ���ʿ��� �ݺ� ������ �ϰ� �ȴ�. �׷��� rw�� �����ϸ� ���� ���� ���μ����� �����ϴ��� FIFO�� �����͸� �� ���μ����� �ִٰ� �ν��ϹǷ� readȣ���� FIFO�� �����Ͱ� ���޵� �� ������ ��ٸ��� �Ǿ� ���ʿ��� �ݺ��� �� ���� �ʰ� �ȴ�. */
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


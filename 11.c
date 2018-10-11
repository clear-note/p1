/* pip*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include<sys/types.h>
#include<sys/waits.h>
#include<unistd.h>

int main(void)
{

 	int pfd[2];

	
	/*pipe install */
	
if( pipe(pfd)==-1 ){
     perror("pipe erorr");
     exit(1);
}



	if(!fork())  {
	close(1);
	dup(pfd[1]);
	close(pfd[0]);

		execlp("is", "is",NULL);
	}
else  {	
	close(0);
	dup(pfd[0]);
	close(pfd[1]);

	execlp("wc" , "wc" , "-1" , NULL);
}

return 0 ;


}






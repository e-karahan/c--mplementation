#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd, i, ch;

	for (i = 1; i < argc; i++) {

		fd = open(argv[1],O_RDONLY); /*READONLY Modda Dosya Acildi*/

		if(fd < 0) {
			perror("open");
			goto OUT;
		}

		while(read(fd,&ch,1)) /*Bit bit okuma yapiliyor*/

			write(STDOUT_FILENO,&ch,1); /*Bitler STDOUT'a Yazdiriliyor*/

		close(fd); /*Dosya Kapatiliyor*/
	}

	return 0;
OUT:
        return -1;
}

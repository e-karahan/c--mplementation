#include<stdio.h>
#include<unistd.h> /*for STDOUT_FILENO*/
#include<stdlib.h>
#include<fcntl.h> /*for open*/

int main(int argc,char *argv[])
{
	int fd, i, ch;

	for (i = 1; i < argc; i++) {

		fd = open(argv[1],O_RDONLY); /*READONLY Modda Dosya Açıldı*/

		if(fd < 0) {
			perror("open");
			goto OUT;
		}

		while(read(fd,&ch,1)) /*Bit bit okuma yapılıyor*/

			write(STDOUT_FILENO,&ch,1); /*Bitler STDOUT'a Yazdırılıyor*/

		close(fd); /*Dosya Kapatılıyor*/
	}

	return 0;
OUT:
        return -1;
}

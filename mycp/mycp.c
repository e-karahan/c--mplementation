#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[])
{
	int srcFD,destFD,nbread,nbwrite;
	char *buff[BUFF_SIZE];

	/*Source ve Destination Dosyalarina Ulasildimi Kontrolu Yapilir Ulasilmadiysa Hata Yazdirilir*/
	if(argc != 3 || argv[1] == "--help")
	{
		printf("\nKullanim: cpcmd source_file destination_file\n");
		exit(EXIT_FAILURE);
	}

	/*Source Dosyasi Aciliyor*/
	srcFD = open(argv[1],O_RDONLY);
  	/*Dosya Acilmadiysa Hata Yazdiriliyor*/
	if(srcFD == -1)
	{
		printf("\nDosya Acilirken Hata  %s errno = %d\n",argv[1],errno);
		exit(EXIT_FAILURE);
	}

	  /*Destination Dosyasi Aciliyor*/
	destFD = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    /*Dosya Acilmadiysa Hata Yazdiriliyor*/
	if(destFD == -1)
	{
		printf("\nDosya Acilirken Hata %s errno = %d\n",argv[2],errno);
		exit(EXIT_FAILURE);
	}

	/*Data transferine EOF'ye(Dosyanin Sonuna) ulasana kadar devam edilir*/
	while((nbread = read(srcFD,buff,BUFF_SIZE)) > 0)
	{
		if(write(destFD,buff,nbread) != nbread)
			printf("\nData Yazilirken Hata %s\n",argv[2]);
	}
/*Datanin okunmasinda hata var*/
	if(nbread == -1)
		printf("\nData Okunurken Hata %s\n",argv[1]);
/*Source Dosyasi Kapatılmadi*/
	if(close(srcFD) == -1)
		printf("\nDosya Kapatilamadi %s\n",argv[1]);
/*Destination Dosyasi Kapatilmadi*/
	if(close(destFD) == -1)
		printf("\nDosya Kapatilamadi %s\n",argv[2]);

	exit(EXIT_SUCCESS);
}

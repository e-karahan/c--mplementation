#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[])
{
	int srcFD,destFD,nbread,nbwrite;
	char *buff[BUFF_SIZE];

	/*Source ve Destination Dosyalarına Ulaşıldımı Kontrolu Yapılır Ulaşılamadıysa Hata Yazdırılır*/
	if(argc != 3 || argv[1] == "--help")
	{
		printf("\nKullanım: cpcmd source_file destination_file\n");
		exit(EXIT_FAILURE);
	}

	/*Source Dosyası Açılıyor*/
	srcFD = open(argv[1],O_RDONLY);
  	/*Dosya Açılamadıysa Hata Yazdırılıyor*/
	if(srcFD == -1)
	{
		printf("\nDosya Açılırken Hata  %s errno = %d\n",argv[1],errno);
		exit(EXIT_FAILURE);
	}

	  /*Destination Dosyası Açılıyor*/
	destFD = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    /*Dosya Açılamadıysa Hata Yazdırılıyor*/
	if(destFD == -1)
	{
		printf("\nDosya Açılırken Hata %s errno = %d\n",argv[2],errno);
		exit(EXIT_FAILURE);
	}

	/*Data transferine EOF'ye(Dosyanın Sonuna) ulaşana kadar devam edilir*/
	while((nbread = read(srcFD,buff,BUFF_SIZE)) > 0)
	{
		if(write(destFD,buff,nbread) != nbread)
			printf("\nData Yazılırken Hata %s\n",argv[2]);
	}
/*Datanın okunmasında hata var*/
	if(nbread == -1)
		printf("\nData Okunurken Hata %s\n",argv[1]);
/*Source Dosyası Kapatılamadı*/
	if(close(srcFD) == -1)
		printf("\nDosya Kapatılamadı %s\n",argv[1]);
/*Destination Dosyası Kapatılamadı*/
	if(close(destFD) == -1)
		printf("\nDosya Kapatılamadı %s\n",argv[2]);

	exit(EXIT_SUCCESS);
}

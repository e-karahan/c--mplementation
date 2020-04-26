#include"stdio.h"
#include"conio.h"
main()
{
      clrscr(); /*Ekran Temizlemek icin Kullanildi*/
      FILE *fp;
      char file[20], ch;
      int c=0, w=0, l=0;
      printf("Dosyanin Adini Giriniz:");
      gets(file);
      fp=fopen(file,"r"); /*Dosya Aciliyor*/
      if(fp==NULL){ /*Dosya Acilmadiysa Hata Yazdiriliyor*/
          printf("\n\nDosya Okunamadi\nDosya Adini Kontrol Edin");
      }
      else{
            while(1){
                ch=fgetc(fp);
                c++; /*Karakterler Sayiliyor.*/
                if(ch==EOF){ /*Dosyanin Sonuna Ulasildiysa Donguden Cikiliyor*/
                  break;
                }
                else if(ch==' '){
                  w++; /*Kelimeler Sayiliyor.*/
                }
                else if(ch=='\n')
                {
                  l++; /*Satir Sayisi Sayiliyor*/
                  w++;
                }
           }
           printf("\n\nDosyadaki Karakter Sayisi %s = %d",file, c);
           printf("\n\nDosyadaki Kelime Sayisi %s = %d",file, w);
           printf("\n\nDosyadaki Sayisi Sayisi %s = %d",file, l);
      }
      fclose(fp); /*Dosya Kapatiliyor*/
      getch();
      return(0);
}

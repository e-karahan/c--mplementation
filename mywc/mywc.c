#include"stdio.h"
#include"conio.h"
main()
{
      clrscr(); /*Ekran Temizlemek İçin Kullanıldı*/
      FILE *fp;
      char file[20], ch;
      int c=0, w=0, l=0;
      printf("Doyanın Adını Giriniz:");
      gets(file);
      fp=fopen(file,"r"); /*Dosya Açılıyor*/
      if(fp==NULL){ /*Dosya Açılamadıysa Hata Yazdırılıyor*/
          printf("\n\nDosya Okunamadı\nDosya Adını Kontrol Edin");
      }
      else{
            while(1){
                ch=fgetc(fp);
                c++; /*Karakterler Sayılıyor.*/
                if(ch==EOF){ /*Dosyanın Sonuna Ulaşıldıysa Döngüden Çıkılıyor*/
                  break;
                }
                else if(ch==' '){
                  w++; /*Kelimeler Sayılıyor.*/
                }
                else if(ch=='\n')
                {
                  l++; /*Satır Sayısı Sayılıyor.*/
                  w++;
                }
           }
           printf("\n\nDosyadaki Karakter Sayısı %s = %d",file, c);
           printf("\n\nDosyadaki Kelime Sayısı %s = %d",file, w);
           printf("\n\nDosyadaki Satır Sayısı %s = %d",file, l);
      }
      fclose(fp); /*Dosya Kapatılıyor*/
      getch();
      return(0);
}

#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct data
{
char nama[30];
   char nim[12];
   char matkul[11];
   int nilai;                                                 
};
data mhs[10];

int n,i,j,a,k,m;
char kata[10],temp[10];

void input()
{
system("cls");printf("+================================+\n");
      printf("|    Rizqie Miftakhuddin Noor    |\n");
      printf("|--------------------------------|\n");
printf("Jumlah data : "); scanf("%d",&n);
   for (i=0; i<n; i++)
   {
        printf("\nData ke-%d\n",i+1);
      printf("  NIM   : "); scanf("%s",&mhs[i].nim);
      printf("  Nama  : "); scanf("%s",&mhs[i].nama);
      printf("  Mata kuliah : "); scanf("%s",&mhs[i].matkul);
      printf("  Nilai : "); scanf("%d",&mhs[i].nilai);
   }
}

void output()
{
system("cls");printf("+================================+\n");
      printf("|    Rizqie Miftakhuddin Noor    |\n");
      printf("|--------------------------------|\n");
   printf("                Tampilan Data awal          \n");
   printf("+===============================================+\n");
   printf("| No |    NIM     |    NAMA    | MATKUL | NILAI |\n");
   printf("|-----------------------------------------------|\n");
   printf("|    |            |            |        |       |\n");
   for(i=0; i<n; i++)
   {
        printf("|    |            |            |        |       |\n");
        gotoxy(3,8+i); printf("%d",i+1);
      gotoxy(8,8+i); printf("%s",mhs[i].nim);
      gotoxy(21,8+i); printf("%s",mhs[i].nama);
      gotoxy(35,8+i); printf("%s",mhs[i].matkul);
      gotoxy(45,8+i); printf("%d\n",mhs[i].nilai);
   }
   printf("+======================================+\n");
}

void urut()
{
system("cls");
  printf("+================================+\n");
      printf("|    Rizqie Miftakhuddin Noor    |\n");
      printf("|--------------------------------|\n");
   for (i=0;i<n;i++)
   {
        for (j=i+1;j<n;j++)
        {
        if (mhs[i].nim<mhs[j].nim)
         {
               data temp;
            temp=mhs[i];
            mhs[i]=mhs[j];
            mhs[j]=temp;
         }
        }
   }
   system("cls");
   printf("        Data Setelah Diurutkan          \n");
      printf("+===============================================+\n");
   printf("| No |    NIM     |    NAMA    | MATKUL | NILAI |\n");
   printf("|-----------------------------------------------|\n");
   printf("|    |            |            |        |       |\n");
   for(i=0; i<n; i++)
   {
        printf("|    |            |            |        |       |\n");
        gotoxy(3,8+i); printf("%d",i+1);
      gotoxy(8,8+i); printf("%s",mhs[i].nim);
      gotoxy(21,8+i); printf("%s",mhs[i].nama);
      gotoxy(35,8+i); printf("%s",mhs[i].matkul);
      gotoxy(45,8+i); printf("%d\n",mhs[i].nilai);
   }
   printf("+======================================+\n");
}

void cari()
{  
system("cls");
printf("+================================+\n");
      printf("|    Rizqie Miftakhuddin Noor    |\n");
      printf("|--------------------------------|\n");
printf ("Cari NIM : "); scanf("%s",&kata);
        for (int i=0;i<n;i++)
   {
               if(strcmp(kata,mhs[i].nim)==0)
               {
               printf("\nData %s Ditemukan\n", kata);
               printf ("NIM   : %s\n",mhs[i].nim);
               printf ("Nama  : %s\n",mhs[i].nama);
               printf ("Nilai : %d\n",mhs[i].nilai);

      }
               else
      {
                      printf("Data ke-%d Tidak Ada\n",i+1);  //break;
      }
   }
   //getch();
}

int main ()
{
int pil;
do{
system("cls");
        printf("+================================+\n");
      printf("|    Rizqie Miftakhuddin Noor    |\n");
      printf("|--------------------------------|\n");
      printf("| 1. Input data                  |\n");
      printf("| 2. Tampilkan Dan Urutkan Data  |\n");
      printf("| 3. Cari Data                   |\n");
      printf("| 0. Keluar                      |\n");
      printf("|--------------------------------|\n");
      printf("| Pilih menu :                   |\n");
      printf("+================================+\n");
      gotoxy(16,8); scanf("%d",&pil);
      switch(pil)
      {
        case 1 : input(); getch(); break;
               case 2 : {
                                   output();
                     printf("\n\n  Tekan enter untuk mengurutkan data\n");
                     getch();
                     urut();
                     getch();
                     break;
                            }
         case 3 : cari(); getch(); break;
               case 0 : break;
         default: printf("Input salah");

      }

}

   while(pil!=0);

        getch();

}


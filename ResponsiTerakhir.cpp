#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
using namespace std;

#define maxItem 5


struct cstr 
{
	string nameItem;
	int amountItem;
	int price;
};
typedef cstr customer;
struct value 
{
	int tos;
	int Payment;
	int SubTotal;
	int Total;
	int cashBack;
	int a;
	customer stack_array[maxItem];
};
typedef value item;
item myItem;
item tempmyitem;

struct myQueue
{
	int id;
	item myque;
};
typedef myQueue Q;
Q antrian[3];
int pembatas = 0;
int imax = 0;

void initStack(item &s) {
	s.tos = -1;
}

int isFull(item s) {
	return s.tos == maxItem - 1;
}

int isEmpty(item s) {
	return s.tos == -1;
}

void push(item &s, customer val) {
	if (isFull(s)) {
		cout << " ";
	}
	else {
		s.tos++;
		pembatas++;
		s.stack_array[s.tos] = val;
	}
}

void showCustomer(item s) {
	customer temp;

	if (isEmpty(s)) {
		cout << "Tidak Ada Apapun Dalam Keranjang";
	}
	else {
		while (!isEmpty(s)) {
			temp = s.stack_array[s.tos];
			s.tos--;

			cout << "Masukkan Nama Barang : " << temp.nameItem << "\n";
			cout << "Masukkan Jumlah Barang : " << temp.amountItem << " pcs\n";
			cout << "Harga satuan : " << "Rp." << temp.price << "\n\n";
		}
	}
}

void showCashier(item &s, Q &ss) {
	ss.myque = s;
	item tmp = ss.myque;
	if (tmp.tos == -1) {
		cout << "\nTidak ada antrian keranjang pengunjung...\n\n";
	} else {
		for (int i = 0; i <= tmp.tos; i++)
		{
			cout << "Masukkan Nama Barang \t\t: " << tmp.stack_array[i].nameItem << endl;
			cout << "Masukkan Jumlah Barang \t: " << tmp.stack_array[i].amountItem << endl;
			cout << "Harga Satuan \t\t: " << "Rp."; cin >> tmp.stack_array[i].price;
			tmp.SubTotal = tmp.stack_array[i].amountItem * tmp.stack_array[i].price;
			tmp.Total = tmp.SubTotal + tmp.Total;
		}
		cout << "------------------------------------------------------------ \n";
		cout << "SubTotal \t: " << "Rp." << tmp.SubTotal << "\n";
		cout << "Total \t\t: " << "Rp." << tmp.Total << "\n";
		cout << "------------------------------------------------------------ \n\n\n";
		cout << "Total belanjaan \t\t: " << "Rp." << tmp.Total << "\n";
		cout << "Masukkan jumlah bayar \t: " << "Rp."; cin >> tmp.Payment;
	if (tmp.Payment < tmp.Total) {
		do {
			tmp.a=tmp.Total-tmp.Payment;
			cout <<"Uang pelanggan kurang :"<<tmp.a<<endl;
			cout << "Masukkan jumlah bayar \t: " << "Rp."; cin >> tmp.Payment;
			if (tmp.Payment >= tmp.Total) {
				break;
			}
		} while (true);
		tmp.cashBack = tmp.Payment - tmp.Total;
		tempmyitem.Total = tmp.Total + tempmyitem.Total;
		cout << "------------------------------------------------------------ \n";
		cout << "Kembalian : " << "Rp." << tmp.cashBack << "\n";
		cout << "Terimakasih sudah berbelanja di Rizqie-Mart...\n";
	}
	else {
		
			tmp.cashBack = tmp.Payment - tmp.Total;
			tempmyitem.Total = tmp.Total + tempmyitem.Total;
			cout << "------------------------------------------------------------ \n";
			cout << "Kembalian : " << "Rp." << tmp.cashBack << "\n";
			cout << "Terimakasih sudah berbelanja di Rizqie-Mart...\n";
		}
	}
	initStack(s);
}

void displayCashier(item &s, Q &ss) {
	ss.myque = s;
	item tmp = ss.myque;
	if (tmp.tos == -1) {
		cout << "\nTidak ada antrian keranjang pengunjung... \n\n";
	} else {
		for (int i = 0; i <= tmp.tos; i++)
		{
			cout << "Nama Barang \t\t: " << tmp.stack_array[i].nameItem << endl;
			cout << "Jumlah Barang \t: " << tmp.stack_array[i].amountItem << endl;
			cout << "Harga Barang \t\t: " << "Rp."<< tmp.stack_array[i].price << endl << endl;
		}
	}
}

customer pop(item &s) {
	customer temp;
	int a;
	if (isEmpty(s)) {
		cout << "\nTidak ada barang dalam keranjang...\n";
	}
	else {
		for (int i = 0; i <= s.tos; i++)
		{
			cout << i << endl;
			cout << "Nama Barang : " << s.stack_array[i].nameItem << "\n";
			cout << "Jumlah Barang : " << s.stack_array[i].amountItem << " pcs\n";
			cout << "Harga Barang : " << "Rp." << s.stack_array[i].price << "\n\n";
		}
		cout << "Masukkan nomor berapa yang akan dikeluarkan : "; cin >> a;
		for (int k = 0; k <= s.tos; k++)
		{
			if (a == k)
			{
				for (int j = k; j <= s.tos; j++)
				{
					if (j > k)
					{
						s.stack_array[j] = s.stack_array[j + 1];
					}
					else if (j == maxItem) {
						s.tos--;
					}
				}
				s.tos--;
			}
		}
		cout << "\nBarang telah dikeluarkan dari keranjang\n";
		pembatas = s.tos;
		myItem.tos = s.tos;
		return temp;
	}
}

customer change(item &s) {
	customer temp;
	int a;
	if (isEmpty(s)) {
		cout << "\nTidak ada barang dalam keranjang...\n";
	}
	else {
		for (int i = 0; i <= s.tos; i++)
		{
			cout << i << endl;
			cout << "Nama Barang : " << s.stack_array[i].nameItem << "\n";
			cout << "Jumlah Barang : " << s.stack_array[i].amountItem << " pcs\n";
			cout << "Harga Barang : " << "Rp." << s.stack_array[i].price << "\n\n";
		}
		cout << "Masukkan nomor barang yang akan dirubah : "; cin >> a;
		for (int k = 0; k <= s.tos; k++)
		{
			if (a == k)
			{
				for (int j = k; j <= s.tos; j++)
				{
					if (j == k)
					{
						cout << "================== Ubah Barang ================== \n";
						cout << "Nama Barang \t\t: "; cin >> s.stack_array[j].nameItem;
						cout << "Jumlah Barang \t: "; cin >> s.stack_array[j].amountItem;
						cout << "\nBarang Telah Dirubah \n\n";
					}
				}
			}
		}
		cout << "\nBarang telah dikeluarkan dari keranjang\n";
		pembatas = s.tos;
		myItem.tos = s.tos;
		return temp;
	}
}



void gotoxy(short x, short y){
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void pembukaan()
{
  cout<<"====================================================\n";
  cout<<"====================================================\n";
  cout<<"                                                    \n";
  cout<<"                   Catatan kecil...                 \n";
  cout<<"                                                    \n";
  cout<<"   ===============================================  \n";
  cout<<"   |                                             |  \n";
  cout<<"   |    Program Kasir Sederhana  (Rizqie-Mart)   |  \n";
  cout<<"   |                                             |  \n";
  cout<<"   ===============================================  \n";
  cout<<"                                                    \n";
  cout<<"   ===============================================  \n";
  cout<<"   |   Program ini dibuat berdasarkan referensi  |  \n";
  cout<<"   | dari teman satu kelas saya, dan kodingannya |  \n";
  cout<<"   | juga dikasih dari beliau, namun juga tidak  |  \n";
  cout<<"   | semuanya langsung dari beliau,sebagian saya |  \n";
  cout<<"   | ubah agar apa yang saya pikirkan tertuang   |  \n";
  cout<<"   | di dalam sini. demikian catatan saya dalam  |  \n";
  cout<<"   | projek Responsi terakhir kali ini.. Thanks. |  \n";
  cout<<"   ===============================================  \n";
  cout<<"====================================================\n";
  cout<<"====================================================";
  int x = 3, y=5,c,d,a,e;
  for(a=1;a<2;a++)
  {
  for (x;x<50;x++)
  {
     gotoxy(x,y);
     cout<<"   ";
     for(c=1;c<1000;c++)
       for(d=1;d<1000;d++)
          cout<<"";
     gotoxy(x,y);
     cout<<"=";
  }
  x = 33, y=3;
  for (x;x<36;x++)
  {
	 gotoxy(x,y);
	 cout<<" . ";
     for(c=1;c<3000;c++)
       for(d=1;d<3000;d++)
          cout<<"";
     gotoxy(x,y);
     cout<<".";
  }
  
  x = 49, y=6;
  for (y;y<10;y++)
  {
     gotoxy(x,y);
     cout<<" ";
     for(c=1;c<1000;c++)
       for(d=1;d<1000;d++)
         cout<<"";
     gotoxy(x,y);
     cout<<"|";
  }
  
  
  x = 49, y=9;
  for (x;x>2;x--)
  {
     gotoxy(x-2,y);
     cout<<"   ";
     for(c=1;c<1000;c++)
       for(d=1;d<1000;d++)
         cout<<"";
     gotoxy(x,y);
     cout<<"=";
  }
  x = 3, y=8;
  for (y;y>5;y--)
  {
     gotoxy(x,y);
     cout<<" ";
     for(c=1;c<1000;c++)
        for(d=1;d<1000;d++)
           cout<<"";
     gotoxy(x,y);
     cout<<"|";
  }
  }
}
void intro()
{
  int x,y;
  for(x=0;x<=100;x=x+3)
  {
   for(y=0;y<=50;y++)
   {
    gotoxy(x,y);
    cout<<"===\n\n";
    for(int a=1;a<80;a++)
      for(int b=1;b<80;b++)
        cout<<"";
   }
   for(int a=1;a<700;a++)
      for(int b=1;b<700;b++)
        cout<<"";
  }
  for(int a=1;a<1800;a++)
      for(int b=1;b<1800;b++)
        cout<<"";
        
	system("cls");
}

int main()
{
	system("color A");
	pembukaan();
	intro();
	system("cls");
	
	initStack(myItem);
	customer cstmr;
	int choiseCashier;
	int choiseCustomer;
	Q s;

	int choise;

	do {
		cout << "==========Selamat Datang di Rizqie-Mart========== \n";
		cout << "1. Masuk Sebagai Pelanggan \n";
		cout << "2. Masuk Sebagai Kasir \n";
		cout << "0. Keluar \n";
		cout << "========================================= \n";
		cout << "Pilihan : "; cin >> choise;

		switch (choise) {
		case 1:
			do {
				system("cls");
				cout << "================ P.O.S. Pelanggan ================ \n"; //P.O.S (Point of Sale)
				cout << "1. Tambah Barang Kedalam Keranjang \t \n";
				cout << "2. Lihat Barang \n";
				cout << "3. Keluarkan Barang \n";
				cout << "4. Ubah Barang \n";
				cout << "0. Mengantri di Kasir \n";
				cout << "=================================================== \n";
				cout << "Pilihan : "; cin >> choiseCustomer;
				system("cls");

				if (choiseCustomer == 1) {
					if (pembatas == maxItem) {
						cout << "================== Tambah Barang ================== \n";
						cout << "Nama Barang \t\t: "; cin >> cstmr.nameItem;
						cout << "Jumlah Barang \t: "; cin >> cstmr.amountItem;
						cout << "\nFull \n\n";
						system("pause");
					}
					else {
						cout << "================== Tambah Barang ================== \n";
						cout << "Nama Barang \t\t: "; cin >> cstmr.nameItem;
						cout << "Jumlah Barang \t: "; cin >> cstmr.amountItem;
						cstmr.price = 0;
						cout << "\nBarang masuk ke dalam keranjang.. \n\n";
						push(myItem, cstmr);
						system("pause");
						system("cls");
					}
				}
				else if (choiseCustomer == 2) {
					cout << "================== Barang dalam keranjang ================== \n";
					showCustomer(myItem);
					cout << "\n";
					system("pause");
					system("cls");
				}
				else if (choiseCustomer == 3) {
					pop(myItem);
					system("pause");
					system("cls");
				}
				else if (choiseCustomer == 4) {
					change(myItem);
					system("pause");
					system("cls");
				}

			} while (choiseCustomer != 0);
			antrian[imax].myque = myItem;
			imax++;
			cout << "\nAntrian barang kedalam kasir sukses. \n\n";
			system("pause");
			system("cls");
			break;
		case 2:
			do {
				system("cls");
				cout << "================= P.O.S. Kasir ================= \n";
				cout << "1. Proses keranjang pelanggan \n";
				cout << "2. Lihat antrian keranjang \n";
				cout << "3. Lihat Pendapatan Hari Ini \n";
				cout << "0. Kembali ke menu \n";
				cout << "================================================== \n";
				cout << "Pilihan : "; cin >> choiseCashier;
				system("cls");

				if (choiseCashier == 1) {
					cout << "=============== Proses Keranjang Pelanggan =============== \n";
					showCashier(myItem, s);
					cout << "\n";
					system("pause");
					system("cls");
				}
				else if (choiseCashier == 2) {
					cout << "================ Lihat Antrian Keranjang ================= \n";
					displayCashier(myItem, s);
					system("pause");
					system("cls");
				}
				else if (choiseCashier == 3) {
					cout << "===================== Pendapatan Hari Ini ======================= \n";
					cout << "\nTotal Pendapatan Hari Ini : " << "Rp." << tempmyitem.Total << "\n\n";
					system("pause");
					system("cls");
				}
			} while (choiseCashier != 0);
			break;
		}
	} while (choise != 0);
}

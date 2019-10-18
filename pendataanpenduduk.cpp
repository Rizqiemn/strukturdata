#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define max 100
using namespace std;

struct penduduk{
	char nama[20];
	int usia;
	int anggota;
	char status[20];
	char agama[10];
}pdk[max];

int main(){
	int x, p, i;
	char j;
	cout<<"Program Data Penduduk Desa Kedungjaya 2019\n\n\n";
	cout<<"=========> By : Rizqie M. Noor <=========\n\n\n";
	cout<<"Masukkan Jumlah Penduduk yang akan didata : ";
	cin>>p;
	
	for(x=1; x<=p; x++){
		cout<<"Data penduduk ke-"<<x<<endl;
		cout<<"Masukkan Nama : "; cin>>pdk[x].nama;
		cout<<"Masukkan Usia : "; cin>>pdk[x].usia;
		cout<<"Masukkan Status : "; cin>>pdk[x].status;
		cout<<"Masukkan Agama : "; cin>>pdk[x].agama;
		cout<<"Berapa anggota keluarga : "; cin>>pdk[x].anggota;
		cout<<endl;
	}
	up:
	cout<<endl<<endl;
	cout<<"Inputan Selesai"<<endl;
	cout<<"Ingin menampilkan datanya?"<<endl;
	cout<<"1. Tampilkan Seluruhnya\n";
	cout<<"2. Tampilkan perpenduduk\n";
	cout<<"3. Tidak perlu"<<endl;
	cout<<"Jawaban anda? "; cin>>i;
	cout<<endl;
	
	switch(i){
		case 1:
			system("cls");
			cout<<"=====> Menu Tampilkan Seluruhnya <=====\n\n";
			cout<<"Data Penduduk Tahun 2019"<<endl;
			for(x=1;x<=p;x++){
				cout<<"Penduduk ke-"<<x<<endl;
				cout<<"Nama : "<<pdk[x].nama<<endl;
				cout<<"Usia : "<<pdk[x].usia<<endl;
				cout<<"Status : "<<pdk[x].status<<endl;
				cout<<"Agama : "<<pdk[x].agama<<endl;
				cout<<pdk[x].anggota<<" Anggota keluarga."<<endl;
				goto up;
			}
			break;
		case 2 :
				system("cls");
				cout<<"=====> Menu Tampilkan yang dipilih <=====\n\n";
				cout<<"Masukkan nomor data penduduk yang akan ditampilkan : ";
				cin>>x;
				cout<<"Penduduk ke-"<<x<<endl;
				cout<<"Nama : "<<pdk[x].nama<<endl;
				cout<<"Usia : "<<pdk[x].usia<<endl;
				cout<<"Status : "<<pdk[x].status<<endl;
				cout<<"Agama : "<<pdk[x].agama<<endl;
				cout<<pdk[x].anggota<<" Anggota keluarga."<<endl;
				goto up;
			break;
		default:
			system("cls");
			for(int x=1;x<100000;x++){
				system("color 02");
			cout<<"====> Terimakasih :) <=====";
				system("color 01");
			cout<<"====> Terimakasih :) <=====";
				system("color 12");
			cout<<"====> Terimakasih :) <=====";
				system("color 11");
			cout<<"====> Terimakasih :) <=====";
			}
			
			break;
	}
	getche();
	return 0;
}

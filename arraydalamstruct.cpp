/*contoh program sederhana array di dalam struct*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define maks 100
using namespace std;

struct TMhs
{
char NIM[9];
char Nama[21];
int NilaiUTS,NilaiUAS,NilaiQuis;
float NilaiAkhir;
char index;
}me[maks];

void printdata(TMhs data);

main ()
{
	TMhs mhs[maks];
	int i,a;
	int pil;
	up:
	cout<<"Pilih salah satu :"<<endl;
	cout<<"1. input"<<endl;
	cout<<"2. Menuju Tabel"<<endl;
	cout<<"Pilihanmu : ";
	cin>>pil;
	switch(pil){
	
		case 1: 
		cout<<"Mau berapa kali input? ";
		cin>>a;
		for(i=0;i<a;i++){
	
			cout << "Pengisian Data Mahasiswa Ke-"<<i+1<< endl;
	
			cout << "NIM : "; cin >> mhs[i].NIM;
	
			cout << "NAMA : "; cin >> mhs[i].Nama;
	
			cout <<"Nilai Quiz : ";cin >> mhs[i].NilaiQuis;
	
			cout <<"Nilai UTS : ";cin >> mhs[i].NilaiUTS;
	
			cout <<"Nilai UAS : ";cin >> mhs[i].NilaiUAS;
	
			mhs[i].NilaiAkhir=0.2*mhs[i].NilaiQuis+0.3*mhs[i].NilaiUTS+0.5*mhs[i].NilaiUAS;
	
			if(mhs[i].NilaiAkhir>=80) {
				mhs[i].index ='A';}else if(mhs[i].NilaiAkhir>=60) {
				mhs[i].index ='B';}else if(mhs[i].NilaiAkhir>=40) {
				mhs[i].index ='C';}else if(mhs[i].NilaiAkhir>=20) {
				mhs[i].index ='D';}else if(mhs[i].NilaiAkhir>=0) {
				mhs[i].index ='E';}
			};
			goto up;
			break;
		case 2: 
				cout <<"Data yang telah dimasukkan adalah : \n";
				cout <<"------------------ \n";
				cout <<"| NIM | NAMA | QUIS | UTS | UAS | NA | INDEX | \n";
				cout <<"------------------ \n";
				for(i=0;i<a;i++)
				{
					cout<< mhs[i].NIM <<" | "<< mhs[i].Nama<<" | " << mhs[i].NilaiQuis<<" | " << mhs[i].NilaiUTS <<" | "<< mhs[i].NilaiUAS<<" | " << mhs[i].NilaiAkhir <<" | "<< mhs[i].index <<" | "<< endl;
				}
				cout<<"------------------ \n";
				cout<<endl<<endl<<endl;
				goto up;
			break;
	}
	
	
	
	return 0;
}

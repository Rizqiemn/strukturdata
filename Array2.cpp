#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main(){
	int A[10]={5,12,24,53,51,26,17,62,36,68};
	int cari;
	
	for(int i=0;i<10;i++){
		cout<<"Data baris ke-"<<i<<" = "<<A[i]<<endl;
	}
	cout<<endl;
	cout<<"Masukkan Data yang dicari: ";
	cin>>cari;
	for(int j=0;j<10;j++){
		if (A[j]==cari){
			cout<<"Nilai yang dicari berada pada indeks ke-"<<j<<endl;
			}else{
				cout<<"Data yang dicari tidak ada"<<endl;
			}
	}cout<<endl;
	return 0;
}

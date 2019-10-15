#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main(){
	int data[5];
	for(int i=0;i<5;i++){
		cout<<"Masukkan data pada elemen ke-"<<i<<"=";
		cin>>data[i];
	}	
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<"Data baris ke-"<<i<<"="<<data[i]<<endl;
	}
	return 0;
}

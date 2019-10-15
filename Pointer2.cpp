#include<iostream>
using namespace std;
int main(){
	void *P;
	int X;
	long Y;
	double Z;
	P=&X;
	X=10;
	cout<<"Nilai Y : "<<Y<<endl;
	cout<<"Nilai P : "<<P<<endl;
	cout<<"Nilai &Y : "<<&Y<<endl;
	cout<<endl;
	
	P=&Z;
	Z=21.0378;
	cout<<"Nlai Z : "<<Z<<endl;
	cout<<"Nilai P : "<<P<<endl;
	cout<<"Nilai &Z : "<<Z<<endl;
	return 0;
}

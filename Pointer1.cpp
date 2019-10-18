#include<iostream>
using namespace std;
int main(){
	long *P;
	long X;
	P = &X;
	X=10;
	cout<<"Nilai X : "<<X<<endl;
	cout<<"Nilai *P : "<<*P<<endl;
	cout<<"Nilai P : "<<P<<endl;
	cout<<"Nilai &X : "<<&X<<endl;
	*P=200;
	cout<<"Nilai X : "<<X<<endl;
	cout<<"Nilai *P : "<<*P<<endl;
	cout<<"Nilai P : "<<P<<endl;
	cout<<"Nilai &X : "<<&X<<endl;
	
	return 0;
}

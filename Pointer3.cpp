#include<iostream>
#define MAX 5
using namespace std;
int main(){
	float *P1;
	int *P2;
	P1=new float;
	*P1=3.14;
	cout<<"Nilai *P1 : "<<*P1<<endl;
	cout<<"Nilai P1 : "<<P1<<endl;
	cout<<"\n";
	
	P2=new int[MAX];
	for(int  C=0;C<5;C++){
		*P2=(C+1)*10;
		P2+=1;
	}
	P2-=5;
	for(int  c=0;c<5;c++){
	cout<<"Nilai *P2 : "<<*P2<<endl;
	cout<<"Nilai P2 : "<<P2<<endl<<endl;
	P2+=1;
	}
	return 0;
}

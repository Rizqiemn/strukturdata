#include<iostream>
using namespace std;
int main(){
	int *P;
	P=new int;
	*P=100;
	cout<<"Nilai *P : "<<*P<<endl;
	delete P;
	return 0;
}

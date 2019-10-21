#include<iostream>
#include<vector>
#include<conio.h>
#include<windows.h>
using namespace std;

class ArrayTerurut{
	private: 
		vector<double> v;
		int jumElemen;
	
	public: 
		ArrayTerurut(int max){
			v.resize(max);
			jumElemen=0;
		}
		
		int bacaUkuran(){
			return jumElemen;
		}
	
		int cari(double kunciPencarian){
			return cariRekursif(kunciPencarian, 0, jumElemen-1);
		}

		int cariRekursif(double kunciPencarian, int batasBawah, int batasAtas){
			int posSkrg;
			posSkrg = (batasBawah + batasAtas)/2;
			if(v[posSkrg]==kunciPencarian)
				return posSkrg;
			else if(batasBawah>batasAtas)
				return jumElemen;
			else{
				if(v[posSkrg]<kunciPencarian)
				return cariRekursif(kunciPencarian,posSkrg+1, batasAtas);
				else
				return cariRekursif(kunciPencarian, batasBawah, posSkrg-1);
			}
		}	
	
		void sisip(double nilai){
			int j;
			for(j=0;j<jumElemen;j++)
			if(v[j]>nilai)
			break;
			
			for(int k=jumElemen;k>j;k--)
			v[k]=v[k-1];
			v[j]=nilai;
			jumElemen++;
		}
		
		void tampil(){
			for(int j=0; j<jumElemen;j++)
			cout<<v[j]<<" ";
			cout<<endl;
		}	
};


int main(){
	up:
	int ukuranMaks=100;
	ArrayTerurut arr(ukuranMaks);
	arr.sisip(72);
	arr.sisip(90);
	arr.sisip(45);
	arr.sisip(126);
	arr.sisip(54);
	arr.sisip(99);
	arr.sisip(135);
	arr.sisip(81);
	arr.sisip(18);
	arr.sisip(108);
	arr.sisip(9);
	arr.sisip(117);
	arr.sisip(63);
	arr.sisip(36);
	arr.sisip(88);
	arr.tampil();
	
	int kunciPencarian;
	cout<<"Masukkan Pencarian : ";cin>>kunciPencarian;
	if(arr.cari(kunciPencarian)!=arr.bacaUkuran()){
		cout<<"Menemukan "<<kunciPencarian<<endl;
	}
	else{
		cout<<"Tidak Menemukan "<<kunciPencarian<<endl;
		getch();
	}
	cout<<endl;
	cout<<"Lagi? (y/n)";
	char y;
	cin>>y;
	if(y=='y'||y=='Y'){
		goto up;
	}else{
		system("CLS");
	}	

	return 0;
}

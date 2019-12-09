#include <iostream>
#include <conio.h>
using namespace std;

class Simpul{
public:
	double dData;
	Simpul* pBrktnya;
	Simpul(double dd):dData(dd),pBrktnya(NULL)
	{}
	void tampilSimpul(){
		cout<<dData<<" ";
	}
};//akhir kelas simpul

class SenaraiBerantaiGanda
{
private:
	Simpul* pPertama;
	Simpul* pAkhir;

public:
	SenaraiBerantaiGanda() : pPertama(NULL),pAkhir(NULL)//konstruktor
	{}
	~SenaraiBerantaiGanda()//destruktor
	{
		//(menghapus semua simpul)
		Simpul* pSkrg = pPertama;
		while(pSkrg!=NULL){
			Simpul* pTemp=pSkrg;
			pSkrg=pSkrg->pBrktnya;
			delete pTemp;
		}
	}
	bool apaKosong(){
		return pPertama==NULL;
	}
	void sisipAkhir(double dd){
		Simpul* pSimpulBaru=new Simpul(dd);
		if (apaKosong())
			pPertama=pSimpulBaru;
		else
			pAkhir->pBrktnya=pSimpulBaru;
		pAkhir=pSimpulBaru;
	}
	
	double hapusPertama(){
		Simpul* pTemp=pPertama;
		double temp = pPertama->dData;
			if (pPertama->pBrktnya==NULL)
				pAkhir=NULL;
			pPertama=pPertama->pBrktnya;
		delete pTemp;
		return temp;
	}

	void tampilSenarai(){
		Simpul* pSkrg=pPertama;
		while(pSkrg!=NULL){
			pSkrg->tampilSimpul();
			pSkrg=pSkrg->pBrktnya;
		}
		cout<<endl;
	}
};//akhir kelas SenaraiBerantaiGanda

class SenaraiAntrian
{
private:
	SenaraiBerantaiGanda senarai;
public:
	bool apaKosong(){
		return senarai.apaKosong();
	}
	void sisip(double j){
		senarai.sisipAkhir(j);
	}
	double hapus(){
		return senarai.hapusPertama();
	}
	void tampilAntrian(){
		cout<<"Antrian (depan->belakang):";
		senarai.tampilSenarai();
	}
};//akhir kelas SenaraiAntrian

int main()
{
	SenaraiAntrian antrian;
	antrian.sisip(20);
	antrian.sisip(40);
	antrian.tampilAntrian();
	antrian.sisip(30);
	antrian.sisip(80);
	antrian.tampilAntrian();
	cout<<"Menghapus dua item"<<endl;
	antrian.hapus();
	antrian.hapus();
	
	antrian.tampilAntrian();
	getch();
	return 0;
}

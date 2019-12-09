//senaraiBerantaiGandalengkap.cpp
//Mendemonstrasikan senarai berantai ganda 
#include <iostream> 
#include <conio.h> 
using namespace std; 
class Simpul{ 
	public: 
		double dData; //item data 
		Simpul* pBrktnya; //simpul berikutnya pada senarai 
		Simpul* pSblmnya; //simpul sbmnya pada senarai 

	public: 
		Simpul(double dd): //konstruktor 
		dData(dd), pBrktnya(NULL), pSblmnya(NULL) {} 
		void tampilSenarai() //menampilkan simpull 
		{ cout << dData << " "; } 
}; //akhir kelas Simpul 
class SenaraiBerantaiGanda
{
 private: 
 	Simpul* pPertama; //pointer ke item pertama 
 	Simpul* pAkhir; //pointer ke item terakhir 

 public: 
 	SenaraiBerantaiGanda() : //konstruktor 
 	pPertama(NULL), pAkhir(NULL)
 	{}
 	~SenaraiBerantaiGanda() //destruktor (menghapus simpul) 
 	{
 		Simpul* pSkrg = pPertama; //mulai diawal senaral 
 		while(pSkrg != NULL) //sampal akhir senaral, 
 		{
 		Simpul* pLama = pSkrg; 
 		pSkrg = pSkrg->pBrktnya; 
 		delete pLama;
 		}
 	}
 	 bool apaKosong() //true jika tidak ada simpul 
 	 {return pPertama==NULL;} 
 	 	//menyisipkan di awal senaral 
 	 	void sisipPertama(double dd)
 	 	{ 
 	 		Simpul* pSimpulBaru = new Simpul(dd); //menciptakan simpul baru 
 	 		if( apaKosong()) //jika senarai kosong, 
 	 			pAkhir = pSimpulBaru; 
 	 		else 
 	 			pPertama->pSblmnya = pSimpulBaru; 
 	 			pSimpulBaru->pBrktnya = pPertama; 
 	 			pPertama = pSimpulBaru; 
 	 	}
 	 	void sisipAkhir(double dd) //menyisipkan di akhir senarai 
 	 	{
 	 		Simpul* pSimpulBaru = new Simpul(dd); //menciptakan simpul baru 
 	 		if( apaKosong()) 
 	 			pPertama = pSimpulBaru; 
 	 		else 
 	 			pAkhir->pBrktnya = pSimpulBaru; 
 	 			pSimpulBaru->pSblmnya = pAkhir; 
 	 			pAkhir = pSimpulBaru; 
 	 	}
 	 	void hapusPertama() 
 	 	{//(asumsi senarai-kosong) 
 	 		Simpul* pTemp = pPertama;
 	 		if(pPertama->pBrktnya==NULL) 
 	 			pAkhir= NULL;
 	 		else
 	 			pPertama->pBrktnya->pSblmnya = NULL;
 	 			pPertama=pPertama->pBrktnya; 
 	 		delete pTemp;
 	 	}
 	 	void hapusAkhir()
 	 	{//(asumsi senarai-kosong) 
 	 		Simpul* pTemp = pAkhir; 
 	 		if(pPertama->pBrktnya == NULL) 
 	 			pPertama = NULL; 
 	 		else 
 	 			pAkhir->pSblmnya->pBrktnya = NULL; 
 	 		pAkhir=pAkhir->pSblmnya; 
 	 		delete pTemp; 
 	 	}
 	 	//menyisipkan tepat setelah kunci 
 	 	bool sisipSetelah(double kunci, double dd) 
 	 	{//(asumsi senarai-kosong) 
 	 		Simpul* pSkrg = pPertama; 
 	 		while(pSkrg->dData != kunci){
 	 			pSkrg = pSkrg->pBrktnya; 
 	 			if(pSkrg = NULL) 
 	 				return false; 
 	 		}
 	 		Simpul* pSimpulBaru = new Simpul(dd);
 	 		if(pSkrg==pAkhir){
 	 			pSimpulBaru->pBrktnya = NULL; 
 	 			pAkhir =pSimpulBaru;
 	 		}else{
 	 			pSimpulBaru->pBrktnya = pSkrg->pBrktnya;
 	 			pSkrg->pBrktnya->pSblmnya = pSimpulBaru;
 	 		}
 	 		pSimpulBaru->pSblmnya = pSkrg;
 	 		pSkrg->pBrktnya=pSimpulBaru;
 	 		return true;
 	 	}
 	 	bool hapusKunci(double kunci)
 	 	{//(asumsi senarai-kosong) 
 	 		Simpul* pSkrg = pPertama; 
 	 		while(pSkrg->dData != kunci) 
 	 			{
 	 				pSkrg = pSkrg->pBrktnya; 
 	 				if(pSkrg == NULL) 
 	 					return false; 
 	 			}
 	 			if(pSkrg==pPertama) 
 	 				pPertama = pSkrg->pBrktnya; 
 	 			else 
 	 				pSkrg->pSblmnya->pBrktnya = pSkrg->pBrktnya; 

 	 			if(pSkrg==pAkhir) 
 	 				pAkhir = pSkrg->pSblmnya; 
 	 			else 
 	 				pSkrg->pBrktnya->pSblmnya = pSkrg->pSblmnya; 
 	 			delete pSkrg; 
 	 			return true; 
 	 		}
 	 		void tampilMaju()
 	 		{ 
 	 			cout << "Senarai (pertama->akhir): ";
 	 			Simpul* pSkrg = pPertama;
 	 			while(pSkrg != NULL){
 	 				pSkrg->tampilSenarai(); 
 	 				pSkrg = pSkrg->pBrktnya;
 	 			}
 	 			cout <<endl;
 	 		}
 	 		void tampilMundur()
 	 		{
 	 			cout<<"Senarai (akhir->pertama): ";
 	 			Simpul* pSkrg=pAkhir;
 	 			while(pSkrg = NULL){
 	 				pSkrg->tampilSenarai();
 	 				pSkrg = pSkrg->pSblmnya;
 	 			}    
 	 			cout <<endl;
 	 		}
 	 	};//akhir kelas SenaraiBerantaiGanda 
 	 	int main(){
 	 		SenaraiBerantaiGanda senarai;	//menciptakan senarai baru
 	 		senarai.sisipPertama(22); //menyisipkan di depan 
 	 		senarai.sisipPertama(44); 
 	 		senarai.sisipPertama(66); 
 	 		senarai.sisipAkhir(11); //menyisipkan di belakang 
 	 		senarai.sisipAkhir(33); 
 	 		senarai.sisipAkhir(55); 
 	 		senarai.tampilMaju(); //menampilkan senarai secara maju 
 	 		senarai.tampilMundur(); //menampilkan senarai secara mundur 
 	 		cout << "Menghapus simpul pertama, simpul akhir, dan 11" << endl; 
 	 		senarai.hapusPertama(); 
 	 		senarai.hapusAkhir(); 
 	 		senarai.hapusKunci(11); 
 	 		senarai.tampilMaju(); //menampilkan senaral secara maju 
 	 		cout << "Menyisipkan 77 selelah simpul 22, dan 88 setelah 33" << endl; 
 	 		senarai.sisipSetelah(22, 77); 
 	 		senarai.sisipSetelah(33, 88); 
 	 		senarai.tampilMaju(); //menampilikan senarai secara maju 
 	 		getch(); 
 	 		return 0; 
 	 		}//akhir main()

//pohonBinerSeimbang.cpp
/*
 *  Program C++ untuk mengimplementasikan Pohon Pencarian Biner Seimbang
 */
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

/* Kelas Simpul_SBBST */

class Simpul_SBBST
{
    public:
        int tinggi, data;
        Simpul_SBBST *kiri, *kanan;

         /* Konstruktor */
         Simpul_SBBST()
         {
             kiri = NULL;
             kanan = NULL;
             data = 0;
             tinggi = 0;
         }

         /* Konstruktor */
         Simpul_SBBST(int n)
         {
             kiri = NULL;
             kanan = NULL;
             data = n;
             tinggi = 0;
         }
};

/*
 * Kelas PohonBSTSeimbang
 */

class PohonBSTSeimbang
{
    private:
        Simpul_SBBST *akar;
    public:
         /* Konstruktor */
         PohonBSTSeimbang()
         {
             akar = NULL;
         }

         /* Fungsi untuk memeriksa apakah pohon kosong */
         bool apaKosong()
         {
             return akar == NULL;
         }

         /* Membuat pohon kosong */
         void membuatKosong()
         {
             akar = NULL;
         }

         /* Fungsi untuk menyisipkan data */
         void sisip(int data)
         {
             akar = sisip(data, akar);
         }

         /* Fungsi untuk mendapatkan tinggi simpul */
         int tinggi(Simpul_SBBST *t)
         {
             return t == NULL ? -1 : t->tinggi;
         }

         /* Fungsi untuk mencari maks dari simpul kiri/kanan */
         int maks(int lhs, int rhs)
         {
             return lhs > rhs ? lhs : rhs;
         }

         /* Fungsi untuk menyisipkan data secara rekursif */
         Simpul_SBBST *sisip(int x, Simpul_SBBST *t)
         {
             if (t == NULL)
                 t = new Simpul_SBBST(x);

             else if (x < t->data)
             {
                 t->kiri = sisip(x, t->kiri);
                 if (tinggi(t->kiri) - tinggi(t->kanan) == 2)
                     if (x < t->kiri->data)
                         t = rotasiDenganAnakKiri(t);
                     else
                         t = doubleDenganAnakKiri(t);
             }

             else if (x > t->data)
             {
                 t->kanan = sisip(x, t->kanan);
                 if (tinggi(t->kanan) - tinggi(t->kiri) == 2)
                     if (x > t->kanan->data)
                         t = rotasiDenganAnakKanan(t);
                     else
                         t = doubleDenganAnakKanan(t);
             }
             t->tinggi = maks(tinggi(t->kiri), tinggi(t->kanan)) + 1;
             return t;
         }

         /* Merotasi simpul pohon biner dengan anak kiri */
         Simpul_SBBST *rotasiDenganAnakKiri(Simpul_SBBST* k2)
         {
             Simpul_SBBST *k1 = k2->kiri;
             k2->kiri = k1->kanan;
             k1->kanan = k2;
             k2->tinggi = maks(tinggi(k2->kiri), tinggi(k2->kanan)) + 1;
             k1->tinggi = maks(tinggi(k1->kiri), k2->tinggi) + 1;
             return k1;
         }

         /* Merotasi simpul pohon biner dengan anak kanan */
         Simpul_SBBST *rotasiDenganAnakKanan(Simpul_SBBST *k1)
         {
             Simpul_SBBST *k2 = k1->kanan;
             k1->kanan = k2->kiri;
             k2->kiri = k1;
             k1->tinggi = maks(tinggi(k1->kiri), tinggi(k1->kanan)) + 1;
             k2->tinggi = maks(tinggi(k2->kanan), k1->tinggi) + 1;
             return k2;
         }

         /*
          * Merotasi ganda pohon biner: pertama-tama anak kiri
          * dengan anak kanannya; kemudian simpul k3 dengan anak kiri baru
          */
         Simpul_SBBST *doubleDenganAnakKiri(Simpul_SBBST *k3)
         {
             k3->kiri = rotasiDenganAnakKanan(k3->kiri);
             return rotasiDenganAnakKiri(k3);
         }

               /*
          * Merotasi ganda pohon biner: pertama-tama anak kanan
          * dengan anak kirinya; kemudian simpul k1 dengan anak kanan baru
          */

         Simpul_SBBST *doubleDenganAnakKanan(Simpul_SBBST *k1)
         {
             k1->kanan = rotasiDenganAnakKiri(k1->kanan);
             return rotasiDenganAnakKanan(k1);
         }

         /* Fungsi untuk menghitung jumlah simpul */
         int hitungSimpul()
         {
             return hitungSimpul(akar);
         }

         int hitungSimpul(Simpul_SBBST *r)
         {
             if (r == NULL)
                 return 0;
             else
             {
                 int l = 1;
                 l += hitungSimpul(r->kiri);
                 l += hitungSimpul(r->kanan);
                 return l;
             }
         }

         /* Fungsi untuk melakukan pencarian thd suatu elemen */
         bool cari(int nil)
         {
             return cari(akar, nil);
         }

         bool cari(Simpul_SBBST *r, int nil)
         {
             bool ditemukan = false;
             while ((r != NULL) && !ditemukan)
             {
                 int nilaiKanan = r->data;

                 if (nil < nilaiKanan)
                     r = r->kiri;
                 else if (nil > nilaiKanan)
                     r = r->kanan;
                 else
                 {
                     ditemukan = true;
                     break;
                 }
                 ditemukan = cari(r, nil);
             }
             return ditemukan;
         }

         /* Fungsi untuk penjelajahan inorder */
         void inorder()
         {
             inorder(akar);
         }

         void inorder(Simpul_SBBST *r)
         {
             if (r != NULL)
             {
                 inorder(r->kiri);
                 cout<<r->data<<"  ";
                 inorder(r->kanan);
             }
         }

         /* Fungsi untuk penjelajahan preorder */
         void preorder()
         {
             preorder(akar);
         }

         void preorder(Simpul_SBBST *r)
         {
             if (r != NULL)
             {
                 cout<<r->data<<"  ";
                 preorder(r->kiri);
                 preorder(r->kanan);
             }
         }

         /* Fungsi untuk penjelajahan postorder */
         void postorder()
         {
             postorder(akar);
         }

         void postorder(Simpul_SBBST *r)
         {
             if (r != NULL)
             {
                 postorder(r->kiri);
                 postorder(r->kanan);
                 cout<<r->data<<"  ";
             }
         }
};

int main()
{
    PohonBSTSeimbang sbbst;
    cout<<"Uji Pohon BST Seimbang\n";
    int nil;
    char ch;

    /*  Melakukan operasi-operasi pohon  */
    do
    {
        cout<<"\nOperasi-Operasi Pohon BST Seimbang\n";
        cout<<"1. Sisip "<<endl;
        cout<<"2. Hitung Simpul"<<endl;
        cout<<"3. Cari"<<endl;
        cout<<"4. Periksa Kosong"<<endl;
        cout<<"5. Membuat Kosong"<<endl;

        int pilihan;
        cout<<"Masukkan pilihan Anda: ";
        cin>>pilihan;

        switch (pilihan)
        {
        case 1 :
            cout<<"Masukkan elemen integer yang akan disisipkan: ";
            cin>>nil;
            sbbst.sisip(nil);
            break;

        case 2 :
            cout<<"Simpul = " <<sbbst.hitungSimpul()<<endl;
            break;

        case 3:
            cout<<"Masukkan elemen integer yang akan dicari: ";
            cin>>nil;

            if (sbbst.cari(nil))
                cout<<nil<<" ditemukan di dalam pohon"<<endl;
            else
                cout<<nil<<" tidak ditemukan"<<endl;
            break;

        case 4 :
            cout<<"Status kosong = ";
            if (sbbst.apaKosong())
                cout<<"Pohon kosong"<<endl;
            else
                cout<<"Pohon tidak kosong"<<endl;
            break;

        case 5 :
            cout<<"\nPohon dikosongkan\n";
            sbbst.membuatKosong();
            break;

        default :
            cout<<"Entri salah \n ";
            break;
        }

        /*  Menampilkan pohon*/
        cout<<"\nPost order : ";
        sbbst.postorder();
        cout<<"\nPre order : ";
        sbbst.preorder();
        cout<<"\nIn order : ";
        sbbst.inorder();
        cout<<"\nAnda ingin melanjutkan (Ketik y atau t): ";
        cin>>ch;
    }
    while (ch == 'Y'|| ch == 'y');

    getch();
    return 0;
}

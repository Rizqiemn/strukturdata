//pohonAVL
/*
 * Program C++ untuk mengimplementasikan pohon AVL
 */
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<conio.h>

#define pow2(n) (1 << (n))
using namespace std;

/*
 * Deklarasi Simpul
 */
struct simpulAVL
{
    int data;
    struct simpulAVL *kiri;
    struct simpulAVL *kanan;
}*akar;

/*
 * Deklarasi kelas
 */
class PohonAVL
{
    public:
        int tinggi(simpulAVL *);
        int selisih(simpulAVL *);
        simpulAVL *rotasi_rr(simpulAVL *);
        simpulAVL *rotasi_ll(simpulAVL *);
        simpulAVL *rotasi_lr(simpulAVL *);
        simpulAVL *rotasi_rl(simpulAVL *);
        simpulAVL* setimbang(simpulAVL *);
        simpulAVL* sisip(simpulAVL *, int );
        void tampil(simpulAVL *, int);
        void inorder(simpulAVL *);
        void preorder(simpulAVL *);
        void postorder(simpulAVL *);
        PohonAVL()
        {
            akar = NULL;
        }
};

/*
 * Program penguji
 */
int main()
{
    int pilihan, item;
    PohonAVL avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"Implementasi Pohon AVL"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Sisipkan elemen ke dalam pohon"<<endl;
        cout<<"2.Tampilkan Pohon AVL Seimbang"<<endl;
        cout<<"3.Penjelajahan InOrder"<<endl;
        cout<<"4.Penjelajahan PreOrder"<<endl;
        cout<<"5.Penjelajahan PostOrder"<<endl;
        cout<<"6.Keluar"<<endl;
        cout<<"Masukkan pilihan Anda: ";

        cin>>pilihan;
        switch(pilihan)
        {
        case 1:
            cout<<"Masukkan nilai yang akan disisipkan: ";
            cin>>item;
            akar = avl.sisip(akar, item);
            break;
        case 2:
            if (akar == NULL)
            {
                cout<<"Pohon kosong"<<endl;
                continue;
            }
            cout<<"Pohon AVL Seimbang:"<<endl;
            avl.tampil(akar, 1);
            break;
        case 3:
            cout<<"Penjelajahan Inorder:"<<endl;
            avl.inorder(akar);
            cout<<endl;
            break;
        case 4:
            cout<<"Penjelajahan Preorder:"<<endl;
            avl.preorder(akar);
            cout<<endl;
            break;
        case 5:
            cout<<"Penjelajahan Postorder:"<<endl;
            avl.postorder(akar);   
            cout<<endl;
            break;
        case 6:
            exit(1);   
            break;
        default:
            cout<<"Pilihan Salah"<<endl;
        }
    }

    getch();
    return 0;
}

/*
 * Tinggi Pohon AVL
 */
int PohonAVL::tinggi(simpulAVL *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int tinggiL = tinggi (temp->kiri);
        int tinggiR = tinggi (temp->kanan);
        int tinggiMaks = max (tinggiL, tinggiR);
        h = tinggiMaks + 1;
    }
    return h;
}

/*
 * Selisih tinggi
 */
int PohonAVL::selisih(simpulAVL *temp)
{
    int tinggiL = tinggi (temp->kiri);
    int tinggiR = tinggi (temp->kanan);
    int faktorB= tinggiL - tinggiR;
    return faktorB;
}

/*
 * RotasiRR
 */
simpulAVL *PohonAVL::rotasi_rr(simpulAVL *induk)
{
    simpulAVL *temp;
    temp = induk->kanan;
    induk->kanan = temp->kiri;
    temp->kiri = induk;
    return temp;
}
/*
 * Rotasi LL
 */
simpulAVL *PohonAVL::rotasi_ll(simpulAVL *induk)
{
    simpulAVL *temp;
    temp = induk->kiri;
    induk->kiri = temp->kanan;
    temp->kanan = induk;
    return temp;
}

/*
 * Rotasi LR
 */
simpulAVL *PohonAVL::rotasi_lr(simpulAVL *induk)
{
    simpulAVL *temp;
    temp = induk->kiri;
    induk->kiri = rotasi_rr (temp);
    return rotasi_ll (induk);
}

/*
 * Rotasi RL
 */
simpulAVL *PohonAVL::rotasi_rl(simpulAVL *induk)
{
    simpulAVL *temp;
    temp = induk->kanan;
    induk->kanan = rotasi_ll (temp);
    return rotasi_rr (induk);
}

/*
 * Menyeimbangkan Pohon AVL
 */
simpulAVL *PohonAVL::setimbang(simpulAVL *temp)
{
    int faktor_seimbang = selisih (temp);
    if (faktor_seimbang > 1)
    {
        if (selisih (temp->kiri) > 0)
            temp = rotasi_ll (temp);
        else
            temp = rotasi_lr (temp);
    }
    else if (faktor_seimbang < -1)
    {
        if (selisih (temp->kanan) > 0)
            temp = rotasi_rl (temp);
        else
            temp = rotasi_rr (temp);
    }
    return temp;
}

/*
 * Menyisipkan elemen ke dalam pohon
 */
simpulAVL *PohonAVL::sisip(simpulAVL *akar, int nilai)
{
    if (akar == NULL)
    {
        akar = new simpulAVL;
        akar->data = nilai;
        akar->kiri = NULL;
        akar->kanan = NULL;
        return akar;
    }
    else if (nilai < akar->data)
    {
        akar->kiri = sisip(akar->kiri, nilai);
        akar = setimbang (akar);
    }
    else if (nilai >= akar->data)
    {
        akar->kanan = sisip(akar->kanan, nilai);
        akar = setimbang (akar);
    }
    return akar;
}

/*
 * Menampilkan Pohon AVL
 */
void PohonAVL::tampil(simpulAVL *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        tampil(ptr->kanan, level + 1);
        printf("\n");
        if (ptr == akar)
        cout<<"Akar -> ";
        for (i = 0; i < level && ptr != akar; i++)
            cout<<"        ";
        cout<<ptr->data;
        tampil(ptr->kiri, level + 1);
    }
}

/*
 * Penjelajahan Inorder atas pohon AVL
 */
void PohonAVL::inorder(simpulAVL *pohon)
{
    if (pohon == NULL)
        return;
    inorder (pohon->kiri);
    cout<< pohon->data<<"  ";
    inorder (pohon->kanan);
}
/*
 * Penjelajahan Preorder atas pohon AVL 
 */
void PohonAVL::preorder(simpulAVL * pohon)
{
    if (pohon == NULL)
        return;
    cout<< pohon->data<<"  ";
    preorder (pohon->kiri);
    preorder (pohon->kanan);

}

/*
 * Penjelajahan Postorder atas pohon AVL
 */
void PohonAVL::postorder(simpulAVL *pohon)
{
    if (pohon == NULL)
        return;
    postorder (pohon ->kiri );
    postorder (pohon ->kanan );
    cout<< pohon ->data<<"  ";
}

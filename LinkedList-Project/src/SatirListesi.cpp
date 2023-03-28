/*
* @file             SatirListesi.cpp
* @description      SatirListesi sinifinin fonksiyonlarini bulunduruyor
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
using namespace std;


SatirListesi::SatirListesi()
{
    ilk = 0;
    ortalama = 0;
    sutunSayisi = 0;
    sonraki = 0;
    onceki = 0;

}


SatirListesi :: ~SatirListesi()
{
    cout << this << ": adresindeki dugum silindi" << endl;

}


Dugum* SatirListesi::dugumGetir(int sira)
{
    Dugum* gecici = ilk;

    while (sira >= 0 && gecici != 0)
    {

        if (sira == 0)
            return gecici;

        gecici = gecici->sonraki;

        sira--;

    }

    return 0;

}


void SatirListesi::ekle(int veri)
{
    Dugum* yeniDugum = new Dugum(veri);

    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        Dugum* gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }

}


void SatirListesi::yazdir(int index/*, SatirListesi** liste*/)
{
    Dugum* gecici = ilk;

    cout << endl;
    cout << setw(index * 14) << "" << setw(10) << " ^^^^^^^^^^^    " << endl;


    while (gecici != 0)
    {
        cout << setw(index * 14) << " " << " " << setw(10) << gecici << endl;
        cout << setw(index * 14) << " " << " " << "----------" << endl;
        cout << setw(index * 14) << " " << " " << "|" << setw(5) << gecici->veri << setw(3) << " " << setw(1) << "|" << endl;
        cout << setw(index * 14) << " " << " " << "----------" << endl;
        cout << setw(index * 14) << " " << " " << setw(10) << gecici->sonraki << endl;
        cout << setw(index * 14) << " " << " " << "----------" << endl;
        cout << setw(index * 14) << " " << " " << endl;

        gecici = gecici->sonraki;

    }
    
}


void SatirListesi::listeSil()
{
    Dugum* gec = ilk;
    while (gec != 0)
    {
        Dugum* silinecek = gec;
        gec = gec->sonraki;

        delete silinecek;
    }

}


void SatirListesi::rastgeleSil(int dizi, SatirListesi** liste)
{
    
    srand(time(NULL));
    int rastgele;
    rastgele = rand()%liste[dizi]->sutunSayisi;
    

    Dugum* silinecek = dugumGetir(rastgele);

    if (silinecek)
    {

        Dugum* silinecekOnceki = silinecek->onceki;
        Dugum* silinecekSonraki = silinecek->sonraki;

        if (silinecekSonraki)
            silinecekSonraki->onceki = silinecekOnceki;

        if (silinecekOnceki)
            silinecekOnceki->sonraki = silinecekSonraki;

        else
            ilk = silinecekSonraki;
        delete silinecek;

    }

}

/*
* @file 					Doku.cpp
* @description 				Bagli liste ile hucreleri gruplandirir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#include "Doku.hpp"
#include <iostream>
#include<iomanip>
using namespace std;


Doku::Doku()
{
    ilk = 0;
    sutunSayisi = 0;


}

Doku::Doku(int veri)
{
    this->veri = veri;
    sol = sag = 0;
}


Doku :: ~Doku()
{


}


void Doku::ekle(int veri)
{
    Hucre* yeniDugum = new Hucre(veri);

    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        Hucre* gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }

}


int* Doku::diziYap(int sutunSayisi)
{
    Hucre* gecici = ilk;

    int *dizi = new int[sutunSayisi];

    int sayac = 0;

  
    for (int i = 0; gecici != 0; i++,gecici=gecici->sonraki)
    {
        dizi[i] = gecici->veri;

    }

    return dizi;


}



#include "Organ.hpp"
#include <iomanip>
#include<iostream>
#include<cmath>
using namespace std;

Organ::Organ()
{
    kok = 0;

}

Organ::~Organ()
{

}

void Organ::ekle(int eklenecek)
{
    if (kok == 0)
        kok = new Doku(eklenecek);
    else
        ekle(eklenecek, kok);
}


void Organ::preOrder() {
    preOrder(kok);
    cout << endl;
}


void Organ::preOrder(Doku* aktif)
{
    if (aktif)
    {
        cout << aktif->veri << "  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}



void Organ::ekle(int veri, Doku* aktifDugum)
{
    if (aktifDugum->veri > veri || aktifDugum->veri == veri)
    {
        if (aktifDugum->sol)
            ekle(veri, aktifDugum->sol);
        else
            aktifDugum->sol = new Doku(veri);
    }
    else if (aktifDugum->veri < veri)
    {
        if (aktifDugum->sag)
            ekle(veri, aktifDugum->sag);
        else
            aktifDugum->sag = new Doku(veri);
    }
    else
        return;
}


ostream& operator<<(ostream& os, Organ& agac)
{
  
    agac.preOrder();

    return os;
}


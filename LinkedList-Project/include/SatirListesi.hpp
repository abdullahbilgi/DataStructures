/*
* @file             SatirListesi.hpp
* @description      SatirListesi sinifinin baslik dosyasi
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include<exception>
#include<iostream>
#include "Dugum.hpp"


class SatirListesi
{
public:
    int sutunSayisi;
    int toplamSatirSayisi;
    float ortalama;
    SatirListesi();
    ~SatirListesi();
    void listeSil();
    Dugum* dugumGetir(int sira);
    void yazdir(int index/*, SatirListesi** liste*/);
    void ekle(int veri);
    void rastgeleSil(int dizi, SatirListesi** liste);

    SatirListesi* onceki;
    SatirListesi* sonraki;


private:

    Dugum* ilk;

};


#endif
/*
* @file             YoneticiListesi.hpp
* @description      YoneticiListesi sinifinin baslik dosyasi
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include<exception>
#include<iostream>
#include "SatirListesi.hpp"


class YoneticiListesi
{
public:
    int dugumSayisi;
    YoneticiListesi();
    ~YoneticiListesi();
    SatirListesi* dugumGetir(int sira);
    void ekle(SatirListesi adres);
    void yazdir(int baslangic);
    void cikar(int index);


private:
    SatirListesi* ilk;

};


#endif
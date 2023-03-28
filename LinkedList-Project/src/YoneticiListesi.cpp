/*
* @file             YoneticiListesi.cpp
* @description      YoneticiListesi sinifinin fonksiyonlarini bulunduruyor
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"
#include <iostream>
#include<iomanip>
using namespace std;


YoneticiListesi::YoneticiListesi() 
{

    ilk = 0;
    dugumSayisi = 0;
}


YoneticiListesi :: ~YoneticiListesi()
{
    cout << this << ": adresindeki dugum silindi" << endl;

}


SatirListesi* YoneticiListesi::dugumGetir(int sira)
{
    SatirListesi* gecici = ilk;

    while (sira >= 0 && gecici != 0)
    {

        if (sira == 0)
            return gecici;

        gecici = gecici->sonraki;

        sira--;

    }

    return 0;

}


void YoneticiListesi::ekle(SatirListesi adres)
{

    SatirListesi* yeniDugum = new SatirListesi(adres);

    if (ilk == 0)
    {
        ilk = yeniDugum;
    }
    else
    {
        SatirListesi* gec = ilk;

        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
    }

}


void YoneticiListesi::yazdir(int baslangic)
{
    

        SatirListesi* gecici = ilk;

         if (baslangic != 0)
        {
            for (int i = 0; i < 8*baslangic; i++)
            {

                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8&& gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(14) << std::left << gecici;
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {

                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8&& gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(14) << std::left << "-----------";
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {
                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << std::left << setw(1) << "|" << setw(9) << gecici->onceki << setw(1) << "|" << setw(3) << " ";
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {

                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(14) << std::left << "-----------";
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8*baslangic; i++)
            {
                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(2) << " " << setw(12) << gecici->ortalama;
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {

                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(14) << std::left << "-----------";
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {
                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << std::left << setw(1) << "|" << setw(9) << gecici->sonraki << setw(1) << "|" << setw(3) << " ";
        }
        cout << endl;

        gecici = ilk;

        if (baslangic != 0)
        {
            for (int i = 0; i < 8 * baslangic; i++)
            {

                gecici = gecici->sonraki;
            }

        }

        cout << " ";

        for (int i = 0; i < 8 && gecici != 0; gecici = gecici->sonraki, i++) {

            cout << setw(14) << std::left << "-----------";
        }
        cout << endl;

}


void YoneticiListesi::cikar(int index)
{

    SatirListesi* silinecek = dugumGetir(index);

    if (silinecek)
    {

        SatirListesi* silinecekOnceki = silinecek->onceki;
        SatirListesi* silinecekSonraki = silinecek->sonraki;

        if (silinecekSonraki)
            silinecekSonraki->onceki = silinecekOnceki;
        
        if (silinecekOnceki)
            silinecekOnceki->sonraki = silinecekSonraki;

        else
            ilk = silinecekSonraki;
        delete silinecek;
    }
}

/*
* @file             Dugum.hpp
* @description      Dugum sinifinin baslik dosyasi
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include<iostream>
using namespace std;


class Dugum
{
    public:
        Dugum(int veri);
        ~Dugum();
        int veri;
        Dugum* sonraki;
        Dugum* onceki;

};

#endif
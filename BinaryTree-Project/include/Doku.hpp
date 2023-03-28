/*
* @file 					Doku.hpp
* @description 				Doku sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef Doku_hpp
#define Doku_hpp
#include<exception>
#include<iostream>
#include "Hucre.hpp"


class Doku
{
public:
    int sutunSayisi;
    int veri;
    
    Doku();
    Doku(int veri);
    ~Doku();
   
    void ekle(int veri);
    int* diziYap(int sutunSayisi);

    Doku* sol;
    Doku* sag;


private:

    Hucre* ilk;

};


#endif
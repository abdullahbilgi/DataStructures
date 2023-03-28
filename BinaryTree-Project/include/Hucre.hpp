/*
* @file 					Hucre.hpp
* @description 				Hucre sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef Hucre_hpp
#define Hucre_hpp
#include<iostream>
using namespace std;


class Hucre
{
public:
    Hucre(int veri);
    ~Hucre();
    int veri;
    Hucre* sonraki;
    Hucre* onceki;

};

#endif
/*
* @file             Dugum.cpp
* @description      Dugum sinifi fonksiyonlarını bulunduruyor
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum :: Dugum(int veri){
    this -> veri = veri;

    onceki = sonraki = 0;

}

Dugum :: ~Dugum(){

    cout << this << ": adresindeki dugum silindi" << endl;
}


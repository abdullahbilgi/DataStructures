/*
* @file 					Kontrol.hpp
* @description 				Kontrol sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef Kontrol_hpp
#define Kontrol_hpp
#include<iostream>
#include<cmath>
#include<iomanip>
#include"Organizma.hpp"
#include"Radix.hpp"

using namespace std;


class Kontrol
{
	public:
		Kontrol();
		~Kontrol();
		void mutasyonYap(int toplamSatirSayisi,int* organDugumleri,Doku** doku,int** siraliDokular,Organ* organ,int sayac,int organSayisi);
		void mutasyonYazdir(int organSayisi, Organ* organ);
		bool isBalanced(Doku* root);
		int height(Doku* root);

};

#endif
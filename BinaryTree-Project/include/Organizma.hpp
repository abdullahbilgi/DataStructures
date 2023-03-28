/*
* @file 					Organizma.hpp
* @description 				Organizma sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef Organizma_hpp
#define Organizma_hpp
#include<iostream>
#include<cmath>
#include<iomanip>
#include"Organ.hpp"
using namespace std;


class Organizma
{
	public:
		Organizma();
		~Organizma();
		void yazdir(int organSayisi,Organ* organ);
		bool isBalanced(Doku* root);
		int height(Doku* root);

};

#endif
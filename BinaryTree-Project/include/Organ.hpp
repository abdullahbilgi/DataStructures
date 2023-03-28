/*
* @file 					Organ.hpp
* @description 				Organ sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef Organ_hpp
#define organ_hpp

#include<iostream>
#include "Doku.hpp"
using namespace std;

class Organ
{
	public:

		Organ();
		~Organ();
		
		void ekle(int veri);
		friend ostream& operator<<(ostream& os, Organ& kuyruk);
		void preOrder();
		Doku* kok;



	private:

		void preOrder(Doku* aktif);
		void ekle(int veri, Doku* aktifDugum);
		
};

#endif


/*
* @file 					TestProgrami.cpp
* @description 				Main class'idir.Organizmayı olusturur.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include "Radix.hpp"
#include"Kontrol.hpp"


using namespace std;

int main()
{

	fstream okunacakDosya;
	okunacakDosya.open("Veri.txt", ios::in);//toplam satir sayisi bulundu
	int satir = 0;
	if (okunacakDosya.is_open())
	{

		string veri;
		while (getline(okunacakDosya, veri))
		{
			satir++;
		}


		okunacakDosya.close();
	}



	int toplamSatirSayisi = satir;
	int organSayisi = satir / 20;
	int sistemsayisi = organSayisi / 100;


	Doku** doku = new Doku * [satir];

	
	okunacakDosya.open("Veri.txt", ios::in);//veriler okunup dokular olusturukldu
	if (okunacakDosya.is_open())
	{
		string veri;
		satir = 0;
		while (getline(okunacakDosya, veri))
		{
			if (veri.empty())
				continue;

			istringstream iss(veri);
			
			int siradaki = 0;

			doku[satir] = new Doku();

			while (iss >> siradaki)
			{

				doku[satir]->ekle(siradaki);

				doku[satir]->sutunSayisi++;

			}


			satir++;


		}
		okunacakDosya.close();

	}



	int** tumDokular = new int* [toplamSatirSayisi];


	for (int i = 0; i < toplamSatirSayisi; i++)//dokular bagli listeden diziye cekildi
	{
		tumDokular[i] = doku[i]->diziYap(doku[i]->sutunSayisi);

	}


	int** siraliDokular = new int* [toplamSatirSayisi];

	for (int i = 0; i < toplamSatirSayisi; i++)//hucreler radix kullanilarak siralandi
	{
		Radix* radix = new Radix(tumDokular[i], doku[i]->sutunSayisi);

		siraliDokular[i] = radix->Sort();

		delete radix;
	}



	int* organDugumleri = new int[toplamSatirSayisi];

	for (int i = 0; i < toplamSatirSayisi; i++)//bst ye eklenecek hucreler bulunarak tek dizi yapildi
	{
		organDugumleri[i] = (siraliDokular[i][doku[i]->sutunSayisi/2]);
	}



	Organ* organ = new Organ[organSayisi];


	int sayac = 0;

	for (int i = 0; i < organSayisi; i++)//organlar olusturuldu
	{

		for (int j = 0; j < 20; j++)
		{
			organ[i].ekle(organDugumleri[sayac]);
			sayac++;
		}

	}


	Organizma o;

	Kontrol k;

   sayac = 0;


	o.yazdir(organSayisi, organ);

	k.mutasyonYap(toplamSatirSayisi,organDugumleri,doku,siraliDokular,organ,sayac,organSayisi);


	char a;
	a = getchar();

	system("cls");

	if (a == 10)
	{
		k.mutasyonYazdir(organSayisi, organ);
	}
	else
	{
		;
	}




	for (int i = 0; i < toplamSatirSayisi; i++)//heap den alinan alanlar serbest birakildi
	{
		delete doku[i];
		delete tumDokular[i];
		delete siraliDokular[i];
	}

	delete [] organ;
	delete[] organDugumleri;
	delete doku;
	delete tumDokular;
	delete siraliDokular;
	

	return 0;
}
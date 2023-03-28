/*
* @file 					Kontrol.cpp
* @description 				Organizmayı mutasyon yaptırır.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#include"Kontrol.hpp"

Kontrol::Kontrol()
{

}
Kontrol::~Kontrol()
{

}

bool Kontrol::isBalanced(Doku* root)
{
    if (root == nullptr) return true;

    int heightLeft = height(root->sol);
    int heightRight = height(root->sag);

    if (abs(heightLeft - heightRight) <= 1 && isBalanced(root->sol) && isBalanced(root->sag))
        return true;

    return false;
}

int Kontrol::height(Doku* root)
{
    if (root == nullptr) return 0;
    return 1 + max(height(root->sol), height(root->sag));
}

void Kontrol::mutasyonYap(int toplamSatirSayisi,int* organDugumleri,Doku** doku,int** siraliDokular,Organ* organ,int sayac,int organSayisi)
{
    for (int i = 0; i < toplamSatirSayisi; i+=20)
	{

		if(organDugumleri[i] % 50 == 0)
		{

			for (int j = i; j < i+20; j++)
			{

				for (int k = 0; k < doku[j]->sutunSayisi; k++)
				{

					if (siraliDokular[j][k] % 2 == 0)
					{
						siraliDokular[j][k] = (siraliDokular[j][k] / 2);
					}
					else
					{
						;
					}

				}

			}

		}
		else
		{
			;
		}
	}


	for (int i = 0; i < toplamSatirSayisi; i++)
	{
		Radix* radix = new Radix(siraliDokular[i], doku[i]->sutunSayisi);

		siraliDokular[i] = radix->Sort();

		delete radix;
	}
	


	for (int i = 0; i < toplamSatirSayisi; i++)
	{
		organDugumleri[i] = (siraliDokular[i][doku[i]->sutunSayisi / 2]);
	}




	for (int i = 0; i < organSayisi; i++)
	{

		for (int j = 0; j < 20; j++)
		{
			organ[i].ekle(organDugumleri[sayac]);
			sayac++;
		}

	}
}


void Kontrol::mutasyonYazdir(int organSayisi, Organ* organ)
{
   
    cout << setw(44) << "ORGANIZMA (MUTASYONA UGRADI)" << endl;

    for (int i = 0; i < organSayisi; i++)
    {

        if (i % 100 == 0) cout << endl;

        if (isBalanced(organ[i].kok))
        {
            cout << " ";
        }
        else
        {
            cout << "#";
        }

    }

}
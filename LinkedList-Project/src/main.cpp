/*
* @file             main.cpp
* @description      Projedeki diger siniflari kullaniyor ve kullanici arayuzu olusturuyor
* @course           Veri Yapıları / 1C
* @assignment       Odev1
* @date             05.11/2022
* @author           Abdullah Bilgi / b221210350@sakarya.edu.tr
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
using namespace std;


int main()
{

    YoneticiListesi* y_liste = new YoneticiListesi();

    fstream okunacakDosya;
    okunacakDosya.open("veriler.txt", ios::in);
    int s_sayac = 0;
    if (okunacakDosya.is_open())
    {

        string veri;
        while (getline(okunacakDosya, veri))
        {
            s_sayac++;
        }
        okunacakDosya.close();
    }


    SatirListesi** s_liste = new SatirListesi * [s_sayac];

    int toplamSatirSayisi = s_sayac;

    
    okunacakDosya.open("veriler.txt", ios::in);
    if (okunacakDosya.is_open())
    {
        string veri;
        s_sayac = 0;
        while (getline(okunacakDosya, veri))
        {
            if (veri.empty())
                continue;

            istringstream iss(veri);
            int toplam = 0;
            int siradaki = 0;

            s_liste[s_sayac] = new SatirListesi();

            while (iss >> siradaki)
            {
                toplam += siradaki;

                s_liste[s_sayac]->ekle(siradaki); 
                
                s_liste[s_sayac]->sutunSayisi++;

            }

            s_liste[s_sayac]->ortalama = (toplam / (float)(s_liste[s_sayac]->sutunSayisi)); 


            s_sayac++;

          
        }
        okunacakDosya.close();

    }



    SatirListesi* temp;

    for (int i = 0; i < toplamSatirSayisi; i++)//YoneticiListesine ortalama sırasına göre sıralanyor 
    {
        for (int j = 0; j < toplamSatirSayisi - 1; j++) 
        {
            if (s_liste[j]->ortalama > s_liste[j + 1]->ortalama)
            {
                temp = s_liste[j];
                s_liste[j] = s_liste[j+1];
                s_liste[j + 1] = temp;
            }

        }
    }

    


    for (int i = 0; i < toplamSatirSayisi; i++) // nesneler YoneticiListesine ataniyor
    {
        y_liste->ekle(*s_liste[i]);
    }


    
    int deger=0;
    
    if (toplamSatirSayisi % 8 == 0)
    {
        deger = toplamSatirSayisi / 8;
    }
    else
    {
        deger = toplamSatirSayisi / 8 + 1;
    }


    
    int index = 0;
    int baslangic = 0;
    int dizi = 0;

    while (true)
    {
        system("cls");


        y_liste->yazdir(baslangic);

        s_liste[dizi]->yazdir(index);


        char ch;
        cin >> ch;

        if (ch == 'a')
        {
            
            if(baslangic > 0)
            {
                baslangic--;
                dizi -= 8;
            }
            
        }
        else if (ch == 'd')
        {
            if (baslangic < deger-1)
            {
                baslangic++;
                dizi += 8;
            }
            else
                baslangic = deger-1;
           
            
        }
        else if (ch == 'c')
        {
            
            if (index < 7)
            {
                index++;
                dizi++;
            }

        }
        else if (ch == 'z') {

            
            if (index > 0) {
                index--;
                dizi--;
            }

        }
        else if (ch == 'p')
        {
            s_liste[dizi]->listeSil();

            y_liste->cikar(dizi);
            

            for(int i =dizi;i<toplamSatirSayisi;i++)
            {
                s_liste[i] = s_liste[i + 1];
            }

            toplamSatirSayisi--;

        }
        else if (ch == 'k')
        {
            char chr;
            cin >> chr;

            if (chr == 'k')
            {


                s_liste[dizi]->rastgeleSil(dizi,&s_liste[dizi]);

                if (s_liste[dizi]->sutunSayisi == 1)
                {
                    y_liste->cikar(dizi);

                    for (int i = dizi; i < toplamSatirSayisi; i++)
                    {
                        s_liste[i] = s_liste[i + 1];
                    }

                    toplamSatirSayisi--;

                }

                s_liste[dizi]->sutunSayisi--;


               
            }
            else
            {
                continue;
            }


        }
        else
        {
            ;
        }

    }

    return 0;
}

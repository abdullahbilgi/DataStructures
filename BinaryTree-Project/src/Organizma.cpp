/*
* @file 					Organizma.cpp
* @description 				Organizmayı olusturmaya yarayan onksiyonlar vardir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#include "Organizma.hpp"

Organizma::Organizma()
{

}
Organizma::~Organizma()
{

}


bool Organizma::isBalanced(Doku* root)
{
    if (root == nullptr) return true;

    int heightLeft = height(root->sol);
    int heightRight = height(root->sag);

    if (abs(heightLeft - heightRight) <= 1 && isBalanced(root->sol) && isBalanced(root->sag))
        return true;

    return false;
}

int Organizma::height(Doku* root)
{
    if (root == nullptr) return 0;
    return 1 + max(height(root->sol), height(root->sag));
}

void Organizma::yazdir(int organSayisi,Organ* organ)
{

    cout << setw(25) << "ORGANIZMA" << endl;

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



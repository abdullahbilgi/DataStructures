/*
* @file 					Radix.hpp
* @description 				Radix sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <cmath>

class Radix {
private:
	int* numbers;
	int length;
	Queue ** queues;
	int maxStep;

	int MaxStepNumber();
	int StepCount(int);
	int* QueueCurrentLengths();
public:
	Radix(int*, int);
	int* Sort();
	~Radix();
};

#endif
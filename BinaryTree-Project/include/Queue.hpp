/*
* @file 					Queue.hpp
* @description 				Queue sinifinin baslik dosyasidir.
* @course 					Veri Yapilari - 1C
* @assignment 				Odev2
* @date 					07/12/2022
* @author 					Abdullah Bilgi - B221210350@sakarya.edu.tr
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;


class Queue
{
	public:
		Queue();
		void clear();
		int count()const;
		bool isEmpty() const;
		const int& peek() {
			if (isEmpty()) throw "Empty List";
			return items[front];
		}
		void enqueue(const int& item);
		void dequeue();
		~Queue();



	private:
		int front;
		int back;
		int capacity;
		int length;
		int* items;

		void reserve(int newCapacity);

};

#endif


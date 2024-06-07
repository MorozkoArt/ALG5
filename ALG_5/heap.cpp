#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(int* mass, int y, int y_next)
{
	int h = mass[y];
	mass[y] = mass[y_next];
	mass[y_next] = h;
}

void ascent(int* mass, int number_of_links) {
	int n = 1;
	for (int i = 0; i < number_of_links; i++) {
		int q = i;
		while (mass[q] > mass[(q - 1) / 2]) {
			swap(mass, q, (q - 1) / 2);
			q = (q - 1) / 2;
		}
		for (int t = 0; t <= i; t++) {
			printf("%d ", mass[t]);
		}
		printf("n=%d", n++);
		printf("\n");
	}
}

void dive(int* mass, int number_of_links)
{
	int y = 0;
	int y_next = 0;
	while (((mass[y] < mass[2 * y + 1]) || (mass[y] < mass[2 * y + 2])) && ((2 * y + 1) < number_of_links - 1)) {
		if (mass[y] < mass[2 * y + 1] && mass[y] < mass[2 * y + 2]) {
			if ((mass[2 * y + 1] > mass[2 * y + 2]) || ((mass[y] < mass[2 * y + 1]) && (2 * y + 2) == number_of_links - 1)) {
				y_next = 2 * y + 1;
				swap(mass, y, y_next);
				y = y_next;
			}
			else {
				if ((2 * y + 2) != number_of_links - 1){
					y_next = 2 * y + 2;
					swap(mass, y, y_next);
					y = y_next;
				}
			}
		}
		else {
			if (mass[y] < mass[2 * y + 1] ) {
				y_next = 2 * y + 1;
				swap(mass, y, y_next);
				y = y_next;
			}
			else {
				if ((2 * y + 2) != number_of_links - 1) {
					y_next = 2 * y + 2;
					swap(mass, y, y_next);
					y = y_next;
				}
				else {
					break;
				}
			}
		}
	}
}

void sort(int* mass, int number_of_links){
	int g = number_of_links;
	while (number_of_links != 0){
		int l = 0;
		for (int i = 0; i < g-1; i++) {
			if (mass[i] < mass[i + 1]) {
				l += 0;
			}
			else {
				l += 1;
				break;
			}
		}
		if (l != 0) {
			swap(mass, 0, number_of_links - 1);
			dive(mass, number_of_links);
		}
		for (int w = 0; w < g; w++) {
			printf("%d ", mass[w]);
		}
		printf("Heapsize = %d ", number_of_links - 1);
		printf("\n");
		number_of_links--;
	}
}

void IsSort(int* mass, int koll_elem) {
	int l = 0; // l отвечает за проверку сортировки по возрастанию или убыванию
	int k = 0; // k отвечает за проверку наличия сортировки
	int g = 0; // g отвечает за проверку, не состоит ли массив из одинаковых чисел
	//проверка на то, что состоит ли массив из одинаковых чисел
	for (int i = 0; i < koll_elem - 1; i++) {
		if (mass[i] == mass[i + 1]) {
			g += 0;
		}
		else {
			g += 1;
			break;
		}
	}
	if (g == 0) {
		printf("Массив состоит из одинаковых чисел");
	}
	// если массив не состоит из одинаковых чисел, проверяем, есть ли там сортировка 
	else {
		// проверка на сортировку по возрастанию 
		for (int i = 0; i < koll_elem - 1; i++) {
			if (mass[i] <= mass[i + 1]) {
				l += 0;
			}
			else {
				l += 1;
				break;
			}
		}
		if (l == 0) {
			k += 1;
			printf("Массив осортирован по возрастанию");
		}
		// проверка на сортировку по убыванию
		else {
			l = 0;
			for (int i = 0; i < koll_elem - 1; i++) {
				if (mass[i] >= mass[i + 1]) {
					l += 0;
				}
				else {
					l += 1;
					break;
				}
			}
			if (l == 0) {
				k += 1;
				printf("Массив осортирован по убыванию");
			}
		}
		// проверяем наличие сортировок, если к = 0 , то элементы массива расположены в хаотичном порядке 
		if (k == 0) {
			printf("Массив не отсортирован");
		}
	}
}
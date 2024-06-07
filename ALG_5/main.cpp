#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "heap.h"

int main()
{
	setlocale(LC_ALL, "Ru");
	int value = 0;
	int mass[10];
	int mass2[5] = { 1, 2, 3, 4, 5 };
	FILE* VD;
	int number_of_links = 0;
	if ((VD = fopen("VD.txt", "r")) == NULL)
	{
		printf("Не удалось открыть файл");
		getchar();
		return 0;
	}
	while (fscanf(VD, "%d", &value) != EOF)
	{
		mass[number_of_links] = value;
		number_of_links++;
		printf("%d ", value);
	}
	printf("\n");
	printf("Make heap\n");
	ascent(mass, number_of_links);
	printf("---------------------------");
	printf("\n");
	printf("Heap\n");
	for (int i = 0; i < number_of_links; i++) {
		printf("%d ", mass[i]);
	}
	printf("Heapsize=%d \n", number_of_links);
	printf("Sort\n");
	sort(mass, number_of_links);
	fclose(VD);
	IsSort(mass2, 5);
}
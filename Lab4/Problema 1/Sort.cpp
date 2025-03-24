#include "Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>

Sort::Sort(int nrElemente, int minValue, int maxValue) {
    size = nrElemente;
    vector = new int[size];
    time_t t; //tabela de timp
    srand((unsigned)time(&t)); //generam seed-ul pentru random
    for (int i = 0; i < size; ++i) {
        vector[i] = minValue + rand() % (maxValue - minValue + 1); //generam numerele random
    }
}

Sort::Sort() : vector(new int[6] {1, 2, 3, 4, 5, 6}) {
	size = 6;
}

Sort::Sort(int* vector, int size) {
    this->size = size;
    this->vector = new int[size];
    for (int i = 0; i < size; ++i) {
        this->vector[i] = vector[i];
    }
}

Sort::Sort(int count, ...) {
    size = count;
    vector = new int[size];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < size; i++) {
		vector[i] = va_arg(args, int);
    }
	va_end(args);
}   

Sort::Sort(char* string) {
	size = 0;
	for (int i = 0; string[i] != '\0'; ++i) {
		if (string[i] == ',') {
			size++;
		}
	}
	size++; //la final nu am virgula, si mai este un numar
	vector = new int[size];
	int cnt = 0;
	for (int i = 0; i < size; ++i) {
		vector[i] = 0; // Initialize the vector elements to 0
	}
	for (int i = 0; string[i] != '\0'; ++i) {
		if (string[i] == ',') {
			cnt++;
		}
		else {
			vector[cnt] = vector[cnt] * 10 + (string[i] - '0'); //construim numarul din string
		}
	}
}

void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < size; ++i) {
		int key = vector[i];
		int j = i - 1;
		if (ascendent) { ///daca vrem sa sortam crescator
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
		}
		else { ///daca vrem sa sortam descrescator
			while (j >= 0 && vector[j] < key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
		}
		vector[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent) {
	QuickSort(0, size - 1, ascendent);
}

void Sort::QuickSort(int left, int right, bool ascendent) {
	if (left < right) {
		int pi = Partition(left, right, ascendent);
		QuickSort(left, pi - 1, ascendent);
		QuickSort(pi + 1, right, ascendent);
	}
}

int Sort::Partition(int left, int right, bool ascendent) {
	int pivot = vector[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++) {
		if (ascendent) { ///daca vrem sa sortam crescator
			if (vector[j] < pivot) {
				i++;
				Swap(i, j);
			}
		}
		else { ///daca vrem sa sortam descrescator
			if (vector[j] > pivot) {
				i++;
				Swap(i, j);
			}
		}
	}
	Swap(i + 1, right);
	return i + 1;
}

void Sort::Swap(int i, int j) {
	int temp = vector[i];
	vector[i] = vector[j];
	vector[j] = temp;
}

void Sort::BubbleSort(bool ascendent) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (ascendent) { ///daca vrem sa sortam crescator
				if (vector[j] > vector[j + 1]) {
					Swap(j, j + 1);
				}
			}
			else { ///daca vrem sa sortam descrescator
				if (vector[j] < vector[j + 1]) {
					Swap(j, j + 1);
				}
			}
		}
	}
}

void Sort::Print() {
	for (int i = 0; i < size; ++i) {
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount() {
	return size;
}

int Sort::GetElementFromIndex(int index) {
	return vector[index];
}
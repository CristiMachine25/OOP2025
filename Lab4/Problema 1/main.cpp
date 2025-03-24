#include "Sort.h"
#include <stdio.h>

int main() {
	Sort s1(10, 1, 100);
	s1.Print();
	s1.InsertSort();
	s1.Print();
	printf("\n");
	
	int vector[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Sort s2(vector, 10);
	s2.Print();
	s2.BubbleSort();
	s2.Print();
	printf("\n");

	Sort s3;
	s3.Print();
	s3.QuickSort();
	s3.Print();
	printf("\n");

	char s[256] = "2,5,9,100";
	Sort s4(s);
	s4.Print();
	s4.QuickSort();
	s4.Print();
	return 0;
}
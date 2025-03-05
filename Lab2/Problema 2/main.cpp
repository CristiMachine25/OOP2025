#include <stdio.h>
#include <stdlib.h>
#include "NumberList.h"
#include "globals.h"

int main() {
    NumberList list1;
    list1.Init();
    list1.Add(1);
    list1.Add(5);
    list1.Add(3);
    list1.Add(7);
    list1.Add(2);
    list1.Sort();
    list1.Print();

    list1.SetNume("Ion", 3);
    printf("%s\n", list1.GetNume());
    list1.SetNotaMate(9);
    list1.SetNotaEngleza(8);
    list1.SetNotaIstorie(5);
    printf("%f\n", list1.GetNotaMate());
    printf("%f\n", list1.GetNotaEngleza());
    printf("%f\n", list1.GetNotaIstorie());
    printf("%f\n", list1.GetMedie());

    NumberList list2;
    list2.Init();
    list2.Add(2);
    list2.Add(4);

    list2.SetNume("Ana", 3);
    printf("%s\n", list2.GetNume());
    list2.SetNotaMate(10);
    list2.SetNotaEngleza(1);
    list2.SetNotaIstorie(8);
    printf("%f\n", list2.GetNotaMate());
    printf("%f\n", list2.GetNotaEngleza());
    printf("%f\n", list2.GetNotaIstorie());
    printf("%f\n", list2.GetMedie());

    // Comparam numele Ana cu Ion

    int result = compareByName(list1, list2);
    printf("Comparison by name result: %d\n", result);
    if (result < 0) {
        printf("%s comes before %s\n", list1.GetNume(), list2.GetNume());
    }
    else if (result > 0) {
        printf("%s comes before %s\n", list2.GetNume(), list1.GetNume());
    }
    else {
        printf("Au acelasi nume\n");
    }

    // Comparam notele de la mate

    result = compareByMathGrade(list1, list2);
    printf("Comparison by math grade result: %d\n", result);
    if (result > 0) {
        printf("%s are nota la mate mai mare decat %s\n", list1.GetNume(), list2.GetNume());
    }
    else if (result < 0) {
        printf("%s are nota la mate mai mare decat %s\n", list2.GetNume(), list1.GetNume());
    }
    else {
        printf("Au aceleasi note la mate\n");
    }

    // Comparam notele de la engleza

	result = compareByEnglishGrade(list1, list2);
	printf("Comparison by english grade result: %d\n", result);
    if (result > 0) {
		printf("%s are nota la engleza mai mare decat %s\n", list1.GetNume(), list2.GetNume());
    }
    else if (result < 0) {
		printf("%s are nota la mate mai mare decat %s\n", list1.GetNume(), list2.GetNume());
	}
    else {
        printf("Au aceleasi note la engleza\n");
    }

	//Comparam notele de la istorie
    
	result = compareByHistoryGrade(list1, list2);
	printf("Comparison by history grade result: %d\n", result);
    if (result > 0) {
        printf("%s are nota la istorie mai mare decat %s\n", list1.GetNume(), list2.GetNume());
    }
    else if (result < 0) {
        printf("%s are nota la istorie mai mare decat %s\n", list2.GetNume(), list1.GetNume());
    }
    else {
		printf("Au aceleasi note la istorie\n");
    }

	// Comparam mediile

	result = compareByAverageGrade(list1, list2);
	printf("Comparison by average grade result: %d\n", result);
    if (result > 0) {
        printf("%s are media mai mare decat %s\n", list1.GetNume(), list2.GetNume());
    }
    else if (result < 0) {
		printf("%s are media mai mare decat %s\n", list2.GetNume(), list1.GetNume());
	}
    else {
        printf("Au aceleasi medii\n");
    }

    return 0;
}
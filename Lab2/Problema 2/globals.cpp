#include "globals.h";
#include <string.h>

int compareByName(NumberList& a, NumberList& b) {
	return strcmp(a.GetNume(),b.GetNume());
}

int compareByMathGrade(NumberList& a, NumberList& b) {
	float x = a.GetNotaMate();
	float y = b.GetNotaMate();
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	return 0;
}

int compareByEnglishGrade(NumberList& a, NumberList& b) {
	float x = a.GetNotaEngleza();
	float y = b.GetNotaEngleza();
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	return 0;
}

int compareByHistoryGrade(NumberList& a, NumberList& b) {
	float x = a.GetNotaIstorie();
	float y = b.GetNotaIstorie();
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	return 0;
}

int compareByAverageGrade(NumberList& a, NumberList& b) {
	float x = a.GetMedie();
	float y = b.GetMedie();
	if (x < y) {
		return -1;
	}
	else if (x > y) {
		return 1;
	}
	return 0;
}
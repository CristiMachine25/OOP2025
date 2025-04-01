#include "Number.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>

Number::Number(const char* value, int base) {
	this->value = new char[strlen(value) + 1];
	strcpy_s(this->value, strlen(value) + 1, value);
	this->base = base;
}

Number::Number(int number) {
	int temp = number;
	int nrCifre = 0;
	if (number == 0)
		nrCifre = 1;
	//calculam numar cifre
	while (temp > 0) {
		temp /= 10;
		nrCifre++;
	}
	char* newValue = new char[nrCifre + 1];
	newValue[nrCifre] = '\0';
	//transformam in baza dorita
	for (int i = nrCifre - 1; i >= 0; i--) {
		int cifra = number % 10;
		number /= 10;
		newValue[i] = cifra + '0';
	}
	this->value = newValue;
	this->base = 10;
}

Number::~Number() {
	delete[] this->value;
}

Number::Number(const Number& copiere) {
	this->value = new char[strlen(copiere.value) + 1];
	strcpy_s(this->value, strlen(copiere.value) + 1, copiere.value);
	this->base = copiere.base;
}

Number::Number(const Number&& mutare) {
	this->value = mutare.value;
	this->base = mutare.base;
}

Number& Number::operator=(Number& other) {
	if (this != &other) {
		delete[] this->value;
		this->value = new char[strlen(other.value) + 1]; ///alocare memorie
		strcpy_s(this->value, strlen(other.value) + 1, other.value); ///copiere valoare
		this->base = other.base; ///copiere baza
	}
	return *this;
}

Number& Number::operator=(Number&& other) {
	if (this != &other) {
		delete[] this->value;
		this->value = other.value; ///mutare valoare
		this->base = other.base; ///mutare baza	
		other.value = nullptr; 
	}
	return *this;
}

Number& Number::operator=(int number) {
	int temp = number;
	int nrCifre = 0;
	if (number == 0)
		nrCifre = 1;
	//calculam numar cifre
	while (temp > 0) {
		temp /= 10;
		nrCifre++;
	}
	char* newValue = new char[nrCifre + 1];
	newValue[nrCifre] = '\0';
	//transformam in baza dorita
	for (int i = nrCifre - 1; i >= 0; i--) {
		int cifra = number % 10;
		number /= 10;
		newValue[i] = cifra + '0';
	}
	delete[] this->value;
	this->value = newValue;
	this->base = 10;
	return *this;
}

Number& Number::operator=(const char* value) {
	delete[] this->value;
	this->value = new char[strlen(value) + 1];
	strcpy_s(this->value, strlen(value) + 1, value);
	return *this;
}

Number& Number::operator+=(Number& other) {
	Number temp = *this + other;
	*this = temp;
	return *this;
}

Number& Number::operator-=(Number& other) {
	Number temp = *this - other;
	*this = temp;
	return *this;
}

void Number::SwitchBase(int newBase) {
	if (newBase < 2 || newBase > 16) { //daca baza este invalida
		printf("Invalid base\n");
		return;
	}

	if (this->base == newBase) {
		return;
	}

	//schimbam in baza 10
	int nrbaza10 = 0;
	int lungime = strlen(this->value);
	for (int i = 0; i < lungime; i++) {
		int cifra;
		if (this->value[i] >= '0' && this->value[i] <= '9') {
			cifra = this->value[i] - '0';
		}
		else {
			cifra = this->value[i] - 'A' + 10;
		}
		nrbaza10 = nrbaza10 * this->base + cifra;
	}
	
	int temp = nrbaza10;
	int nrCifre = 0;
	if (nrbaza10 == 0)
		nrCifre = 1;

	//calculam numar cifre
	while (temp > 0) {
		temp /= newBase;
		nrCifre++;
	}

	char* newValue = new char[nrCifre + 1];
	newValue[nrCifre] = '\0';

	//transformam in baza dorita
	for (int i = nrCifre - 1; i >= 0; i--) {
		int cifra = nrbaza10 % newBase;
		nrbaza10 /= newBase;
		if (cifra < 10) {
			newValue[i] = cifra + '0';
		}
		else {
			newValue[i] = cifra - 10 + 'A';
		}
	}

	delete[] this->value;
	this->value = newValue;

	//updatam baza in private
	this->base = newBase;
}

void Number::Print() {
	printf("%s\n", this->value);
}

int Number::GetDigitsCount() {
	return strlen(this->value);
}

int Number::GetBase() {
	return this->base;
}

Number operator+(const Number& n1, const Number& n2) {
	int maxBase = n1.base;
	if (n2.base > n1.base)
		maxBase = n2.base;

	Number temp1 = n1; //copy
	Number temp2 = n2;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);

	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);

	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}

	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}

	int sum = num1 + num2;
	int temp = sum;

	char newValue[100];
	int contor = 0;
	//number to string
	if (sum == 0) {
		newValue[0] = '0';
		newValue[1] = '\0';
	}
	else {
		while (temp > 0) {
			int cifra = temp % maxBase;
			temp /= maxBase;
			if (cifra < 10) {
				newValue[contor] = cifra + '0';
			}
			else {
				newValue[contor] = cifra - 10 + 'A';
			}
			contor++;
		}
		newValue[contor] = '\0';
	}
	//inversam stringul
	for (int i = 0; i < contor / 2; i++) {
		char aux = newValue[i];
		newValue[i] = newValue[contor - i - 1];
		newValue[contor - i - 1] = aux;
	}

	return Number(newValue, maxBase);
}

Number operator-(const Number& n1, const Number& n2) {
	// Find the maximum base
	int maxBase = std::max(n1.base, n2.base);

	// Convert both numbers to the maximum base
	Number temp1 = n1;
	Number temp2 = n2;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);

	// Convert string representation to integer
	int num1 = 0, num2 = 0;
	int length1 = strlen(temp1.value);
	int length2 = strlen(temp2.value);

	// Convert n1 to an integer
	for (int i = 0; i < length1; i++) {
		int digit = (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			? temp1.value[i] - '0'
			: temp1.value[i] - 'A' + 10;
		num1 = num1 * maxBase + digit;
	}

	// Convert n2 to an integer
	for (int i = 0; i < length2; i++) {
		int digit = (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			? temp2.value[i] - '0'
			: temp2.value[i] - 'A' + 10;
		num2 = num2 * maxBase + digit;
	}

	// Compute the difference
	int dif = num1 - num2;
	bool isNegative = dif < 0;
	dif = abs(dif);

	// Convert the result back to string
	char newValue[100];
	int contor = 0;

	if (dif == 0) {
		newValue[0] = '0';
		newValue[1] = '\0';
		return Number(newValue, maxBase);
	}

	while (dif > 0) {
		int cifra = dif % maxBase;
		dif /= maxBase;
		if (cifra < 10) {
			newValue[contor] = cifra + '0';
		}
		else {
			newValue[contor] = cifra - 10 + 'A';
		}
		contor++;
	}

	newValue[contor] = '\0';
	for (int i = 0; i < contor / 2; i++) {
		char aux = newValue[i];
		newValue[i] = newValue[contor - i - 1];
		newValue[contor - i - 1] = aux;
	}

	if (isNegative) { //in cazul in care da negativ
		char finalValue[101];
		finalValue[0] = '-';
		strcpy_s(finalValue + 1, 100, newValue);
		return Number(finalValue, maxBase);
	}

	return Number(newValue, maxBase);
}

void Number::operator--() {
	int length = strlen(this->value);
	if (length == 1) {
		delete[] this->value;
		this->value = new char[2];
		this->value[0] = '0';
		this->value[1] = '\0';
		return;
	}
	else
		this->value[length - 1] = '\0';
}

void Number::operator--(int number) {
	int length = strlen(this->value);
	if (length == 1) {
		delete[] this->value;
		this->value = new char[2];
		this->value[0] = '0';
		this->value[1] = '\0';
	}
	else if(this->value[0] == '-'){
		char* newValue = new char[length];
		this->value[1] = '-';
		strcpy_s(newValue, length, this->value + 1);
		delete[] this->value;
		this->value = newValue;
	}
	else {
		char* newValue = new char[length];
		strcpy_s(newValue, length, this->value + 1);
		delete[] this->value;
		this->value = newValue;
	}
}

void Number::operator++() { //adauga un zero la final
	int length = strlen(this->value);
	char* newValue = new char[length + 2];
	strcpy_s(newValue, length + 2, this->value);
	newValue[length] = '0';
	newValue[length + 1] = '\0';
	delete[] this->value;
	this->value = newValue;
}

int Number::operator[](int index) {
	if (index < 0 || index >= strlen(this->value)){
		printf("Invalid index\n");
		return -1;
	}
	if (this->value[index] >= '0' && this->value[index] <= '9')
		return this->value[index] - '0';
	else
		return this->value[index] - 'A' + 10;
}

bool Number::operator<(Number& other) {
	if(this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 < num2;
}

bool Number::operator<=(Number& other) {
	if(this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 <= num2;
}

bool Number::operator>(Number& other) {
	if (this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 > num2;
}

bool Number::operator>=(Number& other) {
	if (this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 >= num2;
}

bool Number::operator==(Number& other) {
	if (this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 == num2;
}

bool Number::operator!=(Number& other) {
	if (this->base != other.base)
		return false;
	int maxBase = this->base;
	Number temp1 = *this;
	Number temp2 = other;
	temp1.SwitchBase(maxBase);
	temp2.SwitchBase(maxBase);
	int num1 = 0, num2 = 0;
	int lenght1 = strlen(temp1.value);
	int lenght2 = strlen(temp2.value);
	//string to number for n1
	for (int i = 0; i < lenght1; i++) {
		if (temp1.value[i] >= '0' && temp1.value[i] <= '9')
			num1 = num1 * maxBase + temp1.value[i] - '0';
		else
			num1 = num1 * maxBase + temp1.value[i] - 'A' + 10;
	}
	//string to number for n2
	for (int i = 0; i < lenght2; i++) {
		if (temp2.value[i] >= '0' && temp2.value[i] <= '9')
			num2 = num2 * maxBase + temp2.value[i] - '0';
		else
			num2 = num2 * maxBase + temp2.value[i] - 'A' + 10;
	}
	return num1 != num2;
}

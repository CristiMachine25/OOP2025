#include "NumberList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void NumberList::Init()
{
	this->count = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10)
	{
		return false;
	}
	numbers[this->count] = x;
	this->count++;
	return true;
}
void NumberList::Sort() {
	int aux;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[i] > numbers[j])
			{
				aux = numbers[i];	
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}
}
void NumberList::Print() {
	for (int i = 0; i < count; i++)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
}

void NumberList::SetNume(const char* inputName, int inputNameSize ) {
	this->nume = new char[inputNameSize + 1];
	memcpy(this->nume, inputName, inputNameSize);
	this->nume[inputNameSize] = '\0';
}

const char* NumberList::GetNume() {
	return this->nume;
}

bool NumberList::SetNotaMate(float nota) {
	if (nota < 0 || nota > 10) {
		return false;
	}
	this->notaMate = nota;
	return true;
}

bool NumberList::SetNotaEngleza(float nota) {
	if (nota < 0 || nota > 10) {
		return false;
	}
	this->notaEngleza = nota;
	return true;
}

bool NumberList::SetNotaIstorie(float nota) {
	if (nota < 0 || nota > 10) {
		return false;
	}
	this->notaIstorie = nota;
	return true;
}

float NumberList::GetNotaMate() {
	return this->notaMate;
}

float NumberList::GetNotaEngleza() {
	return this->notaEngleza;
}

float NumberList::GetNotaIstorie() {
	return this->notaIstorie;
}

float NumberList::GetMedie() {
	return (this->notaMate + this->notaEngleza + this->notaIstorie) / 3;
}

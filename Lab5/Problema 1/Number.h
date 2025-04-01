#pragma once
class Number
{
	char* value;
	int base;
	int exemplu;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int number); // constructor to handle int input
	~Number(); //destructor
	Number(const Number& value); //copy constructor
	Number(const Number&& value); //move constructor

	// add operators and copy/move constructor
	friend Number operator+(const Number& n1, const Number& n2); //adunare
	friend Number operator-(const Number& n1, const Number& n2); //scadere

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount(); // returns the number of digits for the current number
	int GetBase(); // returns the current base

	void operator++(); //pentru a adauga un digit la final
	void operator--(); //pentru a sterge un digit de la final
	void operator--(int numar); //pentru a sterge un digit de la inceput

	int operator[](int index); //returneaza cifra de pe pozitia index

	Number& operator=(Number& other); //atribuire
	Number& operator=(Number&& other); //move assignment
	Number& operator=(int number); //atribuire pentru int
	Number& operator=(const char* value); //atribuire
	Number& operator+=(Number& other); //adunare si atribuire
	Number& operator-=(Number& other); //scadere si atribuire
	

	bool operator<(Number& other); //comparare
	bool operator>(Number& other); //comparare
	bool operator<=(Number& other); //comparare
	bool operator>=(Number& other); //comparare
	bool operator==(Number& other); //comparare
	bool operator!=(Number& other); //comparare
};
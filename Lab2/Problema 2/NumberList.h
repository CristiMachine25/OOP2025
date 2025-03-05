#pragma once
class NumberList
{
    int numbers[10];
    int count;
    char* nume;
    float notaMate;
    float notaEngleza;
	float notaIstorie;
public:
    void Init();          // count will be 0
	void SetNume(const char* inputName, int inputNameSize);
    const char* GetNume();
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
    // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vecto
    bool SetNotaMate(float nota);
	bool SetNotaEngleza(float nota);
	bool SetNotaIstorie(float nota);
	float GetNotaMate();
	float GetNotaEngleza();
	float GetNotaIstorie();
    float GetMedie();
};

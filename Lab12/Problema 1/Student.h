#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Materie.h"
using namespace std;
class Student {
private:
	string nume;
	string nrMatricol;
	string programInvatare;

	vector<pair<Materie*, float>> noteMaterii;
public:
	Student(const string& nume, const string& nrMatricol, const string& program) : nume(nume), nrMatricol(nrMatricol), programInvatare(program) {}

	void adaugaNota(Materie* materie, float nota) {
		noteMaterii.push_back({ materie, nota });
	}

	float calculeazaMedie() const {
		if (noteMaterii.empty())
			return 0;
		float suma = 0;
		for (const auto& p : noteMaterii) {
			suma += p.second;
		}
		return suma / noteMaterii.size();
	}
	string getNume() const {
		return nume;
	}
	string getNrMatricol() const {
		return nrMatricol;
	}
	string getProgramInvatare() const {
		return programInvatare;
	}

	void afiseazaNotele() const {
		for (const auto& p : noteMaterii) {
			cout << p.first->getNume() << ": " << p.second << "\n";
		}
	}
};
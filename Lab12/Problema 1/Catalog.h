#pragma once
#include "Student.h";
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Catalog {
protected:
	vector<Student> studenti;
public:
	virtual ~Catalog() = default;

	virtual void adaugaStudent(const Student& student) = 0;
	virtual vector<Student> getStudenti() const = 0;
	
	virtual void afiseazaRanking() const = 0;
};

class CatalogRO : public Catalog {
public: 
    void adaugaStudent(const Student& student) override {  
       if (student.getProgramInvatare() == "RO") {  
           studenti.push_back(student);  
       }  
    }

	vector<Student> getStudenti() const override {
		return studenti;
	}

	void afiseazaRanking() const override {
		vector<Student> copie = studenti;
		
		sort(copie.begin(), copie.end(), [](const Student& a, const Student& b) {
			return a.calculeazaMedie() > b.calculeazaMedie();
			});
		cout << "Ranking Catalog RO:\n";
		for (const auto& s : copie)
			cout << s.getNume() << " " << s.calculeazaMedie() << "\n";

	}
};

class CatalogEN : public Catalog {
public:
	void adaugaStudent(const Student& student) override {
		if (student.getProgramInvatare() == "EN") {
			studenti.push_back(student);
		}
	}

	vector<Student> getStudenti() const override {
		return studenti;
	}

	void afiseazaRanking() const override {
		vector<Student> copie = studenti;

		sort(copie.begin(), copie.end(), [](const Student& a, const Student& b) {
			return a.calculeazaMedie() > b.calculeazaMedie();
			});
		cout << "Ranking Catalog EN:\n";
		for (const auto& s : copie)
			cout << s.getNume() << " " << s.calculeazaMedie() << "\n";

	}
};
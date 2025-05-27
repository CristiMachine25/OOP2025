#pragma once
#include <string>
#include <iostream>
using namespace std;

class Materie
{
protected:;
	string nume;
	string tip;
	int credite;
public:
	Materie(string nume, string tip, int credite) : nume(nume), tip(tip), credite(credite) {}
	
	virtual ~Materie() = default;
	virtual string getNume() const = 0;
	virtual string getTip() const = 0;
	virtual int getCredite() const = 0;
};

//derivatele
class Matematica : public Materie {
public:
	Matematica() : Materie("Matematica", "obligatorie", 6) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override {
		return credite;
	}
};

class Romana : public Materie {
public:
	Romana() : Materie("Romana", "obligatorie", 5) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override{
		return credite;
	}
};

class Engleza : public Materie {
public:
	Engleza() : Materie("Engleza", "facultativa", 3) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override {
		return credite;
	}
};

class Informatica : public Materie {
public:
	Informatica() : Materie("Informatica", "obligatorie", 6) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override {
		return credite;
	}
};

class Optional1 : public Materie {
public:
	Optional1() : Materie("Optional1", "optional", 4) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override {
		return credite;
	}
};

class Optional2 : public Materie {
public:
	Optional2() : Materie("Optional2", "optional", 4) {}
	string getNume() const override {
		return nume;
	}
	string getTip() const override {
		return tip;
	}
	int getCredite() const override {
		return credite;
	}
};

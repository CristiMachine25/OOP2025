#include <iostream>
#include "Materie.h"
#include "Student.h"
#include "Catalog.h"
using namespace std;

int main() {
    // === Materii comune ===
    Matematica m;
    Romana r;
    Engleza e;
    Informatica i;
    Optional1 o1;
    Optional2 o2;

    // === Student 1 (RO) ===
    Student s1("Ion Popescu", "123", "RO");
    s1.adaugaNota(&m, 9.5);
    s1.adaugaNota(&r, 8.0);
    s1.adaugaNota(&i, 10.0);
    s1.adaugaNota(&o1, 7.5);

    // === Student 2 (RO) ===
    Student s2("Maria Ionescu", "124", "RO");
    s2.adaugaNota(&m, 7.0);
    s2.adaugaNota(&r, 9.0);
    s2.adaugaNota(&e, 10.0);
    s2.adaugaNota(&o2, 6.0);

    // === Student 3 (EN) ===
    Student s3("John Doe", "125", "EN");
    s3.adaugaNota(&i, 8.5);
    s3.adaugaNota(&e, 9.5);
    s3.adaugaNota(&o1, 7.0);
    s3.adaugaNota(&o2, 8.0);

    // === Cataloage ===
    CatalogRO catalogRO;
    CatalogEN catalogEN;

    catalogRO.adaugaStudent(s1);
    catalogRO.adaugaStudent(s2);
    catalogEN.adaugaStudent(s3);

    // === Afișare Ranking ===
    catalogRO.afiseazaRanking();
    std::cout << "\n";
    catalogEN.afiseazaRanking();

    return 0;
}
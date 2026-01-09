#pragma once
#include <vector>
#include <iostream>
#include <algorithm> // pentru functii de cautare
#include "Student.h"

using namespace std;

class Catalog {
private:
    vector<Student> studenti; // aici se tin toti studentii

public:
    // 1. adaugam un student nou in lista
    void adaugaStudent(string nume, string prenume) {
        Student s(nume, prenume);
        studenti.push_back(s);
        cout << " -> Studentul " << nume << " " << prenume << " a fost adaugat cu succes!" << endl;
    }

    // 2. afisam toti studentii
    void afiseazaCatalog() {
        if (studenti.empty()) {
            cout << "Nu exista studenti in catalog inca." << endl;
            return;
        }

        cout << "\n--- LISTA STUDENTI ---" << endl;
        for (const auto& s : studenti) {
            s.afiseazaSituatie(); // functia din Student.h
        }
        cout << "----------------------" << endl;
    }

    // 3. se cauta un student ca sa ii punem note
    // se returneaza un pointer (*) ca sa putem modifica studentul original
    Student* cautaStudent(string numeCautat) {
        for (auto& s : studenti) {
            if (s.getNumeComplet().find(numeCautat) != string::npos) {
                return &s; // returnam adresa studentului
            }
        }
        return nullptr;
    }
};
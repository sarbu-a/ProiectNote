#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "FileManager.h" // Avem nevoie de asta pentru salvare

using namespace std;

class Catalog {
private:
    vector<Student> studenti;
    FileManager fileManager; 

public:
    // Constructorul: Incarca datele cand porneste programul
    Catalog() : fileManager("studenti.csv") {
        studenti = fileManager.incarcaDate();
    }

    void adaugaStudent(string nume, string prenume) {
        Student s(nume, prenume);
        studenti.push_back(s);
        salveazaModificari(); // Salvam automat
        cout << " -> Studentul " << nume << " " << prenume << " a fost adaugat!" << endl;
    }

    void afiseazaCatalog() {
        if (studenti.empty()) {
            cout << "Nu exista studenti in catalog." << endl;
            return;
        }
        cout << "\n--- LISTA STUDENTI ---" << endl;
        for (const auto& s : studenti) {
            s.afiseazaSituatie();
        }
    }

    Student* cautaStudent(string numeCautat) {
        for (auto& s : studenti) {
            if (s.getNumeComplet().find(numeCautat) != string::npos) {
                return &s;
            }
        }
        return nullptr;
    }

    void salveazaModificari() {
        fileManager.salveazaDate(studenti);
    }
};
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "FileManager.h"

using namespace std;

class Catalog {
private:
    vector<Student> studenti;
    FileManager fileManager; 

public:
    Catalog() : fileManager("studenti.csv") {
        studenti = fileManager.incarcaDate();
    }

    void adaugaStudent(string nume, string prenume) {
        Student s(nume, prenume);
        studenti.push_back(s);
        salveazaModificari();
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

    // --- NOILE FUNCȚII PENTRU STATISTICI (Aici e noutatea) ---

    // 1. Media Generala a Clasei
    void afiseazaMediaClasei() {
        if (studenti.empty()) {
            cout << "Nu sunt date pentru statistici." << endl;
            return;
        }
        double sumaTotala = 0;
        int contor = 0;
        for (const auto& s : studenti) {
            double m = s.calculeazaMedia();
            if (m > 0) {
                sumaTotala += m;
                contor++;
            }
        }
        if (contor > 0)
            cout << "Media generala a clasei: " << fixed << setprecision(2) << (sumaTotala / contor) << endl;
        else
            cout << "Niciun student nu are note calculate." << endl;
    }

    // 2. Premiantul (Cea mai mare medie)
    void afiseazaPremiantul() {
        if (studenti.empty()) return;
        const Student* best = nullptr;
        double maxMedie = -1.0;

        for (const auto& s : studenti) {
            double m = s.calculeazaMedia();
            if (m > maxMedie) {
                maxMedie = m;
                best = &s;
            }
        }
        
        if (best != nullptr && maxMedie > 0)
            cout << "Premiantul: " << best->getNumeComplet() << " (Media " << maxMedie << ")" << endl;
        else
            cout << "Nu exista note pentru a determina premiantul." << endl;
    }

    // 3. Corigentii (Medie sub 5)
    void afiseazaCorigenti() {
        cout << "\n--- Lista Corigenti (Medie < 5) ---" << endl;
        bool gasit = false;
        for (const auto& s : studenti) {
            double m = s.calculeazaMedia();
            if (m > 0 && m < 5.0) {
                cout << " - " << s.getNumeComplet() << ": " << m << endl;
                gasit = true;
            }
        }
        if (!gasit) cout << "Nu exista corigenti! Bravo!" << endl;
    }
};
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
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
        if (cautaStudent(nume + " " + prenume) != nullptr) {
            cout << "Eroare: Studentul exista deja!" << endl;
            return;
        }
        studenti.push_back(Student(nume, prenume));
        salveazaModificari();
        cout << " -> Student adaugat." << endl;
    }

    Student* cautaStudent(string numeCautat) {
        for (auto& s : studenti) {
            if (s.getNumeComplet().find(numeCautat) != string::npos) return &s;
        }
        return nullptr;
    }

    void afiseazaCatalog() {
        cout << "\n=== SITUATIE SCOLARA COMPLETA ===" << endl;
        for (const auto& s : studenti) s.afiseazaSituatie();
    }

    void salveazaModificari() { fileManager.salveazaDate(studenti); }
    void afiseazaTopMaterii() {
        map<string, pair<double, int>> statistici; 
        for (const auto& s : studenti) {
            for (auto const& [materie, note] : s.getNoteMap()) {
                for (int n : note) {
                    statistici[materie].first += n;
                    statistici[materie].second++;
                }
            }
        }
        if (statistici.empty()) { cout << "Nu exista date pentru statistici." << endl; return; }

        string bestM = "", worstM = "";
        double bestAv = -1.0, worstAv = 11.0;

        cout << "\n--- Statistici pe Materii ---" << endl;
        for (auto const& [m, date] : statistici) {
            double medie = date.first / date.second;
            cout << "Materie: " << m << " | Medie: " << fixed << setprecision(2) << medie << endl;
            if (medie > bestAv) { bestAv = medie; bestM = m; }
            if (medie < worstAv) { worstAv = medie; worstM = m; }
        }
        cout << "\n[+] Cea mai buna materie: " << bestM << " (" << bestAv << ")" << endl;
        cout << "[-] Cea mai slaba materie: " << worstM << " (" << worstAv << ")" << endl;
    }
};
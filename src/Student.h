#pragma once 
#include <string>
#include <vector>
#include <map> 
#include <numeric> 
#include <iostream>
#include <iomanip> 

using namespace std;

class Student {
private:
    string nume;
    string prenume;
    map<string, vector<int>> notePeMaterii; // Materie -> Lista Note

public:
    Student(string n, string p) : nume(n), prenume(p) {}

    string getNume() const { return nume; }
    string getPrenume() const { return prenume; }
    string getNumeComplet() const { return nume + " " + prenume; }

    // Adaugam nota la o materie specifica
    void adaugaNota(string materie, int nota) {
        if (nota >= 1 && nota <= 10) {
            notePeMaterii[materie].push_back(nota);
        } else {
            cout << "Eroare: Nota trebuie sa fie intre 1-10!" << endl;
        }
    }

    const map<string, vector<int>>& getNoteMap() const {
        return notePeMaterii;
    }

    double getMediaGenerala() const {
        if (notePeMaterii.empty()) return 0.0;
        double sumaMedii = 0;
        int numarMaterii = 0;

        for (auto const& [materie, note] : notePeMaterii) {
            if (note.empty()) continue;
            double suma = 0;
            for (int n : note) suma += n;
            sumaMedii += (suma / note.size());
            numarMaterii++;
        }
        return (numarMaterii == 0) ? 0.0 : (sumaMedii / numarMaterii);
    }

    void afiseazaSituatie() const {
        cout << "Student: " << getNumeComplet() << endl;
        if (notePeMaterii.empty()) {
            cout << "  - Nu are note inregistrate." << endl;
            return;
        }
        for (auto const& [materie, note] : notePeMaterii) {
            cout << "  * " << materie << ": ";
            double suma = 0;
            for (int n : note) { cout << n << " "; suma += n; }
            if (!note.empty())
                cout << "| Media: " << fixed << setprecision(2) << (suma / note.size());
            cout << endl;
        }
        cout << "  => Media Generala: " << getMediaGenerala() << endl;
        cout << "-----------------------------------" << endl;
    }
};
#pragma once // Previne includerea fisierului de mai multe ori
#include <string>
#include <vector>
#include <numeric> // Pentru calculul mediei
#include <iostream>
#include <iomanip> // Pentru o afisarea mai frumoasa (setprecision)

using namespace std;

class Student {
private:
    string nume;
    string prenume;
    vector<int> note; // Vector dinamic pentru stocarea notelor (1-10)

public:
    // Constructor: se apeleaza cand se creaza un student nou
    Student(string n, string p) : nume(n), prenume(p) {}

    // Metoda pentru adaugarea unei note
    void adaugaNota(int nota) {
        if (nota >= 1 && nota <= 10) {
            note.push_back(nota);
        } else {
            cout << "Eroare: Nota " << nota << " nu este valida (trebuie 1-10)!" << endl;
        }
    }

    // Metoda pentru calculul mediei
    double calculeazaMedia() const {
        if (note.empty()) return 0.0;
        
        double suma = 0;
        for (int n : note) {
            suma += n;
        }
        return suma / note.size();
    }

    // Getters - functii sa putem citi datele private
    string getNumeComplet() const {
        return nume + " " + prenume;
    }

    // Afisarea detaliilor
    void afiseazaSituatie() const {
        cout << "Student: " << getNumeComplet() << " | Media: " 
             << fixed << setprecision(2) << calculeazaMedia()
             << " | Note: ";
        
        for (int n : note) {
            cout << n << " ";
        }
        cout << endl;
    }
};
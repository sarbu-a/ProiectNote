#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include "Student.h"

using namespace std;

class FileManager {
private:
    string numeFisier;

public:
    FileManager(string fisier) : numeFisier(fisier) {}

    // Salvarea datelor in fisier
    void salveazaDate(const vector<Student>& studenti) {
        ofstream fisier(numeFisier); 
        
        if (!fisier.is_open()) {
            cout << "Eroare: Nu pot deschide fisierul pentru scriere!" << endl;
            return;
        }

        for (const auto& s : studenti) {
            fisier << s.toCSV() << endl; // Scrierea fiecarui student pe un rand
        }
        
        fisier.close();
        cout << "Datele au fost salvate cu succes in " << numeFisier << endl;
    }

    // Citirea datelor din fisier
    vector<Student> incarcaDate() {
        vector<Student> studentiIncarcati;
        ifstream fisier(numeFisier); 

        if (!fisier.is_open()) {
            cout << "Nu exista date salvate anterior. Se porneste de la zero." << endl;
            return studentiIncarcati; // Returnam lista goala
        }

        string linie;
        while (getline(fisier, linie)) {
            stringstream ss(linie);
            string segment;
            vector<string> date;

            // Spargem linia dupa virgula
            while (getline(ss, segment, ',')) {
                date.push_back(segment);
            }

            // Daca avem cel putin Nume si Prenume
            if (date.size() >= 2) {
                Student s(date[0], date[1]); // Nume, Prenume
                
                // Restul sunt note
                for (size_t i = 2; i < date.size(); i++) {
                    try {
                        s.adaugaNota(stoi(date[i])); // Convertim din text in numar
                    } catch (...) {
                        // Ignoram erorile de conversie daca fisierul e corupt
                    }
                }
                studentiIncarcati.push_back(s);
            }
        }
        fisier.close();
        cout << "Au fost incarcati " << studentiIncarcati.size() << " studenti din fisier." << endl;
        return studentiIncarcati;
    }
};
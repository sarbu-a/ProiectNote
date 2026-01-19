#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include "Student.h"

using namespace std;

class FileManager {
private:
    string numeFisier;

public:
    FileManager(string fisier) : numeFisier(fisier) {}

    void salveazaDate(const vector<Student>& studenti) {
        ofstream fisier(numeFisier);
        if (!fisier.is_open()) return;

        for (const auto& s : studenti) {
            if (s.getNoteMap().empty()) {
                fisier << s.getNume() << "," << s.getPrenume() << ",NONE" << endl;
                continue;
            }
            for (auto const& [materie, note] : s.getNoteMap()) {
                fisier << s.getNume() << "," << s.getPrenume() << "," << materie;
                for (int n : note) fisier << "," << n;
                fisier << endl;
            }
        }
        fisier.close();
    }

    vector<Student> incarcaDate() {
        vector<Student> listaStudenti;
        ifstream fisier(numeFisier);
        if (!fisier.is_open()) return listaStudenti;

        string linie;
        while (getline(fisier, linie)) {
            stringstream ss(linie);
            string segment, nume, prenume, materie;
            vector<string> data;

            while (getline(ss, segment, ',')) data.push_back(segment);
            if (data.size() < 3) continue;

            nume = data[0]; prenume = data[1]; materie = data[2];

            Student* studentExistent = nullptr;
            for (auto& s : listaStudenti) {
                if (s.getNume() == nume && s.getPrenume() == prenume) {
                    studentExistent = &s;
                    break;
                }
            }
            if (studentExistent == nullptr) {
                listaStudenti.push_back(Student(nume, prenume));
                studentExistent = &listaStudenti.back();
            }
            if (materie != "NONE") {
                for (size_t i = 3; i < data.size(); i++) {
                    try { studentExistent->adaugaNota(materie, stoi(data[i])); } catch (...) {}
                }
            }
        }
        fisier.close();
        return listaStudenti;
    }
};
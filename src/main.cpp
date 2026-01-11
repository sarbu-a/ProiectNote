#include <iostream>
#include <string>
#include <limits> 
#include "Catalog.h"

using namespace std;

void citesteText(string& variabila) {
    if (cin.peek() == '\n') cin.ignore(); 
    getline(cin, variabila);
}

int main() {
    Catalog catalog; 
    int optiune = 0;

    while (optiune != 5) {
        cout << "\n=== CATALOG SCOLAR (v2.0) ===" << endl;
        cout << "1. Adauga Student" << endl;
        cout << "2. Adauga Nota" << endl;
        cout << "3. Afiseaza toti studentii" << endl;
        cout << "4. Statistici & Rapoarte" << endl; // <--- Optiune Noua
        cout << "5. Iesire" << endl;
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1: {
                string n, p;
                cout << "Nume: "; cin >> n;
                cout << "Prenume: "; cin >> p;
                catalog.adaugaStudent(n, p);
                break;
            }
            case 2: {
                string numeCautat;
                cout << "Cauta student: ";
                citesteText(numeCautat);

                Student* s = catalog.cautaStudent(numeCautat);
                if (s != nullptr) {
                    int nota;
                    cout << "Student gasit: " << s->getNumeComplet() << endl;
                    cout << "Ce nota ii dai? ";
                    cin >> nota;
                    s->adaugaNota(nota);
                    catalog.salveazaModificari(); 
                } else {
                    cout << "Eroare: Studentul nu a fost gasit!" << endl;
                }
                break;
            }
            case 3:
                catalog.afiseazaCatalog();
                break;
            case 4: // Aici apelam statisticile noi
                cout << "\n--- STATISTICI SI RAPOARTE ---" << endl;
                catalog.afiseazaMediaClasei();
                catalog.afiseazaPremiantul();
                catalog.afiseazaCorigenti();
                break;
            case 5:
                cout << "La revedere!" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    }
    return 0;
}
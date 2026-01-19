#include <iostream>
#include <string>
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
        cout << "\n=== CATALOG SCOLAR (v3.0) ===" << endl;
        cout << "1. Adauga Student" << endl;
        cout << "2. Adauga Nota " << endl;
        cout << "3. Afiseaza Raport Complet" << endl;
        cout << "4. Statistici Materii " << endl;
        cout << "5. Iesire" << endl;
        cout << "Optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1: {
                string n, p;
                cout << "Nume: "; cin >> n; cout << "Prenume: "; cin >> p;
                catalog.adaugaStudent(n, p);
                break;
            }
            case 2: {
                string numeCautat; cout << "Cauta student: "; citesteText(numeCautat);
                Student* s = catalog.cautaStudent(numeCautat);
                if (s != nullptr) {
                    string materie; int nota;
                    cout << "Student: " << s->getNumeComplet() << endl;
                    cout << "Materie (ex: Mate): "; cin >> materie;
                    cout << "Nota (1-10): "; cin >> nota;
                    s->adaugaNota(materie, nota);
                    catalog.salveazaModificari(); 
                } else { cout << "Studentul nu exista!" << endl; }
                break;
            }
            case 3: catalog.afiseazaCatalog(); break;
            case 4: catalog.afiseazaTopMaterii(); break;
            case 5: cout << "La revedere!" << endl; break;
            default: cout << "Optiune gresita!" << endl;
        }
    }
    return 0;
}
//fix
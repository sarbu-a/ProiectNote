#include <iostream>
#include "Student.h" // includem fisierul creat de mine

using namespace std;

void afiseazaMeniu() {
    cout << "\n=== SISTEM GESTIONARE NOTE ===" << endl;
    cout << "Aplicatia functioneaza!" << endl;
}

int main() {
    afiseazaMeniu();

    // TEST: crearea unui student fictiv sa vedem dca merge clasa
    cout << "\n--- Testare Clasa Student ---" << endl;
    
    Student s1("Popescu", "Ion");
    s1.adaugaNota(8);
    s1.adaugaNota(10);
    s1.adaugaNota(9);
    
    // testare validarea (nota gresita)
    s1.adaugaNota(15); 

    s1.afiseazaSituatie();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

void afiseazaMeniu() {
    std::cout << "\n=========================================" << std::endl;
    std::cout << "   SISTEM GESTIONARE NOTE STUDENTI      " << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "1. Adaugare nota (urmeaza)" << std::endl;
    std::cout << "2. Iesire" << std::endl;
}

int main() {
    afiseazaMeniu();
    std::cout << "\nProgramul ruleaza corect!" << std::endl;
    return 0;
}
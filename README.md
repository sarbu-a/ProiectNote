## Autor
- **Nume:** [Sarbu Alexandru]
- **Grupă:** [3.2]
- **Email:** [alexandru.sarbu@student.upt.ro]
- **An academic:** 2025-2026

# Sistem de Gestionare a Notelor Școlare

O aplicatie C++ pentru gestionarea situatiei scolare. Aplicatia permite administrarea studentilor, notarea acestora pe materii diferite, pastrarea datelor si generarea de rapoarte statistice complexe.

## Functionalitati

### 1. Management Studenti & Materii
* **Adaugare Studenti:** Inregistrarea studentilor in baza de date.
* **Sistem pe Materii:** Posibilitatea de a adauga note specifice pentru fiecare materie (ex: Matematica).
* **Validari:** Verificarea notelor (interval 1-10) si prevenirea duplicatelor.

### 2. Persistenta Datelor (CSV)
* **Salvare Automata:** Datele sunt salvate automat in fisierul `studenti.csv` după fiecare modificare.
* **Format Avansat:** Structura CSV suporta materii multiple:
    `Nume,Prenume,Materie,Nota1,Nota2...`
* **Incarcare la start:** Aplicatia retine datele intre rulari.

### 3. Statistici si Rapoarte
* **Situatie Scolara Completa:** Afisarea tuturor notelor si mediilor per materie pentru fiecare student.
* **Media Generala:** Calculul automat al mediei generale.
* **Analiza Materii (Best/Worst):**
    * Identificarea **celei mai bune materii** (cu cea mai mare medie a clasei).
    * Identificarea **celei mai slabe materii** (unde clasa are dificultăți).

---

## 🛠️ Tehnologii și Structura

* **Limbaj:** C++ (Standard **C++17**)
* **Concepte POO:** Incapsulare, Clase, Modularizare.
* **Structuri de Date:** `std::vector`, `std::map` (pentru asocierea Materie -> Note), `std::string`.
* **File I/O:** `std::fstream` pentru manipularea fisierelor CSV.

### Structura Proiectului
ProiectNote/
|-- .vscode/             # Configurari editor
|-- .data/             
|-- src/
|   |-- catalog.h        # Logica de business si statistici
|   |-- filemanager.h    # Citire/Scriere CSV
|   |-- main.cpp         # Interfata cu utilizatorul (Meniu)
|   |-- student.h        # Modelul de date (Student + Map Materii)
|   |-- studenti.csv     # Baza de date (generata automat)
|-- README.md            # Documentatie

# Instalare si Rulare

### 1. Clonare Repository
Descarca proiectul pe calculatorul tau:
```bash
git clone [https://github.com/sarbu-a/ProiectNote.git](https://github.com/sarbu-a/ProiectNote.git)
cd ProiectNote

### 2. Build imagine
docker build -t proiect-note .
### 3. Rulare container
docker run -it --rm proiect-note
Resurse folosite
[Documentatie oficiala C++] - https://en.cppreference.com/w/cpp/17
Referinta pentru standardul C++17 si containerele STL (std::map, std::vector).

[Stack Overflow - CSV Parsing in C++] - https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
Discutie detaliata despre metodele eficiente de citire si parsare a fifierelor CSV.

[Tutorial Configurare VS Code] - https://code.visualstudio.com/docs/cpp/config-msvc
Ghid pentru setarea compilatorului MSVC si a fisierelor de configurare .json.

### 4. Licenta
MIT License

Copyright (c) 2025 Sarbu A.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
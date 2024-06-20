// Entwickle ein C++-Programm, das eine Datei einliest, welche eine Liste von
// Mitarbeitern und deren Gehälter enthält. Die Daten sollen in einem Vektor von
// Strukturen gespeichert werden. Jede Struktur soll den Namen des Mitarbeiters
// als std::string und das Gehalt als float enthalten. Implementiere Funktionen
// zum Einlesen der Daten, zum Sortieren der Strukturen im Vektor nach Gehalt
// und zum Ausgeben der sortierten Liste auf der Konsole. Zusätzlich soll das
// Programm die Möglichkeit bieten, das Gehalt eines Mitarbeiters über den Namen
// zu suchen und auszugeben. 
// a) Definiere eine Struktur Mitarbeiter, die einen std::string für den Namen
// und ein float für das Gehalt enthält. 
// b) Schreibe eine Funktion leseMitarbeiterDaten(std::vector<Mitarbeiter>&
// mitarbeiterListe, const std::string& dateiname), die die Daten aus einer
// Datei einliest und in mitarbeiterListe speichert. Die Datei soll folgendes
// Format haben:  
// Max Mustermann;3500.00 
// Anna Schmidt;4200.50 
// ... usw.
// c) Implementiere eine Funktion sortiereNachGehalt(std::vector<Mitarbeiter>&
// mitarbeiterListe), die die Liste der Mitarbeiter nach dem Gehalt in
// absteigender Reihenfolge sortiert. 
// d) Schreibe eine Funktion zeigeMitarbeiterListe(const std::vector
// <Mitarbeiter>& mitarbeiterListe), die die sortierte Liste der Mitarbeiter auf
// der Konsole ausgibt.  
// e) Implementiere eine Funktion sucheGehalt(const std::vector<Mitarbeiter>&
// mitarbeiterListe, const std::string& name), die das Gehalt eines Mitarbeiters
// anhand des Namens sucht und auf der Konsole ausgibt. Wenn der Mitarbeiter
// nicht gefunden wird, soll eine entsprechende Nachricht ausgegeben werden. 

//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#ifndef DAYTIME_H
#define DAYTIME_H

struct Employee {std::string name; float salary;};

class EmployeeList
{
    private:
        std::vector<Employee>& employeeList;

    public:
        void read_employee_data(
            std::vector<Employee>& employeeList,
            const std::string& filename)
        {
            // reads data from file, saves in employeeList, format: Max 
            // Mustermann;3500.00\nAnna Schmidt;4200.50\nusw.
            
        }

        void sort_by_salary(std::vector<Employee>& employeeList)
        {
            // sorts employeeList by salary descending
            
        }

        void display_employee_list(const std::vector<Employee>& employeeList)
        {
            // displays sorted list in console

        }

        void search_salary(const std::vector<Employee>& employeeList, const std::string& name)
        {
            // displays employee salary on console, searched by employee name
            // a message is given, if name is not found

        }


};

#endif // DAYTIME_H

int main()
{
    EmployeeList elist;
    elist.read_employee_data();

    return 0;
}

#include <iostream> 
using namespace std; 
 
int main() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    cout << "Gib die Anzahl der Glieder für die Fibonacci-Folge ein: "; 
    cin >> n; 
 
    // Überprüfung der Eingabe 
    if (n <= 0) { 
        cout << "Bitte eine positive Ganzzahl eingeben!" << endl; 
        return 1; 
    } 
 
    cout << "Fibonacci-Folge bis zum " << n << "-ten Glied:" << endl; 
 
    // Ausgabe der ersten zwei Glieder 
    if (n >= 1) cout << t1 << ", "; 
    if (n >= 2) cout << t2 << ", "; 
 
    // Berechnung der Folge mit der while-Schleife 
    int i = 3; 
    while (i <= n) { 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
        cout << nextTerm << (i < n ? ", " : ""); 
        i++; 
    } 
 
    cout << endl << "Tabelle der Fibonacci-Folge:" << endl; 
    cout << "Glied\tWert" << endl; 
 
    // Zurücksetzen der Werte für die for-Schleife 
    t1 = 0, t2 = 1, nextTerm = 0; 
 
    // // Ausgabe der Tabelle mit der for-Schleife 
    // for (int j = 1; j <= n; ++j) { 
    //     cout << j << "\t" << (j == 1 ? 0 : (j == 2 ? 1 : nextTerm)) << endl; 
    //     if (j > 2) { 
    //         nextTerm = t1 + t2; 
    //         t1 = t2; 
    //         t2 = nextTerm; 
    //     } 
    // } 

    // Ausgabe der Tabelle mit der for-Schleife - korrigiert
    for (int j = 1; j <= n; ++j) { 
        cout << j << "\t" << t1 << endl; 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
    } 
 
    return 0; 
} 
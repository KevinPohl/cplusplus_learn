// mitarb.h: Definition der abstrakten Klasse
// Mitarbeiter.
// ----------------------------------------------------
#ifndef MITARB_H
#define MITARB_H
#include <string>
#include <iostream>
using namespace std;

class Mitarbeiter
{
    private:
        string name;
        // weitere Infos

    public:
        Mitarbeiter( const string& s = ""):name(s) {}
        virtual ~Mitarbeiter() {} // Destruktor
        const string& getName() const{ return name; }
        void setName( const string& n){ name = n; }
        virtual void display() const;
        virtual double einkommen() const = 0;
        virtual Mitarbeiter& operator=(const Mitarbeiter&);
};
#endif

// mitarb.h: Erweiterung der Header-Datei.
// --------------------------------------------------
class Arbeiter : public Mitarbeiter
{
    private:
        double lohn;
        int std;

    public:
        Arbeiter(const string& s="", double l=0.0, int h=0)
        : Mitarbeiter(s), lohn(l), std(h){ }
        double getLohn() const { return lohn; }
        void setLohn( double l ){ lohn = l; }
        int getStd() const { return std; }
        void setStd(int h ) { std = h; }
        void display() const;
        double einkommen() const;
        Arbeiter& operator=(const Mitarbeiter&);
        Arbeiter& operator=(const Arbeiter&);
};

// mitarb.h: Erweiterung der Header-Datei
// --------------------------------------------------
class Angestellter : public Mitarbeiter
{
    private:
        double gehalt; // Monatsgehalt

    public:
        Angestellter( const string& s="", double g = 0.0)
        : Mitarbeiter(s), gehalt(g){ }
        double getGehalt() const { return gehalt; }
        void setGehalt( double g){ gehalt = g; }
        void display() const;
        double einkommen() const { return gehalt; }
        Angestellter& operator=( const Mitarbeiter& );
        Angestellter& operator=( const Angestellter& );
};

double Arbeiter::einkommen() const
{
    return ( lohn * std );
}
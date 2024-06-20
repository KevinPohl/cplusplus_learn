// class Euro with arithmetic operators
//------------------------------------------------------------------------------
#ifndef EURO_H_
#define EURO_H_
#include <iostream>
#include <sstream> // class stringstream
#include <iomanip>
using namespace std;

class Euro
{
    private:
        long data; // Euros * 100 + Cents
    public:
        Euro( int euro = 0, int cents = 0)
        {
        data = 100L * (long)euro + cents;
        }

        Euro( double x)
        {
            x *= 100.0; // round
            data = (long)(x>=0.0 ? x+0.5 : x-0.5); // 9.7 -> 10
        }

        long getWholePart() const { return data/100; }
        int getCents() const { return (int)(data%100); }
        double asDouble() const { return (double)data/100.0; }
        string asString() const; // Euro value as string

        // print() is irrelevant with new shift operator overload
        // void print( ostream& os) const // output on stream os
        // {
        //     os << asString() << " Euro" << endl;
        // }

        // ---- Operatorfunctions ----
        Euro operator-() const // negation (unary minus))
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }

        Euro operator+( const Euro& e2) const // addition
        {
            Euro temp;
            temp.data = data + e2.data;
            return temp;
        }
        Euro operator-( const Euro& e2) const // subtraktion
        {
            Euro temp;
            temp.data = data - e2.data;
            return temp;
        }

        Euro& operator+=( const Euro& e2) // add Euros
        {
        data += e2.data;
        return *this;
        }

        Euro& operator-=( const Euro& e2) // subtract Euros
        {
            data -= e2.data;
            return *this;
        }
};

inline string Euro::asString() const // Euro value as string
{
    stringstream strStream; // stream to conversion
    long temp = data;
    if( temp < 0) { strStream << '-'; temp = -temp; }
    strStream << temp/100 << ',' << setfill('0') << setw(2) << temp%100;
    return strStream.str();
}

// decalaration of in- output operators
ostream& operator<<(ostream& os, const Euro& e);
istream& operator>>(istream& is, Euro& e);


#endif // EURO_H_

// #include "Euro1.h" // definition of class
#include <iostream>
// using namespace std;

//output on stream os
ostream& operator<<(ostream& os, const Euro& e)
{
    os << e.asString() << " Euro";
    return os;
}

// input from stream is
istream& operator>>(istream& is, Euro& e)
{   
    cout << "Euro value (format ...x,xx): ";
    int euro = 0, cents = 0; char c = 0;
    if( !(is >> euro >> c >> cents))
        return is;
    if( (c != ',' && c != '.') || cents>=100)
        // if error; fail bit = true, else false
        is.setstate(ios::failbit);
    else
        e = Euro(euro, cents);
    return is;
}


int main()
{
    cout << " * * * Test of class Euro * * *\n(20,50 -> -6,21)\n" << endl;

    Euro purchase(20,50), sales;
    sales = purchase;
    sales += 9.49; // += (Euro)9.49
    cout << "purchase price: " << purchase << std::endl;
    // purchase.print(cout);
    cout << "sales price: " << sales << std::endl;
    // sales.print(cout);
    Euro discount(2.10); // double constructor
    sales -= discount;
    cout << "\nsales price incl. discount: " << sales << std::endl;
    // sales.print(cout);
    purchase = 34.10;
    cout << "\nnew purchase price: " << purchase << std::endl;
    // purchase.print(cout);
    Euro profit(sales - purchase); // substraction and copy constructor
    cout << "\nThe profit: " << profit << std::endl;
    // profit.print(cout); // negative!
    
    Euro price;
    cout << "Den Preis in Euro eingeben: ";
    cin >> price;
    cout << "price: " << price << std::endl;
    
    return 0;
}
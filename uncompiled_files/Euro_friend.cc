// Euro.h
// Die Klasse Euro mit Operatorfunktionen, die als
// friend-Funktionen definiert sind.
//------------------------------------------------------------------------------
#ifndef EURO_H_
#define EURO_H_
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// ....
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
        void print( ostream& os) const // output on stream os
        {
            os << asString() << " Euro" << endl;
        }

        // ---- Operatorfunctions ----
        Euro operator-() const // negation (unary minus))
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }

        // Euro operator+( const Euro& e2) const // addition
        // {
        //     Euro temp;
        //     temp.data = data + e2.data;
        //     return temp;
        // }
        // Euro operator-( const Euro& e2) const // subtraktion
        // {
        //     Euro temp;
        //     temp.data = data - e2.data;
        //     return temp;
        // }

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

        Euro operator/( double x)
        {
            // division *this / x = *this * (1/x)
            return (*this * (1.0/x));
        }
        
        // global friend-functions
        friend Euro operator+(const Euro& e1, const Euro& e2);
        friend Euro operator-(const Euro& e1, const Euro& e2);
        
        friend Euro operator*(const Euro& e, double x)
        {
            Euro temp(((double)e.data/100.0) * x);
            return temp;
        }

        friend Euro operator*(double x, const Euro& e)
        {
            return e * x;
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

// addition
inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp; temp.data = e1.data + e2.data;
    return temp;
}

// subtraction
inline Euro operator-(const Euro& e1, const Euro& e2)
{
    Euro temp; temp.data = e1.data - e2.data;
    return temp;
}
#endif // EURO_H_

int main()
{
    cout << " * * * Test of class Euro * * *\n" << endl;
    Euro purchase(20,50), sales;
    sales = purchase;
    sales += 9.49; // += (Euro)9.49
    cout << "purchase price: ";
    purchase.print(cout);
    cout << "sales price: ";
    sales.print(cout);
    Euro discount(2.10); // double constructor
    sales -= discount;
    cout << "\nsales price incl. discount: ";
    sales.print(cout);
    purchase = 34.10;
    cout << "\nnew purchase price: "; purchase.print(cout);
    Euro gewinn(sales - purchase); // substraction and copy constructor
    cout << "\nThe profit: ";
    gewinn.print(cout); // negative!
    return 0;
}

// friend class abc; // is possible as well

//------------------------------------------------------------------------------
// can be FloatVek.h file

#ifndef FLOATVEK_H
#define FLOATVEK_H
#include <iostream>
#include <vector>

class FloatVek
{
    private:
        float* vekPtr;
        size_t max;
        size_t count;

    public:

        // constructors
        FloatVek(size_t n = 256)
        {
            max = n;
            count = 0; 
            vekPtr = new float[max];
        };

        FloatVek(size_t n, float value)
        {
            max = count = n;
            vekPtr = new float[max];
            for(size_t i=0; i < count; ++i)
                vekPtr[i] = value;
        };
        
        // copy constructor prototype
        FloatVek(const FloatVek& src);
        FloatVek& operator=(const FloatVek&);

        // destructor
        ~FloatVek()
        {
            delete[] vekPtr;
        };
        
        size_t length() const {return count;}
        
        // index operator
        float& operator[](size_t i);
        float operator[](size_t i) const;

        // // other operators
        // FloatVek& operator+=(const FloatVek& v);
        
        // append a value
        bool append(float value);
        
        // remove a value
        bool remove(size_t pos);

        // walk self
        void walk();

        // Move-Konstruktor
        FloatVek(FloatVek&& src);

};

#endif // FLOATVEK_H


//------------------------------------------------------------------------------
// can be different file - FloatVek.cc
// #include "FloatVek.h"
// #include <iostream>

// FloatVek& operator+=(const FloatVek& v) // not working rn
// {
//     FloatVek retV;
//     if(FloatVek::length()<v.length())
//     {
//         FloatVek base = v;
//         // FloatVek add = FloatVek;
//     } else
//     {

//     }
    
//     // for(size_t i = 0; i < ptr_base.)
//     // vekPtr[i] = v.vekPtr[i]
    
//     return retV;
// }

// FloatVek operator+(const FloatVek& v, const FloatVek& w)
// {
//     FloatVek temp(v); 
//     temp += w; // this is not implemented
//     return temp;
// }

float& FloatVek::operator[](size_t i)
{
    // if(i < 0 || i >= count)
    // not needed, changed type from int to size_t, which is unsigned
    if(i >= count) // range check
    {
        std::cerr << "\n class FloatVek: Out of Range! ";
        exit(1);
    }
    return vekPtr[i];
}

float FloatVek::operator[](size_t i) const
{
    // else as before
}

FloatVek& FloatVek::operator=(const FloatVek& src)
{
    // no self reference!
    if(this != &src)
    {
        max = src.max;
        count = src.count;
        
        // free memory
        delete[] vekPtr;
        
        // reserve new memory
        vekPtr = new float[max];
        
        // copy element
        for(size_t i=0; i < count; i++)
            vekPtr[i] = src.vekPtr[i];
    }
    return *this;
}

FloatVek::FloatVek(FloatVek&& src) 
{ 
    // copy data elements 
    max = src.max;
    count = src.count;
    vekPtr = src.vekPtr;
    
    src.vekPtr = NULL; // important!
}

bool FloatVek::append(float value)
{
    if(count < max)
    { 
        vekPtr[count++] = value;
        return true;
    }
    else
        // without lengthening of the vector
        return false;
}

bool FloatVek::remove(size_t pos)
{
    // if(pos >= 0 && pos < count)
    // not needed, changed type from int to size_t, which is unsigned
    if(pos < count)
    {
        for(size_t i = pos; i < count-1; ++i)
            vekPtr[i] = vekPtr[i+1];
        --count;
        return true;
    }
    else
        return false;

}

// copy constructor
FloatVek::FloatVek(const FloatVek& src)
{
    max = src.max;
    count = src.count;
    vekPtr = new float[max];

    for (size_t i = 0; i < count; i++)
        vekPtr[i] = src.vekPtr[i];
}

void FloatVek::walk()
{
    // size_t: safe and common use for array indexing and loop counting
    for(size_t i=0; i < FloatVek::count; ++i)
    {
        std::cout << vekPtr[i] << std::endl;
    }
}



//------------------------------------------------------------------------------
// can be different file - float_vek.cc
// using namespace std;


int main()
{
    // Vector v for 10 float values
    FloatVek v(10);
    
    // Vector w for 20 float values, initialized with 1.0
    FloatVek w(20, 1.0F);
    
    v.append(0.5F);
    std::cout << "current count of elements in v: " << v.length() << std::endl; // 1
    std::cout << "current count of elements in w: " << w.length() << std::endl; // 20
    
    FloatVek x(5, 0.0F);
    x[2] = 2.2F;
    for(size_t i=0; i < x.length(); ++i)
        std::cout << x[i] << std::endl;

    FloatVek y;

    // fill vector
    for(float i : {14.3, 0.12, 12.4}) {y.append(i);}
    // for(auto i : {14.3, 0.12, 12.4}) {y.append(i);} // alternatively
        
    // walk vector - size_t: safe and common use for array indexing and loop counting
    for(size_t i=0; i < y.length(); ++i) {std::cout << y[i] << std::endl;}
    
    // best practice for explicit cast:
    size_t val = static_cast<size_t>(123);
    val++;


    // test copy constructor
    FloatVek z = y;
    z.walk();

    // test move constructor 20 floats with 1.0
    FloatVek vec1(20, 1.0F);
    
    // call copy constructor.
    FloatVek vec2(vec1); 
    
    // // call of move constructor.
    // FloatVek vec3 = vec2 + vec1; 



    return 0;
}
//------------------------------------------------------------------------------
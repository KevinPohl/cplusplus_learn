//------------------------------------------------------------------------------
#include <iostream>
#include <stdexcept>
// using namespace std;
template <class T=int, int cnt = 10>

class QuadMatrix
{
    private:
        T mat[cnt][cnt];
    
    public:
        int dim() const{ return cnt; }
        T* operator[](int line) // throw(out_of_range)
        {
            if( line < 0 || line >= cnt)
                throw std::out_of_range("Matrix: Index out of range");
            else
                return mat[line];
        }

        const T* operator[](int line) const
        // throw(out_of_range)
        {
            if(line < 0 || line >= cnt)
                throw std::out_of_range("Matrix: Index out of range");
            else
                return mat[line];
        }

        friend QuadMatrix& operator+(const QuadMatrix&, const QuadMatrix&);
};
//------------------------------------------------------------------------------

// #include <iostream>
// using namespace std;
// #include "quadmat.h"
 // explizit instantiation
template class QuadMatrix<long double, 5>;
int main()
{
    typedef QuadMatrix<double> DoubleMat; 
    DoubleMat dm;
 
 
    QuadMatrix<long double, 5> m;
    try
    {
        for(int k=0; k < m.dim(); k++)
        {
            for( int l = 0; l < m.dim(); l++)
            {
                m[k][l] = k*l;
                std::cout << m[k][l] << " ";
            } 
        std::cout << std::endl;
        }
    }
    catch(std::out_of_range& err)
    {
        std::cerr << err.what() << std::endl;
    }
    
    return 0;
}

//------------------------------------------------------------------------------

// int main()
// {

    
//     return 0;
// }



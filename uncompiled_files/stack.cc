// stack.h : class template Stack with methods push() and pop()
//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
template<class T>
class Stack
{
    private:
        // pointer to vector
        T* basePtr;
        
        // tip of stack
        int tip;
        
        // maximal count of elements
        int max;
        
    public:
        Stack(int n){ basePtr = new T[n]; max = n; tip = 0;}
        Stack(const Stack<T>&);
        ~Stack(){ delete[] basePtr; }
        
        Stack<T>& operator=(const Stack<T>&);
        bool empty(){ return (tip == 0); }
        bool push(const T& x);
        bool pop(T& x);
};

template<class T>
bool Stack<T>::push(const T& x)
{
    // if space is available
    if(tip <= max - 1)
    {
        basePtr[tip++] = x;
        return true;
    }
    else return false;
}

// "class" and "typename" are equivalent here
// template<class T>
template<typename T>
bool Stack<T>::pop(T& x)
{
    // if stack is not empty
    if(tip > 0)
    {
        x = basePtr[--tip];
        return true;
    }
    else return false;
}
//------------------------------------------------------------------------------
// Stack for elements of type unsigned
typedef Stack<unsigned> USTACK;

void fill(USTACK& stk);
void clear(USTACK& stk);

int main()
{
    USTACK ustk(256);       // original
    fill(ustk);             // fill
    USTACK ostk(ustk);      // copy
    std::cout << "The copy:" << std::endl; 
    clear(ostk);            // display and clear copy
    std::cout << "The original:" << std::endl; 
    clear(ustk);            // display and clear original
    return 0;
}

void fill( USTACK& stk )
{
    unsigned x;
    std::cout << "Please input positive Integer " << "(Cancel with 0): \n";
    while(std::cin >> x && x != 0)
        if(!stk.push(x))
        {
            std::cerr << "Stack is full!";
            break;
        }
}

void clear(USTACK& stk)
{
    if(stk.empty())
        std::cerr << "Stack is empty!" << std::endl;
    else
    {
        unsigned x;
        while(stk.pop(x))
            std::cout << std::setw(8) << x << " ";
        std::cout << std::endl;
    }
}



//------------------------------------------------------------------------------
// Classes Vault and Castle
#include <iostream>
using namespace std;

class Vault
{
    private:
        int topSecret;

    protected:
        int secret;
        void setTopSecret(int n) { topSecret = n;}
        void setSecret(int n) { secret = n;}

    public:
        int notSecret;
        Vault() { topSecret = 100; secret = 10; notSecret = 0; }
        int getTopSecret() const { return topSecret;}
        int getSecret() const { return secret;}
};

class Castle : protected Vault
// protected inheritance, if no keyword is given, private is implicit
{
    // all public elements of Vault are inherited as protected
    // protected elements of Vault are inherited as protected
    // private elements of Vault are not inherited
    public:
        Castle()
        {
            // topSecret = 10;  // Error, private
            setTopSecret(10);   // ok, protected
            secret = 1;         // ok, protected
            notSecret = 0;      // ok, public
        }
        
        void test()
        {
            // topSecret = 200;     // error, private
            setTopSecret(200);      // ok, protected
            cout << "Top Secret: " << getTopSecret() << endl;
            secret = 20;            // ok, protected
            cout << "    Secret: " << getSecret() << endl;
            notSecret = 2;          // ok, public
            cout << "Not Secret: " << notSecret << endl;
        }
};

class Palace : private Vault    // private inheritance
{
    // all public and protected elements of Vault are inherited as private,
    // private elements are not inherited
    public: 
        // inherit as public, aside from inheritance rule - protected or public
        // "Vault::notSecret;" deprecated in favor of "using Vault::notSecret;"
        using Vault::notSecret;
    
    protected:
        // inherit as protected
        using Vault::secret;
    
    public:
        void test()
        {
            // topSecret = 200;     // error, private
            setTopSecret(200);      // ok, protected
            cout << "Top Secret: " << getTopSecret() << endl;
            secret = 20;            // ok, protected
            cout << "    Secret: " << getSecret() << endl;
            notSecret = 2;          // ok, public
            cout << "Not Secret: " << notSecret << endl;
        }
};

int main()
{
    Palace test1 = Palace();
    test1.test();
    return 0;
}

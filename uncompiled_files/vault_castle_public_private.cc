// Classes Vault and Castle
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Vault
{
    private:
        int topSecret;

    protected:
        int secret;
        void setTopSecret(int n) { topSecret = n;}
        int getTopSecret() const { return topSecret;}
        void setSecret(int n) { secret = n;}
        int getSecret() const { return secret;}

    public:
        int notSecret;
        Vault() { topSecret = 100; secret = 10; notSecret = 0; }
};

class Castle : public Vault
{
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

int main()
{
    Castle test1 = Castle();
    test1.test();
    return 0;
}
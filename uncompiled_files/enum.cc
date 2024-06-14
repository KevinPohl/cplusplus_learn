// use enum constant in a class
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Traffic_light
{
    public:
        // enumeration for class Traffic_light
        enum Status { off, red, green, yellow };
    
    private:
        Status status;
    
    public:
        Traffic_light(Status s = off) : status(s) {}
        Status getStatus() const {return status;}
        void setStatus(Status s)
        {
            switch(s)
            {
                case off:       cout << "      OFF         "; break;
                case red:       cout << "      RED         "; break;
                case green:     cout << "      GREEN       "; break;
                case yellow:    cout << "      YELLOW      "; break;
                default: return;
            }
            status = s;
        }
};

int main()
{
    cout << "Some commands with traffic light objects!\n"
    << endl;
    Traffic_light tl1, tl2(Traffic_light::red);
    Traffic_light::Status tl_status;
    tl_status = tl2.getStatus();
    if(tl_status == Traffic_light::red)
    {
        tl1.setStatus(Traffic_light::red);
        tl2.setStatus(Traffic_light::yellow);
    }
    cout << endl;
    return 0;
}
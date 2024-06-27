// test a priority queue
//------------------------------------------------------------------------------
#include <queue>
#include <string>
#include <iostream>
// using namespace std;

class Package
{
    private:
        unsigned int prio; // priority
        std::string info;
    
    public:
        Package(unsigned int p, const std::string& s)
        :prio(p), info(s) {}

        // overloaded operators
        friend bool operator<(const Package& x1, const Package& x2)
        { return (x1.prio < x2.prio); }

        friend std::ostream& operator<<(std::ostream& os, const Package& x)
        {
            os << x.prio << " " << x.info;
            return os;
        }
};

int main()
{
    std::priority_queue<Package> pq;
    
    // insert
    pq.push(Package(7, "Uwe"));
    pq.push(Package(1, "Peter"));
    pq.push(Package(4, "Susanne"));
    
    while(!pq.empty())
    {
        std::cout << pq.top() << std::endl; // display
        pq.pop(); // delete
    }
    return 0;
}
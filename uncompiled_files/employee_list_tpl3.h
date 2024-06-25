//------------------------------------------------------------------------------
#include <iostream>
#include <fstream> // std::ifstream and std::ofstream
#include <string> // getline()
#include <vector>
#include <algorithm>

#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

struct employee_t
{
    std::string name;
    float salary;
};

typedef std::vector<employee_t> empv_t;

class EmployeeList
{
    private:
        empv_t& employeeList;

    public:
        EmployeeList();
};

#endif // EMPLOYEELIST_H
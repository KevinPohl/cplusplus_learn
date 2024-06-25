//------------------------------------------------------------------------------
#include "employee_list_tpl3.h"

void sort_by_salary(empv_t& employeeList)
{
    // sorts employeeList by salary descending

    // struct to define sort field and order
    struct
    {
        bool operator()(employee_t& a, employee_t& b)
        {
            // < ascending, > descending
            return a.salary > b.salary;
        }
    } desc_salary;

    // sorting itself
    // std::sort from <algorithm>

    std::sort(employeeList.begin(), employeeList.end(), desc_salary); 
}

void display_employee_list(const empv_t& employeeList)
{
    // displays sorted list in console
    employee_t employee;
    for (auto employee : employeeList)
    {
        std::cout
            << "Name: " << employee.name << " - "
            << "Salary: " << employee.salary << std::endl; 
    }
}

int read_employee_data(empv_t& employeeList,
    const std::string& filename)
{
    // create filestream and open file
    std::ifstream file(filename, std::ios::in);
    
    // check if opened
    if(!file)
    {
        std::cerr << "Error while trying to read file " << filename << "."
            << std::endl;
        return 2;
    }

    std::string line, name;
    float salary;
    int separator;
    employee_t employee;

    // read lines from file one by one
    while(getline(file, line, '\n'))
    {
        // find name and salary in line
        separator = line.find(';');

        // write name and salary in variables
        name = line.substr(0, separator);
        salary = std::stof(line.substr(separator+1, 100));

        // use a struct to put the data together into one recordset
        employee = {name, salary};

        // write one dataset into vector
        employeeList.push_back(employee);
    }

    return 0;
}

void search_salary(empv_t& employeeList, const std::string& name)
{
    // displays employee salary on console, searched by employee name
    // a message is given, if name is not found
    
    for (employee_t employee : employeeList)
    {
        if (employee.name == name)
        {
            std::cout << "\nSearch result:\nThe salary of " << employee.name
                << " is " << employee.salary << "." << std::endl;
            return;
        }
    }
    std::cout << "\nEmployee " << name << " not found." << std::endl;
}
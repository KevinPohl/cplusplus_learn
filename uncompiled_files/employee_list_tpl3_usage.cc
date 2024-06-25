//------------------------------------------------------------------------------
#include "employee_list_tpl3_functs.cc"

int main()
{
    empv_t elist;
    read_employee_data(elist, "tpl3_data.csv");
    sort_by_salary(elist);
    display_employee_list(elist);
    search_salary(elist, "John Doe");
    search_salary(elist, "Jane Doe");
    return 0;
}
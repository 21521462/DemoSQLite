#include "Employee.h"
#include "DataBase.h"
#include <fstream>

int main()
{
    int numOfEmp;
    Employee *emp = NULL, anotherEmp;

    numOfEmp = inputInteger();
    emp = new Employee[numOfEmp];

    for (int i = 0; i < numOfEmp; i++)
    {
        cin >> emp[i];
    }

    createDatabase("Employee.db");
    insertData(emp, numOfEmp, "Employee.db");
    anotherEmp = selectData("Employee.db");

    return 0;
}
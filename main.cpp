#include "Employee.h"
#include "DataBase.h"
#include <fstream>

int main()
{
    int numOfEmp;
    Employee *emp = NULL;
    string line;

    // Open file
    ifstream file("Employee.txt");

    // Check the file is open or not 
    if (!file.is_open())
    {
        cerr << "Couldn't open the file - Employee.txt" << endl;
        return EXIT_FAILURE;
    }

    // Read file
    getline(file, line);
    numOfEmp = atoi(line.c_str());
    emp = new Employee[numOfEmp];
    for (int i = 0; i < numOfEmp; i++)
    {
        getline(file, line);
        emp[i].setId(atoi(line.c_str()));
        getline(file, line);
        emp[i].setName(line);
        getline(file, line);
        emp[i].setAge(atoi(line.c_str()));
        getline(file, line);
        emp[i].setAddress(line);
        getline(file, line);
        emp[i].setSalary(atof(line.c_str()));
    }

    // Close file
    file.close();

    // // Input data
    // numOfEmp = inputInteger();
    // emp = new Employee[numOfEmp];

    // for (int i = 0; i < numOfEmp; i++)
    // {
    //     cin >> emp[i];
    // }

    emp->createDatabase("Employee.db");
    emp->insertIntoDatabase("Employee.db");
    emp->selectFromDatabase("Employee.db");
    emp->updateData("Employee.db", "SALARY", "22.0", "AGE", "19");
    emp->deleteData("Employee.db", "ID", "2");

    delete [] emp;

    return 0;
}
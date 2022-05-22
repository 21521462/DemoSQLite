#pragma once
#ifndef Employee_h
#define Employee_h

#include "DataBase.h"
#include <iostream>

using namespace std;

class Employee :public SqliteObject
{
private:
    int Id, Age;
    double Salary;
    string Name, Address;
    static int Count;
public:
    Employee(int = 0, string = "", int = 0, string = "", double = 0);
    Employee(const Employee &);
    ~Employee();
    Employee &operator=(const Employee &);
    void inputEmployee();
    void outputEmployee() const;
    void setId(int);
    void setName(string);
    void setAge(int);
    void setAddress(string);
    void setSalary(double);
    void setEmployee(int, string, int, string, double);
    int getId() const;
    string getName() const;
    int getAge() const;
    string getAddress() const;
    double getSalary() const;
    int getCount() const;
    string createOpenStatement();
    string createInsertStatement();
    string createSelectStatement();
    string createUpdateStatement(string, string, string, string);
    string createDeleteStatement(string, string);
    void executeOpenStatement(string);
    void executeInsertStatement(string);
    void executeSelectStatement(string);
    void executeUpdateStatement(string);
    void executeDeleteStatement(string);
    void createDatabase(const char *);
    void insertIntoDatabase(const char *);
    void selectFromDatabase(const char *);
    void updateData(const char *, string, string, string, string);
    void deleteData(const char *, string, string);
    friend istream &operator>>(istream &, Employee &);
    friend ostream &operator<<(ostream &, const Employee &);
};
int inputInteger();

#endif /* Employee_h */
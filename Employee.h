#pragma once
#ifndef Employee_h
#define Employee_h

#include <iostream>

using namespace std;

class Employee
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
    friend istream &operator>>(istream &, Employee &);
    friend ostream &operator<<(ostream &, const Employee &);
};
int inputInteger();

#endif /* Employee_h */
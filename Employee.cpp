#include "Employee.h"

int Employee::Count = 0;
Employee::Employee(int Id, string Name, int Age, string Address, double Salary)
{
    setEmployee(Id, Name, Age, Address, Salary);
    Count += 1;
}
Employee::Employee(const Employee &emp)
{
    setEmployee(emp.Id, emp.Name, emp.Age, emp.Address, emp.Salary);
    Count += 1;
}
Employee::~Employee()
{
    Count -= 1;
}
Employee &Employee::operator=(const Employee &emp)
{
    setEmployee(emp.Id, emp.Name, emp.Age, emp.Address, emp.Salary);
    return *this;
}
void Employee::inputEmployee()
{
}
void Employee::outputEmployee() const
{

}
void Employee::setId(int Id)
{
    this->Id = Id;
}
void Employee::setName(string Name)
{
    this->Name = Name;
}
void Employee::setAge(int Age)
{
    this->Age = Age;
}
void Employee::setAddress(string Address)
{
    this->Address = Address;
}
void Employee::setSalary(double Salary)
{
    this->Salary = Salary;
}
void Employee::setEmployee(int Id, string Name, int Age, string Address, double Salary)
{
    setId(Id);
    setName(Name);
    setAge(Age);
    setAddress(Address);
    setSalary(Salary);
}
int Employee::getId() const
{
    return Id;
}
string Employee::getName() const
{
    return Name;
}
int Employee::getAge() const
{
    return Age;
}
string Employee::getAddress() const
{
    return Address;
}
double Employee::getSalary() const 
{
    return Salary;
}
int Employee::getCount() const
{
    return Count;
}
istream &operator>>(istream &is, Employee &emp)
{
    cout << "Enter ID: "; is >> emp.Id; is.ignore();
    cout << "Enter NAME: "; getline(is, emp.Name);
    cout << "Enter AGE: "; is >> emp.Age; is.ignore();
    cout << "Enter ADDRESS: "; getline(is, emp.Address);
    cout << "Enter SALARY: "; is >> emp.Salary;

    return is;
}
ostream &operator<<(ostream &os, const Employee &emp)
{
    os << "ID\tNAME\tAGE\tADDRESS\tSALARY" << endl;
    os << emp.Id << "\t" << emp.Name << "\t" << emp.Age << "\t" << emp.Address << "\t" << emp.Salary;

    return os;
}
int inputInteger()
{
    int i; 
    
    cin >> i;

    return i;
}
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
string Employee::createOpenStatement()
{
    string sql = "CREATE TABLE COMPANY(" \
                 "ID INT PRIMARY KEY    NOT NULL," \
                 "NAME           TEXT   NOT NULL," \
                 "AGE            INT    NOT NULL," \
                 "ADDRESS        CHAR(50)," \
                 "SALARY         REAL);";

    return sql;
}
string Employee::createInsertStatement()
{
    string sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)" \
                 "VALUES (" + to_string(Id) + ", '" + Name + "', " + to_string(Age)
                 + ", '" + Address + "', " + to_string(Salary) + ");";

    return sql;
}
string Employee::createSelectStatement()
{
    string sql = "SELECT * from COMPANY";

    return sql;
}
string Employee::createUpdateStatement(string field1, string data1, string field2, string data2)
{
    string sql = "UPDATE COMPANY set " + field1 + " = " + data1 + " where " + field2 + " = " + data2 + ";"
                 "SELECT * from COMPANY";

    return sql;
}
string Employee::createDeleteStatement(string field, string data)
{
    string sql = "DELETE from COMPANY where " + field + " = " + data + ";"
                 "SELECT * from COMPANY";

    return sql;
}
void Employee::executeOpenStatement(string sql)
{
    RC = sqlite3_exec(Database, sql.c_str(), callback, 0, &zErrMsg);

    if (RC != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }
}
void Employee::executeInsertStatement(string sql)
{
    RC = sqlite3_exec(Database, sql.c_str(), callback, 0, &zErrMsg);

    if (RC != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Records created successfully" << endl;
    }
}
void Employee::executeSelectStatement(string sql)
{
    RC = sqlite3_exec(Database, sql.c_str(), callback, (void*)Data.c_str(), &zErrMsg);

    if (RC != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Operation done successfully" << endl;
    }
}
void Employee::executeUpdateStatement(string sql)
{
    RC = sqlite3_exec(Database, sql.c_str(), callback, (void*)Data.c_str(), &zErrMsg);

    if (RC != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Database updated successfully" << endl;
    }
}
void Employee::executeDeleteStatement(string sql)
{
    RC = sqlite3_exec(Database, sql.c_str(), callback, (void *)Data.c_str(), &zErrMsg);

    if (RC != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Data deleted successfully" << endl;
    }
}
void Employee::createDatabase(const char *filename)
{
    openDatabase(filename);
    string sql = createOpenStatement();
    executeOpenStatement(sql);
    sqlite3_close(Database);
}
void Employee::insertIntoDatabase(const char *filename)
{
    int numOfEmp = Count;
    openDatabase(filename);

    for (int i = 0; i < numOfEmp; i++)
    {
        string sql = this[i].createInsertStatement();
        executeInsertStatement(sql);
    }
    sqlite3_close(Database);
}
void Employee::selectFromDatabase(const char *filename)
{
    openDatabase(filename);
    string sql = createSelectStatement();
    executeSelectStatement(sql);
    sqlite3_close(Database);
}
void Employee::updateData(const char *filename, string field1, string data1, string field2, string data2)
{
    openDatabase(filename);
    string sql = createUpdateStatement(field1, data1, field2, data2);
    executeUpdateStatement(sql);
    sqlite3_close(Database);
}
void Employee::deleteData(const char *filename, string field, string data)
{
    openDatabase(filename);
    string sql = createDeleteStatement(field, data);
    executeDeleteStatement(sql);
    sqlite3_close(Database);
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
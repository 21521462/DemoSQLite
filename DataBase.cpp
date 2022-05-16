#include "DataBase.h"

sqlite3 *db;
char *zErrMsg = 0;
int rc;

void createDatabase(const char *filename)
{
    // Open database
    rc = sqlite3_open(filename, &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        exit(0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    // Create SQL statement
    const char *sql = "CREATE TABLE COMPANY (" \
          "ID INT PRIMARY KEY       NOT NULL," \
          "NAME           TEXT      NOT NULL," \
          "AGE            INT       NOT NULL," \
          "ADDRESS        CHAR(50),"\
          "SALARY         REAL);";

    // Execute SQL statement 
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Table created successfully" << endl;
    }

    // Close database 
    sqlite3_close(db);
}
void insertData(const Employee *emp, int numOfEmp, const char *filename)
{
    // Open database 
    rc = sqlite3_open(filename, &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        exit(0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    // Create and execute SQL statement 
    for (int i = 0; i < numOfEmp; i++)
    {
        string sqlTemp = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)" \
                         "VALUES (" + to_string(emp[i].getId()) + ", '" + emp[i].getName() + "', "
                         + to_string(emp[i].getAge()) + ", '" + emp[i].getAddress() + "', "
                         + to_string(emp[i].getSalary()) + ");";
        const char *sql = sqlTemp.c_str();

        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            cout << "SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
        else
        {
            cout << "Records created successfully" << endl;
        }
    }

    // Close database 
    sqlite3_close(db);
}
Employee selectData(const char *filename)
{
    Employee emp;
    const char *data = "Callback function called";

    // Open database 
    rc = sqlite3_open(filename, &db);

    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
        exit(0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    // Create SQL statement
    string sqlTemp = "SELECT * from COMPANY";
    const char *sql = sqlTemp.c_str();

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cout << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Operation done successfully" << endl;
    }

    // Close database 
    sqlite3_close(db);

    return emp;
}
static int callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    
    return 0;
}
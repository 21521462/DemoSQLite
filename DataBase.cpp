#include "DataBase.h"

sqlite3 *db;
char *zErrMsg = 0;
int rc;

int SqliteObject::Count = 0;
SqliteObject::SqliteObject()
{
    Database = NULL;
    zErrMsg = 0;
    Data = "Callback function called";
    RC = 0;

    Count += 1;
}
SqliteObject::SqliteObject(sqlite3 *Database, const char *zErrMsg, string Data, int RC)
{
    setSqliteObject(Database, zErrMsg, Data, RC);

    Count += 1;
}
SqliteObject::SqliteObject(const SqliteObject &obj)
{
    setSqliteObject(obj.Database, obj.zErrMsg, obj.Data, obj.RC);

    Count += 1;
}
SqliteObject::~SqliteObject()
{
    // sqlite3_close(Database);
    // delete zErrMsg;

    Count -= 1;
}
SqliteObject &SqliteObject::operator=(const SqliteObject &obj)
{
    setSqliteObject(obj.Database, obj.zErrMsg, obj.Data, obj.RC);

    return *this;
}
void SqliteObject::setDatabase(sqlite3 *Database)
{
    this->Database = Database;
}
void SqliteObject::setErrMsg(const char *zErrMsg)
{
    strcpy(this->zErrMsg, zErrMsg);
}
void SqliteObject::setData(string Data)
{
    this->Data = Data;
}
void SqliteObject::setRC(int RC)
{
    this->RC = RC;
}
void SqliteObject::setSqliteObject(sqlite3 *Database, const char *zErrMsg, string Data, int RC)
{
    setDatabase(Database);
    setErrMsg(zErrMsg);
    setData(Data);
    setRC(RC);
}
sqlite3 *SqliteObject::getDatabase() const
{
    return Database;
}
char *SqliteObject::getErrMsg() const
{
    return zErrMsg;
}
string SqliteObject::getData() const
{
    return Data;
}
int SqliteObject::getRC() const 
{
    return RC;
}
void SqliteObject::openDatabase(const char *filename)
{
    // Open database
    RC = sqlite3_open(filename, &Database);

    if (RC)
    {
        cout << "Can't open database: " << sqlite3_errmsg(Database) << endl;
        exit(0);
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }
}
int SqliteObject::callback(void *data, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    
    return 0;
}
#pragma once
#ifndef Database_h
#define Database_h

#include <iostream>
#include <sqlite3.h>

using namespace std;

class SqliteObject
{
protected:
    sqlite3 *Database;
    char *zErrMsg;
    string Data;
    int RC;
    static int Count;
public:
    SqliteObject();
    SqliteObject(sqlite3 *, const char *, string, int);
    SqliteObject(const SqliteObject &);
    ~SqliteObject();
    SqliteObject &operator=(const SqliteObject &);
    void setDatabase(sqlite3 *);
    void setErrMsg(const char *);
    void setData(string);
    void setRC(int);
    void setSqliteObject(sqlite3 *, const char *, string, int);
    sqlite3 *getDatabase() const;
    char *getErrMsg() const;
    string getData() const;
    int getRC() const;
    void openDatabase(const char *);
    static int callback(void *, int, char **, char **);
};

#endif /* Database_h */
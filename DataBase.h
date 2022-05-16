#pragma once
#ifndef Database_h
#define Database_h

#include "Employee.h"
#include <sqlite3.h>

using namespace std;

void createDatabase(const char *);
void insertData(const Employee *, int, const char *);
Employee selectData(const char *);
void updateData(const char *);
void deleteData(const char *);
static int callback(void *, int, char **, char **);

#endif /* Database_h */
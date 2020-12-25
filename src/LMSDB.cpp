#pragma once
#include "LMSDB.h"
#include<string>

namespace LMS {
    LMSDB::LMSDB()
    {
        sqlite3_open("LMS.db", &db);
        initializeTables();
    }

    LMSDB::~LMSDB()
    {
    }

    void LMSDB::initializeTables()
    {
        const char* sql;
        sql = "CREATE TABLE student("  \
            "RollNo         CHAR(50)     PRIMARY KEY     NOT NULL," \
            "NAME           CHAR(50)    NOT NULL," \
            "Dob            CHAR(50)     NOT NULL," \
            "Email          CHAR(50)," \
            "uname         CHAR(50)," \
            "password      CHAR(50)    );";

        sqlite3_exec(db, sql, callback, 0, 0);

        sql = "CREATE TABLE Faculty("  \
            "NAME           CHAR(50)    NOT NULL," \
            "Dob            CHAR(50)     NOT NULL," \
            "Email          CHAR(50)," \
            "uname         CHAR(50)," \
            "password      CHAR(50)    );";

        sqlite3_exec(db, sql, callback, 0, 0);

        sql = "CREATE TABLE Course("  \
            "Name           CHAR(50)    NOT NULL," \
            "Code           CHAR(50)    NOT NULL );";
        sqlite3_exec(db, sql, callback, 0, 0);

        /*sql = "CREATE TABLE Person("  \
            "RollNo         CHAR(50)     PRIMARY KEY     NOT NULL," \
            "NAME           CHAR(50)    NOT NULL," \
            "Dob            CHAR(50)     NOT NULL," \
            "Email          CHAR(50)," \
            "uname         CHAR(50)," \
            "password      CHAR(50)    );";

        sqlite3_exec(db, sql, callback, 0, 0);*/

    }

    int LMSDB::callback(void* NotUsed, int argc, char** argv, char** azColName)
    {
        int i;
        for (i = 0; i < argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }
}
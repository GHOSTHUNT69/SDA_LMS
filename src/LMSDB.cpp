//#pragma once
//#include "LMSDB.h"
//#include<string>
//#include<Student.h>
//
//
//namespace LMS {
//    LMSDB::LMSDB()
//    {
//        sqlite3_open("LMS.db", &db);
//        initializeTables();
//    }
//
//    LMSDB::~LMSDB()
//    {
//    }
//
//    void LMSDB::initializeTables()
//    {
//        const char* sql;
//        sql = "CREATE TABLE student("  \
//            "RollNo         CHAR(50)     PRIMARY KEY     NOT NULL," \
//            "NAME           CHAR(50)    NOT NULL," \
//            "Dob            CHAR(50)     NOT NULL," \
//            "Email          CHAR(50)," \
//            "uname         CHAR(50)," \
//            "password      CHAR(50)    );";
//
//        sqlite3_exec(db, sql, callback, 0, 0);
//
//        sql = "CREATE TABLE Faculty("  \
//            "NAME           CHAR(50)    NOT NULL," \
//            "Dob            CHAR(50)     NOT NULL," \
//            "Email          CHAR(50)," \
//            "uname         CHAR(50)," \
//            "password      CHAR(50)    );";
//
//        sqlite3_exec(db, sql, callback, 0, 0);
//
//        sql = "CREATE TABLE Course("  \
//            "Name           CHAR(50)    NOT NULL," \
//            "Code           CHAR(50)    NOT NULL );";
//        sqlite3_exec(db, sql, callback, 0, 0);
//
//        /*sql = "CREATE TABLE Person("  \
//            "RollNo         CHAR(50)     PRIMARY KEY     NOT NULL," \
//            "NAME           CHAR(50)    NOT NULL," \
//            "Dob            CHAR(50)     NOT NULL," \
//            "Email          CHAR(50)," \
//            "uname         CHAR(50)," \
//            "password      CHAR(50)    );";
//
//        sqlite3_exec(db, sql, callback, 0, 0);*/
//
//    }
//
//    void LMSDB::storeStudents()
//    {
//        const char* sql;
//        sql = "INSERT INTO student (RollNo,NAME,Dob,Email,uname,password) "  \
//            "VALUES (1, 'Paul', 18-5-1999, '1@gmail.com', 1,1234 ); " \
//            "INSERT INTO student (RollNo,NAME,Dob,Email,uname,password) "  \
//            "VALUES (2, 'ali', 18-5-1998, '2@gmail.com', 2,1234 ); " \
//            "INSERT INTO student (RollNo,NAME,Dob,Email,uname,password) "  \
//            "VALUES (3, 'usama', 18-5-2000, '3@gmail.com', 3,1234 ); " \
//            "INSERT INTO student (RollNo,NAME,Dob,Email,uname,password) "  \
//            "VALUES (4, 'hussain', 18-4-1999, '4@gmail.com', 4,1234 ); " \
//            "INSERT INTO student (RollNo,NAME,Dob,Email,uname,password) "  \
//            "VALUES (5, 'hamza', 18-9-1999, '5@gmail.com', 5,1234 ); ";
//        sqlite3_exec(db, sql, callback, 0, 0);
//    }
//
//    void LMSDB::storeFaculty()
//    {
//        const char* sql;
//        sql = "INSERT INTO Faculty (NAME,Dob,Email,uname,password) "  \
//            "VALUES ('Paul', 18-5-1999, '1@gmail.com', 5,1234 ); " \
//            "INSERT INTO Faculty (NAME,Dob,Email,uname,password) "  \
//            "VALUES ('ali', 18-5-1998, '2@gmail.com', 6,1234 ); " \
//            "INSERT INTO Faculty (NAME,Dob,Email,uname,password) "  \
//            "VALUES ('usama', 18-5-2000, '3@gmail.com', 7,1234 ); " \
//            "INSERT INTO Faculty (NAME,Dob,Email,uname,password) "  \
//            "VALUES ('hussain', 18-4-1999, '4@gmail.com', 8,1234 ); " \
//            "INSERT INTO Faculty (NAME,Dob,Email,uname,password) "  \
//            "VALUES ('hamza', 18-9-1999, '5@gmail.com', 9,1234 ); ";
//        sqlite3_exec(db, sql, callback, 0, 0);
//    }
//
//    void LMSDB::storeCourses()
//    {
//        const char* sql;
//        sql = "INSERT INTO Course (Name,Code) "  \
//            "VALUES (DLD,123 ); " \
//            "INSERT INTO Course (Name,Code) "  \
//            "VALUES (Sda,1234 ); " \
//            "INSERT INTO Course (Name,Code) "  \
//            "VALUES (PF,1235 ); " \
//            "INSERT INTO Course (Name,Code) "  \
//            "VALUES (OOP,1235 ); " \
//            "INSERT INTO Course (Name,Code) "  \
//            "VALUES (DB,123 ); " \
//            "INSERT INTO Course (Name,Code) "  \
//            "VALUES (DS,1237 ); ";
//
//        sqlite3_exec(db, sql, callback, 0, 0);
//    }
//
//    int LMSDB::callback(void* NotUsed, int argc, char** argv, char** azColName)
//    {
//        int i;
//        for (i = 0; i < argc; i++) {
//            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//        }
//        printf("\n");
//        return 0;
//    }
//}
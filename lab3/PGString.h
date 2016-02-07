/******************************************************************************
 * Patrick Gillespie
 * PGString.h
 * FEB 07 2016
 * This header defines a simple string class.
 ******************************************************************************/

#ifndef __PGLIB__PGString__H
#define __PGLIB__PGString__H

// String.h

#include <iostream>

using namespace std;

// simple string class
class String {
        int size;
        char * buffer;
public:
    // constructors
    String();
    String(const String &);
    String(const char *);
    
    // deconstrutor
    ~String();

    // main methods
    char * begin();
    char * end();
    int length();
    char & operator[](const int);
    string operator=(const String &);
    string operator+=(const String &);

    // other methods
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
} // String

#endif

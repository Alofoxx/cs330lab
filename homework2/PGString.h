/******************************************************************************
 * Patrick Gillespie
 * String.h
 * FEB 07 2016
 * This header defines a simple string class.
 ******************************************************************************/

#ifndef __PGLIB__String__H
#define __PGLIB__String__H

// String.h

#include <iostream>
#include <cstddef> /* size_t, nullptr */

using namespace std;

// simple string class
class String {
    char * buffer;
    size_t size;

public:
    // constructors
    String();
    String(const String &);
    String(const char *);
    
    // deconstrutor
    ~String();

    // operators
    String operator =  ( const String & );
    String operator += ( const String & );
    String operator + ( const String & );
    String operator - ( const String & );
    String operator * ( const String & );
    char operator [] (const int);

    // utility methods
    int length() ; // return length
    char * begin(); //return first char
    char * end(); // return last char
    void reset(); // reset data
    void reset(const int); // reset data

    // other methods
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
}; // String

#endif // __PGLIB__String__H

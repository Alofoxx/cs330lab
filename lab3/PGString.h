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
    char * buffer = nullptr;
    size_t size = 0;

public:
    // constructors
    String();
    String(const String &);
    String(const char *);
    
    // deconstrutor
    ~String();

    // basic methods
    char * begin();
    char * end();
    int length();

    // operators
    String operator =  ( const String & );
    String operator += ( const String & );
    String operator += ( const char * );
    char & operator [] (const int);

    // comparison operators
    bool operator == ( const String & );
    bool operator != ( const String & );
    bool operator >  ( const String & );
    bool operator <  ( const String & );
    bool operator >= ( const String & );
    bool operator <= ( const String & );

    // utility methods
    size_t length() const { return _str_len; }
    size_t size() const { return _str_len; }
    const char & begin();
    const char & end();



    // other methods
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
} // String

// non-member operator overloads
String operator + ( const String & lhs, const String & rhs );

#endif // __PGLIB__String__H

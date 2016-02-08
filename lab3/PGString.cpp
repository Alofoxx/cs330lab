/******************************************************************************
 * Patrick Gillespie
 * PGString.cpp
 * FEB 07 2016
 * This file implements the member functions in the PGString class.
 ******************************************************************************/

#include <iostream>
#include <cstddef> /* size_t, nullptr */
#include <string.h> /* strlen */

#include "PGString.h"

using namespace std;
// implement String methods

// constructors/destructors
String::String( )
{
    reset();
} // default constructor

String::String( const char * char_string )
{
    this->size = strlen(char_string);
    this->buffer = new char[size];
    for( int i = 0; i < size; i++ ){
        buffer[i] = char_string[i];
    }
} // c-string

String::String( const String & source )
{
    this->size = source.size;
    this->buffer = new char[size];
    for( int i = 0; i < size; i++ ){
        this->buffer[i] = source.buffer[i];
    }
} // copy constructor

String::~String()
{
    reset();
} // destructor

// basic methods
char * String::begin()
{
    return buffer;
} // begin

char * String::end()
{
    return buffer + size;
} // end

int String::length()
{
    return size;
} // length

void String::reset()
{
    if(buffer)
        delete [] buffer;
    buffer = new char[0];
    size = 0;
} // reset

void String::reset(int new_size = 0)
{
    if(buffer) 
        delete [] buffer;
    buffer = new char[new_size];
    size = new_size;
} // reset int

// operators
String String::operator = ( const String & source )
{
    this->reset(source.size);
    for( int i = 0; i < size; i++ ){
        this->buffer[i] = source.buffer[i];
    }
    return *this;
} // copy-and-swap assignment

String String::operator += ( const String & source )
{
    // make sure source not empty
    if(source.size < 1) 
        return *this;
    String temp = * this; // hold original value
    this->reset(temp.size + source.size);
    for( int i = 0; i < size; i++ ){
        if(i < temp.size){
            this->buffer[i] = temp.buffer[i];
        }else{
            this->buffer[i] = source.buffer[i - temp.size];
        }
    } 
    temp.reset(0);
    return *this;
} // += string

String String::operator += ( const char * char_string )
{
    String source = char_string;
    *this += source;        
    return *this;
} // += char string

char String::operator[] ( const int index )
{
    if(index < 0) return 0;
    if(index >= (int) this->size) return 0;
    else return buffer[index];
} // []


// non-member operator overloads
bool operator == ( const String & left_string, const String & right_string)
{
    int i, j;
    for(i = 0, j = 0; i < left_string.size && j < right_string.size; i++, j++)
        if(left_string.buffer[i] != right_string.buffer[j])
            return false;
    if(i == left_string.size && j == right_string.size)
        return true;
    return false;
} // string == string

bool operator <= ( const String & left_string, const String & right_string)
{
    int i, j;
    for(i = 0, j = 0; i < left_string.size && j < right_string.size; i++, j++)
        if(left_string.buffer[i] > right_string.buffer[j])
            return false;
    if(i == left_string.size && j <= right_string.size)
        return true;
    return false;
} // string <= string

bool operator < ( const String & left_string, const String & right_string)
{
    int i, j;
    for(i = 0, j = 0; i < left_string.size && j < right_string.size; i++, j++)
        if(left_string.buffer[i] >= right_string.buffer[j])
            return false;
    if(i == left_string.size && j <= right_string.size)
        return true;
    return false;
} // string < string

ostream & operator << ( ostream & out, const String & my_string )
{
    for(int i = 0; i < my_string.size; i++)
        out << my_string.buffer[i];
    return out;
} // << string

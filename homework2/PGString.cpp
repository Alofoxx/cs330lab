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
    buffer = 0;
    size = 0;
} // default constructor

String::String(const char * char_string )
{
    size = strlen(char_string);
    buffer = new char[size];
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
    delete [] buffer;
    size = 0;
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
    //if(buffer)
        delete [] buffer;
    buffer = 0;
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

String String::operator + ( const String & source )
{
    // make sure source not empty
    if(source.size < 1)
        return * this;
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
} //+ string

String String::operator - ( const String & source )
{
    // make sure source not empty
    if(source.size < 1)
        return *this;
    String temp = * this; // hold original value
    int i = 0; // main iterator for this-> buffer
    int x,j = 0; 
    int temp_position, temp_size = 0; // buffer iterator and final size of temp
    bool match; // used to control loops
    while ( i < size ){
        match = true;
        x = i;
        j = 0;
        while ( j < source.size && match){
            if( size < source.size || buffer[x] != source.buffer[j])
                match = false;
            x++; j++;
        }
        if(! match){
            temp.buffer[temp_position] = buffer[i];
            temp_position++; // move buffer iterator for temp
            temp_size++; // increase final size of temp
        }
        i++;
    }
    String result;
    result.reset(temp_size); //sets the buffer and size to temp_size
    x=0;
    while(x < temp_size){
        result.buffer[x] = temp.buffer[x];
        x++;
    }
    return result;
           
} //- string

String String::operator * ( const int & amount )
{
    String result;
    result.reset( size * amount); //set buffer and size of result
    int i = 0;
    while(i < result.size){
        result.buffer[i] = buffer[ i%size ];
        i++;
    }
    return result; 
} //* string

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


main()
{
   String s1 = "abc";
   String s2 = "def";
   String s3 = s1 + s2; // should be abcdef
   cout << s1 << " + " << s2 << " = " << s3 << endl;

   String s4 = "abcbbccdf";
   String s5 = "bc";
   String s6 = s4 - s5; // should be abcdf
   cout << s4 << " - " << s5 << " = " << s6 << endl;
   
   String s7 = s1 * 3; // should be abcabcabc
   cout << s1 << " * 3 = " << s7 << endl;
   
   cout << "End Test";
}

/******************************************************************************
 * Patrick Gillespie
 * Vector.h
 * FEB 14 2016
 * This header defines a vector class.
 ******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);           // copy constructor
   ~Vector();

   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;

   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element

   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size

   T & operator[](unsigned int index);    // return reference to numbered element
   Vector<T> & operator=(const Vector<T> &);

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

// Two sample methods follow

template <class T>
Vector<T>::Vector()
{
	my_size = 0;
	my_capacity = 0;
	buffer = 0;
} // default constructor

template <class T>
Vector<T>::Vector(unsigned size)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for(int i = 0; i < size; i++)
        buffer[i] = T(); // set correct default value for type of T
} // constructor with size

template <class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    buffer = new T[size];
    for(int i = 0; i < size; i++)
        buffer[i] = initial; // set the initial values to passed param
} // constructor with size and initial value

template <class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_capacity];
    for(int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
} // copy constructor

template <class T>
Vector<T>::~Vector()
{
    delete [] buffer;
    my_size = 0;
    my_capacity = 0;
} // deconstructor


template <class T>
// This line doesn't compile: Vector<T>::iterator Vector<T>::begin()
// This line compiles:        T * Vector<T>::begin()
// But the follwoing line is the better solution:
typename Vector<T>::iterator Vector<T>::begin()
{
        return buffer;
}

// Rest of your code goes here ...

#endif


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
unsigned int Vector<T>::capacity() const
{
    return my_capacity;
} // capacity

template <class T>
unsigned int Vector<T>::size() const
{
    return my_size;
} // size

template <class T>
bool Vector<T>::empty() const
{
    if( my_size > 0 )
        return false;
    return true;
} // empty

template <class T>
// This line doesn't compile: Vector<T>::iterator Vector<T>::begin()
// This line compiles:        T * Vector<T>::begin()
// But the follwoing line is the better solution:
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + my_size;
}

template <class T>
T & Vector<T>::front()
{
    return & buffer[0];
}

template <class T>
T & Vector<T>::back()
{
    return & buffer[my_size - 1];
}

template <class T>
void Vector<T>::push_back(const T & value)
{
    int next_position = my_size;
    if(my_capacity == my_size)
        this->resize( my_capacity + 5);
    my_size++;
    buffer[next_position] = value;
}

template <class T>
void Vector<T>::pop_back()
{
    if(my_size > 1) 
        buffer[--my_size] = T();
}

template <class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(capacity > my_capacity) {
        Vector temp = this;
        delete [] buffer;
        buffer = new T[capacity];
        for(int i = 0; i < my_size; i++)
            buffer[i] = temp.buffer[i];
        for(int j = my_size; j < my_capacity; j++)
            buffer[j] = T();
        delete temp;
        my_capacity = capacity;
    }
}

template <class T>
void Vector<T>::resize(unsigned int size)
{
    if(size > my_capacity){
        this->reserve(size);
    } else if(size < my_capacity){
        Vector temp = this;
        delete [] buffer;
        buffer = new T[size];
        if(my_size > size)
            my_size = size;
        for(int i = 0; i < my_size; i++)
            buffer[i] = temp.buffer[i];
        for(int j = my_size; j < my_capacity; j++)
            buffer[j] = T();
        delete temp;
        my_capacity = size;
    }
}

template <class T>
T & Vector<T>::operator[](unsigned int index)
{
    if (index < my_capacity && index >= 0)
        return & buffer[index];
    return & buffer[0];
}

template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & right_side)
{
    delete [] buffer;
    my_size = right_side.my_size;
    my_capacity = right_side.my_capacity;
    buffer = new T[my_capacity];
    for(int i = 0; i < my_capacity; i++)
        buffer[i] = right_side.buffer[i];
}
#endif


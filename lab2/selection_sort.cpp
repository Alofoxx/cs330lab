/******************************************************************************
 * Patrick Gillespie
 * selection_sort.cpp
 * JAN 25 2016
 * This program creates a vector <input> rand numbers between 0 - 1000000 and
 * then sorts the vector using selection sort. Numbers are then output in order.
 ******************************************************************************/
#include <iostream>
#include <functional>   /* modulus */
#include <stdlib.h>     /* srand, rand */
#include <utility>      /* swap */
#include <time.h>       /* time */
#include <vector>

using namespace std;

main()
{
    int n;

    cout << "Please enter a number" << endl;
    cin >> n;

    vector<int> v(n);

    srand(time(0));

    for (int k = 0; k < n; k++ )
        v[k] = rand() % 1000000;

    //selection sort
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (v[i] > v[j])
                swap(v[i], v[j]);

    cout << endl << endl;
    for (int i = 0; i < n; i++ )
        cout << v[i] << endl; 
} // main

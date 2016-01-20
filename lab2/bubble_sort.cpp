/******************************************************************************
 * Patrick Gillespie
 * bubble_sort.cpp
 * JAN 25 2016
 ******************************************************************************/



#include <iostream>
#include <functional>   // modulus,
#include <stdlib.h>     /* srand, rand */
#include <utility>      // swap
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

    //bubble sort
    for (int i = n-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (v[j] > v[j+1])
                swap(v[j], v[j+1]);

    cout << endl << endl;
    for (int i = 0; i < n; i++ )
        cout << v[i] << endl; 

}





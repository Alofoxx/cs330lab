/******************************************************************************
 * Patrick Gillespie
 * insertion_sort.cpp
 * JAN 25 2016
 * This program creates a vector <input> rand numbers between 0 - 1000000 and
 * then sorts the vector using insertion sort. Numbers are then output in order.
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

    int j, temp;
		
    for (int i = 0; i < n; i++){
    	j = i;
		
	while (j > 0 && v[j] < v[j-1]){
     	    temp = v[j];
	    v[j] = v[j-1];
	    v[j-1] = temp;
	    j--;
	}
    }

    cout << endl << endl;
    for (int i = 0; i < n; i++ )
        cout << v[i] << endl; 

} // main

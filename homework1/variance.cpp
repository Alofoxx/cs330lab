/******************************************************************************
 * Patrick Gillespie
 * variance.cpp
 * JAN 25 2016
 * This program takes in up to 100 floats and calculates the variance.
 * It determines the variance by taking the sum of the squares of the diffrences
 *   of each element from the average of the arr[n] of floats, divided by n - 1.
 ******************************************************************************/

#include <iostream>
#include <math.h>       /* pow */

using namespace std;

main()
{
    float arr[100] = { };  
    float n;
    int i = 0;

    cout << "Please enter your numbers one per line and then ^D" << endl;
 
    cin >> n;
    while( ! cin.eof() && i < 100 ){
        arr[i] = n;
        i++;
        cin >> n;
    }
  
    // handle case of input bing less than 2 numbers
    if ( i < 2 ){
        cout << endl <<  "You must input at least 2 numbers." << endl;
        return 0;
    }

    cout << endl << "Calculating Variance for " << i << " numbers ...." << endl;

    //calculate variance
    float average = 0;

    for (int k = 0; k < i; k++) {
        average = average + arr[k];
    }
    average = average / i;


    float variance = 0;
    for (int l = 0; l < i; l++) {
        variance = variance + pow(arr[l] - average, 2.0 );
    }
    variance = variance / ( i - 1 );
   
    cout << "The variance is: " << variance << endl;

    return 0;  
} // main

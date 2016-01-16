/******************************************************************************
 * Patrick Gillespie
 * main.cpp
 * 1/11/16
 * This program takes an infix expression from input and converts it to a
 *   postfix expression.
 *
 * For example,   a + b - c     translates to   a b + c -
 *                a + b * c     translates to   a b c * +
 *                (a + 2) / (5 - d)   goes to   a 2 + 5 d - /
 *                a + ((b - c) * d) / e    to   a b c - d * e / +
 * Valid operands are single digits and characters: 0-9 a-z A-Z
 * Valid operators are: + - * / ( )
 * Highest precedence:  * /
 * Lowest precedence:   + -
 * ( has lowest precedence in the stack and highest precedence outside of stack.
 * ) never goes on stack.
 * Bottom of the stack has the lowest precedence than any operator.
 * Use a prec() function to compare the precedence of the operators based on the
 *   above rules.
 ******************************************************************************/

#include <iostream>
#include <stack>
#include <string>

#include <stdlib.h> 

using namespace std;

//Returns the precedence of an operator - higher has more precedence
int precedence(char operator_to_test)
{
    if (operator_to_test == '(')
        return 0; 
    if (operator_to_test == '+' || operator_to_test == '-' ) 
        return 1;
    if (operator_to_test == '*' || operator_to_test == '/' ) 
        return 2;

    //programatic error: this was called but not passed a valid operator
    cout << endl << endl << "Invalid operator was tested: " << operator_to_test;
    exit (EXIT_FAILURE);
}


//takes 'infix' input from cin and cout the 'postfix' expression 
main()
{
    stack<char> operator_buffer;
    string infix_string;
 
    cout << "enter infix:" << endl;

    getline(cin, infix_string);
  
    cout << endl << "postfix conversion: ";

    for (unsigned i = 0; i < infix_string.length(); i++) {
        if ( infix_string[i] == ' ') {
            cout << " ";
        } else if (infix_string[i] == '(') {
            operator_buffer.push('(');
        } else if (infix_string[i] == ')') {
            while ( ! operator_buffer.empty() && operator_buffer.top() != '(') {
                cout << operator_buffer.top();
                operator_buffer.pop();
            }
            if (! operator_buffer.empty() ) {
                operator_buffer.pop();
            } else {
                //we found a ')' but no matching '('
                cout << endl << endl << "no matching (";
                exit (EXIT_FAILURE);
            }
        } else if ( infix_string[i] == '+' || infix_string[i] == '-' 
                   || infix_string[i] == '*' || infix_string[i] == '/' ) {
            if ( operator_buffer.empty() || 
                  precedence(operator_buffer.top()) < precedence(infix_string[i]) ) {
                operator_buffer.push(infix_string[i]);
            } else {
                while ( ! operator_buffer.empty() && 
                       precedence(operator_buffer.top()) >= precedence(infix_string[i]) ) {
                    cout << operator_buffer.top();
                    operator_buffer.pop();
                }
                operator_buffer.push(infix_string[i]);
            }
        } else {
            if ( (infix_string[i] >= 'A' && infix_string[i] <= 'Z') || 
                 (infix_string[i] >= 'a' && infix_string[i] <= 'z') ||
                 (infix_string[i] >= '0' && infix_string[i] <= '9') ) {
                cout << infix_string[i];
            } else { 
                //something other than letters, spaces, and allowed operators was found
                cout << endl << endl << "Invalid Input: " << infix_string[i];
                exit (EXIT_FAILURE);
            }
        }
    }
    while ( ! operator_buffer.empty() ){
        cout << operator_buffer.top();
        operator_buffer.pop();
    }
    cout << endl << endl << "end of program" << endl;
    return 0;
}


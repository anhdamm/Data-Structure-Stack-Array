//--------------------------------------------------------------------
//
//  Laboratory 6 (Programming Exercise 3)               delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

using namespace std;

#if LAB6_TEST1
#   include "StackLinked.h"
#else
#   include "StackArray.h"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars
    
    cout << "This program checks for properly matched delimiters."
    << endl;
    
    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
        << endl;
        
        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
        
        if( ! cin )              // Reached EOF: stop processing
            break;
        
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    
    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk ( const string &expression )
{
#if LAB6_TEST1
    StackLinked<char> openDelims(20);
#else
    StackArray<char> openDelims(20);
#endif
    
    for ( int i=0 ; i < expression.length() ; i++ )
    {
        if (openDelims.isFull())
        {
            cerr << "Stack is Full" << endl;
            return false;
        }
        
        if(expression[i] == '(' || expression[i] == '[')
        {
            openDelims.push(expression[i]);
        }
        
        if(expression[i] == ')' )
        {
            char delims = openDelims.pop();
            if((delims == '(' && expression[i] != ')'))
            {
                return false;
            }
        }
        
        if(expression[i] == ']')
        {
            char delims = openDelims.pop();
            if((delims == '[' && expression[i] != ']'))
            {
                return false;
            }
        }
    }
    if(!openDelims.isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
}




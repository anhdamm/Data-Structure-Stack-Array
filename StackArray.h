//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackArray : public Stack<DataType> {
  public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:
    int maxSize;
    int top;
    DataType* dataItems;
};

/*Constructor
 Pre:none
 Post: Creates an empty stack.
 */
template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
    :maxSize(maxNumber), top(-1)
{
    dataItems = new DataType[maxNumber];
}


/*Copy Constructor
 Pre:none
 Post: Initializes the stack to be equivalent to the other Stack object parameter.
 */
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
    :maxSize(other.maxSize), top(other.top)
{
    dataItems = new DataType[maxSize];
    for(int i = 0; i <= top; i++)
    {
        dataItems[i] = other.dataItems[i];
    }
}


/*Operator
 Pre:none
 Post: Sets the stack to be equivalent to the other Stack object parameter and returns a reference to the modified stack.
 */
template <typename DataType>
StackArray<DataType>& StackArray<DataType>:: operator= (const StackArray& other)
{
    if(this != other)
    {
        return *this;
    }
    
    if(maxSize < other.maxSize)
    {
        delete [] dataItems;
        dataItems = new DataType[other.maxSize];
    }
    
    maxSize = other.maxSize;
    top = other.top;
    
    for(int i = 0; i <= top; i++)
    {
        dataItems[i] = other.dataItems[i];
    }
    return *this;
}


/*Destructor
 Pre:none
 Post: Frees the memory used to store the stack.
 */
template <typename DataType>
StackArray<DataType>::~StackArray()
{
    delete [] dataItems;
}


/*Push function
 Pre: Stack is not full.
 Post: Inserts newDataItem onto the top of the stack.
 */
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    if(isFull())
    {
        throw logic_error("Stack is full.");
    }
    
    else
    {
        dataItems[top+1] = newDataItem;
        top++;
    }
}


/*Pop function
 Pre: Stack is not empty.
 Post: Removes the most recently added (top) data item from the stack and returns the value of the deleted item.
 */
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
    if(isEmpty())
    {
        throw logic_error("Stack is empty.");
    }
    else
    {
        //DataType temp = dataItems[top];
        dataItems[top] = 0;
        top--;
        maxSize--;
    }
    
    return dataItems[top+1];
}


/*Clear function
 Pre:none
 Post: Removes all the data items in the stack.
 */
template <typename DataType>
void StackArray<DataType>:: clear()
{
    top = -1;
}


/*isEmpty
 Pre:none
 Post: Returns true if the stack is empty. Otherwise returns false.
 */
template <typename DataType>
bool StackArray<DataType>:: isEmpty() const
{
    return (top == -1);
}



/*isFull
 Pre:none
 Post: Returns true if the stack is full. Otherwise returns false.
 */
template <typename DataType>
bool StackArray<DataType>:: isFull() const
{
    return (top == maxSize - 1);
}


/*showStructure
 Pre:none
 Post: Outputs the data items in a stack..
 */
template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
        cout << "Empty stack." << endl;
    }
    else {
        int j;
        cout << "Top = " << top << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        for ( j = 0 ; j <= top  ; j++ )
        {
            if( j == top )
            {
                cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
            }
            else
            {
                cout << dataItems[j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

#endif		//#ifndef STACKARRAY_H

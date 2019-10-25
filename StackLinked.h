//--------------------------------------------------------------------
//
//  Laboratory 6                                          StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem) throw (logic_error);
    DataType pop() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode {
      public:
	StackNode(const DataType& nodeData, StackNode* nextPtr);

	DataType dataItem;
	StackNode* next;
    };

    StackNode* top;
};

/*Constructor
 Pre: none.
 Post: Creates an initialized StackNode.
 */
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}


/*Constructor
 Pre:none
 Post: Creates an empty stack.
 */
template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
    top = nullptr;
}


/*Constructor
 Pre: none
 Post: Copy constructor. Initializes the stack to be equivalent to the other StackLinked object parameter.
 */
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
    :top(-1)
{
    operator=(other);
}

/*Constructor
 Pre: none
 Post: Sets the stack to be equivalent to the other object parameter and returns a reference to the object.
 */
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
    if(this != other)
    {
        return *this;
    }
    clear();
    if(!other.isEmpty())
    {
        top = new StackNode(other.top->dataItem, 0);
        StackNode *otherTemp = other.top->next;
        StackNode *thisTemp = 0, *thisPrevious = top;
        
        while(otherTemp != 0)
        {
            thisTemp = new StackNode(otherTemp->dataItem, 0);
            thisPrevious->next = 0;
            thisPrevious = top->next;
            otherTemp = top;
        }
    }
    return *this;
}


/*Destructor
 Pre:none
 Post: Frees the memory used to store the stack.
 */

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
    clear();
}

/*Push function
 Pre: Stack is not full.
 Post: Inserts newDataItem onto the top of the stack.
 */
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
    if(isFull())
    {
        throw logic_error("Stack is full.");
    }
    
    if(isEmpty())
    {
        top = new StackNode(newDataItem, 0);
    }
    
    else
    {
        StackNode* store = top;
        top = new StackNode(newDataItem, store);
    }
}


/*Pop function
 Pre: Stack is not empty.
 Post: Removes the most recently added (top) data item from the stack and returns the value of the deleted item.
 */
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
    if(isEmpty())
    {
        throw logic_error("Stack is empty.");
    }
    else
    {
        DataType temp = top->dataItem;
        top = top->next;
        return temp;
    }
}


/*Clear function
 Pre:none
 Post: Removes all the data items in the stack.
 */
template <typename DataType>
void StackLinked<DataType>::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}


/*isEmpty
 Pre:none
 Post: Returns true if the stack is empty. Otherwise returns false.
 */
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
     return (top == NULL);
}


/*isFull
 Pre:none
 Post: Returns true if the stack is full. Otherwise returns false.
 */
template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
    return false;
}


/*showStructure
 Pre:none
 Post: Outputs the data items in a stack..
 */
template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
        cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
        for (StackNode* temp = top; temp != 0; temp = temp->next) {
            if( temp == top ) {
                cout << "[" << temp->dataItem << "]\t";
            }
            else {
                cout << temp->dataItem << "\t";
            }
        }
        cout << "Bottom" << endl;
    }
    
}

#endif		//#ifndef STACKARRAY_H


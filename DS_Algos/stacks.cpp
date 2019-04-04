#include<iostream>
#include<sstream>
#include<vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          stackADT - Base Class                           */

template<typename T> 
class stackADT{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const T& newItem) = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
};

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          stack - Derived Class                           */

template<typename T> 
class stack: public stackADT<T> {
private: 
    int maxStackSize;
    int stackTop;
    T* list;

    void copyStack(const stack<T>& otherStack);
public:
    const stack<T>& operator=(const stack<T>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const T& newItem);
    T top() const;
    void pop();
    stack(int stackSize = 100);
    stack(const stack<T>& otherStack);

    ~stack();
};

template<typename T>
void stack<T>::initializeStack()
{
    stackTop = 0;
}

template<typename T>
bool stack<T>::isEmptyStack() const
{
    return (stackTop == 0);
}

template<typename T>
bool stack<T>::isFullStack() const 
{
    return (stackTop == maxStackSize);
}

template<typename T>
void stack<T>::push(const T& newItem) 
{
    if (!isFullStack()) {
        list[stackTop] = newItem;
        stackTop++;
    }
    else {
        cout << "Cannot add to a full stack." << endl;
    }
}

template<typename T>
T stack<T>::top() const
{
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template<typename T>
void stack<T>::pop()
{
    if (!isEmptyStack()) {
        stackTop--;
    }
    else {
        cout << "Cannot remove from an empty stack" << endl;
    }
}

template<typename T>
void stack<T>::copyStack(const stack<T>& otherStack)
{
    delete [] list; // delete is used to delete and deallocate...
                    // new arr[] memory initialized from constuctor
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new T[maxStackSize];     // re-allocate array of memory

    for (int j = 0; j != stackTop; ++j) {
        list[j] = otherStack.list[j];
    }
}

template<typename T>
stack<T>::stack(int stackSize)
{
    if (stackSize <= 0) {
        cout << "Size is 0 or less, setting to default size of 100" << endl;
        maxStackSize = 100;
    }
    else {
        maxStackSize = stackSize;
    }
    stackTop = 0;
    list = new T[maxStackSize];
}

template<typename T>
stack<T>::~stack()
{
    delete [] list;
}

template<typename T>
stack<T>::stack(const stack<T>& otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

template<typename T>
const stack<T>& stack<T>::operator=(const stack<T>& otherStack)
{
    if (this != &otherStack) {      // avoid self copy
        copyStack(otherStack);
    }
    return *this;
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                                  Main                                    */

void testCopyConstructor(stack<int> otherStack);

int main()
{
    stack<int> stack1(50);
    stack<int> copyStack1(50);
    stack<int> dummyStack1(100);

    stack1.initializeStack();
    stack1.push(85);
    stack1.push(28);
    stack1.push(56);
    copyStack1 = stack1;
    
    cout << "The elements of copyStack: ";
    while (!copyStack1.isEmptyStack()) {
        cout << copyStack1.top() << " ";
        copyStack1.pop();
    }
    return 0;
}
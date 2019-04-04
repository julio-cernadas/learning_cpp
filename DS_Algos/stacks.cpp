#include<iostream>
#include<sstream>
#include<vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

/* ________________________________________________________________________ */
/*                                  node                                    */
template<typename T> 
class stackADT{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const T& newItem) = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
}

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
}
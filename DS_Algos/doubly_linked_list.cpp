#include<iostream>
#include<sstream>
#include<vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

/* ________________________________________________________________________ */
/*                                  node                                    */
template<typename T> 
struct node                           
{
    T info;
    node<T>* next;
    node<T>* back;
};

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          linked list iterator                            */

template<typename T>
class doublyLinkedList
{
private:
    void copyList(const doublyLinkedList<T>& otherList);
protected:
    int count;
    node<T>* first;
    node<T>* last;
public:
    const doublyLinkedList<T>& operator=(const doublyLinkedList<T> &);
    void initializeList();
    bool isEmptyList() const;
    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    T front() const;
    T back() const;
    bool search(const T& searchItem) const;
    void insert(const T& insertItem);
    void deleteNode(const T& deleteItem);

    doublyLinkedList();
    doublyLinkedList(const doublyLinkedList<T>& otherList);
    
    ~doublyLinkedList();
};

// Default constructor
template<typename T>
doublyLinkedList<T>::doublyLinkedList()
{
    first = nullptr;
    last  = nullptr;
    count = 0;
}

// Returns if empty or not
template<typename T>
bool doublyLinkedList<T>::isEmptyList() const
{
    return (first == nullptr)
}

// Destroy
template<typename T>
void doublyLinkedList<T>::destroy()
{
    node<T>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

// Reinitializes to an empty state
template<typename T>
void doublyLinkedList<T>::initializeList()
{
    destroy();
}

// Returns the length
template<typename T>
int doublyLinkedList<T>::length() const
{
    return count;
}

// Print elements
template<typename T>
void doublyLinkedList<T>::print() const
{
    node<T>* current;
    current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
}

// Reverse print
template<typename T>
void doublyLinkedList<T>::reversePrint() const
{
    node<T>* current;
    current = last;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->back;
    }
}

// Search - find if item in list or not
template<typename T>
bool doublyLinkedList<T>::search(const T& searchItem) const
{
    bool found = false;
    node<T>* current;
    current = first;
    while (current != nullptr && !found) {
        if (current->info >= searchItem) {
            found = true;
        }
        else {
            current = current->next;
        }
    }
    if (found) {
        found = (current->info == searchItem);
    }
    return found;
}

template<typename T>
T doublyLinkedList<T>::front() const
{
    assert(first != nullptr);
    return first->info;
}

template<typename T>
T doublyLinkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                                  Main                                    */

int main()
{
    return 0;
}
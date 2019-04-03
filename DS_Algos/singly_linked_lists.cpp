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
    node<T>* link;
};

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          linked list iterator                            */

template<typename T>
class linkedListIterator {
private:
    node<T>* current;
public:
    linkedListIterator();
    linkedListIterator(node<T> *ptr);
    T operator*();
    linkedListIterator<T> operator++();
    bool operator==(const linkedListIterator<T>& right) const;
    bool operator!=(const linkedListIterator<T>& right) const;
};

template<typename T>
linkedListIterator<T>::linkedListIterator(): current(nullptr) {}

template<typename T>
linkedListIterator<T>::linkedListIterator(node<T> *ptr): current(ptr) {}

template<typename T>
T linkedListIterator<T>::operator*()
{
    return current->info;
}

template<typename T>
linkedListIterator<T> linkedListIterator<T>::operator++() 
{
    current = current->link;
    return *this;
}

template<typename T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& right) const
{
    return (current == right.current);
}

template<typename T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& right) const
{
    return (current != right.current);
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                              linked list                                 */

template<typename T>
class linkedList {
private:
    void copyList(const linkedList<T>& otherList);
protected:
    int count;
    node<T>* first;
    node<T>* last;
public:
    const linkedList<T>& operator=(const linkedList<T>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    virtual bool search(const T& searchItem) const = 0;
    virtual void insertFirst(const T& newItem) = 0;
    virtual void insertLast(const T& newItem) = 0;
    virtual void deleteNode(const T& deleteItem) = 0;
    linkedListIterator<T> begin();
    linkedListIterator<T> end();
    linkedList();
    linkedList(const linkedList<T>& otherList);

    ~linkedList();

    void reversePrint(node<T>* current) const;
    void printListReverse();
};

template<typename T>
linkedList<T>::linkedList(): first(nullptr), last(nullptr), count(0) {}

template<typename T>
bool linkedList<T>::isEmptyList() const
{
    return (first == nullptr);
}

template<typename T>
void linkedList<T>::destroyList()
{
    node<T>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

// Default constructor already initialized, so this just reinitializes
// to an empty state. So it must delete all the nodes from the list.
template<typename T>
void linkedList<T>::initializeList()
{
    destroyList();
}

// First must always point the head node, so we use a "current" node
template<typename T>
void linkedList<T>::print() const 
{
    node<T>* current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
}

// Just prints the count of the linked list
template<typename T>
int linkedList<T>::length() const
{
    return count;
}

// Returns the head element, note: assert is used to abort the 
// function if first == nullptr. Assert means "make sure that.."
template<typename T>
T linkedList<T>::front() const
{
    assert(first != nullptr);
    return first->info;
}

// Same as above, just used to return the tail element.
template<typename T>
T linkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}

// Returns an iterator to the first node, similar to vector's begin.
template<typename T>
linkedListIterator<T> linkedList<T>::begin()
{
    linkedList<T> temp(first);
    return temp;
}

// Returns an iterator to the last node, simply a nullptr => tail.
template<typename T>
linkedListIterator<T> linkedList<T>::end()
{
    linkedList<T> temp(nullptr);
    return temp;
}

// Copying a list to the present list
template<typename T>
void linkedList<T>::copyList(const linkedList<T>& otherList)
{
    node<T> *newNode;
    node<T> *current;
    if (first != nullptr) {             // clear the list if not empty
        destroyList();
    }
    if (otherList.first == nullptr) {   // copying an empty list
        first = nullptr;              
        last = nullptr;                
        count = 0;
    }
    else {                              // copying a regular list
        current = otherList.first;
        count = otherList.count;
        first = new node<T>;
        first->info = current->info;
        first->link = nullptr;

        last = first;
        current = current->link;

        while (current != nullptr) {
            newNode = new node<T>;
            newNode->info = current->info;
            newNode->link = nullptr;

            last->link = newNode;
            last = newNode;

            current = current->link;
        }
    }
}

// This is where we actually implement the copyList function above,
// here we set it so that when we call "linkedList(otherList)", it is able
// to construct a linkedList through a copy action.
template<typename T>
linkedList<T>::linkedList(const linkedList<T>& otherList)
{
    first = nullptr;
    copyList(otherList);
}

// Assignment operator overload, also used for the case of copyList
template<typename T>
const linkedList<T>& linkedList<T>::operator=(const linkedList<T>& otherList)
{
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}

// Destructor
template<typename T>
linkedList<T>::~linkedList()
{
    destroyList();
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          unordered linked list                           */

template<typename T> 
class unorderedLinkedList: public linkedList<T> {
public:
    using linkedList<T>::first;
    using linkedList<T>::last;
    using linkedList<T>::count;
    bool search(const T& searchItem) const;
    void insertFirst(const T& newItem);
    void insertLast(const T& newItem);
    void deleteNode(const T& deleteItem);
};

template<typename T>
bool unorderedLinkedList<T>::search(const T& searchItem) const
{
    node<T>* current;
    current = first;
    bool found = false;
    
    while (current != nullptr && !found) {
        if (current->info == searchItem) 
            found = true;
        else
            current = current->link;
    }
    return found;
}

template<typename T>
void unorderedLinkedList<T>::insertFirst(const T& newItem)
{
    node<T>* newNode = new node<T>;
    newNode->info = newItem;
    newNode->link = first;
    first = newNode;
    count++;
    if (last == nullptr)            // If the list was empty
        last = newNode;
}

template<typename T>
void unorderedLinkedList<T>::insertLast(const T& newItem)
{
    node<T>* newNode = new node<T>;
    newNode->info = newItem;
    newNode->link = nullptr;
    if (first == nullptr) {         // If list is empty
        first = newNode;
        last  = newNode;
        count++;
    } 
    else {                        // Else the list not empty
        last->link = newNode;
        last = newNode;
        count++;
    }
}

template<typename T>
void unorderedLinkedList<T>::deleteNode(const T& deleteItem)
{
    node<T>* current;               // ptr to traverse the list  
    node<T>* trailCurrent;          // ptr just before current
    bool found;
    if (first == nullptr) {         // if list is empty
        cout << "Cannot delete from an empty list" << endl;
    } 
    else {
        if (first->info == deleteItem) {    // deleteItem is found 
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)           // if list only had one node
                last = nullptr;
            delete current;
        } 
        else {
            found = false;
            trailCurrent = first;
            current = first->link;
            while (current != nullptr && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current->link;
                }
                else {
                    found = true;
                }
            }
            if (found) {
                trailCurrent->link = current->link;
                count--;
                if (last == current) {
                    last = trailCurrent;
                }
                delete current;
            }
            else {
                cout << "Item not in list." << endl;
            }
        }
    }
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                            ordered linked list                           */

template<typename T>
class orderedLinkedList: public linkedList<T> {
public:
    using linkedList<T>::first;
    using linkedList<T>::last;
    using linkedList<T>::count;
    bool search(const T& searchItem) const;
    void insert(const T& newItem);
    void insertFirst(const T& newItem);
    void insertLast(const T& newItem);
    void deleteNode(const T& deleteItem);
};

template<typename T>
bool orderedLinkedList<T>::search(const T& searchItem) const
{
    bool found = false;
    node<T>* current = first;
    while (current != nullptr && !found) {
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    }
    if (found) 
        found = (current->info == searchItem);
    return found;
}

template<typename T>
void orderedLinkedList<T>::insert(const T& newItem)
{
    node<T>* current;
    node<T>* trailCurrent = nullptr;
    node<T>* newNode = new node<T>;
    newNode->info = newItem;
    newNode->link = nullptr;
    bool found;
    if (first == nullptr) {                     // If list is empty...
        first = newNode;
        last  = newNode;
        count++;
    }
    else {                                      // All other cases...
        current = first;
        found = false;
        while (current != nullptr && !found) {  // Traverse til end or found
            if (current->info >= newItem) {
                found = true;
            }
            else {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == first) {                 // newItem is smaller than first
            newNode->link = first;
            first = newNode;
            count++;
        }
        else {                                  // inserting in middle 
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr)             // inserting at end
                last = newNode;
            count++;
        }
    }
}

template<typename T>
void orderedLinkedList<T>::insertFirst(const T& newItem)
{
    insert(newItem);
}

template<typename T>
void orderedLinkedList<T>::insertLast(const T& newItem)
{
    insert(newItem);
}

template<typename T>
void orderedLinkedList<T>::deleteNode(const T& deleteItem) 
{
    node<T>* current;
    node<T>* trailCurrent = nullptr;
    bool found;
    if (first == nullptr) {
        cout << "Empty list" << endl;
    }
    else {
        current = first;
        found = false;
        while (current != nullptr && !found) {  // Search the list for item
            if (current->info >= deleteItem) {  // greater than the deleteItem
                found = true;
            }
            else {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == nullptr) {               // no result
            cout << "deleteItem not in list" << endl;
        }
        else {
            if (current->info == deleteItem) {
                if (current == first) {
                    first = first->link;
                    if (first == nullptr) {
                        last = nullptr;
                    }
                    delete current;
                }
                else {
                    trailCurrent->link = current->link;
                    if (current == last) {
                        last = trailCurrent;
                    }
                    delete current;
                }
                count--;
            }
            else {
                cout << "deleteItem not in list" << endl;
            }
        }
    }
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          Printing Reverse Order                          */

template<typename T>
void linkedList<T>::reversePrint(node<T>* current) const
{
    if (current != nullptr) {
        reversePrint(current->link);
        cout << current->info << " ";
    } 
}

template<typename T>
void linkedList<T>::printListReverse()
{
    reversePrint(first);
    cout << endl;
}

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                                  Main                                    */

int main() 
{
    orderedLinkedList<int> list1, list2;
    int num;
    cout << "Enter Numbers Ending with -999: ";
    cin >> num;
    while (num != -999) {
        list1.insert(num);
        cin >> num;
    }
    cout << "\n" << "list1: ";
    list1.print();
    list2 = list1;
    cout << "Enter number to be deleted: ";
    cin >> num;
    list2.deleteNode(num);
    cout << "Result: ";
    list2.print();
    cout << "\n";
    list2.printListReverse();
    return 0;
}

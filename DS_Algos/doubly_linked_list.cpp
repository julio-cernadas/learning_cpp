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
/* ________________________________________________________________________ */

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




/* ________________________________________________________________________ */

//////////////////////////////////////////////////////////////////////////////

/* ________________________________________________________________________ */
/*                                  Main                                    */
int main()
{
    return 0;
}
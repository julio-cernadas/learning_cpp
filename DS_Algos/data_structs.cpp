#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using std::cout, std::cin, std::endl, std::string, std::vector;

void sock_merchant_map()                // Using unordered_map
{
    int n, num;                         // number of sock in pile
    std::cin >> n;                      // first line read
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);      // second line, sock colors
    std::stringstream ss(input);
    std::vector<int> socks;
    while (ss >> num) {
        socks.push_back(num);
    }
    std::unordered_map<int,int> counts;
    for (const auto i : socks) {
        counts[i]++;
    }
    int count = 0;
    for (auto itr : counts) {
        count += itr.second / 2;
    }
    std::cout << count;
}
;
void jumping_on_the_clouds()       
{
    int n,num;                          // number of clouds
    std::cin >> n;                      // first line read
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);      // second line, sock colors
    std::stringstream ss(input);
    std::vector<int> clouds;
    while (ss >> num) {
        clouds.push_back(num);
    }
    int count = 0;
    for (int i = 0; i < n-2; ++i, ++count) {
        if (clouds[i+2] == 0) {
            ++i;
        }
    }
}

void counting_valleys() 
{
    int n, v_count = 0, sealevel = 0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (auto step : s) {
        std::cout << step << std::endl;
        if (step == 'U') {++sealevel;}
        if (step == 'D') {--sealevel;}
        if (sealevel == 0 && step == 'U') {++v_count;}
    }
    std::cout << v_count;
}


void Array_2D_DS()
{
    int size, num, temp;
    std::cin >> size;
    int arr[size];
    for (int i = 0; i != size; ++i) {
        std::cin >> num;
        arr[i] = num;
    }
    for (int i = 0; i != (size/2); ++i) {
        int temp = arr[i];
        arr[i] = arr[(size - 1) - i];
        arr[(size - 1) - i] = temp;
    }
    for (auto i : arr) {
        std::cout << i << " ";
    }
}

void left_rotation() 
{
    int n, d, temp;
    cin >> n >> d;
    vector<int> vec;
    for (int i = 0; i != n; ++i) {
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i != n; ++ i) {
        cout << vec[(i+d)%n] << " ";
    }
}

void sparse_strings()
{
    int n, q, cnt;
    string tmp;
    vector<string> strings;
    vector<string> queries;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> tmp;
        strings.push_back(tmp);
    }
    cin >> q;
    for (int i = 0; i != q; ++i) {
        cin >> tmp;
        queries.push_back(tmp);
    }
    for (auto word : queries) {
        cout << std::count(strings.begin(), strings.end(), word) << "\n";
    }
}

void print_elements()
{
    int n, tmp;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i != n; ++i) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    for (auto num : vec) {
        cout << num << "\n";
    }
}

/*                              Linked List                                 */

// node* build_linked_list()
// {
//     node *head, *newNode, *tail;
//     int num;
//     cout << "Enter a list of integers ending with -999." << endl;
//     cin  >> num;
//     head = nullptr;
//     tail = nullptr;
//     while (num != -999) 
//     {   
//         newNode = new node;
//         newNode->info = num;
//         newNode->link = nullptr;
//         if (head == nullptr) {
//             head = newNode;
//             tail = newNode;
//         }
//         else {
//             tail->link = newNode;
//             tail = newNode;
//         }
//         cin >> num;
//     }
//     return head;
// }

// node* build_linked_list_backward()
// {
//     node *head, *newNode;
//     int num;
//     cout << "Enter a list of integers ending with -999." << endl;
//     cin  >> num;
//     head = nullptr;
//     while (num != -999) 
//     {   
//         newNode = new node;
//         newNode->info = num;
//         newNode->link = head;
//         head = newNode;
//         cin >> num;
//     }
//     return head;
// }

template<typename T> 
struct node                           
{
    T info;
    node<T> *link;
};


// Linked List Iterator _______________________________________________________
template<typename T>
class linkedListIterator {
private:
    node<T> *current;
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
// _____________________________________________________________________________

// Linked List Class __________________________________________________________
template<typename T>
class linkedList {
protected:
    int count;
    node<T> *first, *last;
private:
    void copyList(const linkedList<T>& otherList);
public:
    const linkedList<T>& operator=(const linkedList<T>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    virtual bool search(const T& searchItem) const =0;
    virtual bool insertFirst(const T& newItem) = 0;
    virtual void insertLast(const T& newItem) = 0;
    virtual void deleteNode(const T& deleteItem) = 0;
    linkedListIterator<T> begin();
    linkedListIterator<T> end();
    linkedList();
    linkedList(const linkedList<T>& otherList);

    ~linkedList();
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
    node<T> * temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template<typename T>
void linkedList<T>::initializeList()
{
    destroyList();
}

template<typename T>
void linkedList<T>::print() const 
{
    node<T> *current;
    current = first;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->link;
    }
}

template<typename T>
int linkedList<T>::length() const
{
    return count;
}

template<typename T>
T linkedList<T>::front() const
{
    assert(first != nullptr);
    return first->info;
}

template<typename T>
T linkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}

template<typename T>
linkedListIterator<T> linkedList<T>::begin()
{
    linkedList<T> temp(first);
    return temp;
}

template<typename T>
linkedListIterator<T> linkedList<T>::end()
{
    linkedList<T> temp(nullptr);
    return temp;
}

template<typename T>
void linkedList<T>::copyList(const linkedList<T>& otherList)
{
    node<T> *newNode;
    node<T> *current;
    if (first != nullptr) {
        destroyList();
    }
    if (otherList.first == nullptr) {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else {
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

template<typename T>
linkedList<T>::~linkedList()
{
    destroyList();
}

template<typename T>
linkedList<T>::linkedList(const linkedList<T>& otherList)
{
    first = nullptr;
    copyList(otherList);
}

template<typename T>
const linkedList<T>& linkedList<T>::operator=(const linkedList<T>& otherList)
{
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}
// ____________________________________________________________________________


int main() 
{

    return 0;
}

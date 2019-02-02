#include <iostream>
#include <vector>

struct Vector                           //  Declaring the Struct named 'Vector'
{                                       //  Declaring variables within it.
    int size;                    
    double* elmt;                       
};

void vector_init(Vector& v, int s)      //  Declaring function 'vector_init'
{                                       //  Takes in a reference, which doesn't occupy memory..
    v.elmt = new double[s];             //  they simply reference another variables, like an alias...   
    v.size = s;                         //  we aren't making a copy, a ref only exists in our source code!
}                                       //  We also declaring variables in the function.

double read_and_sum(int s)
{
    Vector v;                                            
    vector_init(v,s);                   // Since vector_init takes a reference, we can just throw the 'v' in!
    for (int i = 0; i != s; ++i) {
        std::cin >> v.elmt[i];
    }
    double sum = 0;
    for (int i = 0; i != s; ++i) {
        sum += v.elmt[i];
    }
    std::cout << "Sum = " << sum << std::endl;
    return sum;
}

int array_test() 
{
    int* arr[5];
    for (int i = 0; i != 5; ++i) {
        int x = i;
        arr[i] = &x;
        std::cout << "POINTING TO: " << *arr[i] << std::endl;       
        std::cout << "VALUE      : " << arr[i] << std::endl;
        std::cout << "ADDRESS    : " << &arr[i] << std::endl;      
    }
    return 0;
}

void referencing_with_for_loop() 
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (int& x : v) {                  // Here we use a reference to x
        std::cout << x;                 // This allows us to actually increment x without
        ++x;                            // having to make a copy. We increment the actual 
    }                                   // variable in the memory location.
    for (int x = 0; x != 10; ++x) {
        std::cout << v[x] << std::endl;
    }
}

void Print(int value)
{
    std::cout << value << std::endl;
}


template<typename T>
T Printing_with_template(T value)
{
    return value;
}

template<typename T>
class StudentRecord {
private:
    const int size = 5;
    T grade;
    int studentId;
public:
    StudentRecord(T input);
    void setId(int idIn);
    void printGrades();
};

template<typename T>
StudentRecord<T>::StudentRecord(T input)
{
    grade = input;
}

template<typename T>
void StudentRecord<T>::setId(int idIn)
{
    studentId = idIn;
}

template<typename T>
void StudentRecord<T>::printGrades()
{
    std::cout << studentId << ": " << grade;
}

void Vectors_n_Iterators()
{
    std::vector<int> vectorInts;
    std::vector<int>::iterator it;
    std::cout << "vectorInts has " << vectorInts.size() << " elements \n";
    std::cout << "\nAdding four elements to vector \n";
    vectorInts.assign(4,3);
    std::cout << "vectorInts has " << vectorInts.size() << " elements \n";
    std::cout << "Elements in vectors: ";
    for (it = vectorInts.begin(); it != vectorInts.end(); ++it) 
        std::cout << *it << " ";
}

struct Entry {
    std::string name;
    int value;
};

Entry read_entry(std::istream& is)
{
    std::string s;
    int i;
    is >> s >> i;
    return {s,i};
}

void using_Entry() 
{
    Entry e = read_entry(std::cin);
    std::cout << "{ " << e.name << "," << e.value << " } \n";
}

class Vector1 {
private:
    double* elem;                                   // elem points to an array of sz doubles
    int sz;
public:
    Vector1(int s) 
        :   elem{new double[s]}, sz{s}              // constructor: acquire resources
    {
        for (int i=0; i!=s; ++i)                    // initialize elements
            elem[i]=0;
    }
    ~Vector1() { delete[] elem; }                    // destructor: release resources

    double& operator[](int i);
    int size() const;
};


int main() 
{
    using_Entry();
    return 0;
}


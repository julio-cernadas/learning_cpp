/* lvalue vs rvalue , and understanding references
rvalue ->  x + y ; my_func(); 2 + x; cannot be located in memory
lvalue ->  x; y; any variable with an address/location

lvalue reference  -> locator value, located in memory
int a = 5;          // a is a lvalue
int& b = a;         // b is a lvalue reference

rvalue reference  -> register value, registered temporarily in CPU
int&& c;

basic example...
void printInt(int&  i) {std:cout << i << std::endl;}    //lvalue parameter
void printInt(int&& i) {std:cout << i << std::endl;}    //rvalue parameter


int a = 5;          // a = lvalue -> it has an address
printInt(a);        // calls printInt with lvalue
printInt(5);        // calls printInt with rvalue

realistic example below...
*/

class boVector {
private:
    int size;
    double* arr;
public:
    // Referencing an lvalue, object that is already in memory
    boVector(const boVector& rhs) {     // Copy Constructor
        size = rhs.size;                // Expensive!
        arr  = new double[size];
        for (int i = 0; i != size; ++i) {
            arr[i] = rhs.arr[i];
        }
    }

    // Referencing an rvalue, object that is not in memory
    boVector(boVector&& rhs) {          // Move Constructor
        size = rhs.size;                // Here we directly 
        arr  = rhs.arr;                 // steal resources
        rhs.arr = nullptr;              // rather than copy
    }                                   // Much more efficient!
    // With the move constructor, we are taking in rhs's resources,
    // afterwards since we take in an array, we must set the arr
    // pointer to a nullptr. The arr never changed memory location
    // it simply changed owners.

    ~boVector() {
        delete[] arr;
    }    
};

/* Move Semantics
Move semantics allows an object, under certain conditions, to take
ownership of some other object's external resources. As we started 
to do in the above example. 

This helps turn expensive copies into cheap movements. 

However, in order for this to work, then the object has to handle
at least one external resource, aka pointer to something.

when we say "a is moved into b", then it means that a has
transferred ownership of a resource or resources into b. The 
resource that was transferred itself always stays at the same 
place in memory but the onwership has changed. That is a move
semantic, not so bad huh!
*/


/* Braces vs Parenthesis vs Equals
My_class w1;                    calls default constructor
My_class w2 = w1;               not an assignment, calls copy constructor
w1 = w2;                        an assignment, calls copy constructor

std::vector<int> v = {1,3,5};   using equal and braces
std::vector<int> v{1,3,5};      same result as above.

The main reason to use braces is b/c of uniform initialization
and warnings of narrowing conversion, ex -> double to int.
double x, y, z;
int sum1{x + y + z};        compiler will warn of error of narrowing
int sum1 = x + y + z;       compiler won't warn at all


what about working with classes?
My_class w1(10)         calls My_class constructor with argument 10
My_class w2()           calls a function that return a My_class type
My_class w3{}           calls My_class with no arguments
My_class w3             same as above ^


another difference is in working with vectors!
std::vector<int> v1(10,20);     uses non-std::initializer list, thereby
creating a 10-element vector with all elements of value 20!

vs.

std::vector<int> v2{10,20};     uses std::initializer list, thereby
creating a 2 element vector with element 10 and 20!


Summary: start using braces over =, its a sacrafice that is worth it!
*/

// Start using Alias declarations over typdefs
template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;


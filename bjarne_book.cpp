#include <iostream>

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

int main() 
{
    
    return 0;
}
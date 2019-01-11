#include <iostream>


// struct Vector 
// {
//     int size;
//     double* elmt;
// };

// void vector_init(Vector& v, int s)
// {
//     v.elmt = new double[s];
//     v.size = s;
// }

// double read_and_sum(int s)
// {
//     Vector v;                                   
//     vector_init(v,s);
//     for (int i = 0; i != s; ++i) {
//         std::cin >> v.elmt[i];
//     }
//     double sum = 0;
//     for (int i = 0; i != s; ++i) {
//         sum += v.elmt[i];
//     }
//     std::cout << "Sum = ";
//     return sum;
// }

int main() 
{
    int example[] = {1,2,3,4,5};
    for (auto i : example) {
        std::cout << example[i] << std::endl;
        
    }
    return 0;
}

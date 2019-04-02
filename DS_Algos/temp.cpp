#include<iostream>
#include<sstream>
#include<vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

template <typename T>
class Car {
protected:
    int color = 0;
    T currentSpeed;
    T maxSpeed;
};

template <typename T>
class PlayerCar : public Car<T> {
public:
    void Print() {
        cout << color << endl;
    }
};

int main()
{
    PlayerCar<int> temp;
    temp.Print();
    return 0;
}
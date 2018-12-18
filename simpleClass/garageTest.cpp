#include <iostream>
#include "Garage.h"
using namespace std;
using namespace CarStock;
int main()
{
    cout << "test car" << endl;

    Car car1("Ford", "3", 1234);
    cout << car1.getCarMake() << "," << car1.getAge() << "," << car1.getID() << endl;
}
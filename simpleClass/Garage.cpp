#include<iostream>
#include "Garage.h"
using namespace std;
namespace CarStock {
    Car::Car(const std::string& make, const std::string& age, int id )
    : mCarMake(make)
    , mAge(age)
    , mId(id)
    {}
    const std::string& Car::getAge() const {
        return mAge;
    }
    const std::string& Car::getCarMake() const {
        return mCarMake;
    }

    int Car::getID() const {
        return mId;
    }
}
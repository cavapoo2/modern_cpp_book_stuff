#pragma once
#include <string>
namespace CarStock
{

const int maxSpace = 50;
class Car
{
  public:
    Car(const std::string &make, const std::string &age, int id);
    const std::string &getCarMake() const;
    const std::string &getAge() const;
    int getID() const;

  private:
    std::string mCarMake;
    std::string mAge;
    int mId;
};
}

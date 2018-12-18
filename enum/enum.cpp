#include <iostream>

using namespace std;

enum class MyEnum
{
    Val1,
    Val2 = 100,
    Val3
};

std::ostream &operator<<(std::ostream &os, const MyEnum &obj)
{
    os << static_cast<std::underlying_type<MyEnum>::type>(obj);
    return os;
}

int main()
{
    cout << MyEnum::Val1 << "," << MyEnum::Val2 << "," << MyEnum::Val3 << "\n";
}

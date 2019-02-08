//----------------Initialization.cpp
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
template <class T>
struct Vector_Wrapper {
    std::vector<T> vctr;
    Vector_Wrapper(std::initializer_list<T> l) : vctr(l) {}
    void Append(std::initializer_list<T> l) 
    { vctr.insert(vctr.end(), l.begin(), l.end());}
};
int main() {
    Vector_Wrapper<int> vcw = {1, 2, 3, 4, 5}; // list-initialization
    vcw.Append({6, 7, 8});      // list-initialization in function call
    for (auto n : vcw.vctr) { std::cout << n << ' '; }
    std::cout << '\n';
    Vector_Wrapper<double> vcd = {1.1, 2.2, 3.3, 4.4, 5.5}; // list-initialization
    vcd.Append({6.6, 7.7, 8.8});      // list-initialization in function call
    for (auto n : vcd.vctr) { std::cout << n << ' '; }
    std::cout << '\n';


}

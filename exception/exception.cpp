#include <stdexcept>
#include <iostream>

double divZero(double num, double denom) {
    if(denom == 0) {
        throw std::invalid_argument("Can't divide by zero");
    }
    return num/denom;
}

using namespace std;
int main(){
    try {
        cout << divZero(3.3,0.2) << "\n";
        cout << divZero(3.3,0) << "\n";
    }catch (const std::exception& exception) {
        cout << "Got ya:" << exception.what() << "\n";
    }
    return 0;
}
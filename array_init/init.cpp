#include<iostream>
#include<array>

using namespace std;

void printArray(int* a,int len) {
    for(int i=0; i < len; ++i) {
        cout << a[i] << ",";
    }
    cout << "\n";

}

int main(){
    int a1[3] = {0};
    int a2[3] = {2};
    int a3[3] = {1,2,3};
    array<int,3> a4 = {4,5,6};

    printArray(a1,3);
    printArray(a2,3);
    printArray(a3,3);
    printArray(&a4[0],3);


    return 0;
}
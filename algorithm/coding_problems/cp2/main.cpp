/*Given an array of integers, return a new array such that each element at 
index i of the new array is the product of all the numbers in the original 
array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output
 would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1],
  the expected output would be [2, 3, 6].

Follow-up: what if you can't use division? 
*/
#include<vector>
#include<iostream>
using namespace std;
template<typename Cont>
void show(const Cont& c) {
    for(auto &v : c) {
        cout << v << " ";
    }
    cout << "\n";
}
vector<int> productAtI(const vector<int>&in) {
    vector<int> res;
    for(int i=0; i < in.size(); i++) {
        int sum=1;
        for(int j =0; j < in.size(); j++) {
            if (j == i) continue;
             sum *= in[j];   
        }
        res.push_back(sum);
    }
    return res; 
}

int main(int argc, char* argv[]) {

    vector<int> data={1,2,3,4,5};
    vector<int> res  = productAtI(data);
    show(res); 
    data = { 3,2,1};
    res = productAtI(data);
    show(res);

}
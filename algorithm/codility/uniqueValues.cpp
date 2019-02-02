#include<map>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    map<int,int> mc;
    int unique=0;
    for(const auto &v : A ) {
        if(mc.count(v) == 0) {
            mc[v]=1;
            unique++;
        }
    }
    return unique;
}

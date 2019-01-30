#include<vector>
#include<limits>
using namespace std;
template<typename Cont>
void show(const Cont& c) {
    for(const auto &v : c) {
        cout << v << ",";
    }
    cout << endl;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    //try the 2 average
    vector<double> avg;
    vector<double> avg3;
    
    for(int i=0; i < A.size()-1; ++i) {
        double val = (A[i] + A[i+1]) / 2.0;
        double val3=0.0;
        if (i < A.size()-2) {
            val3 = (A[i] + A[i+1] + A[i+2])/ 3.0;
						avg3.push_back(val3);
        }
        avg.push_back(val);
    }
    show(avg);
    
    double min = numeric_limits<double>::max();
    int idx=-1;
    for(int i=0; i < avg.size(); ++i){
        if( avg[i] < min) {
            min = avg[i];
            idx=i;
        } 
        if(i < avg3.size()) {
            if(avg3[i] < min) {
                min = avg3[i];
                idx = i;
            }       
        }
    }
    return idx;
}

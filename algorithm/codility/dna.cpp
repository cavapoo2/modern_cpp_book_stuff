#include<vector>
#include<map>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
template<typename Cont>
void show(const Cont & cont) {
    for(const auto &v : cont) {
        cout << v << ",";
    }
    cout << endl;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    //get prefixes
    map<char,int> mci = {{'A',1},{'C',2},{'G',3},{'T',4}};
    if(S.size() == 1) {
        return vector<int>(1,mci[S[0]]);
    }
    vector<int> ap(S.size()+1,0),cp(S.size()+1,0),gp(S.size()+1,0);
    for(int i=0; i < S.size(); ++i) {
        if(S[i] == 'A') {
            ap[i+1] = ap[i] + 1;
            cp[i+1] = cp[i];
            gp[i+1] = gp[i];
        }else if(S[i] == 'C') {
            ap[i+1] = ap[i];
            cp[i+1] = cp[i] + 1;
            gp[i+1] = gp[i];
        }else if(S[i] == 'G') {
            ap[i+1] = ap[i];
            cp[i+1] = cp[i];
            gp[i+1] = gp[i] + 1;
        }else {
             ap[i+1] = ap[i];
            cp[i+1] = cp[i];
            gp[i+1] = gp[i];
        }
    }
  //  show(ap);
//    show(cp);
  //  show(gp);
    vector<int> res;
    //now interate the positions
    for(int i=0; i < P.size(); ++i) {
        if(ap[Q[i]+1] - ap[P[i]] > 0){ // change happend
            res.push_back(1);
        }else if(cp[Q[i]+1] - cp[P[i]] > 0 ) {
            res.push_back(2);
        }else if (gp[Q[i]+1] - gp[P[i]] > 0 ) {
            res.push_back(3);
        }else {
            res.push_back(4);
        }
    }
    return res;
}
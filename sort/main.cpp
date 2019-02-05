/*We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

  We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

  The figure below shows discs drawn for N = 6 and A as follows:

  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0
  There are eleven (unordered) pairs of discs that intersect, namely:

  discs 1 and 4 intersect, and both intersect with all the other discs;
  disc 2 also intersects with discs 0 and 3.
  Write a function:

  int solution(int A[], int N);

  that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

  Given array A shown above, the function should return 11, as explained above.

  Write an efficient algorithm for the following assumptions:

  N is an integer within the range [0..100,000];
  each element of array A is an integer within the range [0..2,147,483,647].
  */
#include<iostream>
#include<vector>
#include<vector>
#include<utility>
#include <iostream>
#include<algorithm>
#include<limits>
using namespace std;
vector<pair<long long,long long>> transform(vector<int> & in) {
  vector<pair<long long,long long>> res;
  for(long long i=0; i < in.size(); ++i) {
    res.push_back(make_pair(i-static_cast<long long>(in[i]),i+ static_cast<long long>(in[i])));
  }
  return res;
}
template<typename Cont>
void show(const Cont& c) {
  for (const auto&v : c) {
    // cout << v.first << "," << v.second << endl;
  }
  // cout << endl;
}
int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  vector<pair<long long,long long>> vp = transform(A);
  sort(vp.begin(),vp.end(),
      [](const auto&a, const auto&b) -> bool
      {
      return a.first < b.first;
      });
  int count =0; 
  show(vp);   
  for(int i=0; i < vp.size()-1;++i){
    for(int j=i+1; j < vp.size();j++){
      if(vp[j].first >= vp[i].first && vp[j].first <= vp[i].second){
        count++;
        if (count > 10000000) return -1;
      }
      else break;

    }
  }
  return count;
}
using namespace std;

int main (int argc,char* argv[])
{
  cout << numeric_limits<int>::min() << "," << numeric_limits<int>::max() << endl;
  cout << numeric_limits<long int>::min() << "," << numeric_limits<long int>::max() << endl;
  //vector<int> v = {10,13,1,7,22,33};
  vector<int> v = {1,5,2,1,4,0};
  int res = solution(v);
  cout << "res=" << res << endl;
  v = {1,2147483647,0};
  res = solution(v);
  cout << "res=" << res << endl;

  return 0;
}

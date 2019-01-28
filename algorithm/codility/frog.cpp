/*
 *A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

int solution(int X, int A[], int N);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return −1.

For example, given X = 5 and array A such that:

  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and X are integers within the range [1..100,000];
each element of array A is an integer within the range [1..X].
 */
#include<map>
using namespace std;
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.empty() == true) return -1;
    if((A.size() == 1) && A[0] == X) return 0;
    map<int,bool> leaf;
    for(int i =0; i < X+1;++i) {
        leaf[i]=false;
    }
    int cur_pos = A[0];
    leaf[cur_pos]=true;
    for(size_t i=1; i < A.size(); ++i) {
        leaf[A[i]]= true;
        //travel if possible
      //  cout << "cur_pos=" << cur_pos << ",new leaf=" << A[i] << endl;
        while(leaf[cur_pos+1] == true) {
            cur_pos++;
        //    cout << "move to" << cur_pos << endl;
            if(cur_pos == X) return i;
        }
    }
    return -1;
}

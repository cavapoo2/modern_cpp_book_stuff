/*
 You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.

The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:

int solution(int H[], int N);

that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:

  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8
the function should return 7. The figure shows one possible arrangement of seven blocks.
https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array H is an integer within the range [1..1,000,000,000].
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int solution(vector<int> &H){
  stack<int> s;
  int count=0;
  int sum=0;
  for(int i =0; i < H.size(); ++i){
    if(s.empty()){
      count++;
      sum+= H[i];
      s.push(H[i]);
    }
    else
    {
      if(H[i] == sum) // next value is same as stack value
      {
        continue; // nothing to do
      }
      else if(H[i] < sum)
      {
        if(s.size() == 1) {
          //have remove it
          s.pop();
          s.push(H[i]);
          count++;
          sum = H[i];
        }
        else 
        {
          while(!s.empty() && sum > H[i]) 
          {
            int v = s.top();
            s.pop();
            sum -= v;
          }
          if(s.empty()) {
            s.push(H[i]);
            count++;
            sum = H[i];
          }else {
            int diff = H[i] - sum;
            if(diff != 0)
            {
              s.push(diff);
              count++;
              sum+= diff;
            }
          }
        }
      }
      else // H[i] > sum
      {
        int diff = H[i] - sum;
        s.push(diff);
        sum += diff;
        count++;
      }
    }

  }
  return count;

}
int main(int arg, char* argv[])
{
  vector<int> d = {8,8,5,7,9,8,7,4,8};
  int res = solution(d);
  cout << "res=" << res << endl;
  return 0;
}


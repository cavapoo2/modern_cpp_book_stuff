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


#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;
template<typename Cont>
void show(const Cont&in) {
    for(auto &v: in) {
        cout << v << endl;
    }
}
//note this code returns the smallest possible value not int the input vector. ignore negative values
//the value must be greater than zero
bool greaterThanZero(int i)
{
    return i > 0;
}

int getMin(vector<int> &in)
{
    sort(in.begin(), in.end());
    //move to point away from negative values
    vector<int>::iterator it = std::find_if(in.begin(), in.end(), greaterThanZero);
    //in case of duplicates
    set<int> si(it,in.end());
    int i = 1;
    set<int>::iterator iter;
    for (iter = si.begin();iter != si.end(); ++iter)
    {
//        cout << "comp " << " it =" << *iter << " i = " << i << endl;
        if (i < *iter)
        {
            return i;
        }
        i++;
    }
    return i; //just return the last value 
}
int main(int argc, char *argv[])
{

    vector<int> vi{-1, -3, -5, 3, 6, 10, 14, 3, 22, 65};
    int min = getMin(vi);
    cout << "min is " << min << endl;
    vi = {1,3,6,4,1,2};
    min = getMin(vi);
    cout << "min is " << min << endl;
    vi = {-1,-3};
     min = getMin(vi);
    cout << "min is " << min << endl;

}
/*Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>
using namespace std;
bool add2N(const vector<int> &in, int N)
{
    for (int i = 0; i < in.size(); i++)
    {
        for (int j = i + 1; j < in.size(); j++)
        {
            int res = in[i] + in[j];
            if (res == N)
                return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{

    vector<int> data = {10, 15, 3, 7};
    cout << add2N(data,17) << endl;
}
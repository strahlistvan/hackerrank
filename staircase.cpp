#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    cout<<"Size of staircase: ";
    cin >> n;

    for (int i=0; i<n; ++i)
    {
      for (int j=n-1; j>=0; --j)
      {
          char ch = (j>i)?' ':'#';
          cout<<ch;
      }
      cout<<endl;
    }
    return 0;
}

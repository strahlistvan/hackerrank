#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    const int n = 3;
    vector< vector<int> > a(n,vector<int>(n));
    a[0][0] =11;
    a[0][1] = 2;
    a[0][2] = 4;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 10;
    a[2][1] = 8;
    a[2][2] = -12;

    long long sum_prim = 0, sum_sec = 0;
    for (int i=0; i<n; ++i)
    {
       sum_prim+=a[i][i];
       sum_sec+=a[i][n-1-i];
    }
    cout<<abs(sum_prim- sum_sec)<<endl;
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* How many changes needed if you want to reduce all given words to palindromes? (you can only reduce the letter's value) */  
int main() 
{ 
    int cases;
    cin>>cases;
    for (int i=0; i<cases; ++i)
    {
        string str;
        cin>>str;
        int n = str.size();
        int changes_count = 0;
        for (int i=0; i<n/2+1; ++i)
        {
         //   cout<<str[i]<<"="<<str[n-1-i]<<endl;
            if (str[i]!=str[n-1-i])
            {
                changes_count += abs(str[i]-str[n-1-i]);
                str[i] = str[n-1-i] = min(str[i], str[n-1-i]);
            }
        }
        cout<<changes_count<<endl;
    }
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t; //test cases
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int max_cycles;
        cin >> max_cycles;
        int height = 1; //starting 
       
        for (int cycles = 1; cycles<=max_cycles; ++cycles)
        {
            if (cycles%2==1) //summer
                height*=2;
            else           //spring
                ++height;
        }
        cout<<height<<endl;
    }
    return 0;
}

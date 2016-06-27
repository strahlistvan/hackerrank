#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//convert time format from AM/PM to 24-hours format
int main()
{
    string time = "12:40:22AM";

    if (time.substr(8, 2) == "PM")
    {
        int hours = 10*(time[0]-'0') + time[1]-'0';
        if (hours!=12) //add twelve if > 12
             hours+=12;
        time[0] = (hours/10) + '0';
        time[1] = (hours%10) + '0';
    }
    //instead of 12:mm:ss -> 00:mm:ss
    if (time.substr(8, 2) == "AM" && time.substr(0, 2)=="12")
        time[0] = time[1] = '0';

    time = time.substr(0, 8);
    cout<<time<<endl;
    return 0;
}

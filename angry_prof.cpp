#include <iostream>
using namespace std;

int main()
{
    int test_count;
    cout<<"Test case count: ";
    cin >> test_count;
    for(int case_count = 0; case_count < test_count; ++case_count)
    {
        int student_count;  //maximal students of the class
        int least_students; //cancel the class is there is not at least k students
        
        cout<< "student count: ";
        cin >> student_count;
        cout<<"least students: ";
        cin >> least_students;
        
        int arrive_time = 0;
        int students_in_class = 0; //how many students in class at time 0
        for(int a_i = 0; a_i < student_count; a_i++)
        {
           cin >> arrive_time;
           if (arrive_time <= 0)
			 ++students_in_class;
        }
        
        if (students_in_class < least_students)
			cout<<"YES"<<endl;   //cancel the class if there is not enought student
		else
			cout<<"NO"<<endl;   //no cancel
        
    }
    return 0;
}

#include <iostream>
#include <bitset>
using namespace std;

//Pangrams are sentences constructed by using every letter of the alphabet at least once
int main() 
{
    string str;
    cout<<"Write a sentence: ";
    getline(cin, str);
    
    //can't be the string pangram if it's too short.
    if (str.size() < 26)
	{
		cout<<"not pangram"<<endl;
		return 0;
	}
	
	bitset<26> contain_char;
	for (int i=0; i<str.size(); ++i)
	{
		//to lower case
		if (str[i]>='A' && str[i]<='Z')
			str[i] = str[i] -'A' + 'a';
		
		//set the current bit of the character's index in bitset
		if (str[i]>='a' && str[i]<='z')
			contain_char.set(str[i]-'a');
	}
      
     cout<<contain_char.to_string()<<endl;
      
    if (contain_char.count() == 26)
		cout<<"pangram"<<endl;
	else
		cout<<"not pangram"<<endl;
      
    return 0;
}

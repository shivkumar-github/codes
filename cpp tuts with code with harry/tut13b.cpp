/*
learning c type strings and its manipulation
No.	String Function	Description
1	strcat(str1, str2)	Concatenates str2 at the end of str1
2	strcpy(str1, str2)	Copies str2 to str1
3	strlen(str1)	Gives the length of str1
4	strcmp(str1, str2)	Returns 0 if equal
5	strchr(str, ch)	Returns pointer to first occurrence of ch in str
6	strstr(str1, str2)	Returns pointer to first occurrence of str2 in str1
7	strdup	Duplicates the string
8	strlwr(str1)/strupr(str1)	Lower or upper case
9	strev(str1)	Reverses the string


strcat(string1,string2) --> concatenates string2 and strign1 snd stores it in the string1
strlen(string1) --> gives length of the string1
strchr(string1,'t') --> returns the pointer of first occurence of character 't' in the string1 
if put in cout then prints the string after the first occurance of the character 't'
strrev(str1) --> reverses the string1
strlwr() and strupr() convert the string to lowercase and uppercase respectively


suppose 
cstring1[string_size] is a c type string and cppstring1 is a cpp string(object of string class) then 
 to accept the c and C++ strings from user including spaces 
 we can use 
 1) for c type strings
 cin.getline(cstring1,string_size);
 2) for c++ stirngs 
 getline(cin,cppstring1);
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char string1[100];
    char string2[100];
    char string3[100];

    cout << "Enter the string1 : " << endl;
    cin >> string1;
    cout << "Enter the string2 : " << endl;
    cin >> string2;

    cout << "strlen(string1) = " << strlen(string1) << endl;
    cout << "strcpy(string3, string1) = " << (strcpy(string3, string1)) << endl;
    cout << "strcat(string1, string2) = " << (strcat(string1, string2)) << endl;
cout<< "string1 = " << string1 << endl;
    // this will give the string further from that occurance
    cout << "pointer of first occurance of character i in string2 : " << (strchr(string2, 't')) << endl;
    cout << "strlwr(string2) = " << strlwr(string2) << endl;
    cout << "strupr(string2) = " << strupr(string2) << endl;
    cout << "Reverse of the string3 is :" << strrev(string3) << endl;
    return 0;
}

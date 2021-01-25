/* 
Write a function Strcpy to copy one string to another with suitable formal parameters declarations. Following
points must be considered.
a) Source string must not get modified
b) Target string is allowed to get modified
c) The Pointers must be constant pointers.
Use it to copy some strings 
*/

#include <iostream>
using namespace std;

void strcpy(string *const t, const string *const s)
{
    *t = *s;
}

int main()
{
    const string source = "Soumitri";
    string target;
    cout << "Source string: " << source << endl;
    strcpy(&target, &source);
    cout << "Target after copying: " << target;
    return 0;
}
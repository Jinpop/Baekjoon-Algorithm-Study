#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s1, s2, s3 = "", s4 = "";
    cin >> s1 >> s2;

    for (auto ele = s1.rbegin(); ele != s1.rend(); ele++)
    {
        s3.push_back(*ele);
    }

    for (auto ele = s2.rbegin(); ele != s2.rend(); ele++)
    {
        s4.push_back(*ele);
    }

    if (s3 > s4)
    {
        cout << s3;
    }
    else 
    {
        cout << s4;
    }

    return 0;
}
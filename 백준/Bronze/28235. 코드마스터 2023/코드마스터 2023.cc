#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    switch (s[0])
    {
    case 'S':
        cout << "HIGHSCHOOL";
        break;
    case 'C':
        cout << "MASTER";
        break;
    case '2':
        cout << "0611";
        break;
    case 'A':
        cout << "CONTEST";
        break;
    default:
        break;
    }

    return 0;
}
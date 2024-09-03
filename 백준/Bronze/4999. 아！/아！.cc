#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string temp1, temp2;
    cin >> temp1 >> temp2;

    if (temp1.size() >= temp2.size())
    {
        cout << "go";
    }
    else {
        cout << "no";
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string n, m = "";
    cin >> n;

    for (auto i = n.rbegin(); i != n.rend(); i++)
    {
        m.push_back(*i);
    }


    if (n == m)
    {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
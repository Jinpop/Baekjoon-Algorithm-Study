#include <iostream>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int ten = 10;

    set<int> s;

    while (ten--)
    {
        int temp;
        cin >> temp;
        s.insert(temp%42);
    }

    cout << s.size();

    return 0;
}
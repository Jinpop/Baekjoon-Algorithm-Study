#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <stack>
using namespace std;

int num[27][200001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string str;
    int n;
    cin >> str >> n;

    int idx = 0;

    for (auto ele : str)
    {
        num[ele - 'a'][idx]++;
        idx++;
        for (int i = 0; i < 27; i++)
        {
            num[i][idx] = num[i][idx - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (a != 0)
        {
            cout << num[c - 'a'][b] - num[c - 'a'][a - 1] << "\n";
        }
        else
        {
            cout << num[c - 'a'][b] << "\n";
        }
    }

    return 0;
}

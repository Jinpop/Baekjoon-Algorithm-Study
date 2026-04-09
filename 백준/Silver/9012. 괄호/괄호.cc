#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--)
    {
        string temp;
        cin >> temp;

        stack<char> s;

        for (int i = 0; i < temp.size(); i++)
        {

            if (temp[i] == '(')
            {
                s.push('(');
            }
            else
            {
                if (s.empty())
                {
                    s.push('f');
                    break;
                }
                s.pop();
            }
        }

        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
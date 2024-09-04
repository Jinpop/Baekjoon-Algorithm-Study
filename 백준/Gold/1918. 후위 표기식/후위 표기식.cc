#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string temp;
    stack<char> s;
    cin >> temp;
    
    for (auto ele : temp)
    {
        if (ele >= 'A' && ele <= 'Z')
        {
            cout << ele;
        }
        else
        {
            if (ele == '+' || ele == '-')
            {
                while (!s.empty() && s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(ele);
            }
            else if (ele == '*' || ele == '/')
            {
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cout << s.top();
                    s.pop();
                }
                s.push(ele);
            }
            else if (ele == ')')
            {
                while (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                s.push(ele);
            }
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}

// A+B*C-D/E
//  ABC*+DE/-

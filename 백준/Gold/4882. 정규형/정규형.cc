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

    int idx = 0;

    while (1)
    {
        idx++;
        string temp;
        cin >> temp;

        if (temp == "()")
        {
            break;
        }

        // 가장 깊은 괄호가 몇번째인지 확인함.
        int cnt = 0;
        int max_depth = 0;
        for (auto ele : temp)
        {
            if (ele == '(')
            {
                cnt++;
                if (max_depth < cnt)
                {
                    max_depth = cnt;
                }
            }
            else if (ele == ')')
            {
                cnt--;
            }
        }

        //
        bool flag = 0;
        stack<char> s;
        for (auto ele : temp)
        {
            if (ele == '(')
            {
                cnt++;
                s.push(ele);
            }
            else if (ele == ')')
            {

                pair<bool, bool> temp_result = {0, 0};
                while (s.top() != '(')
                {
                    if (s.top() == 'T')
                    {
                        temp_result.first = 1;
                    }
                    else
                    {
                        temp_result.second = 1;
                    }
                    s.pop();
                }
                s.pop();

                // AND 연산
                if ((max_depth - cnt) % 2 == 0)
                {
                    if (temp_result.second == 1)
                    {
                        s.push('F');
                    }
                    else
                    {
                        s.push('T');
                    }
                }
                // OR 연산
                else
                {
                    if (temp_result.first != 1)
                    {
                        s.push('F');
                    }
                    else
                    {
                        s.push('T');
                    }
                }

                cnt--;
            }
            else
            {
                s.push(ele);
            }
        }

        if (s.top() == 'T')
        {
            cout << idx << ". " << "true\n";
        }
        else
        {
            cout << idx << ". " << "false\n";
        }
    }

    return 0;
}
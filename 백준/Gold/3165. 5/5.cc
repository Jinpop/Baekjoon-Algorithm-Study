#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int c;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long s, k;
    cin >> s >> k;
    s++;

    string n = to_string(s);
    int cnt = 0;
    for (auto ele : n)
    {
        if (ele == '5')
        {
            cnt++;
        }
    }

    int idx = n.size() - 1;
    while (cnt < k)
    {
        if (n[idx] != '5')
        {
            if (n[idx] < '5')
            {
                n[idx] = '5';
                cnt++;
            }
            else
            {
                int temp_cnt = 0;
                for (int j = 0; j < n.size() - idx; j++)
                {
                    temp_cnt++;
                    if (n.back() == '5')
                    {
                        cnt--;
                    }
                    n.pop_back();
                }

                while (n.back() == '9' && n.size() != 0)
                {
                    temp_cnt++;
                    n.pop_back();
                }

                if (n.size() == 0)
                {
                    n.push_back('1');
                }
                else
                {
                    if (n.back() == '5')
                    {
                        cnt--;
                    }
                    else if (n.back() == '4')
                    {
                        cnt++;
                    }

                    n.back()++;
                }

                for (int j = 0; j < temp_cnt; j++)
                {
                    n.push_back('0');
                }
            }
            idx = n.size() - 1;
        }
        else
        {
            idx--;
            if (idx < 0)
            {
                long long temp_num = pow(10, n.size());
                cnt = 0;
                n = to_string(temp_num);
                idx = n.size() - 1;
            }
        }
    }

    cout << n;

    return 0;
}
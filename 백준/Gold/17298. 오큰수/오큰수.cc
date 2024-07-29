#include <iostream>
#include <stack>
using namespace std;
int num[1000001];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    stack<int> s;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];

        while (!s.empty() && num[s.top()] < num[i])
        {
            num[s.top()] = num[i];
            s.pop();
        }

        s.push(i);
    }   

    while(s.size())
    {
        num[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}
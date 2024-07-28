#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    queue<int> v;
    long long list[21] = {0};
    cin >> n >> k;

    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        count += list[temp.length()];
        list[temp.length()]++;
        v.push(temp.length());

        if (v.size() > k)
        {
            list[v.front()]--;
            v.pop();
        }
    }

    cout << count;

    return 0;
}
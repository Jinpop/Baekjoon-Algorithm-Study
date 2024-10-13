#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

queue<long long> q;
int num[100][100];
long long mov[100][100];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}
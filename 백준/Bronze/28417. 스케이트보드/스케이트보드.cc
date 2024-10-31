#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int result = 0;

    for (int i = 0; i < n; i++)
    {   
        int temp1, temp2;
        cin >> temp1 >> temp2;
        int sum = max(temp1, temp2);
        
        priority_queue<int> q;
        for (int j = 0; j < 5; j++)
        {
            int temp;
            cin >> temp;
            q.push(temp);
        }

        sum+=q.top();
        q.pop();
        sum+=q.top();

        result = max(result, sum);
    }

    cout << result;

    return 0;
}
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int cut;
    float index = n * 0.15;

    while (index >= 1)
    {
        index -= 1;
    }

    // cout << "index " << index << "\n";
    if (index >= 0.5)
    {
        cut = n * 0.3 / 2 + 1;
    }
    else
    {
        cut = n * 0.3 / 2;
    }

    // cout << cut << "cut\n";
    vector<int> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    int total = 0;
    for (int i = cut; i < n - cut; i++)
    {
        // cout << list[i] << " ";
        total += list[i];
    }

    float div = float(total) / float(n - cut - cut);
    // cout << total << "/" << (n - cut - cut) << "\n";
    // cout << "\n" << div << " div \n";

    while (div >= 1)
    {
        div -= 1;
    }

    if (div >= 0.5)
    {
        cout << total / (n - cut - cut) + 1;
    }
    else
    {
        cout << total / (n - cut - cut);
    }

    return 0;
}
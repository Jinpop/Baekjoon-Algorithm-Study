#include <iostream>
using namespace std;

int euclid(int a, int b)
{
    int big = max(a,b);
    int small = min(a,b);

    if (small == 0)
    {
        return big;
    }
    else{
        return euclid(small, big%small);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, num;

    cin >> n;
    cin >> num;

    n--;
    while (n--)
    {
        int temp;

        cin >> temp;
        int div = euclid(num, temp);

        cout << num/div << "/" << temp/div << "\n";
    }

    return 0;
}
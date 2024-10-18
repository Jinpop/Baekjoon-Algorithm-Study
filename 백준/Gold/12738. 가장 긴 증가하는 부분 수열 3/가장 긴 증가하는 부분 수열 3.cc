#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

long num[1000000];
vector<long> list;

int idx_bsearch(int k) {
	int lo = 0, hi = list.size() - 1, mid;

	while (lo < hi) {
		mid = lo + (hi - lo) / 2;

		if (list[mid] >= k) 
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    list.push_back(num[0]);
    for (int i = 1; i < n; i++)
    {
        if (num[i] > list.back())
        {
            list.push_back(num[i]);
        }
        else {
            list[idx_bsearch(num[i])] = num[i];
        }
    }

    cout << list.size() << "\n";

    return 0;
}

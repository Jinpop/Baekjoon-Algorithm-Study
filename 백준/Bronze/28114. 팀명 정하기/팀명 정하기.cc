#include <iostream>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;

bool compare(const pair<int, char*>& x, const pair<int, char*>& y) {
    if (x.first > y.first) {
        return true;
    }
    else if (x.first < y.first) {
        return false;
    }
    else {
        return strcmp(x.second, y.second) < 0; // First name alphabetically if years are equal
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    pair<int, char*> q_name[3];
    int year[3];

    for (int i = 0; i < 3; i++){    
        q_name[i].second = new char[6];
        cin >> q_name[i].first >> year[i] >> q_name[i].second;
    }

    sort(year, year+3);
    sort(q_name, q_name+3, compare);

    int name1 = year[0]%100*10000 + year[1]%100*100 + year[2]%100;
    char name2[4] = {q_name[0].second[0],q_name[1].second[0],q_name[2].second[0]};

    cout << name1 << "\n" << name2;

    return 0;
}
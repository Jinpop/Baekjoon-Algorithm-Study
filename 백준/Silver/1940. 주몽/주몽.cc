#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    unordered_set<int> list;

    int count = 0;
    while(n--){
        int temp;
        cin >> temp;
        
        if (list.find(m-temp) != list.end()){
            list.erase(m-temp);
            count++;
        }
        else{
            list.insert(temp);
        }
    }

    cout << count;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    unordered_map<string, int> map;

    for (int i = 0; i < n; i++){
        string temp, real;;
        cin >> real;
        temp = real;
        reverse(temp.begin(), temp.end());

        //뒤집었을 때 같은 경우
        if (temp == real){
            cout << real.length() << " "<< real[real.length()/2];
            break;
        }
        //뒤집은게 map에 있는 경우
        else if (map.find(temp) != map.end()){
            cout << real.length() << " "<< real[real.length()/2];
            break;
        }
        //처음 입력된 경우
        else{
            map[real]++;
        }
    }

    return 0;
}
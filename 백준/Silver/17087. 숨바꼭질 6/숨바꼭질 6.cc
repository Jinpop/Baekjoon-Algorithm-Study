#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd_multiple(const vector<int>& num) {
    int result = num[0];
    for (int x : num) {
        result = gcd(result, x);
        if (result == 1) {
            break; 
        }
    }
    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s;
    vector<int> num;

    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        int a;

        cin >> a;

        int y = a - s;

        if(y < 0){
            y *= -1;
        }

        num.push_back(y);
    }
    cout << gcd_multiple(num);

    return 0;
}
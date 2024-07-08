#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        long temp = 1, m, real;
        cin >> real >> m;

        for (int j = 0; j < m; j++){
            temp=temp*real%10;
        }

        if (temp == 0){
            temp = 10;
        }

        cout << temp <<"\n";
    }
    
    return 0; 
}
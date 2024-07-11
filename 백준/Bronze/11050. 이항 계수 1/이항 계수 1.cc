#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int fac[11] = {0};
    fac[1] = 1;
    fac[2] = 2;

    for(int i = 3; i <= 10; i++){
        fac[i] = i*fac[i-1];
    }

    int n, m;
    cin >> n >> m; 

    if (n != m && m != 0){
        cout << fac[n]/fac[m]/fac[n-m];
    }
    else{
        cout << 1;
    }
    

    return 0;
}
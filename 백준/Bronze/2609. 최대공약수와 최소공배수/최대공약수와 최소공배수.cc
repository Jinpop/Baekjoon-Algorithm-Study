#include <iostream>
using namespace std;

int euclid(int a, int b){
    if(b > a){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    if (a%b==0){
        return b;
    }
    return euclid(b, a%b);
}

int main(){
    int n, m;
    cin >> n >> m;

    int result = euclid(n, m);
    cout << result << "\n";
    cout << n*m/result;

    return 0;
}
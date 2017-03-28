#include <iostream>

using namespace std;
// D(n) = (n-1)(D(n - 1) + D(n - 2))

int D(int n){
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else 
        return (n - 1) * (D(n - 1) + D(n - 2));
}

int main(void){
    int res[20] = {0};
    res[1] = 0;
    res[2] = 1;
    for(int i = 3; i <= 4; i++){
        res[i] = (i - 1) * (res[i - 1] + res[i - 2]);
    }
    for(int i = 1; i <= 4; i++)
        cout << res[i] << endl; 

    return 0;
}

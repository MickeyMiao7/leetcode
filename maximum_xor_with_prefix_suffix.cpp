#include <iostream>
#include <algorithm>

long long max(long long *tmp, int start, int end){
    long long res = 0;
    for ( int i = start; i < end; i ++)
        res = std::max(res, tmp[i]);
    return res;
}

int main(void){
    long long input[100000];
    long long prefixSum[100000];
    long long suffixSum[100000];
    long long maximum = 0;
    int N;
    std::cin >> N;
    for ( int i = 0; i < N; i++ ){
        std::cin >> input[i];
    }

    if ( N == 1 )
        std::cout << 0 << std::endl;
    else if ( N == 2 )
        std::cout << (input[0] ^ input[1]) << std::endl;
    else{
        prefixSum[0] = 0;
        prefixSum[1] = input[0] ^ input[1];
        suffixSum[N - 1] = 0;
        suffixSum[N - 2] = input[N - 1] ^ input[N - 2];

        for ( int i = 2; i < N; i++ ){
            prefixSum[i] = prefixSum[i - 1] ^ input[i];
        }
        for ( int i = N - 3; i >= 0; i-- ){
            suffixSum[i] = input[i] ^ suffixSum[i + 1];
        }

        for ( int i = 0; i < N; i++ ){
            maximum = std::max(maximum, std::max(max(prefixSum, 0, i), max(suffixSum, i + 1, N))); 
        }
        std:: cout << maximum << std::endl;
    }


    return 0;
    
}

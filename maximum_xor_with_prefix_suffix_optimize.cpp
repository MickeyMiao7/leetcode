#include <iostream>
#include <algorithm>

int main(void){
    long long input[100000];
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
        long long prefixSum[100000];
        long long maxPrefixSum[100000];
        long long suffixSum[100000];
        long long maxSuffixSum[100000];
        long long maximum = 0;
        prefixSum[0] = 0;
        prefixSum[1] = input[0] ^ input[1];
        suffixSum[N - 1] = 0;
        suffixSum[N - 2] = input[N - 1] ^ input[N - 2];

        for ( int i = 2; i < N; i++ ){
            prefixSum[i] = prefixSum[i - 1] ^ input[i];
        }

        maxPrefixSum[0] = prefixSum[0];
        for ( int i = 1; i < N; i++){
            maxPrefixSum[i] = std::max(maxPrefixSum[i - 1], prefixSum[i]);
        }

        for ( int i = N - 3; i >= 0; i-- ){
            suffixSum[i] = input[i] ^ suffixSum[i + 1];
        }

        maxSuffixSum[0] = suffixSum[0];
        for ( int i = N - 2; i >= 0; i-- ) {
            maxSuffixSum[i] = std::max(maxSuffixSum[i + 1], suffixSum[i]);
        }

        for ( int i = 0; i < N - 1; i++ ){
            maximum = std::max(maximum, std::max(maxPrefixSum[i], maxSuffixSum[N - 2 - i])); 
        }
        maximum = std::max(maximum, prefixSum[N - 1]);
        std:: cout << maximum << std::endl;
    }


    return 0;
    
}

#include <iostream>
#include <vector>
#include <string>

int main(void){
    int N, M, K;
    int min = 1;
    
    std::string str;
    std::string tmp;
    std::cin >> N >> M >> K;
    int size = N * M;
    int matrix[N*M];
    memset(matrix, 0, sizeof(int) * N *M);

    for ( int i = 0; i < K; i++ )
        for ( int j = 0; j < N; j++){
            std::cin >> tmp;
            str += tmp;
        }

    for ( int i = 0; i < K; i++ )
        for ( int j = 0; j < size; j++)
            if ( str[i * size + j] == '0' )
                matrix[j] += 1;
    for ( int i = 0; i < size; i++ )
        std::cout << matrix[i] << std::endl;
    return 0;
}

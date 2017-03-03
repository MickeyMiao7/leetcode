#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[100];
vector<vector<int> > arr_num;

void combine(int n, int r){
    a[r - 1] = n;
    if ( r == 1 ){
        int i = 0;
        while ( a[i] != 0 )
            i++;
        vector<int> tmp;
        for(int j = i - 1; j >= 0; j--)
            tmp.push_back(a[j] - 1);
        arr_num.push_back(tmp);
    }
    else{
        for ( int i = n - 1; i >= r - 1; i -- )
            combine(i, r - 1);
    }

}

int main(void){
    int N, M, K;
    cin >> N >> M >> K;

    string str;
    string tmp;
    for ( int i = 0; i < K; i++ )
        for ( int j = 0; j < N; j++){
            cin >> tmp;
            str += tmp;
        }

    int size = N * M;
    int len = 1;
    for (; len < size; len ++){
        arr_num.clear();
        for(int i = size; i >= len; i--)
            combine(i, len);

        for(int k = 0; k < arr_num.size(); k++){
            int able = 0;
            for(int i = 0; i < K - 1; i ++)
                for(int j = 0; j < K; j ++){
                    bool flagb = false;
                    for(int l = 0; l < arr_num[k].size(); l++){
                        // cout << str[i * size + arr_num[k][l]];
                        if (str[i * size + arr_num[k][l]] != str[j * size + arr_num[k][l]])
                            flagb = true;
                    }
                    if ( flagb )
                        able += 1;
                }
           
            if ( able == K * (K - 1) / 2)
            {

                goto breakLoop;
            }
        } 
    }
    breakLoop:  cout << len << endl;
    return 0;
}

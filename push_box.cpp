#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
struct state{
    int hx, hy, bx, by;
    state(int a, int b, int c, int d):hx(a),hy(b), bx(c), by(d){}
};

int main(void){
    int N, M;
    cin >> N >> M;

    int hx, hy, bx, by;
    int endx, endy;
    vector<vector<char> > map(N, vector<char>(M, '0'));
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] == 'X'){
                map[i][j] = 'X';
                hx = i;
                hy = j;
            }
            else if(str[j] == '*'){
                map[i][j] = '*';
                bx = i;
                by = j;
            }
            else if(str[j] == '#'){
                map[i][j] = '#';
            }
            else if(str[j] == '@'){
                map[i][j] = '@';
                endx = i;
                endy = j;
            }
        }
    }

    int stepx[] = {0, 0, 1, -1};
    int stepy[] = {1, -1, 0, 0};
    int count[8][8][8][8] = {0};
    count[hx][hy][bx][by] = 0;
    queue<state> q;
    q.push(state(hx, hy, bx, by));
    while(!q.empty()){
        state top_element = q.front();
        q.pop();
        if(top_element.bx == endx && top_element.by == endy){
            cout << count[top_element.hx][top_element.hy][top_element.bx][top_element.by] - 1 << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int hnx = top_element.hx + stepx[i];
            int hny = top_element.hy + stepy[i];
            if(hnx < 0 || hny < 0 || hnx >= M || hny >= N || map[hnx][hny] == '#')
                continue;
            if(hnx == top_element.hx && hny == top_element.hy){
                int bnx = top_element.bx + stepx[i];
                int bny = top_element.by + stepy[i];
                if(bnx < 0 || bny < 0 || bnx >= M || bny >= N || map[bnx, bny] == '#')
                   continue; 
                if(count[hnx][hny][bnx][bny]) 
                    continue;
                count[hnx][hny][bnx][bny] = count[top_element.hx][top_element.hy][top_element.bx][top_element.by] + 1;
                q.push(state(hnx, hny, bnx, bny));
            }
            
            else{
                if(count[hnx][hny][top_element.bx][top_element.by])
                    continue;
                count[hnx][hny][top_element.bx][top_element.by] = count[top_element.hx][top_element.hy][top_element.bx][top_element.by] + 1;
                q.push(state(hnx, hny, top_element.bx, top_element.by));
            }

        }
    }
    cout << "Not Found" << endl;

    return 0;
}

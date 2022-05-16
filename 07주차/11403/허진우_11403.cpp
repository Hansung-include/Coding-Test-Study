/*
 * 이름: 허진우 
 * 언어: C++17
 * 문제: 백준/11403
*/

#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000
using namespace std;

/* 
 * 풀이
 * 최단 경로를 구하는 문제는 아니지만, 모든 정점 쌍에 대해 i > j 로의 이동이 가능한지 따지기 때문에, 플로이드 워셜 알고리즘으로 모든 정점쌍을 채운다.
*/

int dist[100][100];
int n;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == 0) dist[i][j] = INF;
        }
    }
}

void sol() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) 
            cout << (dist[i][j] != INF) << ' ';
        cout << endl;
    }            
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    sol();
}


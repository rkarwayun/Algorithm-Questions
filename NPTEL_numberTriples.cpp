/*
Number Triples, appeared in Indian National Olympiad in Informatics 2005.
Solved as a question for NPTEL Algortihm course.
*/


#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;
    int d;
};

struct compare {
    bool operator()(Edge &a, Edge &b) {
        return a.d > b.d;
    }
};

int g[2001][2001];
bool visit[2001];
int dist[2001];


int mini(int a, int b) {
    if(a <= b)
        return a;
    else
        return b;
}

int dijkstra(int a, int b) {
    priority_queue<Edge, vector<Edge>, compare> pq;
    Edge e = Edge();
    e.v = a;
    e.d = 0;
    dist[a] = 0;
    pq.push(e);
    while(!pq.empty()) {
        Edge e1 = pq.top();
        pq.pop();
        int v = e1.v;
        int d = e1.d;
        if(visit[v])
            continue;
        visit[v] = true;
        for(int j = 0; j < 2001; j++) {
            if(!visit[j]) {
                if(dist[j] > dist[v] + g[v][j]) {
                    dist[j] = dist[v] + g[v][j];
                    Edge e2;
                    e2.v = j;
                    e2.d = dist[j];
                    pq.push(e2);
                }
            }
        }
    }
    return dist[b];
}

int main() {
	
	for(int i = 0; i < 2001; i++) {
	    for(int j = 0; j < 2001; j++) {
	        g[i][j] = 1000000;
	    }
	    visit[i] = false;
	    dist[i] = 1000000;
	}
	
	int m, a, b;
	cin >> m >> a >> b;
	a--; b--;
	
	for(int t = 0; t < m; t++) {
	    int a1, w1, b1;
	    cin >> a1 >> w1 >> b1;
	    a1--; b1--;
	    g[a1][b1] = mini(g[a1][b1], w1);
	    g[b1][a1] = mini(g[b1][a1], w1);
	}
	
	int ans = dijkstra(a, b);
	if(ans == 1000000)
	    cout << "NO" << endl;
	else
	    cout << "YES" << endl << ans << endl;
	
	return 0;
}

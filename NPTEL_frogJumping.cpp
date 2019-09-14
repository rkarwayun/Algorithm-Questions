/*
Frog Jumping, appeared in INOI 2005.
Solved as a question for NPTEL Algortihm course.
*/

#include <iostream>
#include <list>
#define INT_MAX 10000000

using namespace std;

typedef struct {
    int r;
    int d;
} Node;

typedef struct {
    int x;
    int y;
} Point;

int mini(int a, int b) {
    if(a <= b)
        return a;
    else
        return b;
}

int main() {
	int m,n;
	
	Node chess[250][250];
	bool visit[250][250];
	int dist[250][250];
	
	cin >> m >> n;
	
	for(int i = 0; i < m; i++)  {
	    for(int j = 0; j < n; j++) {
	        cin>>chess[i][j].r;
	        visit[i][j] = false;
	        dist[i][j] = INT_MAX;
	    }
	}
	
	for(int i = 0; i < m; i++) {
	    for(int j = 0; j < n; j++) {
	        cin>>chess[i][j].d;
	    }
	}
	
	list<Point> q;
	dist[0][0] = 0;
	Point p;
	p.x = 0;
	p.y = 0;
	q.push_back(p);
	
	//BFS
	while(!q.empty()) {
	    Point p1 = q.front();
	    q.pop_front();
	    int ii,jj; ii = p1.x; jj = p1.y;
        if(visit[ii][jj])
	        continue;
	    int r = chess[ii][jj].r;
	    int d = chess[ii][jj].d;
	    visit[ii][jj] = true;
	    for(int i = 1; i <= d; i++) {
	        if(ii + i >= m)
	            break;
	       if(!visit[ii + i][jj]) {
	           Point p2;
	           p2.x = ii + i;
	           p2.y = jj;
	           q.push_back(p2);
	           dist[ii + i][jj] = mini(dist[ii + i][jj], dist[ii][jj] + 1);
	       }
	    }
	    for(int j = 1; j <= r; j++) {
	        if(jj + j >= n)
	            break;
	       if(!visit[ii][jj + j]) {
	           Point p2;
	           p2.x = ii;
	           p2.y = jj + j;
	           q.push_back(p2);
	           dist[ii][jj + j] = mini(dist[ii][jj + j], dist[ii][jj] + 1);
	       }
	    }
	}
	//BFS ends.
	
	cout << dist[m - 1][n - 1] << endl;
	return 0;
}

/*
Voting in Siruseri, appeared in Zonal Computing Olympiad 2010.
Solved as a question for NPTEL Algortihm course.
*/

#include <iostream>
#include<map>
using namespace std;

int main() {
	map<int, int> m;
	int n1, n2, n3, n4, n5;
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	//cout << endl << n1 << " : ";
	for(int i = 0; i < n1; i++)
	{
	    int a; cin >> a;
	    //cout << a << " ";
	    m[a]++;
	}
	//cout << endl << n2 << " : ";
	for(int i = 0; i < n2; i++)
	{
	    int a; cin >> a;
	    //cout << a << " ";
	    m[a]++;
	}
	//cout << endl << n3 << " : ";
	for(int i = 0; i < n3; i++)
	{
	    int a; cin >> a;
	    //cout << a << " ";
	    m[a]++;
	}
	//cout << endl << n4 << " : ";
	for(int i = 0; i < n4; i++)
	{
	    int a; cin >> a;
	    //cout << a << " ";
	    m[a]++;
	}
	//cout << endl << n5 << " : ";
	for(int i = 0; i < n5; i++)
	{
	    int a; cin >> a;
	    //cout << a << " ";
	    m[a]++;
	}
	map<int, int>:: iterator it = m.begin();
	int res = 0;
	while(it != m.end()) {
	    //cout << it->first << ":" << it->second << endl;
	    if(it->second >= 3)
	        res++;
	    it++;
	}
	cout << res << endl;
	return 0;
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>
#define FOREACH(I, C) for(__typeof((C).begin()) I = (C).begin(); I != (C).end(); I++)

using namespace std;
typedef long long ll;

map<pair<int, int>, bool> vis;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
const int kInf = 0x3f3f3f3f;

class RotatingBot {
	public:
		int minArea(vector <int> moves) {
			vis.clear();
			int n = moves.size();
			int x = 0, y = 0;
			vis[make_pair(x,y)] = true;
			int minX = kInf, maxX = -kInf,
				minY = kInf, maxY = -kInf;
			for ( int i = 0; i < n; i ++ ) {
				int dir = i % 4;
				for ( int j = 0; j < moves[i]; j ++ ) {
					x = x + dx[dir], y = y + dy[dir];
					if ( vis.count(make_pair(x, y)) ) 
						return -1;
					vis[make_pair(x, y)] = true;
				}
				if ( !vis.count(make_pair(x+dx[dir], y+dy[dir])) ) {
					if ( i != n-1 ) {
						if ( dir == 0 ) {
							if ( maxY != -kInf && maxY != y ) return -1;
							maxY = y;
						} else if ( dir == 1 ) {
							if ( minX != kInf && minX != x ) return -1;
							minX = x;
						} else if ( dir == 2 ) {
							if ( minY != kInf && minY != y ) return -1;
							minY = y;
						} else {
							if ( maxX != -kInf && maxX != x ) return -1;
							maxX = x;
						}
					}
				}
			}
			FOREACH(it, vis) {
				if ( minX != kInf && it->first.first < minX ) return -1;
				if ( maxX != -kInf && it->first.first > maxX ) return -1;
				if ( minY != kInf && it->first.second < minY ) return -1;
				if ( maxY != -kInf && it->first.second > maxY ) return -1;
			}
			FOREACH(it, vis) {
				minX = min(minX, it->first.first);
				maxX = max(maxX, it->first.first);
				minY = min(minY, it->first.second);
				maxY = max(maxY, it->first.second);
			}
			return (maxY-minY+1) * (maxX-minX+1);
		}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	RotatingBot *obj;
	int answer;
	obj = new RotatingBot();
	clock_t startTime = clock();
	answer = obj->minArea(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	int p1;

	{
		// ----- test 0 -----
		int t0[] = {15};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 16;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = {3,10};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 44;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = {1,1,1,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = -1;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = {9,5,11,10,11,4,10};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 132;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 420;
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}
	{
		// ----- test 5 -----
		int t0[] = {8,6,6,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = -1;
		all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 6 -----
		int t0[] = {8,6,6};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 63;
		all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 7 -----
		int t0[] = {5,4,5,3,3};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 30;
		all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

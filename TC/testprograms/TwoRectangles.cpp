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
bool vis[1111][1111], visX[1111], visY[1111];
class TwoRectangles {
	public:
		string describeIntersection(vector <int> A, vector <int> B) {
			memset(vis, 0, sizeof(vis));
			memset(visX, 0, sizeof(visX));
			memset(visY, 0, sizeof(visY));
			for ( int x = A[0]; x <= A[2]; x ++ )
				for ( int y = A[1]; y <= A[3]; y ++ )
					vis[x][y] = true;
			int cntX = 0, cntY = 0;
			for ( int x = B[0]; x <= B[2]; x ++ )
				for ( int y = B[1]; y <= B[3]; y ++ )
					if ( vis[x][y] ) {
						if ( !visX[x] )
							visX[x] = true, cntX++;
						if ( !visY[y] )
							visY[y] = true, cntY++;
					}
			if ( cntX == 0 )
				return "none";
			else if ( cntX == 1 && cntY == 1 )
				return "point";
			else if ( cntX == 1 || cntY == 1 )
				return "segment";
			return "rectangle";
		}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	TwoRectangles *obj;
	string answer;
	obj = new TwoRectangles();
	clock_t startTime = clock();
	answer = obj->describeIntersection(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	vector <int> p1;
	string p2;

	{
		// ----- test 0 -----
		int t0[] = {0,0,3,2};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {1,1,5,3};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "rectangle";
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = {0,0,5,3};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {1,2,2,3};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "rectangle";
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = {1,1,6,2};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {3,2,5,4};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "segment";
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = {0,1,2,3};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {2,0,5,2};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "segment";
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = {0,0,1,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {1,1,5,2};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "point";
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		int t0[] = {1,1,2,2};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {3,1,4,2};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = "none";
		all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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

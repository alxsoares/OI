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

const int MOD = 1000000009;
const int kInf = 0x3f3f3f3f;

void add(int &x, int y) {
	x += y;
	x %= MOD;
	if ( x < 0 ) x += MOD;
}

int mul(int x, int y) {
	return (int)((ll)x * y % MOD);
}

struct Answer {
	int val, ways;
	Answer(){}
	Answer(int _val, int _ways):
		val(_val), ways(_ways){}
};

void upd(Answer &cur, Answer tmp) {
	if ( cur.val > tmp.val ) 
		cur = tmp;
	else if ( cur.val == tmp.val )
		add(cur.ways, tmp.ways);
}

class Pikachu {
	public:
		bool done[33][33][33][33];
		Answer memo[33][33][33][33];
		int len[33], start[33], end[33];
		int sufSum[33];
		int fact[33], bino[33][33];
		int n;

		Answer dp(int i, int j, int k, int l) {
			//assert(j >= k && k >= l);
			if ( done[i][j][k][l] ) return memo[i][j][k][l];
			done[i][j][k][l] = true;
			Answer &ret = memo[i][j][k][l] = Answer(kInf, 0);

			if ( i == 0 ) {
				ret = Answer(0, 1);
			} else {
				for ( int x = j >= i ? i : 0; x <= min(i, j); x ++ ) {
					//choose x nodes to fix
					Answer curans = dp(i-x, k, l+2*(j-x), j-x);
					curans.val += sufSum[i-x]; //last i-x element's sum
					curans.ways = mul(curans.ways, fact[x]);
					curans.ways = mul(curans.ways, bino[j][x]);
					int last = n-i+x-1, curlen = end[last]-max(start[last], n-i) + 1;
					curans.ways = mul(curans.ways, bino[curlen][last-max(start[last], n-i)+1]);
					upd(ret, curans);
				}
			}

			return ret;
		}

		vector <int> bestEncoding(vector <int> freq) {
			memset(done, 0, sizeof(done));
			sort(freq.begin(), freq.end(), greater<int>());
			n = freq.size();

			for ( int i = 0; i < n; i ++ ) {
				int st = i;
				while ( i+1 < n && freq[i+1] == freq[i] ) i ++;
				int en = i;
				for ( int k = st; k <= en; k ++ )
					len[k] = en - st + 1, start[k] = st, end[k] = en;
			}

			sufSum[0] = 0;
			for ( int i = 1; i <= n; i ++ )
				sufSum[i] = sufSum[i-1] + freq[n-i];

			bino[0][0] = 1;
			for ( int i = 1; i <= n; i ++ ) {
				bino[i][0] = 1;
				for ( int j = 1; j <= i; j ++ ) {
					add(bino[i][j], bino[i-1][j]);
					add(bino[i][j], bino[i-1][j-1]);
				}
			}

			fact[0] = 1;
			for ( int i = 1; i <= n; i ++ )
				fact[i] = mul(fact[i-1], i);

			Answer ans = dp(n, 2, 1, 0);
			ans.val += sufSum[n]*2;
			vector<int> ret(2);
			ret[0] = ans.val, ret[1] = ans.ways;

			return ret;
		}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Pikachu *obj;
	vector <int> answer;
	obj = new Pikachu();
	clock_t startTime = clock();
	answer = obj->bestEncoding(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	{
		// ----- test 0 -----
		int t0[] = {1,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {4,2};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}
	
	{
		// ----- test 1 -----
		int t0[] = {1,1,2};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {9,4};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}
	
	{
		// ----- test 2 -----
		int t0[] = {1,1,1,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {13,48};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}


	{
		// ----- test 3 -----
		int t0[] = {2,3,5,7,11,13,17,19};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {309,96};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = {533,533,533,353,335,335};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {10290,288};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = {72,362124467};
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
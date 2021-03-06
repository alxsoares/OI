#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <numeric>
#include <cstdio>
#include <memory.h>

using namespace std;   

#define SZ(a) ((int)(a).size())
#define SQR(a) ((a)*(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))
#define FHAS(a, b) (find((a).begin(), (a).end(), (b))!=(a).end())
#define HAS(a, b) ((a).find(b) != (a).end())
#define HASB(a, b) ((a & (1 << b))>0)

template<class A, class B> A convert(B x) {stringstream s; s << x; A r; s >> r; return r;}

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;

char ch[1<<20];
int n;
ULL h1[1<<19], h2[1<<19];

bool isPal(int pref) { return h1[pref] == h2[pref]; }

int main() {

	freopen("t.in", "r", stdin);

	int tc; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%s", ch);
		n = strlen(ch);

		h1[0] = h2[0] = 0;
		LL p = 1;

		FOR(i, 1, n+1)
		{
			h1[i] = h1[i-1]*31ULL+(ch[i-1]-'a'+1);
			h2[i] = h2[i-1] + p*(ch[i-1]-'a'+1);
			p *= 31ULL;
		}

		ch[n++] = 32;

		int d[2] = {0};
		d[0]=1;	while (d[0]<n && ch[d[0]]==ch[d[0]-1]) d[0]++;
		d[1]=2; while (d[1]<n && ch[d[1]]==ch[d[1]-2]) d[1]++;

		ULL res = 0;
		ULL mn = 1;

		FORD(L, n, 2)
		{
			int nn = (L&1);
			ULL K;
			if (d[nn]+1>=L)
				K = d[nn]-L+2;
			else
				K = isPal(L)+1;

			if (K<n-L+1)
				res += K*mn;

			mn *= 100007ULL;
		}

		cout << res << endl;
	}

	return 0;
}

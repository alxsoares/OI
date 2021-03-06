#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int BASE = 29;
const int N_MAX = 1000010;

char sa[N_MAX], sb[N_MAX], si[N_MAX], st[2 * N_MAX];
int xsa[N_MAX], xsb[N_MAX], xsi[N_MAX];
int pow[N_MAX], pre[2 * N_MAX];

void initPreSum(char *str, int n, int *res){
	for(int i = 0; i < n; i ++)
		res[i] = (i ? res[i - 1] : 0) * BASE + (str[i]);
}
int getHash(int *s, int l, int r){
	if(l > r)
		return 0;
	return s[r] - (l ? s[l - 1] : 0) * pow[r - l + 1];
}
int main(){
	gets(sa);
	gets(sb);
	int na = strlen(sa),
		nb = strlen(sb);
	if(na != nb){
		printf("-1 -1\n");
		return 0;
	}
	int n = na;
	pow[0] = 1;
	for(int i = 1; i <= n; i ++)
		pow[i] = pow[i - 1] * BASE;
	for(int i = 0; i < na; i ++)
		si[i] = sa[na - i - 1];
	initPreSum(sa, n, xsa);
	initPreSum(sb, n, xsb);

	strcpy(st, si);
	st[n] = 0;
	strcpy(st + n + 1, sb);
	pre[0] = -1;
	int t = -1;
	for(int i = 1; i <= 2 * n; i ++){
		while(t >= 0 && st[t + 1] != st[i])
			t = pre[t];
		if(st[t + 1] == st[i])
			t ++;
		pre[i] = t;
	}

	int ansI = -1, ansJ = -1;
	for(int i = 0; i < n - 1; i ++){
		if(sa[i] != sb[n - i - 1])
			break;
		int j = n - pre[2 * n - i - 1] - 1;
		if(j == -1)
			continue;
		if(getHash(xsa, i + 1, j - 1) == getHash(xsb, 0, j - 2 - i)){
			if(i > ansI)
				ansI = i, ansJ = j;
			else if(i == ansI && j < ansJ)
				ansJ = j;
		}
	}

	printf("%d %d\n", ansI, ansJ);
}

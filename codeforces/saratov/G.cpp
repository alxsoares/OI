/*
 * $Date: Wed Oct 19 10:39:36 2011 +0800
 * $Author: csimstu
 * $Source: School Regional Team Contest, Saratov, 2011 Problem G
 * $Method:	Implemetation
 */
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n, m, t;
int a[111][2], b[111][2], d[111][111];
vector<string> ans[111];
struct Card{
	string str;
	int dif;
} card[111];
int Q[1111111];
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &t);
	for(int i = 1; i <= n; i ++)
		scanf("%d%d%d%d", &a[i][0], &b[i][0], &a[i][1], &b[i][1]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++){
		cin >> card[i].str >> card[i].dif;
	}
	int qh = 0, qt = 0;
	for(int i = 1; i <= m; i ++)
		Q[qt ++] = i;
	int i = 1, j = 0;
	while(qh < qt){
		int left = t;
		while(qh < qt && left > 0){
			int k = Q[qh];
			int need = max(1, card[k].dif - (a[i][j] + b[i][!j]) - d[i][k]);
			if(need <= left){
				left -= need;
				qh ++;
				ans[i].push_back(card[k].str);
			}
			else{
				qh ++;
				Q[qt ++] = k;
				d[i][k] += left;
				left = 0;
			}
		}
		i ++;
		if(i == n + 1)
			i = 1, j ^= 1;
	}
	for(int i = 1; i <= n; i ++){
		printf("%d", ans[i].size());
		for(int k = 0; k < (int)ans[i].size(); k ++)
			printf(" %s", ans[i][k].c_str());
		printf("\n");
	}
}

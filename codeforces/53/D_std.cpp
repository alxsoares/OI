#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;

#define ll (long long)
long double ans;
int cnt, n, m, rowa[1010], rowb[1010];

void solve(int n, int m, int row[1010]){
    for(int i=0; i<n; i++){
        if(row[i]==-1)  continue;
        int tmp=row[i], maxim=row[i];
        for(int j=i; j<n; j++){
            if(row[j]>=maxim){
                maxim=row[j];
                ans+=tmp*(m-1-maxim)*4;
            }else break;
        }
        tmp=row[i], maxim=row[i];
        for(int j=i-1; j>=0; j--){
            if(row[j]>maxim){
                maxim=row[j];
                ans+=tmp*(m-1-maxim)*4;
            }else break;
        }
    }
    for(int i=0; i<n; i++)  for(int j=0; j<n; j++)  ans+= ll (m-(row[i]!=-1))* ll (m-(row[j]!=-1))* ll abs(i-j);
}

int main(){
	freopen("t.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(rowa, -1, sizeof rowa);  memset(rowb, -1, sizeof rowb);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            scanf(" %c", &c);
            if(c=='X'){
                cnt++;
                rowa[i]=j;  rowb[j]=i;
            }
        }
    }
    //solve
    solve(n, m, rowa);
    solve(m, n, rowb);
    
    cout<<ans/double( ll (n*m-cnt)* ll (n*m-cnt))<<endl;
    
    return 0;
}

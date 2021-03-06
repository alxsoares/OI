#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int Maxn=25;
const double wc=1e-9;

double f[Maxn][Maxn][Maxn];
double v1[Maxn],v2[Maxn];
int pos[Maxn];
int num[Maxn];
int n1,n2,n3,len;
double r1,r2,r3,d1,d2;
double res;

void Update(double &x,double y)
{
	if (y>x) x=y;
}

double Cross(double X1,double Y1,double X2,double Y2)
{
	double X=max(X1,X2);
	double Y=min(Y1,Y2);
	return max((double)0,Y-X);
}

double Dp()
{
	for (int i=0;i<=len+1;++i)
		for (int j=0;j<=n1;++j)
			for (int k=0;k<=n2;++k)
				f[i][j][k]=-999999999;
	for (int i=1;i<=len;++i)
	{
		v1[i]=d1*r1*2;
		for (int jj=1;jj<=n3;++jj)
			v1[i]+=Cross(pos[jj]-r3,pos[jj]+r3,i-r1,i+r1)*d1;
	}
	for (int i=1;i<=len;++i)
	{
		v2[i]=d2*r2*2;
		for (int jj=1;jj<=n3;++jj)
			v2[i]+=Cross(pos[jj]-r3,pos[jj]+r3,i-r2,i+r2)*d2;
	}
	f[0][0][0]=0;
	for (int i=0;i<len;++i)
		for (int j=0;j<=n1;++j)
			for (int k=0;k<=n2;++k)
				if (f[i][j][k]>-wc)
					for (int j1=0;j+j1<=n1 && j1<=2-num[i+1];++j1)
						for (int j2=0;k+j2<=n2 && j1+j2<=2-num[i+1];++j2)
							Update(f[i+1][j+j1][k+j2],f[i][j][k]+v1[i+1]*j1+v2[i+1]*j2);
	return f[len][n1][n2];
}
	
void Dfs(int x,int n)
{
	if (!n)
	{
		res=max(res,Dp());
		return;
	}
	if (x>len) return;
	
	Dfs(x+1,n);
	
	++num[x];pos[n]=x;
	Dfs(x+1,n-1);
	
	if (n>1)
	{
		++num[x];pos[n-1]=x;
		Dfs(x+1,n-2);
	}
	
	num[x]=0;
}

int main()
{	
	freopen("t.in","r",stdin);
	//freopen("x.out","w",stdout);
	
	scanf("%d%d%d%lf%lf%lf%lf%lf",&n1,&n2,&n3,&r1,&r2,&r3,&d1,&d2);
	
	r1=sqrt(r1*r1-1);
	r2=sqrt(r2*r2-1);
	r3=sqrt(r3*r3-1);
	len=(n1+n2+n3)/2+1;
	
	res=0;
	memset(num,0,sizeof(num));
	
	Dfs(1,n3);
	
	printf("%.10lf\n",res);
	
	return 0;
}


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vector<pii> v;

typedef pair<pii,int> p3;

vector<p3> q;
int r[111111];

set<p3> b;

void add(int from,int to,int flag){
	//next
	set<p3>::iterator it = b.lower_bound(p3(pii(to+1,0),0));
	if(it!=b.end() && it->second==flag && it->first.second==to+1){
		int tt = it->first.first;
		b.erase(it);
		add(from,tt,flag);
		return;
	}
	//prev
	if(it!=b.begin()){
		it--;
		if(it->second==flag && it->first.first==from-1){
			int ff = it->first.second;
			b.erase(it);
			add(ff,to,flag);
			return;
		}
	}
	
	b.insert(p3(pii(to,from),flag));
}

int row;

void make_w(int pos,int flag){
	set<p3>::iterator it = b.lower_bound(p3(pii(pos,0),0));
	if(it->second==flag)return;
	//cout<<(it==b.end())<<endl;
	int from = it->first.second;
	int to = it->first.first;
	b.erase(it);

	if(pos-1>=from)
		add(from, pos-1, 1-flag);
	add(pos,pos,flag);
	if(pos+1<=to)
		add(pos+1,to,1-flag);
}

void out(){
	cout<<"ROW "<<row<<endl;
	int prev = -1;
	for(set<p3>::iterator it = b.begin();it!=b.end();it++){
		cout<<"["<<it->first.second<<','<<it->first.first<<"] : "<<it->second<<endl;
		if(prev==it->second)
			while(1) cout<<"FUCK"<<endl;
		prev=it->second;
	}
}

void check(){
	int prev = -1;
	for(set<p3>::iterator it = b.begin();it!=b.end();it++){
		if(prev==it->second){
//			while(1) cout<<"FUCK"<<endl;
			vi x(10);
			cout<<x[100]<<endl;
		}
		prev=it->second;
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	freopen("t.in", "r", stdin);

	int tc;
	cin>>tc;
	REP(TC,tc){
		int MX = 1000000000;
begin:
		//n=4;//rand()%((MX+1)*(MX+1)+1);m=0;//rand()%100;
		cin>>n;
		//cout<<"START "<<n<<endl;
		v.resize(n);
		set<pii> s;
		REP(i,n){
			scanf("%d %d",&v[i].first,&v[i].second);
			if(0){
				while(1){
					v[i].first=rand()%(MX+1);
					v[i].second=rand()%(MX+1);
					if(!s.count(v[i])){
						s.insert(v[i]);
						break;
					}
				}
				cout<<v[i].first<<' '<<v[i].second<<endl;
			}
		}
		SORT(v);
		cin>>m;
		q.resize(m);
		CL(r,-1);
		REP(i,m){
			scanf("%d %d",&q[i].first.first,&q[i].first.second),q[i].second=i;
			if(0){
				while(1){
					q[i].first.first=rand()%(MX+1);
					q[i].first.second=rand()%(MX+1);
					q[i].second=i;
					if(!s.count(q[i].first)){
						s.insert(q[i].first);
						break;
					}
				}
			}
		}
		SORT(q);

		//q.clear();
		//REP(i,6)REP(j,7)q.pb(p3(pii(i,j),q.size()));
		//m=q.size();

		int p1 = 0;
		int p2 = 0;

		b.clear();
		b.insert(p3(pii(MX,0),1));
		row = 0;
		while(p1<n || p2<m){
//			out();
			int n1 = (p1<n ? v[p1].first : MX);
			int n2 = (p2<m ? q[p2].first.first : MX);

			n1 -= row;
			n2 -= row;
			int n3 = min(n1,n2);
			if(n3){
	//			cout<<"START HERE "<<n3<<endl;
				int los = -1;

				set<p3>::iterator it = b.begin();
				if(it->second == 0) it++;
				if(it!=b.end()){
					if(it->second == 1){
						los = it->first.second;
						n3=min(n3,it->first.first-los+1);
					}
					int from = it->first.second;
					int to = it->first.first;
					b.erase(it);
					add(los,los+n3-1,0);
					if(los+n3<=to)
						add(los+n3,to,1);

					row+=n3;
		//			cout<<"DOING STUFF "<<n3<<endl;
					if(n3)
						continue;
				}
			}

			vi pos;
			while(p1<n && v[p1].first==row) pos.pb(v[p1].second),p1++;

			vector<pii> qr;
			while(p2<m && q[p2].first.first==row) qr.pb(pii(q[p2].first.second,q[p2].second)),p2++;

			set<int> losers;

			REP(i,pos.size()+1){
				int from = (i ? pos[i-1]+1: 0);
				int to = (i==pos.size() ? MX : pos[i]-1);
				//cout<<"TRY "<<from<<' '<<to<<" row "<<row<<endl;
				if(from<=to){
					set<p3>::iterator it = b.lower_bound(p3(pii(from,0),0));
					if(it->second == 0) it++;
					if(it!=b.end()){
						if(it->second == 1){
							int x = max(from,it->first.second);
							if(x<=to){
								losers.insert(x);
							//	cout<<"LOSER "<<x<<endl;
							}
						}
					}
				}
			}

			REP(i,qr.size()) if(losers.count(qr[i].first))
				r[qr[i].second]=0;
			else r[qr[i].second]=1;

			REP(i,pos.size()) make_w(pos[i],1);
			for(set<int>::iterator it = losers.begin();it!=losers.end();it++)
				make_w(*it,0);

			row++;

			//out();check();
		}

		REP(i,m){
			//cout<<q[i].first.first<<' '<<q[i].first.second<<" ";
			//if(r[i]==-1) puts("????");
			if(r[i]==0) puts("Bob");
			if(r[i]==1) puts("Alice");
		}

		//cout<<"KO "<<n<<endl;

		//goto begin;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
				

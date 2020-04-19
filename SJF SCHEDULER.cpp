#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define F first
#define S second
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
bool compare(iii p1,iii p2)
{
	return p1.first.first>=p2.first.first;
}
struct comp{
	bool operator()(iii p1,iii p2)
{
	
	if(p1.first.second==p2.first.second)
		return p1.first.first>=p2.first.second;
	return p1.first.second<p2.first.second;
}
};
void schedule(viii v)
{
	priority_queue<iii, vector<iii>,comp> pq;
	int n=v.size();
	int total_waiting=0;
	int total_turnaround=0;
	int check=0;
	if(!v.empty()){ pq.push(v[0]);v.erase(v.begin());}
	while(!pq.empty())
	{
		iii o=pq.top();
		pq.pop();
		check+=max(o.S,o.F.S);
		total_waiting+=o.S-o.F.F+1;
		for(int i=0;i<v.size();i++)
		{
			if(v[i].F.F<=check)
			{
				pq.push(v[i]);
				v.erase(v.begin()+i);
			}
		}
		total_turnaround=o.F.S+total_waiting;
	}
	cout<<"\nAverage_waiting:"<<total_waiting/n<<"\nAverage_turnaround:"<<total_turnaround/n;
}
int main()
{
int n;
	int c=1;
	priority_queue<iii ,vector<iii> ,comp> pq;
	printf("no of process:\n");
	scanf("%d",&n);
	viii v;
	f(i,0,n)
	{
		int a,b,s;
		printf("Process %d:\n",c);
		printf("enter arrival time, burst time, service time:");
		scanf("%d%d%d",&a,&b,&s);
		ii o1(a,b);
		iii o(o1,s);
		v.pb(o);
		c++;
	}
	sort(v.begin(),v.end());
	schedule(v);
}

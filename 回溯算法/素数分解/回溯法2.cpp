#include<iostream>
using namespace std;
int n,ans;
int a[205];

bool prime(int n)
{
	if(n==1)
		return 0;
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

void search(int s,int step)
{
	for(int i=2; i<=s; i++)
	{
		if(prime(i)&&i>a[step-1])
		{
			a[step]=i;
			if(s-a[step]==0)
			{
				ans=max(ans,step);
			}
			else
			{
				search(s-a[step],step+1);
			}
		}
	}
}

int main()
{
	cin>>n;
	search(n,1);
	cout<<ans;
	return 0;
}

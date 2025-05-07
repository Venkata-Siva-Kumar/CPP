//RABIN KARP
#include<iostream>
using namespace std;
int pre_count = 0,count=0;

void Rabin_Karp(string T,string P,int d,int q)
{
	int h=1,p=0,t=0,j;
	int n = T.length();
	int m = P.length();

	for(int i=0;i<m-1;i++)
	{
		h = (h*d) % q;
	}

	for(int i=0;i<m;i++)
	{
		pre_count++;
		p = (d*p + P[i]) % q;
		t = (d*t + T[i]) % q;
	}

	for(int s=0;s<=n-m;s++)
	{
		count++;
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				count++;
				if(T[s+j] != P[j])
					break;
			}
			if(j==m)
				cout<<"Pattern Occurs with shift : "<<s<<endl;
		}

		if(s<n-m)
			t = (	(t-T[s]*h)*d + T[s+m] )%q;

		if(t<0)
			t = t+q;
	}
}
int main()
{
	string T,P;
	cout<<"Text : ";
	cin>>T;
	cout<<"Pattern : ";
	cin>>P;
	

	Rabin_Karp(T,P,10,11);
	cout<<"Pre-processing Time : "<<pre_count<<endl;
	cout<<"Count : "<<count<<endl;

}

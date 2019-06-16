#include<bits/stdc++.h>
using namespace std;
bool sortInReverse(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
} 
bool checkPresence(vector<char> v , char c)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==c)
			return true;
	return false;
}
int main(int argc, char const *argv[])
{	
	printf("Enter Number of TID's : ");
	int n,i,j;
	cin>>n;
	int tid[n];
	printf("Enter TID's: \n");
	for(i=0;i<n;i++)
		cin>>tid[i];
	vector<vector<char> >items(n);
	char temp='\0';
	int freq[123]={0};
	for(i=0;i<n;i++)
	{	
		temp='\0';
		printf("Enter items Taken by TID %d (Seprated by spaces , Enter '!' when Done): \n", tid[i]);
		while(temp!='!')
		{
			scanf("%c",&temp);
			if(temp!='!')
			{	
				freq[temp]++;
				items[i].push_back(temp);
			}
		}
	}
	/*for(i=0;i<items.size();i++)
	{
		for(j=0;j<items[i].size();j++)
			cout<<items[i][j]<<" ";
		cout<<endl;
	}*/
	printf("Enter Minimum support % : ");
	int minPercent;
	cin>>minPercent;
	vector<char>order;
	int min = ceil(((float)minPercent/100)*n);
	for(i=97;i<=122;i++)
	{	
		if(freq[i]>=min)
			order.push_back(i);
	}
	vector<pair<char,int>>count;
	for(i=0;i<order.size();i++)
		count.push_back(make_pair(order[i],freq[order[i]]));
	sort(count.begin(),count.end(),sortInReverse);
	cout<<endl;
	printf("Items  Support\n");
	for(i=0;i<count.size();i++)
		cout<<count[i].first<<"         "<<count[i].second<<endl;
	for(i=0;i<items.size();i++)
	{
		for(j=0;j<items[i].size();j++)
		{
			bool cc=checkPresence(order,items[i][j]);
			if(cc==false)
				items[i][j]='\0';
		}
	}
	vector<vector<pair<int,int>> >x(n);
	printf("\nNew Ordered Pairs : \n");
	for(i=0;i<items.size();i++)
	{
		for(j=0;j<items[i].size();j++)
			x[i].push_back(make_pair(items[i][j],freq[items[i][j]]));
		sort(x[i].begin(),x[i].end(),sortInReverse);
	}
	for(i=0;i<x.size();i++)
	{
		printf("%d : ",tid[i]);
		for(j=0;j<x[i].size();j++)
			if(x[i][j].first!='\0')
				printf("%c ",x[i][j].first);
		cout<<endl;
	}
		
	return 0;
}
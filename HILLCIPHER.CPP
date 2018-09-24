#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
char p[20],filla[3]={'x','y','z'};
char c[20];
int r;
void encrypt()
{
	cout<<"Enter Plain Text : ";
	gets(p);
	cout<<"Enter value of r in key matrix rxr : ";
	cin>>r;
	int key[10][10],sum=0;
	int s[20][1],l=strlen(p),i,j;
	cout<<"Enter key :"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			cout<<"key ["<<i<<"]"<<"["<<j<<"] : ";
			cin>>key[i][j];
		}
	}
	sum=l;
	if(sum%r!=0)
	{
		while(sum%r!=0)
		{
			sum+=1;
		}
		int x=0;
		for(i=l;i<sum;i++)
		{
			if(x==3)
			{
				x=0;
			}
			p[i]=filla[x];
			x++;
		}
	}
	int q=0,q1=0,s1=0,r2=0;
	while(sum>0)
	{
		for(i=0;i<r;i++)
		{
			s1=0;
			for(int k=0;k<r;k++)
			{       if(q==r2+r)
				{
					q=r2;
				}
				if(p[q]>=97)
				{
					s1=s1+(key[i][k]*(int)((p[q]-97)%26));
				}
				else if(p[q]>=65)
				{
					s1=s1+(key[i][k]*(int)((p[q]-65)%26));
				}
				q++;
			}
			s[i][0]=s1;
		}
		for(i=0;i<r;i++)
		{
			if(p[q1]>=97)
			{
				c[q1]=s[i][0]%26+97;
				q1++;
			}
			else if(p[q1]>=65)
			{
				c[q1]=s[i][0]%26+65;
				q1++;
			}
		}
		sum=sum-r;
		r2=r2+r;
	}
}
int  main()
{

	encrypt();
	cout<<"Encrypted text is : ";
	puts(c);
	getch();
	return 0;
}

#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
char p[30],key[30],c[30],p2[30];
int s[30];
void encrypt()
{
	int k=0,k1=0;
	cout<<"Enter plaintext: ";
	gets(p);
	cout<<"Enter key in string: ";
	gets(key);
	for(int i=0;i<strlen(p);i++)
	{
		if(p[i]>=97)
		{
			s[i]=((p[i]-97)+(key[k]-97))%26;
			c[i]=s[i]+97;
		}
		else if(p[i]>=65)
		{
			s[i]=((p[i]-65)+(key[k]-65))%26;
			c[i]=s[i]+65;
		}
		k++;
		if(k==strlen(key))
		{
			key[k]=p[k1];
			k1++;
		}
	}
}
void decrypt()
{
	int k=0;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]>=97)
		{
			s[i]=((c[i]-97)-(key[k]-97))%26;
			if(s[i]<0)
			{
			      s[i]=s[i]+26;
			}
			p2[i]=s[i]+97;
		}
		else if(c[i]>=65)
		{
			s[i]=((c[i]-65)-(key[k]-65))%26;
			if(s[i]<0)
			{
				s[i]=s[i]+26;
			}
			p2[i]=s[i]+65;
		}
		k++;
		if(k==strlen(key))
		{
			k=0;
		}
	}
}
int  main()
{

	encrypt();
	cout<<"Encrypted value is ";
	puts(c);
	decrypt();
	cout<<"Decrypted value is ";
	puts(p2);
	getch();
	return 0;
}

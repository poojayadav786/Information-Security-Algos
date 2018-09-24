#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int key,i,s[20];
char p[20],c[20],p2[20];
void encrypt()
{
	cout<<"Enter Plain Text : ";
	gets(p);
	cout<<"Enter key : ";
	cin>>key;
	for(i=0;i<strlen(p);i++)
	{
		if(p[i]>=97)
		{
			s[i]=((p[i]-97)+key)%26;
			c[i]=s[i]+97;
		}
		else if(p[i]>=65)
		{
			s[i]=((p[i]-65)+key)%26;
			c[i]=s[i]+65;
		}
	}
}
void decrypt()
{
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]>=97)
		{
			s[i]=((c[i]-97)-key)%26;
			if(s[i]<0)
			{
				s[i]+=26;
			}
			p2[i]=s[i]+97;
		}
		else if(c[i]>=65)
		{
			s[i]=((c[i]-65)-key)%26;
			if(s[i]<0)
			{
				s[i]+=26;
			}
			p2[i]=s[i]+65;
		}
	}
}
int  main()
{

	encrypt();
	cout<<"Cipher text after encryption is ";
	puts(c);
	decrypt();
	cout<<"Plain text after decryption is ";
	puts(p2);
	getch();
	return 0;
}

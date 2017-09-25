#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"youxian.h"
#include<math.h>
#include"Stack.h"
#include<malloc.h>
#include<iostream>
using namespace std;
int main()
{
	char s[MAXNUM];
	int a;
	printf("这是我们可爱的计算器，它功能强大，但是身体瘦弱，请不要欺负它。\n功能有：\n1、它支持简单的四则运算以及括号等。\n2、它支持阶乘。形式为6！,请输入整数。3、它支持乘方。形式为6^6，六的六次方。\n请按照我们的要求书写四则运算句子，否则不受理哦~\n谢谢合作！）;
	scanf("%s",s);
	a=shifouheli(&s,strlen(s));
	if(a==0) return 0;
	int i,j,k=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='!')                                     //阶乘
		{
			char st[MAXNUM];
			for(j=i+1;j<strlen(s);j++)
			{
				st[k]=s[j];
				k++;
			}
			st[k]='\0';
			for(j=i-1;j>=0;j--)
			{
				if(s[j]<48||s[j]=='$') break;
			}
			int c,b=0,d=j+1;
			for(c=i-j-2;c>=0;c--)
			{
				b=b+(s[j+1]-48)*pow(10,c);
				j++;
			}
			s[d]='\0';
			char *str=Jiecheng(b);
			strcat(s,str);
			strcat(s,st);
		}
		else if(s[i]=='^')                                //乘方
		{
			for(j=i+1;j<strlen(s);j++)
			{
				if(s[j]<48||s[j]=='$') break;
			}
			int b=j-1,c,d,e,f=0;
			j=i;
			for(e=b-i-1;e>=0;e--)
			{
				f=f+(s[j+1]-48)*pow(10,e);
				j++;
			}
			double q=0;
			for(j=i-1;j>=0;j--)
			{
				if(s[j]<48&&s[j]!='.') break;
			}
			c=j;
			for(j=i-1;j>c;j--)
			{
				if(s[j]=='.') break;
			}
			d=j;
			if(d==c)
			{
				for(e=i-c-2;e>=0;e--)
				{
					q=q+(s[j+1]-48)*pow(10,c);
					j++;
				}
			}
			else if(d>c)
			{
				j=c;
				for(e=d-c-2;e>=0;e--)
				{
					q=q+(s[j+1]-48)*pow(10,e);
					j++;
				}
				j=d;
				for(e=1;e<i-d;e++)
				{
					q=q+(s[j+1]-48)*pow(10,-e);
					j++;
				}
			}
			s[c+1]='\0';
			char st[MAXNUM];
			k=0;
			for(j=b+1;j<strlen(s);j++)
			{
				st[k]=s[j];
				k++;
			}
			st[k]='\0';
			char *str=Chengfang(q,f);
			strcat(s,str);
			strcat(s,st);
		}
	}
	return 0;
}









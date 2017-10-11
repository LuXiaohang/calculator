#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"youxian.h"
#include<math.h>
#include"Stack.h"
#include"合理性.h"
#include"乘方.h"
#include"jiecheng.h"
#include"JISUAN.h"
#include"former main.h"
#include"Latter main.h"
char* zhuchengxu(char *u)
{
	char s[MAXNUM],v[MAXNUM],t[MAXNUM];
	int a,o,b[MAXNUM],i,j,k=0;
	o=strlen(u);
	for(i=o;i>0;i--)
	{
		u[i]=u[i-1];
	}
	u[0]='$';
	u[o+1]='$';
	u[o+2]='\0';
	strcpy(s,u);
	strcpy(v,u);
	strcpy(t,u);
	o=strlen(u);
	a=shifouheli(u,o);
	if(a==0) return 0;
	qianzhui(v);
	printf("\n");
	houzhui(t);
	printf("\n");
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='!')                                     //阶乘
		{
			k=0;
			o=strlen(s);
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
				b=b+(s[j+1]-48)*pow(10.0,c);
				j++;
			}
			s[d]='\0';
			int m=Jiecheng(b);
			char str[MAXNUM];
			itoa(m,str,10);
			strcat(s,str);
			strcat(s,st);
		}
		else if(s[i]=='^')                                //乘方
		{
			o=strlen(s);
			for(j=i+1;j<strlen(s);j++)
			{
				if(s[j]<48||s[j]=='$') break;
			}
			int b=j-1,c,d,e,f=0;
			j=i;
			for(e=b-i-1;e>=0;e--)
			{
				f=f+(s[j+1]-48)*pow(10.0,e);
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
					q=q+(s[j+1]-48)*pow(10.0,e);
					j++;
				}
			}
			else if(d>c)
			{
				j=c;
				for(e=d-c-2;e>=0;e--)
				{
					q=q+(s[j+1]-48)*pow(10.0,e);
					j++;
				}
				j=d;
				for(e=1;e<i-d;e++)
				{
					q=q+(s[j+1]-48)*pow(10.0,-e);
					j++;
				}
			}
			s[c+1]='\0';
			char st[MAXNUM];
			k=0;
			for(j=b+1;j<o;j++)
			{
				st[k]=s[j];
				k++;
			}
			st[k]='\0';
			char *str=Chengfang(q,f);
			strcat(s,str);
			strcat(s,st);
			int w=strlen(s);
			s[w]='\0';
		}
	}
	j=0;                           //计算
	for(i=0;i<o;i++)
	{
		if(s[i]=='(')
		{
			b[j]=i;
			j++;
		}
	}
	k=j-1;
	for(i=k;i>=0;i--)
	{
		o=strlen(s);
		char st[MAXNUM],str[MAXNUM];
		int l,q=1,p;
		st[0]='$';
		for(l=b[i];s[l]!=')';l++)
		{
			st[q]=s[l];
			q++;
		}
		st[q]=')';
		st[q+1]='$';
		st[q+2]='\0';
		s[b[i]]='\0';
		q=0;
		for(p=l+1;p<o;p++)
		{
			str[q]=s[p];
			q++;
		}
		str[q]='\0';
		double y=JiSuan(st);
		sprintf(st,"%lf",y);
		strcat(s,st);
		strcat(s,str);
	}
	o=strlen(s);
	for(i=o;i>1;i--)
	{
		s[i]=s[i-1];
	}
	s[1]='(';
	s[o]=')';
	s[o+1]='$';
	s[o+2]='\0';
	double y=JiSuan(s);
	sprintf(s,"%lf",y);
	int p;
	p=strlen(s);
	p--;
	while(s[p]=='0')
	{
		p--;
	}
	if(s[p]=='.') s[p]='\0';
	else s[p+1]='\0';
	return s;

}









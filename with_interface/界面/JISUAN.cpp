#include<stdio.h>
#include<math.h>
#include"Stack.h"
#include"Stack2.h"
#include"youxian.h"
#include"JISUAN.h"
double jieguo(double y,double x,char h);
double JiSuan(char *shizi)
{
	int i=1,a[MAXNUM],j=1,k=0,d=0,m,n;              //a数组用来放每个运算符所在位置，b数组用来放每个运算数字
	double e,b[MAXNUM]={0.0};                                                   //e用来放结果
	Stack S;                                                  //s用来放每个运算数字栈，op用来放每个运算符的栈
	Stack2 op;
	S.t=0;
	op.t=0;
	a[0]=0; 
	while(shizi[i]!='$')
	{
		if(shizi[i]<48&&shizi[i]!='.')
		{
			a[j]=i;
			j++;
		}
		i++;
	}                                                     //此时i是整个式子包括最后一个$的长度，j-1是有多少个运算符
	m=j-1;
	a[j]=i;
	for(k=0;k<j;k++)
	{
		if(shizi[a[k+1]]!='('&&shizi[a[k]]!=')')
		{
			int c,x,y,z=a[k+1];
			for(c=a[k]+1;c<a[k+1];c++)
			{
				if(shizi[c]=='.') 
				{
					z=c;
					break;
				}
			}
			for(c=z-a[k]-2;c>=0;c--)
			{
				y=z-c-1;
				x=shizi[y]-48;
				b[d]=b[d]+pow(10.0,c)*x;
			}
			for(c=1;c<=a[k+1]-z-1;c++)
			{
				x=shizi[z+c]-48;
				b[d]=b[d]+pow(10.0,-c)*x;
			}
			d++;
		}
	}                                         //把式子列出来
	n=d-1;                                    //m是有多少个运算符，n是有多少个数字
	Push(S,b[0]);
	Push2(op,shizi[0]);
	Push2(op,shizi[a[1]]);
	if(Top2(op)=='$') return b[0];
	d=1;
	j=2;
	do
	{
		if(Top2(op)==')')
		{
			Pop2(op);
			Pop2(op);
			break;
		}
		else if(Top2(op)=='(')
		{
			Push2(op,shizi[a[j]]);
			j++;
			if(shizi[a[j]]=='$'&&S.t==1) break;
			Push(S,b[d]);
			d++;
		}
		else
		{
			int q=youxian(Top2(op),shizi[a[j]]);
			if(q==0)
			{
				Push2(op,shizi[a[j]]);
				j++;
			    Push(S,b[d]);
		    	d++;
			}
			else
			{
				double x,y;
				x=Top(S);
				Pop(S);
				y=jieguo(Top(S),x,Top2(op));
				Pop(S);
				Push(S,y);
				Pop2(op);
				if(shizi[a[j]]=='$'&&S.t==1) break;
			}
		}
	}while(shizi[a[j]]!='$');
	e=Top(S);
	return e;
}
double jieguo(double y,double x,char h)
{
	switch(h)
	{
	case'+':
		return y+x;
	case'-':
		return y-x;
	case'*':
		return y*x;
	case'/':
		return y/x;
	}
}
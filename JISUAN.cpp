#include<stdio.h>
#include<math.h>
#include"Stack.h"
float jieguo(float y,float x,char h);
float JiSuan(char *shizi)
{
	int i=1,a[MAXNUM],j=1,b[MAXNUM]=0,k=0,d=0,m,n;              //a数组用来放每个运算符所在位置，b数组用来放每个运算数字
	float e;                                                   //e用来放结果
	Stack s,op;                                               //s用来放每个运算数字栈，op用来放每个运算符的栈
	a[0]=0; 
	while(shizi[i]!='$')
	{
		if(shizi[i]<48)
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
		if(a[k+1]-a[k]-1!=0)
		{
			int c,x,y;
			for(c=a[k+1]-a[k]-2;c>=0;c--)
			{
				y=a[k+1]-c-1;
				x=shizi[y]-48;
				b[d]=b[d]+pow(10,c)*x;
			}
			d++;
		}
	}                                         //把式子列出来
	n=d-1;                                    //m是有多少个运算符，n是有多少个数字
	Push(s,b[0]);
	Push(op,shizi[0]);
	Push(op,shizi[a[1]]);
	d=1;
	j=2;
	while(shizi[a[j]]!='$')
	{
		if(Top(op)==')')
		{
			Pop(op);
			Pop(op);
		}
		if(a[j]-a[j-1]==1)
		{
			Push(op,shizi[a[j]]);
			j++;
		}
		else
		{
			Push(s,b[d]);
			d++;
			int q=YouXian(Top(op),shizi[a[j]]);
			if(q==0)
			{
				Push(op,shizi[a[j]]);
				j++;
			}
			else
			{
				float x,y;
				x=Top(s);
				Pop(s);
				y=jieguo(Top(s),x,Top(op));
				Push(s,y);
				Pop(op);
				Push(op,shizi[a[j]]);
				j++;
			}
		}
	}
	e=Top(s);
	return e;
}
float jieguo(float y,float x,char h)
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
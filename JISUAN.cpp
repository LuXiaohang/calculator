#include<stdio.h>
#include<math.h>
#include"Stack.h"
float jieguo(float y,float x,char h);
float JiSuan(char *shizi)
{
	int i=1,a[MAXNUM],j=1,b[MAXNUM]=0,k=0,d=0,m,n;              //a����������ÿ�����������λ�ã�b����������ÿ����������
	float e;                                                   //e�����Ž��
	Stack s,op;                                               //s������ÿ����������ջ��op������ÿ���������ջ
	a[0]=0; 
	while(shizi[i]!='$')
	{
		if(shizi[i]<48)
		{
			a[j]=i;
			j++;
		}
		i++;
	}                                                     //��ʱi������ʽ�Ӱ������һ��$�ĳ��ȣ�j-1���ж��ٸ������
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
	}                                         //��ʽ���г���
	n=d-1;                                    //m���ж��ٸ��������n���ж��ٸ�����
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
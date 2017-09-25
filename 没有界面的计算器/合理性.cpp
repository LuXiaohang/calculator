#include<stdio.h>
#include<string.h>
#include"合理性.h"
int shifouheli(char *shizi,int max)
{
	int i,j,k,t;
	for(i=0;i<max;i++)
	{
		if(shizi[1]=='+'||shizi[1]=='-'||shizi[1]=='*'||shizi[1]=='/'||shizi[1]==')'||shizi[1]=='!'||shizi[1]=='^')//式子的开头不能是“+”“-”“*”“/”“）”“！”“^”
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='=')//式子中不能出现“=”
		{	printf("buheli\n");
		return 0;}
		if((shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='('||shizi[i]=='^')&&(shizi[i+1]=='$'))//式子的结尾不能是“+”“-”“*”“/”“（”“^”
		{
			printf("buheli\n");
			return 0;}
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/')//运算符的后面不能紧跟着除"("以外的运算符
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]==')'||shizi[i+1]=='!'||shizi[i+1]=='^')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='(')//"("之后不能跟运算符
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]=='!'||shizi[i+1]=='^')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]==')')//")"之后不能跟数字
		{
			if(shizi[i+1]>='0'&&shizi[i+1]<='9')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='(')//括号不能紧邻括号
		{
			if(shizi[i+1]==')')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]==')')//括号不能紧邻括号
		{
			if(shizi[i+1]=='(')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='!'||shizi[i]=='^')//阶乘或者乘方符号前面必须是数字或者“）”
		{
			if(shizi[i-1]<'0'||shizi[i-1]>'9')
			{	
				if(shizi[i-1]!=')')
			    printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]=='^')//乘方符号后面必须是整数或者“（”
		{
			if(shizi[i+1]<'0'||shizi[i+1]>'9')
			{
				if(shizi[i+1]!='(')
				printf("buheli\n");
				return 0;
			}
			t=i+1;
			while(shizi[t]>'0'&&shizi[t]<'9'&&shizi[t+1]!='$')//遇到小数点了，说明不是整数
			{
				if(shizi[t+1]=='.')
				{
					printf("buheli\n");
				return 0;
				}
				t++;
			}
		}
    	if(shizi[i]=='(')//括号中不能只有数字
		{
			int c=0;//用于计数运算符出现的次数
			j=i+1;
			while(shizi[j]!=')')
			{
				if(shizi[j]=='+'||shizi[j]=='-'||shizi[j]=='*'||shizi[j]=='/')
				{
					c++;
				}
				j++;
			}
			if(c==0)
			{
				printf("书写不规范，括号中不能全部为数字\n");
			}
		}
	}
	int f=0;
	for(i=0;i<max;i++)
	{
		
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='!'||shizi[i]=='^')
			f++;
	}
	if(f==0)
	{
		printf("buheli\n");
		return 0;
	}


	for(i=0;i<max;i++)//括号的数量和方向必须匹配
	{
		if((shizi[i]!='(')&&(shizi[i]!=')')) 
			shizi[i]=' ';
	}
	for(i=0;i<max;i++)
	{
		if(shizi[i]==')')
		{
			for(k=i;k>=0;k--)
			{
				if(shizi[k]=='(')
				{
					shizi[k]=' ';
					shizi[i]=' ';
					break;
				}
			}
			if(k<0) shizi[i]='?';
		}
	}
	for(i=0;i<max;i++)
	{
		if(shizi[i]=='(') shizi[i]='?';
	}
	for(i=0;i<max;i++)
	{
		if(shizi[i]=='?')
		{printf("buheli");
		return 0;
		}
	}
	printf("该式子合理\n");
	return 1;
}       












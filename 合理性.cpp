#include<stdio.h>
#include<string.h>
#include<malloc.h>
int shifouheli(char *shizi,int max)
{
	int i,j,k;
	for(i=0;i<max;i++)
	{
		if(shizi[1]=='+'||shizi[1]=='-'||shizi[1]=='*'||shizi[1]=='/'||shizi[1]==')')//式子的开头不能是“+”“-”“*”“/”“）”
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='=')//式子中不能出现“=”
		{	printf("buheli\n");
		    return 0;
		}
		if((shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='(')&&shizi[i+1]=='$')//式子的结尾不能是“+”“-”“*”“/”“（”
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/')//运算符的后面不能紧跟着除"("以外的运算符
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]==')')
			{	
				printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]=='(')//"("之后不能跟运算符
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/')
			{	printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]==')')//")"之后不能跟数字
		{
			if(shizi[i+1]>='0'&&shizi[i+1]<='9')
			{	
				printf("buheli\n");
				return 0;
			}
		}
		if(shizi[i]=='('||shizi[i]==')')//括号不能紧邻括号
		{
			if(shizi[i+1]=='('||shizi[i+1]==')')
			{	
				printf("buheli\n");
			    return 0;
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
		if(shizi[i]=='('||shizi[i]==')') shizi[i]='?';
	}
	for(i=0;i<max;i++)
	{
		if(shizi[i]=='?')
		{
			printf("buheli");
		    return 0;
		}
	}
	
	printf("该式子合理\n");
	return 1;
}












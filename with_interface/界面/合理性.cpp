#include<stdio.h>
#include<string.h>
#include"������.h"
int shifouheli(char *shizi,int max)
{
	int i,j,k,t;
	for(i=0;i<max;i++)
	{
		if(shizi[1]=='+'||shizi[1]=='-'||shizi[1]=='*'||shizi[1]=='/'||shizi[1]==')'||shizi[1]=='!'||shizi[1]=='^')//ʽ�ӵĿ�ͷ�����ǡ�+����-����*����/����������������^��
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='=')//ʽ���в��ܳ��֡�=��
		{	printf("buheli\n");
		return 0;}
		if((shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='('||shizi[i]=='^')&&(shizi[i+1]=='$'))//ʽ�ӵĽ�β�����ǡ�+����-����*����/����������^��
		{
			printf("buheli\n");
			return 0;}
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/')//������ĺ��治�ܽ����ų�"("����������
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]==')'||shizi[i+1]=='!'||shizi[i+1]=='^')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='(')//"("֮���ܸ������
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]=='!'||shizi[i+1]=='^')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]==')')//")"֮���ܸ�����
		{
			if(shizi[i+1]>='0'&&shizi[i+1]<='9')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='(')//���Ų��ܽ�������
		{
			if(shizi[i+1]==')')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]==')')//���Ų��ܽ�������
		{
			if(shizi[i+1]=='(')
			{	printf("buheli\n");
			return 0;}
		}
		if(shizi[i]=='!'||shizi[i]=='^')//�׳˻��߳˷�����ǰ����������ֻ��ߡ�����
		{
			if(shizi[i-1]<'0'||shizi[i-1]>'9')
			{	
				if(shizi[i-1]!=')')
			    printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]=='^')//�˷����ź���������������ߡ�����
		{
			if(shizi[i+1]<'0'||shizi[i+1]>'9')
			{
				if(shizi[i+1]!='(')
				printf("buheli\n");
				return 0;
			}
			t=i+1;
			while(shizi[t]>'0'&&shizi[t]<'9'&&shizi[t+1]!='$')//����С�����ˣ�˵����������
			{
				if(shizi[t+1]=='.')
				{
					printf("buheli\n");
				return 0;
				}
				t++;
			}
		}
    	if(shizi[i]=='(')//�����в���ֻ������
		{
			int c=0;//���ڼ�����������ֵĴ���
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
				printf("��д���淶�������в���ȫ��Ϊ����\n");
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


	for(i=0;i<max;i++)//���ŵ������ͷ������ƥ��
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
	printf("��ʽ�Ӻ���\n");
	return 1;
}       












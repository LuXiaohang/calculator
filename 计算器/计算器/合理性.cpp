#include<stdio.h>
#include<string.h>
#include<malloc.h>
int shifouheli(char *shizi,int max)
{
	int i,j,k;
	for(i=0;i<max;i++)
	{
		if(shizi[1]=='+'||shizi[1]=='-'||shizi[1]=='*'||shizi[1]=='/'||shizi[1]==')')//ʽ�ӵĿ�ͷ�����ǡ�+����-����*����/��������
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='=')//ʽ���в��ܳ��֡�=��
		{	printf("buheli\n");
		    return 0;
		}
		if((shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='(')&&shizi[i+1]=='$')//ʽ�ӵĽ�β�����ǡ�+����-����*����/��������
		{
			printf("buheli\n");
			return 0;
		}
		if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/')//������ĺ��治�ܽ����ų�"("����������
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/'||shizi[i+1]==')')
			{	
				printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]=='(')//"("֮���ܸ������
		{
			if(shizi[i+1]=='+'||shizi[i+1]=='-'||shizi[i+1]=='*'||shizi[i+1]=='/')
			{	printf("buheli\n");
			    return 0;
			}
		}
		if(shizi[i]==')')//")"֮���ܸ�����
		{
			if(shizi[i+1]>='0'&&shizi[i+1]<='9')
			{	
				printf("buheli\n");
				return 0;
			}
		}
		if(shizi[i]=='('||shizi[i]==')')//���Ų��ܽ�������
		{
			if(shizi[i+1]=='('||shizi[i+1]==')')
			{	
				printf("buheli\n");
			    return 0;
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
	
	printf("��ʽ�Ӻ���\n");
	return 1;
}












#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char Chengfang(double a,int b)
{
	double i,c=1;//aΪ������cΪ�˷����
	int a1,a2;//bΪָ����a1Ϊ������������֣�a2Ϊ�����С������ת��Ϊ����
	char zhengshu[50],xiaoshu[8],dian[10]=".";
	for(i=1;i<=b;i++)
	{
		c=c*a;
	}
    a1=(int)c;
	a2=(c-a1)*1000000;//��С������ת��Ϊ����
    itoa(a1,zhengshu,10);
	itoa(a2,xiaoshu,10);
    strcat(zhengshu,dian);
	strcat(zhengshu,xiaoshu);
	return &zhengshu;
}

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char Chengfang(double a,int b)
{
	double i,c=1;//a为底数，c为乘方结果
	int a1,a2;//b为指数，a1为结果的整数部分，a2为结果的小数部分转化为整数
	char zhengshu[50],xiaoshu[8],dian[10]=".";
	for(i=1;i<=b;i++)
	{
		c=c*a;
	}
    a1=(int)c;
	a2=(c-a1)*1000000;//将小数部分转化为整数
    itoa(a1,zhengshu,10);
	itoa(a2,xiaoshu,10);
    strcat(zhengshu,dian);
	strcat(zhengshu,xiaoshu);
	return &zhengshu;
}

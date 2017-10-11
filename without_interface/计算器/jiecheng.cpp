#include<stdio.h>
#include<string.h>
#include<math.h>
#include"jiecheng.h"
int Jiecheng(int n)
{
	int jieguo=n;
	if(n==1)
		return 1;
	if(n>1) 
	{
		jieguo=jieguo*Jiecheng(n-1);
	}
	return jieguo;
}

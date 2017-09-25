#include<stdio.h>
#include<string.h>
#include<math.h>
int Jiecheng(int n)
{
	int jieguo=n;
	if(n==1)
		return 1;
	if(n>1) 
	{
		jieguo=jieguo*Jiecheng(n-1);
	}
	int zongshu=0;
	char str[1000000];
	int i;
	for(i=0;i<1000000;i++)
	{
		str[i]=jieguo%10+48;
		jieguo=jieguo/10;
		zongshu++;
		if(jieguo==0)
			break;
	}
	int k;
	int j;
	for(k=0;k<zongshu;k++)
	{
	    j=str[zongshu-k-1];  
		str[zongshu-k-1]=str[k];
		str[k]=str[zongshu-k-1];
	    if(k>=zongshu-k-1)
		   break;
	}
	str[zongshu+1]='\0';
	return &str;
}

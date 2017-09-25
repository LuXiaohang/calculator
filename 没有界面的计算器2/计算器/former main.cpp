#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Fstack.h"
#include"Fyouxian.h"
static int t;
void StackToStack31(Stack3 &S1,Stack3 &S2);
void qianzhui(char *shizi)
{
	int len,q;
	int i=1,j=0;
	len=strlen(shizi)-2;
	Stack3 L1,L2;//L1用于存储整个后缀表达式；L2用于存储运算符
	InitializeEmptyStack3(L1);
	InitializeEmptyStack3(L2);
	Push3(L1,shizi[0]);
	for(i=len;i>=1;i--)
	{   
		
		if((shizi[i]>=48&&shizi[i]<94)||shizi[i]=='.')
		{
			 Push3(L1,shizi[i]);
		}
		else
		{
			Push3(L1,'#');
			 t++;
			if( IsEmptyStack3(L2))
		    {
				 Push3(L2,shizi[i]);
			}
            else
			{
			   q=youxian3(Top3(L2),shizi[i]);
			   if(q==1)
			   {
				Push3(L2, shizi[i]);
			   }
			   else
			   {
				   if(q==-1)
				   {
					   Pop3(L2);
				   }
				   else
				   {
				    Push3(L1, Top3(L2));
				    Pop3(L2);
				    i++;
				   }
			    }
		    }
	      }
	}
	Push3(L1, '#');
	StackToStack31(L2,L1);
	printf("前缀表达式为：\n");
	while(Top3(L1)!='$')
	{
		if(Top3(L1)=='#')
		{  
		 	 Pop3(L1);
		   if(Top3(L1)!='#')
		  {
		    printf(" ");
		  }
	
		  continue;
		}
        printf("%c",Top3( L1));
		Pop3(L1);
	}
	return;
}
void StackToStack31(Stack3 &S1,Stack3 &S2)
{
	int a=0;
	while(!IsEmptyStack3(S1))
	{
		 Push3 (S2,Top3(S1)) ;
		 Push3 (S2,'#') ;
		 Pop3(S1);
		 t++;
	}
}


	


	






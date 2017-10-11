#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"youxian.h"
int youxian(char a,char b)
{
	switch(a)
	{
	case'+':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 0;
	         case'/':return 0;
			 case'(':return 0;
			 case')':return 1;
			 case'$':return 1;
			}
	case'-':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 0;
	         case'/':return 0;
		     case'(':return 0;
			 case')':return 1;
			 case'$':return 1;
			}
	case'*':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
			 case'(':return 0;
			 case')':return 1;
			 case'$':return 1;
			}
	case'/':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return 0;
			 case')':return 1;
			 case'$':return 1;
			}
	case'(':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 0;
	         case'/':return 0;
             case'(':return 0;
			 case')':return equal;
			 case'$':return error;
			}
	case')':switch(b)
			{
	         case'+':return 1;
	         case'-':return 1;
	         case'*':return 1;
	         case'/':return 1;
             case'(':return error;
			 case')':return 1;
			 case'$':return 1;
			}
	case'$':switch(b)
			{
	         case'+':return 0;
	         case'-':return 0;
	         case'*':return 0;
	         case'/':return 0;
             case'(':return 0;
			 case')':return error;
			 case'$':return 1;
			}
	}
}
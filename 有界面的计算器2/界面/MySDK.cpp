#include"stdafx.h"
#include "Resource.h"
#include <windows.h>
#include<Windows.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"主程序.h"
#include"Stack.h"

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);//声名消息处理函数(处理windows和接收windows消息)
void NumResult(char );
void EquResult();
HWND hWndhWnd,hEditResult,
	hButtonOptSum0,hButtonOptSum1,hButtonOptSum2,hButtonOptSum3,
	hButtonOptSum4,hButtonOptSum5,hButtonOptSum6,hButtonOptSum7,
	hButtonOptSum8,hButtonOptSum9,hButtonOptSumDec,hButtonCF,hButtonJC,
	hButtonOptAdd,hButtonOptSub,hButtonOptMul,hButtonOptDiv,
	hButtonOptLeft,hButtonOptRight,hButtonOptEqu,hButtonCancelEntry;
	HINSTANCE hInst;
	char mine[MAXNUM];//待处理的字符串
	char jg[MAXNUM];
	char lpszOpt[ ]="N"; //储存操作符号
	char *stop;
	int nMax;
	int nOptF=0;   // 判断是否按了操作符键
	bool bDec=false ;  //判断是否按了操作符“；”
int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,
	    LPSTR lpCmdLine , int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	char lpszClassName[ ]="编辑框";
	char lpszTitle[ ]="计算器";
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)(GetStockObject(LTGRAY_BRUSH));
	WndClass.hCursor=LoadIcon(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=WndProc; //消息处理
	WndClass.lpszClassName=lpszClassName;
	WndClass.lpszMenuName=lpszClassName;
	WndClass.style=0;
	if(!RegisterClass(&WndClass))
	{
		MessageBeep(0);
		return FALSE;
	}
	hInst=hInstance;
	hWnd=CreateWindow(lpszClassName,lpszTitle,
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT , CW_USEDEFAULT ,350 , 350 ,NULL,NULL,hInstance , NULL);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	while(GetMessage (&Message, NULL , 0 , 0  ))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message. wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
		case WM_CREATE:
			hEditResult=CreateWindow("EDIT",
				NULL,
				WS_CHILD|WS_VISIBLE|ES_RIGHT|WS_BORDER|ES_READONLY,
				10,10,330,30,hwnd,(HMENU)IDE_RESULT,hInst,NULL);
			hButtonOptSum7=CreateWindow("BUTTON",
				"7",WS_CHILD|WS_VISIBLE,
				15,50,50,50,hwnd,(HMENU) IDB_NUM7,hInst,NULL);
			hButtonOptSum8=CreateWindow("BUTTON",
				"8",WS_CHILD|WS_VISIBLE,
				75,50,50,50,hwnd,(HMENU) IDB_NUM8,hInst,NULL);
			hButtonOptSum9=CreateWindow("BUTTON",
				"9",WS_CHILD|WS_VISIBLE,
				135,50,50,50,hwnd,(HMENU) IDB_NUM9,hInst,NULL);
			hButtonOptSum4=CreateWindow("BUTTON",
				"4",WS_CHILD|WS_VISIBLE,
				15,110,50,50,hwnd,(HMENU) IDB_NUM4,hInst,NULL);
			hButtonOptSum5=CreateWindow("BUTTON",
				"5",WS_CHILD|WS_VISIBLE,
				75,110,50,50,hwnd,(HMENU) IDB_NUM5,hInst,NULL);
			hButtonOptSum6=CreateWindow("BUTTON",
				"6",WS_CHILD|WS_VISIBLE,
				135,110,50,50,hwnd,(HMENU) IDB_NUM6,hInst,NULL);
			hButtonOptSum1=CreateWindow("BUTTON",
				"1",WS_CHILD|WS_VISIBLE,
				15,170,50,50,hwnd,(HMENU) IDB_NUM1,hInst,NULL);
			hButtonOptSum2=CreateWindow("BUTTON",
				"2",WS_CHILD|WS_VISIBLE,
				75,170,50,50,hwnd,(HMENU) IDB_NUM2,hInst,NULL);
			hButtonOptSum3=CreateWindow("BUTTON",
				"3",WS_CHILD|WS_VISIBLE,
				135,170,50,50,hwnd,(HMENU) IDB_NUM3,hInst,NULL);
			hButtonOptSum0=CreateWindow("BUTTON",
				"0",WS_CHILD|WS_VISIBLE,
				15,230,50,50,hwnd,(HMENU) IDB_NUM0,hInst,NULL);
			hButtonOptSumDec=CreateWindow("BUTTON",
				".",WS_CHILD|WS_VISIBLE,
				75,230,50,50,hwnd,(HMENU) IDB_NUMDEC,hInst,NULL);
			hButtonOptSumDec=CreateWindow("BUTTON",
				"(",WS_CHILD|WS_VISIBLE,
				135,230,25,50,hwnd,(HMENU) IDB_OPTLEFT,hInst,NULL);
			hButtonOptSumDec=CreateWindow("BUTTON",
				")",WS_CHILD|WS_VISIBLE,
				160,230,25,50,hwnd,(HMENU) IDB_OPTRIGHT,hInst,NULL);


			
			hButtonCF=CreateWindow("BUTTON",
				"^",WS_CHILD|WS_VISIBLE,
				280,110,50,50,hwnd,(HMENU) IDB_CF,hInst,NULL);
			hButtonJC=CreateWindow("BUTTON",
				"!",WS_CHILD|WS_VISIBLE,
				280,170,50,50,hwnd,(HMENU) IDB_JC,hInst,NULL);
			hButtonCancelEntry=CreateWindow("BUTTON",
				"C",WS_CHILD|WS_VISIBLE,
				280,50,50,50,hwnd,(HMENU) IDB_CANCLEENTRY,hInst,NULL);
		   hButtonOptAdd=CreateWindow("BUTTON",
				"+",WS_CHILD|WS_VISIBLE,
				220,50,50,50,hwnd,(HMENU) IDB_OPTADD,hInst,NULL);
		   	hButtonOptSub=CreateWindow("BUTTON",
				"-",WS_CHILD|WS_VISIBLE,
				220,110,50,50,hwnd,(HMENU) IDB_OPTSUB,hInst,NULL);
		 	hButtonOptMul=CreateWindow("BUTTON",
				"*",WS_CHILD|WS_VISIBLE,
				220,170,50,50,hwnd,(HMENU) IDB_OPTMUL,hInst,NULL);
			hButtonOptDiv=CreateWindow("BUTTON",
				"/",WS_CHILD|WS_VISIBLE,
				220,230,50,50,hwnd,(HMENU) IDB_OPTDIV,hInst,NULL);
		    hButtonOptEqu=CreateWindow("BUTTON",
				"=",WS_CHILD|WS_VISIBLE,
				280,230,50,50,hwnd,(HMENU) IDB_OPTEQU,hInst,NULL);
		SetWindowText(hEditResult,"0");
		break;
		case WM_SETFOCUS:
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
			case IDB_NUM0:
				
				NumResult('0'); break;
			case IDB_NUM1:
				NumResult('1'); break;
			case IDB_NUM2:
				NumResult('2'); break;
			case IDB_NUM3:
				NumResult('3'); break;
			case IDB_NUM4:
				NumResult('4'); break;
	    	case IDB_NUM5:
				NumResult('5'); break;
			case IDB_NUM6:
				NumResult('6'); break;
			case IDB_NUM7:
				NumResult('7'); break;
			case IDB_NUM8:
				NumResult('8'); break;
			case IDB_NUM9:
				NumResult('9'); break;
			case IDB_NUMDEC:
				if(bDec==true) break;
				NumResult('.');
				nOptF=1;
			//	bDec=true;
				break;
			case IDB_OPTADD:
				NumResult('+'); break;
				break;
			case IDB_OPTSUB:
				NumResult('-'); break;
				break;
			case IDB_OPTMUL:
				NumResult('*'); break;
				break;
			case IDB_OPTDIV:
	        	NumResult('/'); break;
				break;
			case IDB_OPTRIGHT:
				NumResult(')'); break;
				break;
			case IDB_OPTEQU:
				EquResult( );
				break;
			case IDB_OPTLEFT:
	     		NumResult('('); break;
				break;
			case IDB_CF:
				NumResult('^'); break;
				break;
			case IDB_JC:
				NumResult('!'); break;
				break;
			case IDB_CANCLEENTRY:
				SetWindowText(hEditResult,"0");
				break;
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);break;
		default:
			return DefWindowProc(hwnd,message,wParam,lParam);
			}
			return 0;
		}
void NumResult(char Data)
{
	//if(nOptF==0)
	//	SetWindowText(hEditResult,"");

	nMax=GetWindowTextLength(hEditResult)+1;
	GetWindowText(hEditResult,mine,nMax);
	if(strcmp(mine,"0")==0)
	{
		mine[0]=Data;
	}
	else
	{
		char m[2];
		m[0]=Data;
		m[1]='\0';
		strcat(mine,m);
	}
	SetWindowText(hEditResult,mine);
}

void EquResult()
{
	char *s=zhuchengxu(mine);
	MessageBox(NULL,TEXT(s),TEXT("结果"),MB_OK);//结果
}




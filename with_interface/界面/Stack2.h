
#define MAXNUM 1000

#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef char DataType2;//栈中存放的数据元素

struct Stack2
{

	//s表示存放栈中数据元素的连续存储区域的首地址
	//存储空间大小MAXNUM的连续存储单元
	//s指示的为栈底,元素从s开始依次存放		

	//栈顶位置:用栈顶元素的下标表示,
	//有效值(-1,MAXNUM-1),约定: 空栈时令t=-1;
	//栈非空时: s[t]表示栈顶元素
	
	DataType2 s[MAXNUM];	
	int t;  
};

//创建空栈 
int InitializeEmptyStack2(Stack2 &S);

//入栈,将新的元素X插入栈S中，置为栈顶
int Push2(Stack2 &op, DataType2 x);

//出栈,将栈顶元素删除
int Pop2(Stack2 &op);

//取栈顶,读取栈顶元素
DataType2 Top2(Stack2 S);


//判栈空,若S为空栈，返回TRUE，否则FALSE。  
int IsEmptyStack2(Stack2 S);



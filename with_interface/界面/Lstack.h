
#define MAXNUM 1000
#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef char DataType4;//ջ�д�ŵ�����Ԫ��

struct Stack4
{

	//s��ʾ���ջ������Ԫ�ص������洢������׵�ַ
	//�洢�ռ��СMAXNUM�������洢��Ԫ
	//sָʾ��Ϊջ��,Ԫ�ش�s��ʼ���δ��		

	//ջ��λ��:��ջ��Ԫ�ص��±��ʾ,
	//��Чֵ(-1,MAXNUM-1),Լ��: ��ջʱ��t=-1;
	//ջ�ǿ�ʱ: s[t]��ʾջ��Ԫ��
	
	DataType4 s[MAXNUM];	
	int t;  
};

//������ջ 
int InitializeEmptyStack4(Stack4 &S);

//��ջ,���µ�Ԫ��X����ջS�У���Ϊջ��
int Push4(Stack4 &S, DataType4 x);

//��ջ,��ջ��Ԫ��ɾ��
int Pop4(Stack4 &S);

//ȡջ��,��ȡջ��Ԫ��
DataType4 Top4(Stack4 S);


//��ջ��,��SΪ��ջ������TRUE������FALSE��  
int IsEmptyStack4(Stack4 S);

//��Ԫ�ش�һ��ջ������һ��ջ��
void StackToStack4(Stack4 &S1,Stack4 &S2);



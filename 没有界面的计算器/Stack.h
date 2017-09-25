
#define MAXNUM 1000

#define OK 0
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2

typedef double DataType;//ջ�д�ŵ�����Ԫ��

struct Stack
{

	//s��ʾ���ջ������Ԫ�ص������洢������׵�ַ
	//�洢�ռ��СMAXNUM�������洢��Ԫ
	//sָʾ��Ϊջ��,Ԫ�ش�s��ʼ���δ��		

	//ջ��λ��:��ջ��Ԫ�ص��±��ʾ,
	//��Чֵ(-1,MAXNUM-1),Լ��: ��ջʱ��t=-1;
	//ջ�ǿ�ʱ: s[t]��ʾջ��Ԫ��
	
	DataType s[MAXNUM];	
	int t;  
};

//������ջ 
int InitializeEmptyStack(Stack &S);

//��ջ,���µ�Ԫ��X����ջS�У���Ϊջ��
int Push(Stack &S, DataType x);

//��ջ,��ջ��Ԫ��ɾ��
int Pop(Stack &S);

//ȡջ��,��ȡջ��Ԫ��
DataType Top(Stack S);


//��ջ��,��SΪ��ջ������TRUE������FALSE��  
int IsEmptyStack(Stack S);



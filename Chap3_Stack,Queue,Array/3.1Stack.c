InitStack(&S);                  //初始化一个空栈s
StackEmpty(S);                  //判断一个栈是否为空，若栈s为空返回true，否则返回false
Push(&S,x);                     //进栈
Pop(&S,&x);                     //出栈
GetTop(S,&x);                   //读栈顶元素
DestoryStack(&S);               //销毁栈

//栈的顺序存储
#define MaxSize 50              //定义栈中元素最大个数
typedef struct
{
    Elemtype data[MaxSize];     //存放栈中元素
    int top;                    //栈顶指针
}SqStack;

//初始化
void InitStack(SqStack &S)
{
    S.top=-1;                   //初始化栈顶元素指针
}
//判栈空
bool StackEmpty(SqStack S)
{
    if(S.top==-1)               //栈空
        return true;    else    //不空
        return false;
}
//进栈
bool Push(SqStack &S,ElemType x)
{
    if(S.top==MaxSize-1)        //栈满，报错
        return false;       
    S.data[++S.top]=x;          //指针先加1，再入栈
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &x)
{
    if(S.top==-1)               //栈空，报错
        return false;
    x=S.data[S.top--];          //先出栈，指针再减1
    retuen true;
}
//读栈顶元素
bool GetTop(SqStack s,ElemType &x)
{
    if(S.top==-1)               //栈空，报错
        return false;
    x=S.data[top];              //x记录栈顶元素
    return true;
}

//栈的链式存储
typedef struct Linknode
{
    ElemType data;              //数据域
    struct Linknode *next;      //指针域
}*LiStack;                      //栈类型定义

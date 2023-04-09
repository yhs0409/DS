//线性表顺序存储类型描述 假定线性表元素类型为ElemType
#define MaxSize 50              //定义线性表最大长度
typedef struct{
    ElemType data{MaxSize};     //顺序表的元素
    int Length;                 //顺序表的当前长度
}SqList;                        //顺序表类型定义

//动态分配
#define InitSize 100        //表长度的初始定义
typedef struct 
{
    ElemType *data;         //指示动态分配数组的指针
    int MaxSize,length;     //数组最大容量和当前个数
}SeqList;                   //动态分配数组顺序表的类型定义
//C的初始动态分配语句为
L.data=(ElemType*)malloc(sizeof(ElemType)*InitSize);

//插入
bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1)           //判断i的范围是否有效
        return false;
    if(L.Length>=MaxSize)           //当前存储空间已满，不能插入
        return false;
    for(int j=L.length;j>=i;j--)    //将第i个元素及以后的元素后移
    {
        L.data[j]=L.data[j--];
    }
    L.data[i-1]=e;                  //在位置i处插入e
    L.length++;                     //线性表长度+1
    return ture;
}

//删除
bool ListDelete(SqList &L,int i,Elemtype &e)
{
        if(i<1||i>L.length+1)           //判断i的范围是否有效
        return false;
        e=L.data[i-1];                  //将被删除元素赋给e
        for(int j=i,j<L.length,j++)     //将第i个位置元素前移
        {
            L.data[j-1]=L.data[j];
        }
        L.length--;                     //表长度-1
        return ture;
}

//按值查找
int LocateElem(SqList L,ElemType e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        return i+1;                 //下标为i的元素值等于e，返回其位序i+1
    }
    return 0;                       //退出循环，说明查找失败
}
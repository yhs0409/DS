//Basic Difinition
InitList(&L)        //初始化表
Length(L)           //求表长
LocateElem(L,e)     //按值查找，在表L中查找具有给定关键字值的元素
GetElem(L,i)        //按位查找，获取表L中第i个位置元素的值
ListInsert(&L,i,e)  //插入，在表L中第i个位置插入指定元素e
ListDelete(&L,i,&e) //删除
PrintList(L)        //输出，按前后顺序输出线性表L中所有元素值
Empty(L)            //判空，若L为空表，返回true，否则返回false
DestoryList(&L)     //销毁线性表 ，并释放所占用内存空间

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkList;

int ListCreate(LinkList *head); //创建 
int ListDeleteAll(LinkList *head);//删除整个链表
void ListPrint(LinkList head); //输出整个链表 
int ListInsertItem(LinkList head,int pos,int x); //插入元素 
int ListDeleteItem(LinkList head,int pos,int *item); //删除元素 

int main(){
	LinkList head;
	ListCreate(&head); 
	int choice;
	
	int pos;//位置 
	int value;//插入元素值 
	int result;//结果 

	while(1){
		printf("请选择操作：\n");
	  	printf("1.插入元素    2.删除元素    3.显示链表    4.删除链表    0.退出\n");
	  	scanf("%d",&choice);
	  	switch(choice){
	  		case 0:
	  			goto end;
//	  			printf("退出成功，欢迎您的使用！");
//	  			break;
	  		case 1:
	  			printf("请输入要插入的值：\n");
				scanf("%d",&value);
				printf("请输入要插入在链表中的位置：\n");
				scanf("%d",&pos);
				result = ListInsertItem(head,pos,value); 
				if(result == 1){
				printf("插入成功！\n"); 
//				printf("插入后的链表为：\n");
//				h = head -> next;
//				while(h){
//					printf("%d\n",h->data);
//					h = h -> next;
//				}  
				}else{
					printf("插入失败！");
				}
	  			break;
	  		case 2:
	  			printf("请输入要删除的元素在链表中的位置：\n");
				scanf("%d",&pos);
				result = ListDeleteItem(head,pos,&value);
					if(result == 1){
				printf("删除成功！\n"); 
				printf("删除的元素为：%d\n",value); 
//				printf("删除后的链表为：\n");
//				h = head -> next;
//				while(h){
//					printf("%d\n",h->data);
//					h = h -> next;
//				}  
				}else{
					printf("删除失败！");
				}
				break;
			case 3:
				printf("输出显示链表：\n");
				if(head->next != NULL){
					ListPrint(head);
				} else{
					printf("链表为空,无法输出!");
				}
				
				break;
			case 4:
				ListDeleteAll(&head);
				printf("链表已清空！\n");
				break;
			default: 
				printf("操作输入非法！\n"); 
		  }
	}
//	head = (LinkList)malloc(sizeof(LNode));
//	head->next = NULL;
//	LinkList h = head;
//	//初始化链表
//	int i;//循环变量
//	int item = 0; 
//	printf("请输入元素值，输入-1结束\n"); 
//	for(i=0;item != -1;i++){
//		scanf("%d",&item);
//		if(item == -1){
//			printf("输入结束\n");
//			break;
//		}
//		LinkList q = (LinkList)malloc(sizeof(LNode));
//		h->next = q;
//		q->next = NULL;
//		h = h->next;
//		q->data = item;
//	} 
	
//	int pos;//插入位置
//	int value;//插入元素值 
//	int result;//插入结果 
//	printf("请输入要插入的值：\n");
//	scanf("%d",&value);
//	printf("请输入要插入在链表中的位置：\n");
//	scanf("%d",&pos);
//	
//	result = ListInsert(head,pos,value); 
//	
//	if(result == 1){
//		printf("插入成功！\n"); 
//		printf("插入后的链表为：\n");
//		h = head -> next;
//		while(h){
//			printf("%d\n",h->data);
//			h = h -> next;
//		}  
//	} else{
//		printf("插入失败！");
//	}
	end:printf("退出成功，欢迎您的使用！");
	return 0;
}

//链表的初始化
int ListCreate(LinkList *head){
	(*head) = (LinkList*)malloc(sizeof(LNode));
	(*head)->next = NULL;
	LinkList h = *head;
	//初始化链表
	int i;//循环变量
	int item = 0; 
	printf("请输入元素值，输入-1结束\n"); 
	for(i=0;item != -1;i++){
		scanf("%d",&item);
		if(item == -1){
			printf("输入结束\n");
			break;
		}
		LinkList q = (LinkList)malloc(sizeof(LNode));
		h->next = q;
		q->next = NULL;
		h = h->next;
		q->data = item;
	} 
} 

//链表的清空（不删除头结点） 
int ListDeleteAll(LinkList *head){
	LinkList p = *head;
    if (p->next == NULL){
		printf("链表为空，无需再删除！");
		return 0;
	}
    while(p->next != NULL)//删除链表非首结点元素
    {
        LinkList q = p->next;
        p->next = q->next;
        free(q);
    }
    //free(p);删除链表头结点元素
    //*head = NULL;
    return 1;
//	if(h->next == NULL){
//		printf("链表清空完毕！\n");
//		return 1;
//	}else{
//		printf("链表清空失败！\n");
//		return 0;
}

//输出整个链表 
void ListPrint(LinkList head){
	LinkList h;
	h = head -> next;
//	if(h == NULL){
//		printf("链表为空！\n");
//	}else{
		while(h){
		printf("%d\n",h->data);
		h = h -> next;
		}  
//	}
}

// 插入元素 
int ListInsertItem(LinkList head,int pos,int x){
	LinkList p=head;
	LinkList q = (LinkList)malloc(sizeof(LNode));
	int i=0;
	while(p && i<pos-1) { 
        p=p->next;
        i++;
    }
	if(!p || i>pos-1){
		printf("插入位置不合法！\n");
		return 0;
	}
	if(!q){
		printf("不能生成新结点\n");
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

//删除元素 
int ListDeleteItem(LinkList head,int pos,int *item){
	LinkList p=head,q;	
	int i=0;
	while(p->next && i<pos-1) {
		p=p->next;
		i++;
	}
	if(!p->next || i>pos-1){
		printf("删除位置不合法！\n");
		return 0;
	}
	q=p->next;
	p->next=q->next;
	*item=q->data;
	free(q);
	return 1;
} 

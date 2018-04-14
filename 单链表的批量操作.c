#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkList;

int ListCreate(LinkList *head); //���� 
int ListDeleteAll(LinkList *head);//ɾ����������
void ListPrint(LinkList head); //����������� 
int ListInsertItem(LinkList head,int pos,int x); //����Ԫ�� 
int ListDeleteItem(LinkList head,int pos,int *item); //ɾ��Ԫ�� 

int main(){
	LinkList head;
	ListCreate(&head); 
	int choice;
	
	int pos;//λ�� 
	int value;//����Ԫ��ֵ 
	int result;//��� 

	while(1){
		printf("��ѡ�������\n");
	  	printf("1.����Ԫ��    2.ɾ��Ԫ��    3.��ʾ����    4.ɾ������    0.�˳�\n");
	  	scanf("%d",&choice);
	  	switch(choice){
	  		case 0:
	  			goto end;
//	  			printf("�˳��ɹ�����ӭ����ʹ�ã�");
//	  			break;
	  		case 1:
	  			printf("������Ҫ�����ֵ��\n");
				scanf("%d",&value);
				printf("������Ҫ�����������е�λ�ã�\n");
				scanf("%d",&pos);
				result = ListInsertItem(head,pos,value); 
				if(result == 1){
				printf("����ɹ���\n"); 
//				printf("����������Ϊ��\n");
//				h = head -> next;
//				while(h){
//					printf("%d\n",h->data);
//					h = h -> next;
//				}  
				}else{
					printf("����ʧ�ܣ�");
				}
	  			break;
	  		case 2:
	  			printf("������Ҫɾ����Ԫ���������е�λ�ã�\n");
				scanf("%d",&pos);
				result = ListDeleteItem(head,pos,&value);
					if(result == 1){
				printf("ɾ���ɹ���\n"); 
				printf("ɾ����Ԫ��Ϊ��%d\n",value); 
//				printf("ɾ���������Ϊ��\n");
//				h = head -> next;
//				while(h){
//					printf("%d\n",h->data);
//					h = h -> next;
//				}  
				}else{
					printf("ɾ��ʧ�ܣ�");
				}
				break;
			case 3:
				printf("�����ʾ����\n");
				if(head->next != NULL){
					ListPrint(head);
				} else{
					printf("����Ϊ��,�޷����!");
				}
				
				break;
			case 4:
				ListDeleteAll(&head);
				printf("��������գ�\n");
				break;
			default: 
				printf("��������Ƿ���\n"); 
		  }
	}
//	head = (LinkList)malloc(sizeof(LNode));
//	head->next = NULL;
//	LinkList h = head;
//	//��ʼ������
//	int i;//ѭ������
//	int item = 0; 
//	printf("������Ԫ��ֵ������-1����\n"); 
//	for(i=0;item != -1;i++){
//		scanf("%d",&item);
//		if(item == -1){
//			printf("�������\n");
//			break;
//		}
//		LinkList q = (LinkList)malloc(sizeof(LNode));
//		h->next = q;
//		q->next = NULL;
//		h = h->next;
//		q->data = item;
//	} 
	
//	int pos;//����λ��
//	int value;//����Ԫ��ֵ 
//	int result;//������ 
//	printf("������Ҫ�����ֵ��\n");
//	scanf("%d",&value);
//	printf("������Ҫ�����������е�λ�ã�\n");
//	scanf("%d",&pos);
//	
//	result = ListInsert(head,pos,value); 
//	
//	if(result == 1){
//		printf("����ɹ���\n"); 
//		printf("����������Ϊ��\n");
//		h = head -> next;
//		while(h){
//			printf("%d\n",h->data);
//			h = h -> next;
//		}  
//	} else{
//		printf("����ʧ�ܣ�");
//	}
	end:printf("�˳��ɹ�����ӭ����ʹ�ã�");
	return 0;
}

//����ĳ�ʼ��
int ListCreate(LinkList *head){
	(*head) = (LinkList*)malloc(sizeof(LNode));
	(*head)->next = NULL;
	LinkList h = *head;
	//��ʼ������
	int i;//ѭ������
	int item = 0; 
	printf("������Ԫ��ֵ������-1����\n"); 
	for(i=0;item != -1;i++){
		scanf("%d",&item);
		if(item == -1){
			printf("�������\n");
			break;
		}
		LinkList q = (LinkList)malloc(sizeof(LNode));
		h->next = q;
		q->next = NULL;
		h = h->next;
		q->data = item;
	} 
} 

//�������գ���ɾ��ͷ��㣩 
int ListDeleteAll(LinkList *head){
	LinkList p = *head;
    if (p->next == NULL){
		printf("����Ϊ�գ�������ɾ����");
		return 0;
	}
    while(p->next != NULL)//ɾ��������׽��Ԫ��
    {
        LinkList q = p->next;
        p->next = q->next;
        free(q);
    }
    //free(p);ɾ������ͷ���Ԫ��
    //*head = NULL;
    return 1;
//	if(h->next == NULL){
//		printf("���������ϣ�\n");
//		return 1;
//	}else{
//		printf("�������ʧ�ܣ�\n");
//		return 0;
}

//����������� 
void ListPrint(LinkList head){
	LinkList h;
	h = head -> next;
//	if(h == NULL){
//		printf("����Ϊ�գ�\n");
//	}else{
		while(h){
		printf("%d\n",h->data);
		h = h -> next;
		}  
//	}
}

// ����Ԫ�� 
int ListInsertItem(LinkList head,int pos,int x){
	LinkList p=head;
	LinkList q = (LinkList)malloc(sizeof(LNode));
	int i=0;
	while(p && i<pos-1) { 
        p=p->next;
        i++;
    }
	if(!p || i>pos-1){
		printf("����λ�ò��Ϸ���\n");
		return 0;
	}
	if(!q){
		printf("���������½��\n");
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}

//ɾ��Ԫ�� 
int ListDeleteItem(LinkList head,int pos,int *item){
	LinkList p=head,q;	
	int i=0;
	while(p->next && i<pos-1) {
		p=p->next;
		i++;
	}
	if(!p->next || i>pos-1){
		printf("ɾ��λ�ò��Ϸ���\n");
		return 0;
	}
	q=p->next;
	p->next=q->next;
	*item=q->data;
	free(q);
	return 1;
} 

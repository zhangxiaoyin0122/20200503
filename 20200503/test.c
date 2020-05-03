#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//��ͷ˫��ѭ������
typedef int Type;

typedef struct Node {
	struct Node* _prev;
	struct Node* _next;
	Type _value;
}Node;

typedef struct List {
	Node* _header;
}List;
//����ڵ�
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_next = node->_prev = NULL;
	node->_value = data;
	return node;
}
//��ʼ��

void ListInit(List* l) {
	//����һ��ͷ���,����ѭ���ṹ
	l->_header = creatNode(0);
	l->_header->_next = l->_header;
	l->_header->_prev = l->_header;

}

//β��
void ListPushBack(List* l,Type data) {
	Node* node = creatNode(data);
	Node* last = l->_header->_prev;
	last->_next = node;
	node->_prev = last;
	node->_next = l->_header;
	l->_header->_prev = node;
}
//βɾ
void ListPopBack(List* l) {
	Node* last, *prev;
	//�ж��Ƿ�Ϊ�ձ�
	if (l->_header->_next == l->_header) {
		return;
	}
	 last = l->_header->_prev;
	 prev = last->_prev;
	prev->_next = l->_header;
	l->_header->_prev = prev;
	free(last);
}
//ͷ��
void ListPushFront(List* l,Type data) {
	Node* node = creatNode(data);
	Node* next = l->_header->_next;
	l->_header->_next = node;
	node->_prev = l->_header;
	node->_next = next;
	next->_prev = node;
}
//ͷɾ
void ListPopFrront(List* l) {
	Node* front, *next;
	//�ж��Ƿ�Ϊ�ձ�
	if (l->_header->_next == l->_header)
		return;
	front = l->_header->_next;
	next = front->_next;
	l->_header->_next = next;
	next->_prev = l->_header;
	free(front);
}

 //����ڵ�ǰ����
void ListInsert(Node* pos, Type data) {
	Node* node = creatNode(data);
	Node* prev = pos->_prev;
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}
//����λ��ɾ��

void ListErase(Node* pos) {
	if (pos->_next==pos)
		return;
	Node* prev = pos->_prev;
	Node* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}

void ListPrint(List* l) {
	Node* cur = l->_header->_next;
	while (cur) {
		printf("%d ", cur->_value);
		cur = cur->_next;
	}
	printf("\n");
}

void ListDestory(List* l) {
	Node* cur = l->_header->_next;
	while (cur) {
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(l->_header);//�ͷ�ͷ���
	l->_header = NULL;
}
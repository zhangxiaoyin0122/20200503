#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//带头双向循环链表
typedef int Type;

typedef struct Node {
	struct Node* _prev;
	struct Node* _next;
	Type _value;
}Node;

typedef struct List {
	Node* _header;
}List;
//创造节点
Node* creatNode(Type data) {
	Node* node = (Node*)malloc(sizeof(Type));
	node->_next = node->_prev = NULL;
	node->_value = data;
	return node;
}
//初始化

void ListInit(List* l) {
	//创造一个头结点,构成循环结构
	l->_header = creatNode(0);
	l->_header->_next = l->_header;
	l->_header->_prev = l->_header;

}

//尾插
void ListPushBack(List* l,Type data) {
	Node* node = creatNode(data);
	Node* last = l->_header->_prev;
	last->_next = node;
	node->_prev = last;
	node->_next = l->_header;
	l->_header->_prev = node;
}
//尾删
void ListPopBack(List* l) {
	Node* last, *prev;
	//判断是否为空表
	if (l->_header->_next == l->_header) {
		return;
	}
	 last = l->_header->_prev;
	 prev = last->_prev;
	prev->_next = l->_header;
	l->_header->_prev = prev;
	free(last);
}
//头插
void ListPushFront(List* l,Type data) {
	Node* node = creatNode(data);
	Node* next = l->_header->_next;
	l->_header->_next = node;
	node->_prev = l->_header;
	node->_next = next;
	next->_prev = node;
}
//头删
void ListPopFrront(List* l) {
	Node* front, *next;
	//判断是否为空表
	if (l->_header->_next == l->_header)
		return;
	front = l->_header->_next;
	next = front->_next;
	l->_header->_next = next;
	next->_prev = l->_header;
	free(front);
}

 //任意节点前插入
void ListInsert(Node* pos, Type data) {
	Node* node = creatNode(data);
	Node* prev = pos->_prev;
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}
//任意位置删除

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
	free(l->_header);//释放头结点
	l->_header = NULL;
}
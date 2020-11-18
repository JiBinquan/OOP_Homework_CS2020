#ifndef __INT_STACK_H
#define __INT_STACK_H
#include "m_head.h"



class int_stack {
private:
	int data[maxn];
	int topz;
public:
	int_stack();
	int size();
	bool empty();
	int top();
	void pop();
	void push(int);
	void create(int);
};

void Stack_test();



#endif


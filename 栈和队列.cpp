/*#include<iostream>
using namespace std;
#define maxsize 100
typedef struct {
	int stack[maxsize];
	int top;
}seqstack;
seqstack* initstack() {
	seqstack* s;
	s = new seqstack();
	if (!s) {
		cout << "¿Õ¼ä²»×ã";
		return NULL;
	}
	else {
		s->top = -1;
		return s;
	}
}
int gettop(seqstack* s) {
	if (s->top == -1) return false;
	else {
		return s->stack[s->top];
	}
}
seqstack* push(seqstack* s, int x) {
	if (s->top == maxsize - 1) return NULL;
	else {
		s->top++;
		s->stack[s->top] = x;
		return s;
	}
}
int pop(seqstack* s) {
	if (s->top == -1) return false;
	else {
		s->top--;
		return s->stack[s->top + 1];
	}
}
int main() {
	seqstack* s = initstack();
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 1);
	pop(s);
	int a=gettop(s);
	cout << a << endl;
	return 0;
}*/                                                                                     //Ë³ÐòÕ»
/*#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node* next;;
}linkstack;
linkstack* top;
int stackempty(linkstack* top) {
	return top == NULL;
}
int gettop(linkstack* top) {
	if (top == NULL) return false;
	return top->data;
}
linkstack* push(linkstack* top, int x) {
	linkstack* p;
	p = new linkstack();
	p->data = x;
	p->next = top;
	top = p;
	return top;
}
linkstack* pop(linkstack* top) {
	linkstack* p;
	p = top;
	if(!top) return NULL;
	top = top->next;
	free(p);
	return top;
}
int main() {
	linkstack* top=NULL;
	top=push(top, 3);
	top=push(top, 2);
	top=push(top, 1);
	int a = gettop(top);
	cout << a<<endl;
	top = pop(top);
	a = gettop(top);
	cout << a << endl;
	return 0;
}*/
                                                                    //Á´±íÕ»
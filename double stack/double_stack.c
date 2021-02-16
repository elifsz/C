#include<stdio.h>
#define STACK_SIZE 10
typedef struct{
	int top1;
	int top2;
	int data[STACK_SIZE];
}doublestack ;
/*functions with number "1" work with the single stack logic
except is_full_s1 
is_full_s1 and is_full_s2 functions are same.
(s->top1)+1==s->top2 means stack size reached.
*/
void initialize_s1(doublestack  *s){
	s->top1=-1;
}
int is_empty_s1(doublestack  *s){
	if(s->top1==-1)
		return 1;
	return 0;
}
int is_full_s1(doublestack  *s){
	if((s->top1)+1==s->top2)	
		return 1;
	return 0;
}
void push1(doublestack  *s,int item){
	if(is_full_s1(s))
		printf("Error:Stack is full!\n");
	else{
		(s->top1)++;
		s->data[s->top1]=item;
	}
}
int pop1(doublestack  *s){
	int item;
	if(is_empty_s1(s))
		printf("Error:Stack is empty!\n");
	else{
		item=s->data[s->top1];
		s->top1--;
	}
	return (item);
}
/*functions with number "2" , initialization must start at the end of the data.
the addition process starts from the end,push and pop fonctions are 
written with the reverse logic of the single stack.
*/
void initialize_s2(doublestack  *s){
	s->top2=STACK_SIZE-1;
}
int is_empty_s2(doublestack  *s){
	if(s->top2==STACK_SIZE-1)	
		return 1;
	return 0;
}
int is_full_s2(doublestack  *s){
	if((s->top1)+1==s->top2)	
		return 1;
	return 0;
}
void push2(doublestack  *s,int item){
	if(is_full_s2(s))
		printf("Error: Stack is full!\n");
	else{
		s->data[s->top2]=item;
		(s->top2)--;		
	}	
}
int pop2(doublestack  *s){
	int item;
	if(is_empty_s2(s))
		printf("Error: Stack is empty!\n");
	else{
		(s->top2)++;
		item=s->data[s->top2];
	}
	return (item);
}
void display(doublestack s){
	while(!is_empty_s1(&s))
		printf("%d\n",pop1(&s));
	while(!is_empty_s2(&s))
		printf("%d\n",pop2(&s));
 }
int main(){
	//a testing to understand that it works correctly.
	doublestack stack;
	initialize_s1(&stack);
	initialize_s2(&stack);
	push1(&stack,405);
	push2(&stack,15);
	push1(&stack,41821);
	pop1(&stack);
	pop2(&stack);
	display(stack);
}

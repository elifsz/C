#include<stdio.h>
#include<string.h>
#define STACK_SIZE 30
#define QUEUE_SIZE 100
#define POSSIBLE_NUM 250
typedef struct{
	int day,month,year;	
}date_app; //date of application
typedef struct{
	char name[50];
	char address[150];	
	date_app dates;
}information; //application form
typedef struct{
	int top;
	char tel_number[STACK_SIZE];
}stack_tel; //phone number of people
typedef struct{
	int rear,front,count;	
	information info_que[QUEUE_SIZE];
	//users are given telephone numbers according to their order of entering their information.
	//queue already provides this.
	stack_tel telephone[QUEUE_SIZE];
}queue_t;
typedef struct{
	int top;
	char pos_tel[POSSIBLE_NUM][STACK_SIZE];
	//pos_tel=possible telephone number
}stack_all_tel;
void initialize_stack(stack_tel *tel){
	tel->top=-1;
}
int is_empty_stack(stack_tel *tel){
	if(tel->top==-1)	
		return 1;
	return 0;
}
int is_full_stack(stack_tel *tel){
	if(tel->top==QUEUE_SIZE-1)
		return 1;
	return 0;
}
void push_stack(stack_tel *tel,char tel_num){
	if(is_full_stack(tel))	
		printf("error:stack is full!\n");
	else{
		tel->top++;
		tel_num=tel->tel_number[tel->top];
	}
}
char pop_stack(stack_tel *tel){
	char num;
	if(is_empty_stack(tel))
		printf("error:stack is empty!\n");
	else{
		tel->tel_number[tel->top]=num;
		tel->top--;	
	}
	return num;
}
void initialize_stack_tel(stack_all_tel *tel){
	tel->top=-1;
}
int is_empty_stack_tel(stack_all_tel *tel){
	if(tel->top==-1)	
		return 1;
	return 0;
}
int is_full_stack_tel(stack_all_tel *tel){
	if(tel->top==POSSIBLE_NUM-1)
		return 1;
	return 0;
}
void push_stack_tel(stack_all_tel *tel,char *tel_num){
	if(is_full_stack_tel(tel))	
		printf("error:stack is full!\n");
	else{
		(tel->top)++;
		strcpy(tel->pos_tel[tel->top],tel_num);
	}
}
char *pop_stack_tel(stack_all_tel *tel){
	char *num;
	if(is_empty_stack_tel(tel))
		printf("error:stack is empty!\n");
	else{
		strcpy(num,tel->pos_tel[tel->top]);
		(tel->top)--;	
	}
	return num;
}

void pop_stack_tel2(stack_all_tel *tel,char *num)
//used in functions
{
	if(is_empty_stack_tel(tel))
		printf("error:stack is empty!\n");
	else{
		strcpy(num,tel->pos_tel[tel->top]);
		(tel->top)--;	
	}
}
void initialize_queue(queue_t *que){
	que->rear=-1;
	que->front=0;
	que->count=0;
}
int is_empty_queue(queue_t *que){
	if(que->count==0)
		return 1;
	return 0;
}
int is_full_queue(queue_t *que){
	if(que->count==QUEUE_SIZE)
		return 1;
	return 0;
}
//gets an application and puts it in the queue
void gets_app_queue(queue_t *que,char *name_q,char *adress){
	if(is_full_queue(que))
		printf("error: queue is full!\n");
	else{
		que->rear=(que->rear+1)%QUEUE_SIZE;
		strcpy(que->info_que[que->rear].name,name_q);
		strcpy(que->info_que[que->rear].address,adress);
	}
}
//after entering the user information,
//the user is given a phone number.
void gives_telephone_number(queue_t *que,stack_all_tel *nums){
	if(is_full_queue(que))
		printf("error: queue is full!\n");
	else{
		char number[STACK_SIZE];
		pop_stack_tel2(nums,number);
		strcpy(que->telephone[que->rear].tel_number,number);
		(que->count)++;
		}	
}
void insert_queue(queue_t *que,char *item){
	if(is_full_queue(que))	
		printf("Error:Queue is full\n");
	else{
		que->rear=(que->rear+1)%QUEUE_SIZE;
		strcpy(que->telephone[que->rear].tel_number,item);
		(que->count)++;	
	}	
}
void remove_queue(queue_t *que,char *item){
	if(is_empty_queue(que))
		printf("queue is empty\n");
	else{
		strcpy(item,que->telephone[que->front].tel_number);
		que->front=(que->front+1)%QUEUE_SIZE;
		(que->count)--;
	}
}
//nums=the number to be deleted
void delete_phone_number(queue_t *que,char *nums,stack_all_tel *s){
	char num[STACK_SIZE],temp_num[STACK_SIZE];
	queue_t temp;
	initialize_queue(&temp);
	/*after removing the telephone numbers other than 
	the deleted number into another queue.
	the remaining ones are taken from the temp into the que.
	*/
	while(!is_empty_queue(que)){
	remove_queue(que,num);
	if(strcmp(nums,num)!=0)
			insert_queue(&temp,num);
	else{
		char note[30];
		strcpy(note,"number deleted");
		insert_queue(&temp,note);
		}	
	}
	initialize_queue(que); 
	//the end of the queue has been reached so must be restarted.
	while(!is_empty_queue(&temp)){
		remove_queue(&temp,temp_num);
		insert_queue(que,temp_num);
	}
	push_stack_tel(s,nums);
	//the deleted number has been pushed to the stack 
}
int main(){
	//a testing to understand that it works correctly.
	char name[50],addres[150],telephone_num[STACK_SIZE],tel_inf[STACK_SIZE];
	char t1[STACK_SIZE],t2[STACK_SIZE],t3[STACK_SIZE];
	queue_t town_queue;
	stack_tel telephone;
	stack_all_tel tels;
	strcpy(tel_inf,"453 124 13 43");
	strcpy(t1,"5454 544 22 1");
	strcpy(t2,"665 34 2");
	strcpy(t3,"4763 234 23");
	initialize_queue(&town_queue);
	initialize_stack(&telephone);
	initialize_stack_tel(&tels);
	push_stack_tel(&tels,tel_inf);
	push_stack_tel(&tels,t1);
	push_stack_tel(&tels,t2);
	push_stack_tel(&tels,t3);
	int i;
	char numss[STACK_SIZE];
	for(i=0;i<4;i++){
	printf("enter name:"); gets(name);
	printf("enter address:"); gets(addres);
	gets_app_queue(&town_queue,name,addres);
	gives_telephone_number(&town_queue,&tels);
	printf("info:%s %s \ntel num:%s\n",town_queue.info_que[i].name,town_queue.info_que[i].address,town_queue.telephone[i].tel_number);
	}
	delete_phone_number(&town_queue,t2,&tels);
	printf("numbers after deleted:\n");
	while(!is_empty_stack_tel(&tels)){
	pop_stack_tel2(&tels,numss);
		printf("%s\n",numss);
}
	for(i=0;i<4;i++){
		printf("info:%s %s \ntel num:%s\n",town_queue.info_que[i].name,town_queue.info_que[i].address,town_queue.telephone[i].tel_number);
	}
}

#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 16
#define MAX_THREAD 8
int a[] = {1,5,7,10,12,14,15,18,20,22,25,27,30,64,110,220};
//int a[] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
double product[8] = {1,1,1,1,1,1,1,1};
int part = 0;
pthread_mutex_t mutex;

void* product_array(){
    int thread_part = part++;
    pthread_mutex_lock(&mutex);
    for(int i = thread_part * (MAX / 8) ; i < (thread_part + 1)*(MAX / 8);i++){
    product[thread_part] *= a[i];
    }
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t threads[MAX_THREAD];

    pthread_mutex_init(&mutex, NULL);

    //creating 8 threads
    for(int i=0;i<MAX_THREAD;i++){
    pthread_create(&threads[i],NULL,product_array,(void*)NULL);
    }

    for(int i=0;i<MAX_THREAD;i++){
    pthread_join(threads[i],NULL);
    }

    double total_product = 1;
    for(int i=0;i<MAX_THREAD;i++){
        total_product *= product[i];
    }

    printf("product is %.0f \n",total_product);

    pthread_mutex_destroy(&mutex);

}

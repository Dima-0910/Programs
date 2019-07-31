#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/times.h>
static pthread_mutex_t vilka[5];
sem_t nom;
void *take(void *arg)
{
	int id=*(int*)arg;
	sem_post(&nom);
	pthread_mutex_lock(&vilka[id]);   //pravaya vilka
	printf("filosof %d vzyal pravuyu vilku\n",id);
	sleep(1);
	pthread_mutex_lock(&vilka[(5+id-1)%5]);
	printf("filosof %d vzyal levuyu vilku\n",id);
	sleep(1);
	printf("filosof %d poobedal\n",id);
	pthread_mutex_unlock(&vilka[id]);
	pthread_mutex_unlock(&vilka[((5+id-1)%5)]);
	return NULL;
}
int main(void)
{
	pthread_t filosof[5];
	sem_init(&nom,0,0);
	int res,id;
	for(id=0;id<5;id++)
	{	
		res= pthread_create(&filosof[id],NULL,take,&id);
		if(res!=0) EXIT_FAILURE;
		sem_wait(&nom);
	}
	for(id=0;id<5;id++)
	{
		res=pthread_join(filosof[id],NULL);
		if(res!=0) EXIT_FAILURE;
	}
	sem_destroy(&nom);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

pthread_mutex_t *lock; // mutex
pthread_cond_t *cond;  /* 
	cond  variable on which competing threads 
	will be block for access to a resource 
	*/ 
bool done = false;

void* printEven(void *max) {
	int range = *(int* ) max;
		for(int i=0; i<range; i+=2) {
			pthread_mutex_lock(lock); /* 
			mutex object is in locking state with the calling thread as its owner */			
			while(done) {
				pthread_cond_wait(cond, lock); /* 
				wait on condition and block other threads on a condition
				called with mutex locked by the calling thread
				upon successfully return, the mutex has been locked 
				and is owned by the calling thread
				*/			
			}
			//printf("ping\n"); 
			printf("1srt thread -> %d\n",i);
			done = true;
			pthread_cond_signal(cond);/* 
			signal a condition and unblock at least one thread 
			that are blocked on one condition variable 
			*/
			pthread_mutex_unlock(lock); /*
			release the mutex object referenced by lock		
			*/
		}
	return NULL;
}

void* printOdd(void *max) {
	int range = *(int* ) max;
		for(int i=1; i<range; i+=2) {
			pthread_mutex_lock(lock);
			while(!done) {
				pthread_cond_wait(cond, lock);
			}
			//printf("pong\n");
			printf("2nd thread -> %d\n",i);
			done = false;
			pthread_cond_signal(cond);
			pthread_mutex_unlock(lock);
		}
	return NULL;
}

int main( int argc, char** argv){
	if (argc < 2) {
		fprintf(stderr, "Provide the max range of numbers to print\n");
		return -1;
	}
	pthread_t t1, t2;
	lock = (pthread_mutex_t *) malloc(sizeof(*lock));
	cond = (pthread_cond_t *) malloc(sizeof(*cond));
	int rm = pthread_mutex_init(lock, NULL); /*
		the state of the mutex becomes initialized and unlocked
	*/
	int rc = pthread_cond_init(cond, NULL); /*
		the state of condition variable becomes initialized	
	*/
	assert(rc == 0 && rm == 0);
	int max = atoi(argv[1]);
	if (pthread_create(&t1, NULL, printEven, &max)) {
		fprintf (stderr, "Error creating thread\n");
		return -1;
	}
	if (pthread_create(&t2, NULL, printOdd, &max)){
		fprintf (stderr, "Error creating thread\n");
		return -1;		
	}	
	if(pthread_join(t1, NULL)){
		fprintf (stderr, "Error joining first thread\n");
		return -1;		
	}
	if(pthread_join(t2, NULL)){
		fprintf (stderr, "Error joining second thread\n");
		return -1;		
	}
	int rdm = pthread_mutex_destroy(lock);
  int rdc = pthread_cond_destroy(cond);
	assert(rdc == 0 && rdm == 0);
	return 0;
}

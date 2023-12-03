#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define STEP 5
#define NUM 8

typedef struct{
	int cnt;		//numer watku
	int sum;		//suma kontrolna
	const char* msg;//wiadomosc
}thread_data;


/* Funkcja wykonywana przez watek */

void* start_routine (void* data){
	int i, id;


	thread_data * get_data = (thread_data*)data;
	int cnt = get_data->cnt;
	int sum = get_data->sum;
	char *msg = get_data->msg;
	printf("msg: %s\n", msg);

	/* Wyswietl nr watku i krok */
	for(i = 0; i < STEP; i++)
	{
		printf("\tWatek: %d, step = %d\n", cnt, i);
		sleep(1);
	}
	pthread_exit(NULL);
}


/* Program glowny */


int main ()
{

	thread_data data;
	char *messages[NUM];

	messages[0] = "English";
	messages[1] = "French";
	messages[2] = "Spanish";
	messages[3] = "Polski";
	messages[4] = "German";
	messages[5] = "Russian";
	messages[6] = "Japan";
	messages[7] = "Latin";


	int i, rc;
	pthread_t thread_id[NUM];
	void* status;
	data.sum=0;


	for(i=0; i<NUM; i++)
	{
		printf("tworze watek nr: %d\n", i);
		data.cnt = i;
		data.sum+=i;

		data.msg = messages[i];
		rc = pthread_create(&thread_id[i], NULL, &start_routine, (void *) &data);
		if(rc){
			printf("blad w tworzeniu\n");
			exit(1);
		}
	}

	for(i=0; i<NUM; i++){
		rc = pthread_join(thread_id[i], &status);
		if(rc){
			printf("blad w powrocie\n");
			exit(1);
		}

		printf("watek glowny dolacyzl watek %d o statusie %d\n", i, (int)status);
	}

	printf("watek glowny zakonczony\n");
	pthread_exit(NULL);
}



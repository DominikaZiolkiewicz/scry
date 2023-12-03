#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM 4

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
double wynik = 0;

int num_steps = 100000;

typedef struct{
	int ood;
	int przedzial;

}calculate_pi;

void* start_routine(void* str){
    printf("startuje...\n");
	int i;
	double x, step, sum = 0.0;
	calculate_pi* data = (calculate_pi*)str;
	int od = data->ood;
	int doo = od+data->przedzial;
	

	step = 1.0 / (double) num_steps;
	for (i=od; i < doo; i++)
	{
		x = (double)(i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
    pthread_mutex_lock(&mutex);
    printf("teraz dodaje do wyniku\n");
	wynik += step * sum;
    printf("%.3f\n", wynik);
    pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}


int main ()
{

	calculate_pi data[NUM];

	pthread_t thread_id[NUM];
	int rc;
	int i=0;
	int przedzial = num_steps/NUM;
	
    for(i=0; i<NUM; i++){

		data[i].ood = i*przedzial;
		data[i].przedzial = przedzial;
		rc = pthread_create (&thread_id[i], NULL, &start_routine, (void *) &data[i]);

		if(rc){
			printf("blad w tworzeniu\n");
			exit(1);
		}
	}

	for(i=0; i<NUM; i++){
		pthread_join(thread_id[i], NULL);
	}

	printf("PI = %.5f\n", wynik);

	return 0;
}

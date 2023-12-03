#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM 4


int num_steps = 100000;

typedef struct{
	int ood;
	int przedzial;
	double wynik;

}calculate_pi;

void* start_routine(void* str){
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
	data->wynik += step * sum;
	pthread_exit(NULL);
}


int main ()
{

	calculate_pi data[NUM];

	pthread_t thread_id[NUM];
	int rc;
	int i=0;
	int przedzial = num_steps/NUM;
	double wynik=0;

	for(i=0; i<NUM; i++){

		data[i].wynik = 0;
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
		wynik += data[i].wynik;
	}

	printf("PI = %.5f\n", wynik);

	return 0;
}

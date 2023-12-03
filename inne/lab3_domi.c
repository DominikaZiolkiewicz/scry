#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{
	double x,y,z;
}Wektor;


int ile_liczb(int a, int b){
	int d = 8;
	int ile = 0;
	int i=0;
	int j=0;

	if(a>b){
		int c = a;
		a = b;
		b = c;
	}

	for(i=a; i<b; i++){
		for(j=a; j<b; j++){
			if((i^2+j^2) <= d){
				ile++;
			}
		}
	}
	return ile;
}

int main(int argc, char *argv[]) {
	//sinus();
	int a, b;
	Wektor w1;

	scanf("%d %d\n", &a, &b);
	int gg = ile_liczb(a, b);
	printf("%d\n", gg);
	return 0;
}

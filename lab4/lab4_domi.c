#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*
int main()
{

	int pid_p;
	pid_p = getpid();
	printf("Parent PID = %d\n", pid_p);

	int r1, r2, s1, s2;
	int pid_r1, pid_r2, pid_s1, pid_s2;


	r1 = fork();
	pid_r1 = r1;

	if(pid_r1 != 0){
		printf("R1 PID = %d\n", pid_r1);
	}



	if(r1 == 0){
		printf("R1 Parent (main) PID = %d\n", getppid());
		s1 = fork();
		pid_s1 = s1;
		if(s1 != 0){
			printf("S1 PID = %d\n", pid_s1);
		}
		if(s1 == 0){
			printf("S1 Parent (R1) PID = %d %d\n", pid_r1, getppid());
		}
	}
	else if(getpid() == pid_p){
		 r2 = fork();
		 pid_r2 = r2;
		 if(r2 != 0){
			 printf("R2 PID = %d\n", pid_r2);
			 printf("R2 Parent (main) PID = %d, %d\n",pid_p, getpid());
		 }
	}

	if(r2 == 0 && getppid() == pid_p){
		s2 = fork();
		pid_s2 = s2;
		if(s2 != 0){
			printf("S2 PID = %d\n", pid_s2);
		}

		if(s2 == 0){
			printf("S2 Parent (R2) PID = %d, %d\n", pid_r2, getppid());
		}
	}

  return 0;
}*/

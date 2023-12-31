#include <stdio.h>
// #include <process.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define CHILD 8
#define PARENT 4

int main()
{
  int fork_pid;
  int i, j;
  int status;

  fork_pid = fork();

  if (fork_pid == -1)
    {
      perror("M: Nie udalo sie utworzyc procesu potomnego...\n");
    }
  else if (fork_pid == 0)
    {
      /* proces potomny */
      printf("P: Proces potomny PID = %d\n",getpid());
      for(j = 0; j < CHILD; j++)
        {
          printf("P: pracuje %d sek. ...\n", j);
          sleep(1);
        }
      printf("P: Koniec petli\n");
    }
  else
    {
      /* Proces macierzysty, fork_pid = PID procesu potomnego */
      printf("M: Proces macierzysty PID = %d\n",getpid());
      for(i = 0; i < PARENT; i++)
        {
          printf("M: pracuje %d sek. ...\n", i);
          sleep(1);
        }
      printf("M: Koniec petli\n");
      printf("M: Czekam na potomny...\n");
      pid_t pidzik = waitpid(fork_pid, &status, 0);
      //fork_pid = wait(&status);
      printf("M: Proces potomny PID=%d zakonczony; status: %d\n", pidzik, WEXITSTATUS(status));
    }
  printf("Proces PID=%d konczy prace\n", getpid());
  return 0;
}


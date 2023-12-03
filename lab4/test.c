#include <stdio.h>
#include <unistd.h>


int main() {
   
    int num_processes = 5;
    int child_pid;
    
    for (int i = 0; i < num_processes - 1; ++i) {
        child_pid = fork();

        if (child_pid == -1) {
           
            perror("Fork failed");
            return 1;
        } else if (child_pid != 0) {
            
            printf("Child %d, PID: %d, Parent PID: %d\n", i + 1, getpid(), getppid());
            break;  
        }
    }

    
    printf("PID: %d\n", getpid());

  
    for (int i = 0; i < num_processes - 1; ++i) {
        wait(NULL);
    }

    return 0;
}
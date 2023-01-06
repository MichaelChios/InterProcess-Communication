// Sum calculation with child processes using fork and pipes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int sums[4];
    int sum=0, j = 1, n, i, N;
    
    printf("Give N:");
    scanf("%d", &N);
    
    int w = N/4;
    
    // Create the pipes
    int fd[4][2];
    for(i=0; i<4; i++){
        pipe(fd[i]);
    }
    
    // Create 4 child processes
	for(n=0;n<4;n++) {
	// After the first child process, change the limits for sum calculation
	    if(n>0){
		    j+=N/4;
		    w+=N/4;
	    }
	    // Child processes
		if(fork() == 0) {
		    int tmpsum = 0;
		    for (j; j<=w; j++){
		        tmpsum+=j; 
		    }
		    printf("%d\n", tmpsum);
		    close(fd[n][0]); // close read
            write(fd[n][1], &tmpsum, sizeof(tmpsum));
		    close(fd[n][1]); // close write
		    exit(0);
		}
		// Parent process waits for all child processes to finish
		wait(NULL);
	}
	// The parent process takes the four sums and calculates the overall sum
	for(i=0; i<4; i++){
	    close(fd[i][1]);    // close write
	    read(fd[i][0], &sums[i], sizeof(sums[i]));
	    sum+=sums[i];
	}
	// Calculate the overall sum: sum = N*(N+1)/2 in steps to avoid overflow
	int sum2 = N/2;
	sum2 = sum2*(N+1);
	
	printf("The total sum calculated from the sums of child processes is: %d\n", sum);
	printf("The total sum calculated by parent process is: %d", sum2);
	
	return 0;
}


#include "assignment1.h"

void *runThd(void *threadID){

	int i;

	//run each thread 8 times
	for(i = 0; i<=NUM_OF_THREADS; i++){
		sem_wait(&FLAG); //get the semaphore
		printf("Thread %d (%d) is running\n", threadID, pthread_self()); //print running both thread IDs to console
		file = fopen("QUOTE.txt", "a+"); //append to QUOTE.txt file
		
		//print even numbered thread quote followed by carriage return and newline
		if((int)(intptr_t)threadID%2==0) 
			fprintf(file,"Thread ID %d (%d) : \"Controlling complexity is the essence of computer programming.\" --Brian Kernigan\r\n", threadID, pthread_self());
		
		//print odd numbered thread quote followed by carriage return and newline	
		else 
			fprintf(file,"Thread ID %d (%d) : \"Computer science is no more about computers than astronomy is about telescopes.\" --Edsger Dijkstra\r\n", threadID, pthread_self()); 
		
		fclose(file); //close QUOTE.txt file
		
		sem_post(&FLAG); //release the semaphore
		
		sleep(2+(int)(intptr_t)threadID%2); //delay 2/3 seconds on even/odd threads 
	}
	pthread_exit(NULL); //terminates the calling thread	
}

void main(){
	 	
	file = fopen("QUOTE.txt","w+"); //create QUOTE.txt file
	fprintf(file, "Process ID: %d\r\n", getpid()); //print the process id followed by carriage return and newline
	fclose(file); //close QUOTE.txt file

	int i; //variable i will be the user made thread ID
	
	//initialize semaphore to value 1 to be shared and be visible to all threads 
	sem_init(&FLAG, 0, 1);

	//creating 7 threads		
	pthread_t thread[NUM_OF_THREADS+1];
	for(i=1;i<=NUM_OF_THREADS; i++)
		//creates thread, calls the runThd function, and sends the user thread ID to the function
		pthread_create(&thread[i],NULL,runThd,(void *)(intptr_t)i);
	
	//wait for all 7 threads to complete their work
	for(i=1;i<=NUM_OF_THREADS;i++)
		pthread_join(thread[i],NULL);
		
	sem_destroy(&FLAG); //destroy the semaphore
	
	//print a friendly message to console
	printf("Congratulations! Finished managing all threads.\n");	
	
	pthread_exit(NULL);
	exit(0); //terminates the process
}

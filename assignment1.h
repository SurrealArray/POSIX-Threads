
#include <stdlib.h>
#include <stdio.h>  
#include <semaphore.h>
#include <pthread.h>
#include <stdint.h>

#define NUM_OF_THREADS 7

FILE *file;

sem_t FLAG; 

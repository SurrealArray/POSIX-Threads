/*
 * Omar Beltran
 * RedID: 818036447
 * cssc2146
 * CS 570, Summer 2020
 * Assignment #1, Multiple Threads Manager
 * assignment.h
 */

#include <stdlib.h>
#include <stdio.h>  
#include <semaphore.h>
#include <pthread.h>
#include <stdint.h>

#define NUM_OF_THREADS 7

FILE *file;

sem_t FLAG; 

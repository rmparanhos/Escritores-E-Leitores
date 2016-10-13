#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int readcount,temLeitores; 
sem_t escritores, leitores;

void *leitoresMet(void *arg) { 

	while (1){ 
		sem_wait(&escritores);
		temLeitores = 1;
		//READUNIT(); 
		printf("leitores\n");
		fflush(stdout);
		temLeitores = 0;
		sleep(1);
		sem_post(&escritores); 
		} 
} 

void *escritoresMet(void *arg){ 
 
	while (1){ 
		sem_wait(&escritores); //Apenas um escritor de cada vez, os outros processos escritores ficam presos aqui
		while (temLeitores);
		//temEscritores = 1; //Se existe um escritor, ngm pode ler
		//WRITEUNIT(); 
		printf("escritores\n");
		fflush(stdout);
		//temEscritores = 0;
		sem_post(&escritores); 
	}
}

void main() { 
	pthread_t threadLeitor;
	pthread_t threadEscritor;
	readcount = 0;
	temLeitores = 0;
	sem_init(&escritores, 0, 1);  
	if(pthread_create(&threadLeitor,NULL,leitoresMet,NULL)){
		printf("error creating thread leitor ");
		abort();
	}
	if(pthread_create(&threadEscritor,NULL,escritoresMet,NULL)){
		printf("error creating thread escritor");
		abort();
	}
	if(pthread_join(threadLeitor,NULL)){
		printf("error joining thread.");
		abort();
	}
	if(pthread_join(threadEscritor,NULL)){
		printf("error joining thread;");
		abort();
	}
}


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int temLeitores,temEscritores; 
sem_t escritores, leitores;

void *leitor(void *arg) { 
	while (1){ 
		//temLeitores ++;
		if(temEscritores){
			sem_post(&leitores);
			sem_wait(&escritores);
			printf("leitores ini %d\n",arg);
			fflush(stdout);
			//READUNIT(); 
			sleep(1);
			printf("leitores fim %d\n",arg);
			fflush(stdout);
			sem_post(&escritores); 
			sem_post(&leitores);
		}
		else{
			printf("leitores ini %d\n",arg);
			fflush(stdout);
			//READUNIT();
			sleep(1);
			printf("leitores fim %d\n",arg);
			fflush(stdout);
		}
	  /*temLeitores --;
		if(!temLeitores){
			sem_post(&leitores);
		}*/
	}
} 

void *escritor(void *arg){ 
 
	while (1){ 
		temEscritores = 1; //Se existe um escritor, ngm pode ler
		sem_wait(&leitores);
		sem_wait(&escritores); //Apenas um escritor de cada vez, os outros processos escritores ficam presos aqui
		printf("escritores ini %d\n",arg);
		fflush(stdout);
		//WRITEUNIT(); 
		sleep(1); 
		fflush(stdout);
		printf("escritores fim %d\n",arg);
		sem_post(&escritores);
		sem_post(&leitores);
		temEscritores = 0;
	}
}

void main() { 
	pthread_t threadLeitor;
	pthread_t threadLeitor2;
	pthread_t threadEscritor;
	pthread_t threadEscritor2;
	temLeitores = 0;
	temEscritores = 0;
	int n = 1, m = 2;
	sem_init(&escritores, 0, 1);  
	sem_init(&leitores, 0, 0);
	if(pthread_create(&threadLeitor,NULL,leitor,(void*)n)){
		printf("error creating thread leitor ");
		abort();
	}
	if(pthread_create(&threadLeitor2,NULL,leitor,(void*)m)){
		printf("error creating thread leitor2");
		abort();
	}
	if(pthread_create(&threadEscritor,NULL,escritor,(void*)n)){
		printf("error creating thread escritor");
		abort();
	}
	if(pthread_create(&threadEscritor2,NULL,escritor,(void*)m)){
		printf("error creating thread escritor2");
		abort();
	}
	if(pthread_join(threadLeitor,NULL)){
		printf("error joining thread.");
		abort();
	}
	if(pthread_join(threadLeitor2,NULL)){
		printf("error joining thread;");
		abort();
	}
	if(pthread_join(threadEscritor,NULL)){
		printf("error joining thread;");
		abort();
	}
	if(pthread_join(threadEscritor,NULL)){
		printf("error joining thread;");
		abort();
	}
	
}


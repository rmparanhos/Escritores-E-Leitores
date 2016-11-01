#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista.c"
 
int temEscritores;
sem_t escritores, leitores;

 
void *leitor(void *arg) {
    while (1){
        if(temEscritores){
           // sem_post(&leitores); //libera o arquivo pros escritores
            sem_wait(&escritores); //espera os escritores para entrar na regiao critica
            printf("leitores ini %d\n",(int)arg);
 
          //Leitura no arquivo;
            int c;
            FILE *f = fopen("Teste.txt","r");
            if(f!=NULL){
                while ((c = getc(f)) != EOF){
                	putchar(c);
                }
                fclose(f);
            }
            else{
                printf("ERRO AO ABRIR ARQUIVO!\n");
            }
	    	
		  //sleep(1);
            printf("leitores fim %d\n",(int)arg);
            sem_post(&escritores); //libera os outros escritores/processos para entrar na regiaao critica
            sem_post(&leitores);//libera o arquivo pros escritores
        }
        else{
            printf("leitores ini %d\n",(int)arg);
          //Leitura no arquivo
            int c;
            FILE *f = fopen("Teste.txt","r");
            if(f!=NULL){
                while ((c = getc(f)) != EOF){
                    putchar(c);
                }
                fclose(f);
            }
            else{
                 printf("ERRO AO ABRIR ARQUIVO!\n");
            }
	      //sleep(1);
            printf("leitores fim %d\n",(int)arg);
           
        }
 
    }
}
 



void *escritor(void *arg){
     while (1){
        temEscritores = 1; //Se existe um escritor, os leitores devem entrar na regiao critica
        sem_wait(&leitores); //espera os leitores liberarem o arquivo
        sem_wait(&escritores); //Apenas um escritor de cada vez, os outros processos escritores ficam presos aqui
        printf("escritores ini %d\n",(int)arg);
      
        //Escrita no arquivo
		if(printf("Digite seu texto!:\n") != 0){
        
			Tfrase *texto = NULL;	
			char aux; //Variavel auxiliar para coletar os caracteres da frase

	   		do{
				scanf("%c",&aux);
				if(aux!='\n'){
			    	texto = ins_fim(texto,aux); //Insere na Lista o caractere
				}
	   		}while(aux!='\n');
			if(texto){
			
			FILE *f = fopen("Teste.txt","a");
	 
			if(f!=NULL){
				Tfrase *fraseAtual = texto;	
				fprintf(f,"%c",fraseAtual->c);
				while(fraseAtual->prox!=NULL){
					fraseAtual = fraseAtual->prox;							
					fprintf(f,"%c",fraseAtual->c);	
				}
				fprintf(f,"\n");
		    	fclose(f);
			}
	
			else{
		     	printf("ERRO AO ABRIR ARQUIVO!\n");
			}
			libera(texto);
		}
		else{
			printf("Digite algo");
		}
			printf("escritores fim %d\n",(int)arg);
		}	
		else{
			printf("ALGUM ERRO");
		}
        sem_post(&escritores);
        sem_post(&leitores);
        temEscritores = 0;
    }
}
 
void main() {
    pthread_t threadLeitor;
    pthread_t threadLeitor2;
    pthread_t threadLeitor3;
    pthread_t threadLeitor4;
    pthread_t threadLeitor5;
    pthread_t threadLeitor6;
    pthread_t threadLeitor7;
    pthread_t threadLeitor8;
    pthread_t threadLeitor9;
    pthread_t threadLeitor10;
    pthread_t threadLeitor11;
    pthread_t threadLeitor12;
    pthread_t threadLeitor13;
    pthread_t threadLeitor14;
    pthread_t threadLeitor15;
    pthread_t threadLeitor16;
    pthread_t threadLeitor17;
    pthread_t threadLeitor18;
    pthread_t threadLeitor19;
    pthread_t threadLeitor20;
    pthread_t threadEscritor;
    pthread_t threadEscritor2;
 
    temEscritores = 0;
    int n = 1, m = 2,x=2;
    sem_init(&escritores, 0, 1);
    sem_init(&leitores, 0, 0);
    if(pthread_create(&threadLeitor,NULL,leitor,(void*)n)){
        printf("error creating thread leitor ");
        abort();
    }
    if(pthread_create(&threadLeitor2,NULL,leitor,(void*)m)){
        printf("error creating thread leitor");
        abort();
    }
    if(pthread_create(&threadLeitor3,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor ");
        abort();
    }
    if(pthread_create(&threadLeitor4,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
    if(pthread_create(&threadLeitor5,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor ");
        abort();
    }
    if(pthread_create(&threadLeitor6,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
    }
    if(pthread_create(&threadLeitor7,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor ");
        abort();
    }
    if(pthread_create(&threadLeitor8,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor9,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor10,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor11,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor12,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor13,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor14,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor15,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor16,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor17,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor18,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor19,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
	if(pthread_create(&threadLeitor20,NULL,leitor,(void*)++m)){
        printf("error creating thread leitor");
        abort();
	}
    
    if(pthread_create(&threadEscritor,NULL,escritor,(void*)n)){
        printf("error creating thread escritor");
        abort();
    }
    if(pthread_create(&threadEscritor2,NULL,escritor,(void*)x)){
        printf("error creating thread escritor");
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
    if(pthread_join(threadLeitor3,NULL)){
        printf("error joining thread.");
        abort();
    }
    if(pthread_join(threadLeitor4,NULL)){
        printf("error joining thread;");
        abort();
    }
    if(pthread_join(threadLeitor5,NULL)){
        printf("error joining thread.");
        abort();
    }
    if(pthread_join(threadLeitor6,NULL)){
        printf("error joining thread;");
        abort();
    }
    if(pthread_join(threadLeitor7,NULL)){
        printf("error joining thread.");
        abort();
    }
    if(pthread_join(threadLeitor8,NULL)){
        printf("error joining thread;");
        abort();
    }
    if(pthread_join(threadEscritor,NULL)){
        printf("error joining thread;");
        abort();
    }
    if(pthread_join(threadEscritor2,NULL)){
        printf("error joining thread;");
        abort();
    }


}


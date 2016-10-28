#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	char c;
	struct no * prox; 
}Tfrase;


Tfrase *ins_ini(Tfrase * f, char c ){
	Tfrase * novo = (Tfrase*) malloc(sizeof(Tfrase));
	novo->c = c;
	novo->prox = f;
	return novo;
}

Tfrase *ins_fim(Tfrase *f,char c){
	if(!f){
		return ins_ini(f,c);
	}
	Tfrase *p = f;
	while(p->prox) {
		p = p->prox;
	}
	p->prox = ins_ini(NULL,c);
	return f;

}

void libera (Tfrase *f){
	while (f){
		Tfrase *p = f;
		f = f->prox;
		free(p);
	}
}



Tfrase* cria_lista(char c)
{
    Tfrase *ptr = (Tfrase*) malloc(sizeof(Tfrase));
    if(NULL == ptr)
    {
       
        return NULL;
    }
    ptr->c = c;
    ptr->prox = NULL;

   
    return ptr;
}

Tfrase * add_lista(Tfrase *frase,char c){
	if(NULL == frase)
	{
	        return cria_lista(c);
	}
	else{
	Tfrase *ptr = (Tfrase*)malloc(sizeof(Tfrase));
	if(NULL == ptr)
	{
	        return NULL;
	}
	ptr->c = c;
	ptr->prox = NULL;

   	Tfrase *F_atual = frase;
		while(F_atual->prox){
			F_atual= F_atual->prox; 
		}
	F_atual->prox =ptr;
	}
	return frase;
}


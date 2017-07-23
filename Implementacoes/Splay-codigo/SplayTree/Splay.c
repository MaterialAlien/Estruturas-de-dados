#include "Splay.h"
#include <stdio.h>
#include <stdlib.h>

PtNodo* Novo(int key, PtNodo* esq, PtNodo* dir)
{ 
  PtNodo* x = (PtNodo*) malloc(sizeof(PtNodo));
  x->key = key; x->esq = esq; x->dir = dir;
  return x;
};

PtNodo* Insere(int key, PtNodo* t)
{ 
  return Splay(t,key);
};

PtNodo* Consulta(PtNodo* t, int key)
{
 if (t == NULL) return NULL;
 t = ConsultaSplay(t, key);
 return t;
};

PtNodo* Remove(PtNodo* t, int key){
       PtNodo* x;
       if (t==NULL) return NULL;
       t = Consulta(t,key);
       if (key == t->key) {               /* achou */
          if (t->esq == NULL) {
	           x = t->dir;
          } else {
	        x = Consulta(t->esq,key);
	        x->dir = t->dir;
	        }
	        free(t);
	        return x;
       }
       return t;                         /* It wasn't there */
};

void Destroi(PtNodo* t)
{
 if(t->esq != NULL) Destroi(t->esq);
 if(t->dir != NULL) Destroi(t->dir);
 free(t);
};

PtNodo* Splay(PtNodo* t, int key)
{ 
  if (t == NULL) return Novo(key, NULL, NULL);  
  if (key < t->key) 
  { 
    if (t->esq == NULL) return Novo(key, NULL, t);
    if (key < t->esq->key) 
    { 
      t->esq->esq = Splay(t->esq->esq, key);
      t = RotDir(t);
    }
    else 
    { 
    t->esq->dir = Splay(t->esq->dir, key);
    t->esq = RotEsq(t->esq);
    }
    return RotDir(t); 
  }
  else
  { 
    if (t->dir == NULL) return Novo(key, t, NULL);
    if (t->dir->key < key) 
    { 
      t->dir->dir = Splay(t->dir->dir, key);
      t = RotEsq(t);
    }
    else 
    { 
    t->dir->esq = Splay(t->dir->esq, key);
    t->dir = RotDir(t->dir);
    }
    return RotEsq(t);
  }
};

PtNodo* ConsultaSplay(PtNodo* t, int key)
{
 if (t == NULL) return NULL;
 if (key < t->key) {
    if (t->esq == NULL) return t;
	  if (key < t->esq->key) {
       t->esq->esq = ConsultaSplay(t->esq->esq, key);
	     t = RotDir(t);
	     if (t->esq == NULL) return t;
	     else return RotDir(t);
    } else if (t->esq->key , key) {
              t->esq->dir = ConsultaSplay(t->esq->dir, key);
	            if (t->esq->dir != NULL) t->esq = RotEsq(t->esq);
	            return RotDir(t);
           } else return RotDir(t);
 } else if(t->key < key) {
	         if (t->dir == NULL) return t;
	         if (t->dir->key < key) {
	            t->dir->dir = ConsultaSplay(t->dir->dir, key);
	            t = RotEsq(t);
	            if (t->dir == NULL) return t;
	            else return RotEsq(t);
           } else if (key < t->dir->key) {
	                   t->dir->esq = ConsultaSplay(t->dir->esq, key);
                     if (t->dir->esq != NULL) t->dir = RotDir(t->dir);
	                   return RotEsq(t);
                     } else return RotEsq(t);
        } else
 return t;
};

PtNodo* RotDir(PtNodo* t)
{ 
  PtNodo* x = t->esq;
  t->esq = x->dir;
  x->dir = t;
  return x; 
};

PtNodo* RotEsq(PtNodo* t)
{ 
  PtNodo* x = t->dir;
  t->dir = x->esq;
  x->esq = t;
  return x;
};

void Desenha(PtNodo* t, int nivel)
{
int x;
 if (t !=NULL)
 {
   for (x=1; x<=nivel; x++)
      printf("=");
   printf("%d \n", t->key);
   if (t->esq != NULL) Desenha(t->esq, (nivel+1));
   if (t->dir != NULL) Desenha(t->dir, (nivel+1));
 }
 else printf("Arvore Vazia");
};

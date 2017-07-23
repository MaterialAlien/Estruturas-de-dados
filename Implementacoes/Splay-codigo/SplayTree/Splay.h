
// Defini��o da Estrutura
typedef struct SplayTree PtNodo;
struct SplayTree { 
       int key;
       PtNodo* esq;
       PtNodo* dir;
       };


// Defini��o das Fun��es
PtNodo* Novo(int key, PtNodo* esq, PtNodo* dir);
PtNodo* Insere(int key, PtNodo* t);
PtNodo* Splay(PtNodo* t, int key);
PtNodo* Consulta(PtNodo* t, int key);
PtNodo* Remove(PtNodo* t, int key);
void Destroi(PtNodo* t);

// Fun��es Auxiliares
PtNodo* RotEsq(PtNodo* t);
PtNodo* RotDir(PtNodo* t);
void Desenha(PtNodo* t , int nivel);
PtNodo* ConsultaSplay(PtNodo* t, int key); // Auxiliar do Inserem, al�m de fazer o Splay Insere o elemento.

#ifndef LISTA_ENTEROS
#define LISTA_ENTEROS


#define L_DER 1;
#define L_IZQ -1;
#define L_MED 0;

struct l_enteros {
	int x;
};

typedef struct l_dir *lista;

lista lista_nueva ( );
int lista_vacia ( );
void lista_mete ( lista c, struct l_enteros e, int donde );
void lista_saca ( lista c, struct l_enteros *e, int donde );
void lista_dest ( lista *c );
lista lista_copyseg ( lista c, int ini, int fin );
lista lista_copy ( lista c );
lista lista_corta ( lista c, int posicion );
lista lista_contat ( lista *c, lista *d );
lista lista_merge (  lista *c, lista *d );
void lista_mergesort ( lista *c );
void lista_look ( lista c,  struct l_enteros *e );
void l_next ( lista c );
int l_tama ( lista c );
int l_posi ( lista c );
void l_marc ( lista c, int indice );
int l_marcado ( lista c, int indice );
int l_find ( lista c, struct l_enteros *e );


#endi  f

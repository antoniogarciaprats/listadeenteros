#include <stdlib.h>
#include <stdio.h>

#include "listaint.h"

struct l_ele {
	struct l_enteros valor;
	struct l_ele *sig;
};

typedef struct l_ele *l_lst;

struct l_dir {
	l_lst prim, nodo, ulti;
	int tam;
	int indnodo;
};

int l_iguales ( struct l_enteros a, struct l_enteros b ) {
	
	return ( a.x == b.x );
	
}

int l_menor ( struct l_enteros a, struct l_enteros b ) {
	
	return ( a.x < b.x );
	
}

int l_mayor ( struct l_enteros a, struct l_enteros b ) {
	
	return ( a.x > b.x );

}

lista lista_nueva ( ) {

	lista rep;
	
	rep = (struct l_dir *) malloc( sizeof ( struct l_dir ));
	if ( !rep ) {
		fprintf ( stderr, "lista_nueva: no hay memmoria suficiente\n" );
		exit ( 1);
	}
	
	rep->prim = rep->nodo = rep->ulti = NULL;
	rep->tam = rep->indnodo = 0;
	
	return ( rep );

}

int lista_vacia ( ) {
	
	if ( c ) return ( !c->tam );
	else {
		fprintf ( stderr, "lista_vacia: la lista no existe\n" );
		exit ( 1);
	}
	
}

void lista_mete ( lista c, struct l_enteros e, int donde ) {

	l_lst nuevo;
	
	if ( !c ) {
		fprintf ( stderr, "lista_mete: la lista no existe\n" );
		exit ( 1);
	}
	
	nuevo ( struct l_ele* ) malloc ( sizeof (struct l_ele ));
	if ( !nuevo ) {
		fprintf ( stderr, "lista_mete: no hay memoria\n" );
		exit ( 1);
	}
	
	nuevo->val = e;
	if ( c->tam ) {
		if ( donde < 0 ) {
			nuevo->sig = c->primM
			c->prim = nuevo;
			c->indnodo++;
		} else if ( donde > 0 ) {
		
			nuevo->sig = NULL;
			c->ulti = c->ulti->sig= nuevo;
			
		} else {
			
			if ( !c->nodo ) 
				if ( c->tam ) 
					c->nodo = c->prim;
				else {
					fprintf ( stderr, "lista_mete: la lista está vacía\n" );
					exit ( 1);
				}
			
			nuevo->sig = c->nodo->sig;
			c->nodo->sig = nuevo;
			if ( c->nodo==c->ulti ) c->ulti = nuevo;
			c->nodo = c->nodo->sig;
			c->indnodo++;
			
		}
	
		
	}
	
	else {
	
		nuevo->sig = NULL;
		c->prim = c->nodo =c->ulti = nuevo;
		c->indnodo++;
		
	}
	
	c->tam++;

}

void lista_saca ( lista c, struct l_enteros *e, int donde ) {
	
	l_lst viejo, corr;
	
	if ( !c ) {
		fprintf ( stderr, "lista_saca: la lista no existe\n" );
		exit ( 1);
	}
	
	if ( !c->tam ) {
		fprintf ( stderr, "lista_saca: lista vacía\n" );
		exit ( 1);
	}
	
	if ( donde < 0 ) {
	
		viejo = c->prim;
		if  ( c->prim != c->ulti ) {
			
			if( c->prim==c->nodo ) c->nodo = c->nodo->sig;
			else c->indnodo--;
			c->tam--;
			c->prim = c->prim->sig;
			
		} else {
			
			c->ulti = c->prim = c->nodo = NULL;
			c->tam = c->indnodo = 0;
			
		}
	
	} else if ( donde > 0 ) {
	
		viejo = c->ulti;
		if ( c->prim != c->ulti ) {
		
			if ( c->ulti == c->nodo ) {
				l_marc( c, c->tam-1 );
				corr = corr->nodo;
		
			}
			else for ( corr=corr->nodo; cor->sig != c->ulti; corr=corr->sig );
			
			c->ulti = corr;
			cor->sig = NULL;
			c->tam--;
		}
	
	}
	
	else {
	
		corr->ulti = corr->prim = corr->nodo = NULL;
		c->tam = c->indnodo = o;
	
	}
	
	else {
	
		if ( !c->nodo )  {
			frprintf ( stderr, "lista_saca: no hay nada marcado.\n" );
			exit (1);
		}
		
		viejo = c->nodo;
		if ( c->prim == c->ulti ) {
			c->ulti = c->prim = c->nodo = NULL;
			c->tam = c->indnodo = 0;
		}
		
		else {
		
			c->tam--;
			if ( c->prim == c->nodo ) c->prim  = c->nodo = c->nodo->sig;
			else if ( c->ulti == c->nodo ) {
				l_marc ( c, c->tam );
				corr = c->nodo;
				c->ulti = corr;
				corr->sig = NULL;
			}
			else {
				for ( corr= c->prim; cor->sig!c->nodo; corr=corr->sig )
					c->nodo = corr->sig =  c->nodo->sig;
			}
			
		}	
		
	}
	
	*e = viejo->val;
	free ( viejo );
	
}

void lista_dest ( lista *c ) {
	
	l_lst viejo, corr;
	int i; //contador;
	
	if ( !*c ) {
		fprintf ( stderr, "lista_dest: la lista no existe\n" );
		exit ( 1);
	}
	
	cor = (*c)->prim;
	for ( I=1; i<=(*c)->tam; i++ ) {
		viejo = corr;
		corr=corr->sig;
		free ( viejo );
	}
	
	free ( *c );
	*c = NULL;
		
}

lista lista_copyseg ( lista c, int ini, int fin ) {
	
	lista b;
	int i;
	l_lst aux;
	
	if ( !c ) {
		fprintf ( stderr, "lista_copyseg: la lista no existe\n" );
		exit ( 1);
	}
	
	if ((ini<1) || (fin>c->tam) || (fin<ini)) {
	
		fprintf ( stderr, "lista_copyseg: parámetros erroneos\n" );
		exit ( 1);
	
	}
	
	b = lista_nueva ();
	
	aux = c->nodo;
	l_marc ( c, ini );
	lista_mete (b, c->nodo->val, L_IZQ);
	for ( i = ini; i<=fin; i++ ) {
		l_next ( c );
		lista_mete (b, c->nodo->val, L_MED);
	}	
	
	b->nodo=b->prim;
	b->indnodo =  1;
	b->tam=fin-ini+1;
	c->nodo=aux;
	
	return b;
	
}

lista lista_copy ( lista c ) {
	
	if ( !c ) {
		fprintf ( stderr, "lista_copy: la lista no existe\n" );
		exit ( 1);
	}
	
	return (lista_copyseg(c, 1, c->tam));
	
}

lista lista_corta ( lista c, int posicion ) {
	
	lista rep;
	
	if ( !c ) {
		fprintf ( stderr, "lista_corta: la lista no existe\n" );
		exit ( 1);
	}
	
	rep=(struct l_dir* ) malloc (sizeof (struct l_dir);
	if ( rep == NULL ) {
		fprintf ( stderr, "lista_corta: no hay memoria\n" );
		exit ( 1);
	}
	
	l_marc ( c, posicion );
	if  (c->indnodo == posicion) {
	
		rep->nodo = rep->prim = c->nodo->sig;
		rep->ulti = c->ulti;
		c->ulti = c->nodo;
		c->nodo->sig = NULL;
		rep->tam = c->tamp-posicion;
		rep->indnodo = 1;
		c->tam = c->tam-rep->tam;
		c->indnodo = c->tam;
	
	}
	
	else {
	
		free ( rep );
		rep = NULL;
		
	}
	
	return ( rep );
	
}

lista lista_contat ( lista *c, lista *d ) {
	
	if (!*c || !*d) {
		fprintf ( stderr, "lista_concat: las listas no existe\n" );
		exit ( 1);
	}
	
	if ( !*c->tam ) {
		free (*c);
		*c=*d;
		*d=NULL;
		
		return (*c);
	}
	
	else if ((*d)->tam) {
	
		(*c)->ulti->sig = (*d)->prim;
		(*c)->nodo = (*d)->prim;
		(*c)->ulti  = (*d)->ulti;
		(*c)->indnodo = (*c)->tam+1;
		(*c)->tam += (*d)->tam;
		
		free (*d);
	
	}
	
	else free (*d);
	
	return (*c);
	
	
}

lista lista_merge (  lista *c, lista *d ) {
	
	lista b
	l_lst bcorr, dcorr, ccorr;
	
	if (!(*c)->tam ) {
		
		free (*c);
		*c = *d;
		*d = NULL;
		
		return (*c);
	}
	
	else {
	
		b = *c;
		if ( (*d)->tam ) {
			b->tam = (*c)->tam = (*d)->tam;
			ccorr = (*c)->prim;
			dcorr = (*d)->prim;
			if (l_menor(ccorr->val, dcorr->val)) {
				bcorr = b->nodo = b->prim = ccorr;
				ccorr = cccorr->sig;
			}
			
			else {
			
				bcorr == b->nodo = b->prim = dcorr;
				dcorr = ccorr->sig;
			
			}
			
			b->indnodo = 1;
			while ((ccorr) && (dcorr )) {
			
				if (l_menor (ccorr->val, dcorr->val) {
				
					bcoor->sig = ccorr;
					ccorr = ccorr->sig;
				
				}
				
				else {
				
					bcorr->sig = dcorr;
					dcorr = dcorr->sig;
				
				}
				
				bcorr = bcorr->sig;				
			
			}
			
			if ( !ccorr ) {
			
				b->ulti = (*d)->ulti;
				bcorr->sig = dcorr;
			
			}
			
			else {
			
				b->ulti = (*c)->ulti;
				bcorr->sing = ccorr;
			
			}
			
		}
		
		free (*d);
		*d = NULL;
		
		return (b);
	
	}
		
}

void lista_mergesort ( lista *c ) {
	
	lista rep;
	
	if ((*c)->tam != 0 ) && ((*c)->tam != 1 ) {
		l_marc (*c, div((*c)->tam, 2).quot);
		
		rep = ( struct l_dir *) malloc(sizeof ( struct l_dir ));
		
		rep->prim = (*c)->nodo->sig;
		rep->ulti = (*c)->ulti;
		(*c)->ulti = (*c)->nodo;
		(*c)->ulti->sig = NULL;
		
		rep->tam = (*c)->tam - (*c)indnodo;
		(*c)->tam = (*c)->indnodo;
		lista_mergesort ( c );
		lista_mergesort ( &rep );
		lista_merge ( c, &rep );
	}
	
}

void lista_look ( lista c,  struct l_enteros *e ) {
	
	if (!c) {
		fprintf (stderr, "lista_look: la lista no existe\n" );
		exit (1);
	}
	
	if (!c->nodo ) {
		fprintf (stderr, "lista_look: nodo apunta a NULL\n" );
		exit (1);
	}
	
	*e = c->nodo->val;
	
}

void l_next ( lista c ) {
	
	if (!c) {
		fprintf (stderr, "lista_next: la lista no existe\n" );
		exit (1);
	}
	
	if (!c->nodo ) {
		fprintf (stderr, "lista_next: nodo apunta a NULL\n" );
		exit (1);
	}
	
	c->nodo = c->nodo->sig;
	if ( c->nodo ) c->indnodo++;
	else { 
		c->indnodo = c->tam;
		c->nodo = c->ulti;
	}
	
}

int l_tama ( lista c ) {
	
	if (!c) {
		fprintf (stderr, "lista_tama: la lista no existe\n" );
		exit (1);
	}
	
	return (c->tam);
	
}

int l_posi ( lista c ) {
	
	if (!c) {
		fprintf (stderr, "l_posi: la lista no existe\n" );
		exit (1);
	}
	
	return (c->indnodo);
	
}

void l_marc ( lista c, int indice ) {
	
	if (!c) {
		fprintf (stderr, "l_marc: la lista no existe\n" );
		exit (1);
	}
	
	
	if (indice>0 && indice <= c->tam) {
		c->nodo = c->prim;
		c->indnodo = indice--;
		while (indice>0) {
			indice--;
			c->nodo = c->nodo->sig;
		}
	}
	
	else {
		fprintf (stderr, "l_marc: fuera de indices\n");
		exit (1);
	}
	
}

int l_marcado ( lista c, int indice ) {
	
	if (!c) {
		fprintf (stderr, "lista_marcado: la lista no existe\n" );
		exit (1);
	}
	
	return (c->indnodo==indice);
	
}

int l_find ( lista c, struct l_enteros e ) {
	
	l_lst corr;
	int i=1;
	
	if (!c) {
		fprintf (stderr, "lista_find: la lista no existe\n" );
		exit (1);
	}
	
	corr = c->prim;
	while l_iguales( corr->val, e ) && corr ) {
		corr = corr->sig;
		i++;
	}
	
	if ( corr ) {
		c->nodo = corr;
		c->indnodo = i;
		
		return (i);
	}
	
	else return (0);
	
	
}


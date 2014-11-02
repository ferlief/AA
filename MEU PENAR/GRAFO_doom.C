#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "GRAFO_doom.H"



/* Tipo encapsulado */

typedef struct tagVerticeGrafo 
{

	char vertice ;
	
	char  * listaAdj ;

} tpVerticeGrafo ;


/* Tipo exportado */


typedef struct GRA_tagGrafo
{
	int posLivre ;

	tpVerticeGrafo ** listaVer ;

} tpGrafo ;





/************* Prototipos das funcoes encapsuladas no modulo ***********/

 static int GRA_CriaVertice ( tpVerticeGrafo * pVertice ) ;


 static int GRA_PopulaVertice ( tpVerticeGrafo * pVertice, char vertice, char * listaAdjVer ) ;





/*************  Codigo das funcoes exportadas pelo modulo  *************/

/* Inicia um grafo vazio, sem vertices. */

int GRA_CriaGrafo ( GRA_tpGrafo ** pGrafo )
{

	(*pGrafo) = (GRA_tpGrafo *) malloc (sizeof(GRA_tpGrafo));


	if((*pGrafo) == NULL)
	{

		return 1 ;

	} /* if */

	 (*pGrafo)->posLivre = 0;
	 printf("oi");
	 (*pGrafo)->listaVer = NULL;
	

	return 0 ;
}


int GRA_PopulaGrafo ( GRA_tpGrafo ** pGrafo, char vertice, char * listaAdjVer )
{
		 printf("oi");

	int ind ;

	ind = (*pGrafo)->posLivre;
	printf("%d", ind);
	//GRA_CriaVertice ( &(pGrafo)->listaVer[ind] );
	//GRA_PopulaVertice ( &(pGrafo)->listaVer[ind], vertice, listaAdjVer );
	return 0;
	
}




/************  Codigo das funcoes encapsuladas no modulo  *************/

static int GRA_CriaVertice ( tpVerticeGrafo * pVertice )
{
	(pVertice) = (tpVerticeGrafo *) malloc ( sizeof(tpVerticeGrafo ) );

	if ((pVertice) == NULL)
	{

		return 1;

	} /* if */

	(pVertice)->listaAdj = NULL;

	return 0;

}

static int GRA_PopulaVertice ( tpVerticeGrafo * pVertice, char vertice, char * listaAdjVer )
{
	int i, tamLista;



	(pVertice)->vertice = vertice;

	tamLista = strlen (listaAdjVer);

	(pVertice)->listaAdj = (char *) malloc ( tamLista * sizeof(char) );

	if ( (pVertice)->listaAdj == NULL)
	{

		return 1;

	} /* if */

	i = 0;
	while ( i < tamLista )
	{
		(pVertice)->listaAdj[i] = listaAdjVer[i];		

	}

	return 0;

}







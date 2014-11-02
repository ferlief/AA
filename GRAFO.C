#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "GRAFO.H"



/* Tipo encapsulado */

typedef struct tagVerGraph 
{

	char vertex ;
	
	char  * adjVec ;

} ttVerGraph ;


/* Tipo exportado */


typedef struct GRA_tagGraph
{
	int total;
	int freePos;

	ttVerGraph ** nodesVec ;

} ttGraph ;





/************* Prototipos das funcoes encapsuladas no modulo ***********/





 static int FillVertex (ttVerGraph ** pVertex, char pVer, char * pAdj);






/*************  Codigo das funcoes exportadas pelo modulo  *************/

/* Inicia um grafo vazio, sem vertices. */

int GRA_CreateGraph ( GRA_ttGraph ** pGraph, int pNumVer )
{
	int i;

	(*pGraph) = (GRA_ttGraph *) malloc ( sizeof(GRA_ttGraph) );
		if((*pGraph) == NULL) return 1;

	(*pGraph)->nodesVec = (ttVerGraph **) malloc ( pNumVer * sizeof(ttVerGraph*) );
		if ((*pGraph)->nodesVec == NULL) return 1;

	for (i=0; i<pNumVer; i++)
	{
	 	(*pGraph)->nodesVec[i] = NULL;
	}

	(*pGraph)->total = pNumVer;
	(*pGraph)->freePos = 0;

	return 0 ;
}


int GRA_FillGraph ( GRA_ttGraph ** pGraph, char pVer, char * pAdjVec )
{
	
	
	if ( (*pGraph)->freePos == (*pGraph)->total ) 
		return 1;

	
	(*pGraph)->nodesVec[(*pGraph)->freePos] = (ttVerGraph*) malloc ( sizeof(ttVerGraph) );
		if ((*pGraph)->nodesVec[(*pGraph)->freePos] == NULL) return 1;


	FillVertex (&(*pGraph)->nodesVec[(*pGraph)->freePos], pVer, pAdjVec);
	(*pGraph)->freePos = ((*pGraph)->freePos)++;

	return 0;
	
}




/************  Codigo das funcoes encapsuladas no modulo  *************/


 static int FillVertex (ttVerGraph ** pVertex, char pVer, char * pAdjVec)
{
	int i;
	int SizeVec;



	SizeVec = strlen (pAdjVec);


	(*pVertex)->vertex = pVer;

	(*pVertex)->adjVec = (char *) malloc ( SizeVec * sizeof(char) );
		if ( (*pVertex)->adjVec == NULL) return 1;


	i = 0;
	while ( i < SizeVec )
	{
		(*pVertex)->adjVec[i] = pAdjVec[i];		
		printf("%c",(*pVertex)->adjVec[i] );
		i++;
	}


	return 0;

}







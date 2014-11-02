#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs for graph */

typedef struct vertex {
	char name;
	int size;
	int id;
	struct vertex ** adjList;
} tVertex;


typedef struct graph {
	int size;
	tVertex ** nodesList;
} tGraph;


/* Functions for test and verification  - prototype */

void verifyGraph (tGraph ** pGraph);



/* Functions for graph manipulation  - prototype */


void fillGraph (tGraph ** pGraph, int pInd, char * pAdj);


void createGraph (tGraph ** pGraph, char * nodes);




/* DFS Algorithm - prototype */

void markVisited (tGraph ** pGraph, char ** pVisited, int pId, char ** pOrder);

void breadthFirstSearch (tGraph ** pGraph, char ** pVisited, char ** pOrder);




/************************************/
/************* MAIN *****************/
/************************************/


int main (void)
{
	int i;

	tGraph * graph ;

	int size = 11;
	char * list_of_vertexes = "ABCDEFGHIJ";
	char ** list_of_adj;

	//char * visited;

	list_of_adj = (char **) malloc (size * sizeof(char*));

	list_of_adj[0] = "CB";
	list_of_adj[1] = "ACD";
	list_of_adj[2] = "ABDE";
	list_of_adj[3] = "CB";
	list_of_adj[4] = "CHF";
	list_of_adj[5] = "EH";
	list_of_adj[6] = "HI";
	list_of_adj[7] = "EFGI";
	list_of_adj[8] = "GHJ";
	list_of_adj[10] = "I";



	createGraph (&graph, list_of_vertexes);

	for (i=0; i<size ; i++)
	{
		fillGraph (&graph, i, list_of_adj[i]);
	}

	verifyGraph (&graph);





	return 0;
}

/************************************/
/********** END MAIN ****************/
/************************************/


/* Functions for test and verification  - prototype */

void verifyGraph (tGraph ** pGraph)
{
	int i, j;

	char * visited;

	char * order;

	depthFirstSearch (&(*pGraph), &visited, &order);

	/***********************************/
	printf("graph:\n");
	for(i=0; i<(*pGraph)->size; i++)
	{
		for (j=0; j < (*pGraph)->nodesList[i]->size; j++)
		{
			printf("%c ", (*pGraph)->nodesList[i]->adjList[j]->name);
		}
		printf("\n");
	}
	/***********************************/
	printf("visited list:\n");
	for (i=0; i<(*pGraph)->size; i++)
	{
		printf("%d ", (visited)[i]);
	}
	printf("\n");
	free (visited);
	/***********************************/
	printf("visitation order:\n");
	for (i=0; order[i]!=0; i++){
		printf("%c ", (order)[i]);
	}
	printf("\n");
	free (order);
	/***********************************/
	printf("size of adjacency list of each node:\n");
	for (i=0; i<(*pGraph)->size; i++)
	{
		printf("%d ", (*pGraph)->nodesList[i]->size);
	}
	printf("\n");
	/***********************************/
	printf("id of each node:\n");
	for (i=0; i<(*pGraph)->size; i++)
	{
		printf("%d ", (*pGraph)->nodesList[i]->id );
	}
	printf("\n");
	/***********************************/
	


}




/* Functions for graph manipulation  - prototype */


void fillGraph (tGraph ** pGraph, int pInd, char * pAdj)
{
	int i, j;
	int sizeAdj;

	sizeAdj = strlen (pAdj);
	(*pGraph)->nodesList[pInd]->adjList = (tVertex **) malloc (sizeAdj*sizeof(tVertex*));
		if ((*pGraph)->nodesList[pInd]->adjList == NULL) exit (1);

	(*pGraph)->nodesList[pInd]->size = sizeAdj;



	i=0, j=0;
	while ((i<(*pGraph)->size)&&(j<sizeAdj))
	{
		if ((*pGraph)->nodesList[i]->name == pAdj[j])
		{
			(*pGraph)->nodesList[pInd]->adjList[j] = (*pGraph)->nodesList[i];
			i=0;
			j++;
			continue;
		}
		i++;
	}

}

void createGraph (tGraph ** pGraph, char * nodes)
{
	int i;

	int sizeGraph;

	sizeGraph = strlen (nodes);


	(*pGraph) = (tGraph *) malloc (sizeof(tGraph));
		if ((*pGraph) == NULL) exit (1);

	(*pGraph)->size = sizeGraph;



	(*pGraph)->nodesList = (tVertex **) malloc (sizeGraph*sizeof(tVertex*));

	for (i=0; i<sizeGraph; i++)
	{
		(*pGraph)->nodesList[i] = (tVertex *) malloc (sizeof(tVertex));
		(*pGraph)->nodesList[i]->name = nodes[i];
		(*pGraph)->nodesList[i]->id = i;

	}

}




/* DFS Algorithm - code */

void markVisited (tGraph ** pGraph, char ** pVisited, int pId, char ** pOrder)
{
	int i;

	int SizeAdj = (*pGraph)->nodesList[pId]->size;
	int IdNodeAdj;


	if ((*pVisited)[pId] == 0)
	{
		(*pVisited)[pId] = 1;

		for (i=0; (*pOrder)[i]!=0 ; i++){}
		(*pOrder)[i] = (*pGraph)->nodesList[pId]->name;


		i=0;
		while (i<SizeAdj)
		{
			IdNodeAdj = (*pGraph)->nodesList[pId]->adjList[i]->id;
			if ((*pVisited)[IdNodeAdj] == 0)
			{
				(*pVisited)[IdNodeAdj] = 1;
				for (i=0; (*pOrder)[i]!=0 ; i++){}
				(*pOrder)[i] = (*pGraph)->nodesList[IdNodeAdj]->name;
			}
			i++;
		}

		markVisited (&(*pGraph), &(*pVisited), IdNodeAdj, &(*pOrder));
	}

}

void breadthFirstSearch (tGraph ** pGraph, char ** pVisited, char ** pOrder)
{
	int i;
	int size;

	char * completed;

	size = (*pGraph)->size;

	(*pVisited) = (char*) malloc (size*sizeof(char));
	(*pOrder) = (char*) malloc (size*sizeof(char));


	for (i=0; i<size; i++)
	{
		(*pVisited)[i] = 0;
		(*pOrder)[i] = 0;
	}

	markVisited (&(*pGraph), &(*pVisited), 0, &(*pOrder));

}

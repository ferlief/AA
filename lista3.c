#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs for graph */

typedef struct vertex {

	char vertex;
	
	int id; 
	
	struct vertex * vAdjList;
	
	int sizeAdjList;

} tVertex;


typedef struct graph {

	int size;

	tVertex * vVertexes;

	char * vVisited;

	int * vOrder;

	int * vQueue;

	int * vArticPts;

} tGraph;


/* Functions for reation adifferent graphs - prototype */

void graph_lista3 ( tGraph * pGraph );

void graph_arv ( tGraph * pGraph );


/* Functions for testing and verification  - prototype */


void verifyGraph (tGraph * pGraph);



/* Functions for graph manipulation  - prototype */


void fillGraph (tGraph * pGraph, int pId, char * pAdjList);


void createGraph (tGraph * pGraph, char * pVertexes);

void resetVectors (tGraph * pGraph);


/* DFS Algorithm - prototype */


void depthFirstSearch (tGraph * pGraph, int pId);

void breadthFirstSearch (tGraph * pGraph, int pId);



/* DFS Based Algorithms - prototype */

int connected (tGraph * pGraph);

int acyclic (tGraph * pGraph);

/* prob */
int bipartite (tGraph * pGraph);

/* prob */

void articulationPoints (tGraph * pGraph, char ** pArticPts);

int biconnectedComponents;

/************************************/
/************* MAIN *****************/
/************************************/


int main (void)
{
	tGraph lista3 ;

	tGraph arv ;

	graph_lista3 (&lista3);


	graph_arv (&arv);


	verifyGraph (&arv);



	return 0;
}

/************************************/
/********** END MAIN ****************/
/************************************/





/* DFS Algorithm - code */

void depthFirstSearch (tGraph * pGraph, int pId)
{
	int i=0;

	int SizeAdjList;

	if ((pGraph)->vVisited[pId] == 0)
	{
		(pGraph)->vVisited[pId] = 1;
		
		for (i=0; (pGraph)->vOrder[i] != 0; i++){}
		(pGraph)->vOrder[i] = (pGraph)->vVertexes[pId].vertex;

		SizeAdjList = (pGraph)->vVertexes[pId].sizeAdjList;

		
		for (i=0; i < SizeAdjList; i++)
		{
			depthFirstSearch (pGraph, (pGraph)->vVertexes[pId].vAdjList[i].id);
		}
	}
}


/* BFS Algorithm - code */
void breadthFirstSearch (tGraph * pGraph, int pId)
{
	int i=0, j=0;

	int IdQ;
	int IdAdj;
	int SizeAdjList;

	(pGraph)->vVisited[pId] = 1;
	
	for (i=0; (pGraph)->vOrder[i] != 0; i++){}
	(pGraph)->vOrder[i] = (pGraph)->vVertexes[pId].vertex;


	for (i=0; (pGraph)->vQueue[i] != -1; i++){}
	(pGraph)->vQueue[i] = pId;


	while ( (pGraph)->vQueue[0] != -1 )
	{
		IdQ = (pGraph)->vQueue[0];

		for (i=0; (pGraph)->vQueue[i] != -1; i++)
		{
			(pGraph)->vQueue[i] = (pGraph)->vQueue[i+1];
		}

		SizeAdjList = (pGraph)->vVertexes[IdQ].sizeAdjList;

		for (j=0; j < SizeAdjList; j++)
		{
			IdAdj = (pGraph)->vVertexes[IdQ].vAdjList[j].id;

			if ( (pGraph)->vVisited[IdAdj] == 0)
			{
				(pGraph)->vVisited[IdAdj] = 1;
	
				for (i=0; (pGraph)->vOrder[i] != 0; i++){}
				(pGraph)->vOrder[i] = (pGraph)->vVertexes[IdAdj].vertex;


				for (i=0; (pGraph)->vQueue[i] != -1; i++){}
				(pGraph)->vQueue[i] = IdAdj;

			}
		}

	}

}


/* DFS Based Algorithms - codes */

int connected (tGraph * pGraph)
{
	int i;

	resetVectors (pGraph);
	depthFirstSearch (pGraph);


	for (i=0; i<(pGraph)->size; i++)
	{
		if((pGraph)->vVisited[i] == 0) return 0;
	}
	
	return 1;

}

void depthFirstSearch (tGraph * pGraph, int pId)
{
	int i=0;

	int SizeAdjList;

	if ((pGraph)->vVisited[pId] == 0)
	{
		(pGraph)->vVisited[pId] = 1;
		
		for (i=0; (pGraph)->vOrder[i] != 0; i++){}
		(pGraph)->vOrder[i] = (pGraph)->vVertexes[pId].vertex;

		SizeAdjList = (pGraph)->vVertexes[pId].sizeAdjList;

		
		for (i=0; i < SizeAdjList; i++)
		{
			depthFirstSearch (pGraph, (pGraph)->vVertexes[pId].vAdjList[i].id);
		}
	}
}

int acyclic (tGraph * pGraph)
{
	resetVectors (pGraph);




}

// int bipartite_MV (tGraph ** pGraph, char ** pVisited, int pId)
// {
// 	int i, ret = 1;

// 	int SizeAdj = (*pGraph)->nodesList[pId]->size;
// 	int IdNodeAdj;


// 	i=0;
// 	while (i<SizeAdj)
// 	{
// 		IdNodeAdj = (*pGraph)->nodesList[pId]->adjList[i]->id;

// 		if ((*pVisited)[IdNodeAdj] == 0)
// 			(*pVisited)[IdNodeAdj] = -(*pVisited)[pId];
// 		else
// 		{
// 			if ((*pVisited)[IdNodeAdj] == (*pVisited)[pId]) 
// 				ret = 0;

// 		}

// 		ret =  bipartite_MV (&(*pGraph), &(*pVisited), IdNodeAdj);
// 		i++;
// 	}

// 	return ret;
// }

// int bipartite (tGraph ** pGraph)
// {
// 	int i;
// 	int size;

// 	char * visited;

// 	size = (*pGraph)->size;

// 	(visited) = (char*) malloc (size*sizeof(char));


// 	for (i=0; i<size; i++)
// 	{
// 		(visited)[i] = 0;
// 	}

// 	(visited)[0] = 1;
// 	if (!bipartite_MV (&(*pGraph), &visited, 0)) 
// 		return 0;
// 	else
// 	{
// 		for (i=0; i<size; i++)
// 		{
// 			if (visited[i] == 0){
// 				(visited)[i] = 1;
// 				if (!bipartite_MV (&(*pGraph), &visited, i)) 
// 					return 0;
// 			}
// 	}
// 		return 1;
// 	}
// }


// void articulationPoints (tGraph ** pGraph, char ** pArticPts)
// {

// }



/* Functions for reation adifferent graphs - code */

void graph_lista3 ( tGraph * pGraph )
{
	int i;

	int size = 14;
	char * list_of_vertexes = "ABCDEFGHIJKLMN";
	char ** list_of_adj;


	list_of_adj = (char **) malloc (size * sizeof(char*));

	list_of_adj[0] = "CB";
	list_of_adj[1] = "ACD";
	list_of_adj[2] = "ABDE";
	list_of_adj[3] = "CB";
	list_of_adj[4] = "CHF";
	list_of_adj[5] = "EH";
	list_of_adj[6] = "HI";
	list_of_adj[7] = "EFGI";
	list_of_adj[8] = "GHN";
	list_of_adj[9] = "MK";
	list_of_adj[10] = "JLM";
	list_of_adj[11] = "K";
	list_of_adj[12] = "JK";
	list_of_adj[13] = "I";



	createGraph (pGraph, list_of_vertexes);

	for (i=0; i<size ; i++)
	{
		fillGraph (pGraph, i, list_of_adj[i]);
	}

}

void graph_arv ( tGraph * pGraph )
{
	int i;

	int size = 15;
	char * list_of_vertexes = "ABCDEFGHIJKLMNO";
	char ** list_of_adj;

	//char * visited;

	list_of_adj = (char **) malloc (size * sizeof(char*));

	list_of_adj[0] = "BCD";
	list_of_adj[1] = "AEF";
	list_of_adj[2] = "AG";
	list_of_adj[3] = "AHI";
	list_of_adj[4] = "BJ";
	list_of_adj[5] = "BK";
	list_of_adj[6] = "C";
	list_of_adj[7] = "DMN";
	list_of_adj[8] = "D";
	list_of_adj[9] = "EL";
	list_of_adj[10] = "F";
	list_of_adj[11] = "J";
	list_of_adj[12] = "HO";
	list_of_adj[13] = "H";
	list_of_adj[14] = "M";



	createGraph (pGraph, list_of_vertexes);

	for (i=0; i<size ; i++)
	{
		fillGraph (pGraph, i, list_of_adj[i]);
	}

}



/* Functions for graph manipulation  - prototype */


void fillGraph (tGraph * pGraph, int pId, char * pAdjList)
{
	int i, j;
	int SizeAdjList;

	SizeAdjList = strlen (pAdjList);

	(pGraph)->vVertexes[pId].vAdjList = (tVertex *) malloc (SizeAdjList*sizeof(tVertex));
		if ((pGraph)->vVertexes[pId].vAdjList == NULL) exit (1);

	(pGraph)->vVertexes[pId].sizeAdjList = SizeAdjList;



	i=0, j=0;
	while ( (i < (pGraph)->size) && (j < SizeAdjList) )
	{
		if ( (pGraph)->vVertexes[i].vertex == pAdjList[j])
		{
			(pGraph)->vVertexes[pId].vAdjList[j] = (pGraph)->vVertexes[i];
			i=0;
			j++;
			continue;
		}
		i++;
	}

}

void createGraph (tGraph * pGraph, char * pVertexes)
{
	int i;

	(pGraph)->size = strlen (pVertexes);

	(pGraph)->vVertexes = (tVertex *) malloc ((pGraph)->size*sizeof(tVertex));
		if ((pGraph)->vVertexes == NULL) exit (1);

	(pGraph)->vVisited = (char *) malloc ((pGraph)->size*sizeof(char));
		if ((pGraph)->vVisited == NULL) exit (1);
	
	(pGraph)->vOrder = (int *) malloc ((pGraph)->size*sizeof(int));
		if ((pGraph)->vOrder == NULL) exit (1);

	(pGraph)->vQueue = (int *) malloc ((pGraph)->size*sizeof(int));
		if ((pGraph)->vQueue == NULL) exit (1);

	(pGraph)->vArticPts = (int *) malloc ((pGraph)->size*sizeof(int));
		if ((pGraph)->vArticPts == NULL) exit (1);

	for (i=0; i < (pGraph)->size; i++)
	{
		(pGraph)->vVertexes[i].vertex = pVertexes[i];
		(pGraph)->vVertexes[i].id = i;
		(pGraph)->vVisited[i] = 0;
		(pGraph)->vOrder[i] = 0;
		(pGraph)->vQueue[i] = -1;
		(pGraph)->vArticPts[i] = 0;

	}

}


void resetVectors (tGraph * pGraph)
{
	int i;

	for (i=0; i < (pGraph)->size; i++)
	{
		(pGraph)->vVisited[i] = 0;
		(pGraph)->vOrder[i] = 0;
		(pGraph)->vQueue[i] = -1;

	}
}


/* Functions for test and verification  - prototype */
void verifyGraph (tGraph * pGraph)
{
	int i, j;

	
	printf("/***********************************/");
	printf ("\n");
	/***********************************/

	printf("graph:\n");
	
	for(i=0; i < (pGraph)->size; i++)
	{
		printf ("%d %c -> ", (pGraph)->vVertexes[i].id, (pGraph)->vVertexes[i].vertex);
		for (j=0; j < (pGraph)->vVertexes[i].sizeAdjList; j++)
		{
			printf("%c ", (pGraph)->vVertexes[i].vAdjList[j].vertex);
		}
		printf("\n");
	}
	printf("\n");
	/***********************************/
	
	resetVectors (pGraph);
	depthFirstSearch (pGraph, 0);
	
	printf("dfs visited list from 0:\n");
	
	for(i=0; i < (pGraph)->size; i++)
	{
		printf("%d ", (pGraph)->vVisited[i]);
	}
	printf("\n");


	printf("\n");

	printf("dfs order visited list from 0:\n");
	
	for(i=0; i < (pGraph)->size; i++)
	{
		printf("%c ", (pGraph)->vOrder[i]);
	}
	printf("\n");

	printf("\n");
	
	/***********************************/

	resetVectors (pGraph);
	breadthFirstSearch (pGraph, 0);

	printf("bfs visited list from 0:\n");
	
	for(i=0; i < (pGraph)->size; i++)
	{
		printf("%d ", (pGraph)->vVisited[i]);
	}
	printf("\n");

	printf("\n");

	printf("bfs order visited list from 0:\n");
	
	for(i=0; i < (pGraph)->size; i++)
	{
		printf("%c ", (pGraph)->vOrder[i]);
	}
	printf("\n");

	printf("\n");

	printf("/***********************************/");
	printf ("\n");
	// /***********************************/
	// if (connected (&(*pGraph), &order))
	// 	printf("graph's connected.\n");
	// else 
	// 	printf("graph's not connected.\n");
	// /***********************************/
	// printf("visitation order -connected:\n");
	// for (i=0; order[i]!=0; i++){
	// 	printf("%c ", (order)[i]);
	// }
	// free (order);
	// /***********************************/
	// printf("\n");
	// if (acyclic (&(*pGraph), &order)) 
	// 	printf("graph's acyclic.\n");
	// else 
	// 	printf("graph's not acyclic.\n");
	// /***********************************/
	// // printf("visitation order -acyclic:\n");
	// // for (i=0; order[i]!=0; i++){
	// // 	printf("%c ", (order)[i]);
	// // }
	// // free (order);
	// // *********************************
	// // if (bipartite (&(*pGraph))) 
	// // 	printf("graph's bipartite.\n");
	// // else 
	// // 	printf("graph's not bipartite.\n");
	// // /***********************************/
	


}
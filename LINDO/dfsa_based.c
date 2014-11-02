#include <stdlib.>

#include <graph.h>
#include <dfsa_based.h>



/************* Prototipos das funcoes encapsuladas no modulo ***********/


static int DFS_DepthFirstSearch (GRA_ttGraph ** pGraph, char ** pvisitedVec);




/*************  Codigo das funcoes exportadas pelo modulo  *************/


int DFS_Connected (GRA_ttGraph ** pGraph);

int DFS_Acyclic (GRA_ttGraph ** pGraph);

int DFS_Bipartite (GRA_ttGraph ** pGraph);

int DFS_ArticulationPoints (GRA_ttGraph ** pGraph);

int DFS_BiconnectedComponent (GRA_ttGraph ** pGraph);




/*************  Codigo das funcoes encapsuladas pelo modulo  *************/


static int DFS_MarkVisited (GRA_ttGraph ** pGraph, int NumNodes, char ** pvisitedVec)
{

	int i=0, j=0, k=0;
	int SizeVec;

	char VerCurr;
	int IndVerCurr;
	
	char AdjCurr;
	int IndAdjCurr;


	i=0;
	while (i<(NumNodes; i++)
	{
		IndVerCurr = i;

		GRA_RetVerInd ( &(*pGraph), IndVerCurr, &VerCurr );
		
		(*pvisitedVec)[i] = 1;
		
		j=0;
		IndAdjCurr = j;
		GRA_RetEleAdj ( &(*pGraph), IndAdjCurr, , &AdjCurr );

		GRA_FindVerGraph ( &(*pGraph), AdjCurr, int * pInd)


	}


}

static int DFS_DFSA (GRA_ttGraph ** pGraph, char ** pvisitedVec)
{

	int NumNodes;

	GRA_RetTotalVer ( &(*pGraph), &NumNodes );

	(*pvisitedVec) = (char *) malloc ( (NumNodes) * sizeof(char) );
		if ((*pvisitedVec) == NULL) return 1;

	for (i=0; i<NumNodes; i++)
			(*pvisitedVec)[i] = 0;
	
	DFS_MarkVisited (&(*pGraph), NumNodes, &(* pvisitedVec));



}














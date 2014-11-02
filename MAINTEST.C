#include <stdio.h>

#include "GRAFO.H"

int main (void)
{
	int i;
	char input;
	
	int NumVer;
	char Ver = 'A';
	char AdjVec[] = "ACB";
	
	GRA_ttGraph * graphTest;


	scanf("%d", &NumVer);
	printf("\n");

	GRA_CreateGraph ( &graphTest, NumVer) ;


	// do 
	// {
	// 	/* lê vértice */
	// 	scanf ("%c", &no);
	// 	scanf ("\n");
	// 	if (no == '0') return 0;

	// 	/* lê lista de adjacências do vértice */
	// 	i=0;
	// 	do 
	// 	{
	// 		scanf ("%c", &input);
	// 		adj[i] = input;
	// 		i++;
		

	// 	} while (input!='\n');
	// 	adj[i] = '\0';
	// 	GRA_PopulaGrafo ( &graTeste, no, adj ) ;
	// }
	// while (input!='0');

	//vet = 'A';
	//adj = {'A', 'C', 'B', '\0'};
	GRA_FillGraph ( &graphTest, Ver, AdjVec ) ;

	
	return 0;
}
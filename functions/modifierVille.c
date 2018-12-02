int modifierVille(ptville pdebutVille, int numVille)
{
	ptville px;
	int newnumVille;
	px = rechercherVille(pdebutVille, numVille);
	if(px == NULL){
		printf("[!!!] La ville %d n'existe pas !\n", numVille);
		return 0;
	}
	else{
		printf("Quel est le noveau code postal : ");
		scanf("%d", &newnumVille);
		px->numVille = newnumVille;
		printf("[!!!] La ville %d est bien devenue la ville %d !\n", numVille, px->numVille);
		return 1;
	}
}











int modifierVille(ptville pdebutVille, int numVille)
{
	ptville px, py;
	int newnumVille;
	px = rechercherVille(pdebutVille, numVille);
	if(px == NULL){
		printf("[!!!] La ville %d n'existe pas !\n", numVille);
		return 0;
	}
	else{
		printf("[?] Quel est le noveau code postal : ");
		scanf("%d", &newnumVille);
		py = rechercherVille(pdebutVille, newnumVille);
		if(py == NULL){
            px->numVille = newnumVille;
            printf("[!!!] La ville %d est bien devenue la ville %d !\n", numVille, px->numVille);
            return 1;
		}
        else{
            printf("[!!!] Cette ville existe deja !\n");
            return 0;
        }
	}
}











int transfert(ptville pdebutVille, int numVilleA, int numVilleB){

	ptlivraison py, pw, pAvanty;
	int chauffeur;

	ptville px = rechercherVille(pdebutVille, numVilleA);

	if(px == NULL)
	{
		printf("[!!!] Cette ville n'existe pas !\n");
		return 0;
	}
	else
    {
		py = px->listeLivraison;
		afficherLivraison(pdebutVille, numVilleA);
		printf("[?] Quelle est le numero du chauffeur  : ");
		scanf("%d", &chauffeur);

	    while(py->chauffeur != chauffeur)
        {
            if(py->livraisonSuivante == NULL)
            {
                break;
            }
            else
            {
                pAvanty = py;
                py = py->livraisonSuivante;
            }
		}
		if(py->livraisonSuivante == NULL)
        {
            printf("[!!!] Cette livraison n'existe pas !\n");
            return 0;
        }
        else
            pAvanty->livraisonSuivante = py->livraisonSuivante;
    }


ptville pz = rechercherVille(pdebutVille, numVilleB);

	if(pz == NULL){
		printf("[!!!] Cette ville n'existe pas !\n");
		return 0;
	}
	else
    {
		pw = pz->listeLivraison;
	   	while(pw->livraisonSuivante->livraisonSuivante != NULL) // on va à la fin de la liste livraison de ville B (avant le bidon de fin)
		{
	   		pw = pw->livraisonSuivante;
	   	}
	   	py->livraisonSuivante = pw->livraisonSuivante;
		pw->livraisonSuivante = py;
		if(py->enLivraison != NULL)
        {
            if(py->enLivraison->numVille == numVilleB)
            {
                py->enLivraison = NULL;
                py->disponible = 1;
            }
        }
        printf("[!!!] La livrasion a bien ete transfere !\n");
	}
}

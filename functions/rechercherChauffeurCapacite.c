int rechercheChauffeurCapacite(ptville pdebutVille,int numVille){

	ptlivraison py;
	int capacite;
	ptville px = rechercherVille(pdebutVille, numVille);

	if(px == NULL){
		printf("[!!!] Cette ville n'existe pas !");
		return 0;
	}
	else
    {
        px = pdebutVille->villeSuivante;
		py = px->listeLivraison->livraisonSuivante;
		printf("Quelle est la capacite de la livraion : ");
		scanf("%d", &capacite);

        while(py->livraisonSuivante != NULL)
        {
            if(py->capacite == capacite && py->disponible == 1)
            {
            printf("Le chauffeur %d est disponible dans la ville %d et a une capacite %d, se rend dans %d\n", py->chauffeur, numVille, capacite, py->enLivraison->numVille);
            }
            py = py->livraisonSuivante;
        }

	}

}

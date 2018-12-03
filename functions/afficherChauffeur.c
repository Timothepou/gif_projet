void afficherChauffeur(ptville pdebutVille){
	ptville px = pdebutVille->villeSuivante;
    ptlivraison py;

    while(px->villeSuivante != NULL)
    {
		py = px->listeLivraison->livraisonSuivante;
		printf("Dans la ville %d, chauffeur :\t\n",px->numVille);
		while(py->livraisonSuivante != NULL)
		{
			printf("\t\t\t\t%d\n", py->chauffeur);
			py = py->livraisonSuivante;
		}
        px = px->villeSuivante;
    }
}


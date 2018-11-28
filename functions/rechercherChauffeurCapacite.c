void rechercheChauffeurCapacite(ptville pdebutVille,int numVille){
	
	ptlivraison py;
	int capacite;
	ptville px = rechercherVille(pdebutVille, numVille);
	
	if(px == NULL){
		printf("[!!!] Cette ville n'existe pas !");
		return 0;
	}
	else
		px = pdebutVille->villeSuivante;
		py = px->listeLivraison->livraisonSuivante;
		printf("Quelle est la capacite de la livraion : ");
		scanf("%d", &capacite);
	
	while(py->livraisonSuivante != NULL){
		py = py->livraisonSuivante;
		if(py->capacite == capacite && py->disponible == 1){
		printf("Le chauffeur disponible est %d ayant une capacite %d dans la ville %d\n", py->chauffeur, capacite, numVille);
		}
	}
	
}

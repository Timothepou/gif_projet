int transfert(ptville pdebutVille, int numVilleA, int numVilleB){

	ptlivraison py,pw;

	ptlivraison ptAvanty=(ptlivraison)malloc(sizeof(tlivraison));
	int chauffeur;
	
	ptville px = rechercherVille(pdebutVille, numVilleA);
	
	if(px == NULL)
	{
		printf("[!!!] Cette ville n'existe pas !");
		return 0;
	}
	else
    {
		py = px->listeLivraison->livraisonSuivante;
		printf("Quelle est le numero du chauffeur  : ");
		scanf("%d", &chauffeur);

	   while(py->chauffeur != chauffeur)
        {   
            ptAvanty=py;
            py = py->livraisonSuivante;
		}
		ptAvanty->livraisonSuivante=py->livraisonSuivante;
    }
	
		
ptville pz = rechercherVille(pdebutVille, numVilleB);

	if(pz == NULL){
		printf("[!!!] Cette ville n'existe pas !");
		return 0;
	}
	else
    {
		pw = pz->listeLivraison->livraisonSuivante;
	   	while(pw->livraisonSuivante != NULL)
		{
	   		pw=pw->livraisonSuivante;
	   	}
	   	py->livraisonSuivante = pw->livraisonSuivante;
		pw->livraisonSuivante = py;
	  //py->livraisonSuivante=NULL;
	}

}

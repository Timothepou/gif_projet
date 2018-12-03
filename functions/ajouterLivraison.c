int ajouterLivraison(ptville pdebutVille, ptlivraison pdebutLivraisonPoubelle int numVille){

        ptlivraison py = (ptlivraison)malloc(sizeof(tlivraison)), px, plivraison = pdebutLivraisonPoubelle, pAvantlivraison;
        ptville ptest = rechercherVille(pdebutVille, numVille), pz;
        int postal, capacite;

        if(ptest == NULL){
            printf("Cette ville n'existe pas");
            return 0;
        }
        else
		{
			printf("Quelle est la capacite du camion : ");
            scanf("%d", &capacite);
            pz = ptest;
            px = pz->listeLivraison;
            printf("Ou va la livraison : ");
	        scanf("%d", &postal);
	        ptest = rechercherVille(pdebutVille, postal);
	        if(ptest == NULL)
			{
            	printf("Cette ville n'existe pas");
            	return 0;
	        }
	        else
			{
	            py->enLivraison = ptest;
	            system("cls");
	            printf("[OK] Livraison en direction de %d ajoutee avec succes !\n", py->enLivraison->numVille);
	        }
		}
            

        while(px->livraisonSuivante->livraisonSuivante != NULL)
        {
            px = px->livraisonSuivante; // on va à la fin de la liste livraison
        }
        while(plivraison->livraisonSuivante->livraisonSuivante != NULL) // on va à la fin de la liste livraison poubelle
        {
        	pAvantlivraison = plivraison;
        	plivraison = plivraison->livraisonSuivante;
		}
		if(plivraison != pdebutLivraisonPoubelle) // la liste livraison poubelle n'est pas vide 
		{
			pAvantlivraison->livraisonSuivante = plivraison->livraisonSuivante;
			
		}

        py->chauffeur = rechercheNbChauffeur(pdebutVille) + 1; // fonction qui renvoie le numÃ©ro du dernier chauffeur + 1.
        py->livraisonSuivante = px->livraisonSuivante;
        px->livraisonSuivante = py;
        py->capacite = capacite;
        py->disponible = 1;
        return 1;
}

int ajouterLivraison(ptville pdebutVille, ptlivraison pdebutLivraisonPoubelle, int numVille){

        ptlivraison px, plivraison = pdebutLivraisonPoubelle, pAvantlivraison;
        ptville ptest = rechercherVille(pdebutVille, numVille), pz;
        int postal, capacite;

        if(ptest == NULL){
            printf("[!!!] Cette ville n'existe pas !\n");
            return 0;
        }
        else
		{
			printf("[?] Quelle est la capacite du camion : ");
            scanf("%d", &capacite);
            pz = ptest;
            px = pz->listeLivraison;
            printf("[?] Ou va la livraison : ");
	        scanf("%d", &postal);
	        ptest = rechercherVille(pdebutVille, postal);
	        if(ptest == NULL)
			{
            	printf("[!!!] Cette ville n'existe pas !\n");
            	return 0;
	        }
	        else
			{
			    while(px->livraisonSuivante->livraisonSuivante != NULL){
                    px = px->livraisonSuivante; // on va à la fin de la liste livraison
                }
                while(plivraison->livraisonSuivante->livraisonSuivante != NULL){ // on va à la fin de la liste livraison poubelle
                    pAvantlivraison = plivraison;
                    plivraison = plivraison->livraisonSuivante;
                }
                if(plivraison != pdebutLivraisonPoubelle){ // la liste livraison poubelle n'est pas vide
                    pAvantlivraison->livraisonSuivante = plivraison->livraisonSuivante; // on enlève une livraison de la poubelle
                    plivraison->chauffeur = rechercheNbChauffeur(pdebutVille) + 1; // fonction qui renvoie le numéro du dernier chauffeur + 1.
                    plivraison->livraisonSuivante = px->livraisonSuivante;
                    px->livraisonSuivante = plivraison;
                    plivraison->capacite = capacite;
                    plivraison->disponible = 0;
                    plivraison->enLivraison = ptest;
                    system("cls");
                    printf("[OK] Livraison en direction de %d ajoutee avec succes !\n", plivraison->enLivraison->numVille);
                }
                else{ // la liste poubelle livraison est vide
                    ptlivraison py = (ptlivraison)malloc(sizeof(tlivraison));
                    py->chauffeur = rechercheNbChauffeur(pdebutVille) + 1; // fonction qui renvoie le numéro du dernier chauffeur + 1.
                    py->livraisonSuivante = px->livraisonSuivante;
                    px->livraisonSuivante = py;
                    py->capacite = capacite;
                    py->disponible = 0;
                    py->enLivraison = ptest;
                    system("cls");
                    printf("[OK] Livraison en direction de %d ajoutee avec succes !\n", py->enLivraison->numVille);
                }
	            return 1;
	        }
		}
}

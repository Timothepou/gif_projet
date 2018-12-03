int supprimerLivraison(ptville pdebutVille, ptville pdebutLivraisonPoubelle, int numVille)
{
	int presence = 0, numLivraison;
	ptville pville = rechercherVille(pdebutVille, numVille);
	ptlivraison pz = pdebutLivraisonPoubelle;
	if(pville == NULL){
		printf("[!!!] Cette ville n'existe pas !");
		return 0;
	}
	ptlivraison pAvantx = pville->listeLivraison;
	ptlivraison px = pville->listeLivraison->livraisonSuivante;

	afficherLivraison(pdebutVille, numVille);

	printf("Quelle livraison voulez-vous supprimer : ");
	scanf("%d", &numLivraison);

	while(px->livraisonSuivante != NULL) // On vérifie que la livraison à supprimer existe
    {
        if(px->chauffeur == numLivraison)
        {
            presence = 1;
            break;
        }
        px = px->livraisonSuivante;
    }

    px = pville->listeLivraison->livraisonSuivante;

    if(presence == 1)
    {
        while(px->chauffeur != numLivraison) // on trouve la livraison à supprimer
        {
            pAvantx = px; // 0 1 2 3
            px = px->livraisonSuivante; // 1 2 3 4
        }
        while(pz->livraisonSuivante->livraisonSuivante != NULL) // on va à la fin de la liste poubelle livraison
		{
			pz = pz->villeSuivante;
		}
        pAvantx->livraisonSuivante = px->livraisonSuivante;
        px->livraisonSuivante = pz->livraisonSuivante; // on ajoute la livraison supprimée à la poubelle
		pz->livraisonSuivante = px;

        printf("[OK] Suppression de la ville %d avec succes !\n", px->chauffeur);
        px = NULL; // le ptr px ne pointe nulle part
        return 1;
    }
    else
        printf("[!!!] La livraison %d n'existe pas !\n", numLivraison);
        return 0;
}

int supprimerVille(ptville pvilleDebut, ptville pdebutVillePoubelle, ptlivraison pdebutLivraisonPoubelle, int numeroVille){

    ptville px = pvilleDebut, pz = pdebutVillePoubelle;
    ptville pAvantx = (ptville)malloc(sizeof(tville));
    ptlivraison plivraison, pderniereLivraison, plivraisonPoubelle = pdebutLivraisonPoubelle;
    int presence = 0;

    while(px->villeSuivante!= NULL) // On vérifie que la ville à supprimer existe
    {
        if(px->numVille == numeroVille)
        {
            presence = 1;
            break;
        }
        px = px->villeSuivante;
    }

    px = pvilleDebut->villeSuivante;
    printf("[!!!] Voici la liste des livraisons d'autres villes qui passeront 'disponible'.");
    while(px->villeSuivante != NULL)
    {
        plivraison = px->listeLivraison->livraisonSuivante;
        while(plivraison->livraisonSuivante != NULL)
        {
            if(plivraison->enLivraison->numVille == numeroVille)
            {
                printf("\n[!!!]\t-Livraison %d dans la ville %d\n", plivraison->chauffeur, px->numVille);
            }
            plivraison = plivraison->livraisonSuivante;
        }
        px = px->villeSuivante;
    }
    printf("[?] Etes-vous sur de vouloir supprimer la ville (0/1) :");
    int choix;
    scanf("%d", &choix);
    if(choix == 1)
    {
        px = pvilleDebut->villeSuivante;
        while(px->villeSuivante != NULL)
        {
            printf("OK");
            plivraison = px->listeLivraison->livraisonSuivante;
            while(plivraison->livraisonSuivante != NULL)
            {
                if(plivraison->enLivraison->numVille == numeroVille)
                {
                    plivraison->disponible = 1;
                    plivraison->enLivraison = NULL;
                }
                plivraison = plivraison->livraisonSuivante;
                printf("DACO");
            }
            px = px->villeSuivante;
        }
    }
    else
    {
        printf("[!!!] Supression abandonnee !");
        return 0;
    }

    if(presence == 1)
    {
        while(px->numVille != numeroVille) // on trouve la ville à supprimer
        {
            pAvantx = px; // 0 1 2 3
            px = px->villeSuivante; // 1 2 3 4
        }
        pAvantx->villeSuivante = px->villeSuivante;
        px->villeSuivante->villePrecedente = pAvantx; // mettre en place un système de poubelle
		while(pz->villeSuivante->villeSuivante != NULL) // on va à la fin de la liste poubelle ville
		{
			pz = pz->villeSuivante;
		}
		while(plivraisonPoubelle->livraisonSuivante->livraisonSuivante != NULL) // on va à la fin de la liste livraison poubelle
        {
            plivraisonPoubelle = plivraisonPoubelle->livraisonSuivante;
        }
        pderniereLivraison = px->listeLivraison;
        while(pderniereLivraison->livraisonSuivante->livraisonSuivante != NULL)
        {
            pderniereLivraison = pderniereLivraison->livraisonSuivante;
        }
        pderniereLivraison->livraisonSuivante = plivraisonPoubelle->livraisonSuivante;
        plivraisonPoubelle->livraisonSuivante = px->listeLivraison->livraisonSuivante; // livraisons ajoutées à la poubelle

		px->villeSuivante = pz->villeSuivante;
		pz->villeSuivante = px; // ajout de la ville supprimée à la poubelle
		px->villePrecedente = pz;


        printf("[OK] Suppression de la ville %d avec succes !\n", px->numVille);
        px = NULL; // le ptr px ne pointe nulle part
    }
    else
        printf("[!!!] La ville %d n'existe pas !\n", numeroVille);

}

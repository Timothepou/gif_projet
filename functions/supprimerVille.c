int supprimerVille(ptville pdebutVille, ptville pdebutVillePoubelle, ptlivraison pdebutLivraisonPoubelle, int numeroVille){

    ptville px, py, pAvantx;
    ptlivraison plivraison, plivraisonPoubelle = pdebutLivraisonPoubelle;
    int presence = 0;

    px = rechercherVille(pdebutVille, numeroVille); // on v�rifie que la ville existe
    if(px == NULL)
    {
        printf("[!!!] Cette ville n'existe pas !\n");
        return 0;
    }

    py = pdebutVille->villeSuivante;
    printf("[!!!] Voici la liste des livraisons d'autres villes qui passeront 'disponible'.\n");
    while(py->villeSuivante != NULL)
    {
        plivraison = py->listeLivraison->livraisonSuivante;
        while(plivraison->livraisonSuivante != NULL && py->numVille != numeroVille)
        {
            if(plivraison->enLivraison != NULL)
            {
                if(plivraison->enLivraison->numVille == numeroVille)
                {
                    printf("[!!!]\t-Livraison %d dans la ville %d\n", plivraison->chauffeur, py->numVille);
                }
            }
            plivraison = plivraison->livraisonSuivante;
        }
        py = py->villeSuivante;
    } // on finit d'afficher les livraisons qui d�pendent de la ville � supprimer
    printf("[?] Etes-vous sur de vouloir supprimer la ville (0/1) :");
    int choix;
    scanf("%d", &choix);
    if(choix == 1) // l'utilisateur souhaite supprimer cette ville
    {
        py = pdebutVille->villeSuivante;
        while(py->villeSuivante != NULL)
        {
            plivraison = py->listeLivraison->livraisonSuivante;
            while(plivraison->livraisonSuivante != NULL)
            {
                if(plivraison->enLivraison != NULL)
                {
                    if(plivraison->enLivraison->numVille == numeroVille)
                    {
                        plivraison->disponible = 1;
                        plivraison->enLivraison = NULL;
                    }
                }
                plivraison = plivraison->livraisonSuivante;
            }
            py = py->villeSuivante;
        } // on finit de modifier les livraisons qui d�pendent de la ville � supprimer

        pAvantx = px->villePrecedente; // On supprime maintenant la ville et ses livraisons
        pAvantx->villeSuivante = px->villeSuivante;
        px->villeSuivante->villePrecedente = pAvantx; // la ville px est supprim�e

        py = pdebutVillePoubelle;
        while(py->villeSuivante->villeSuivante != NULL){
            py = py->villeSuivante;} // on va � la fin de la liste ville poubelle

        px->villeSuivante = py->villeSuivante;
        px->villePrecedente = py;
        py->villeSuivante->villePrecedente = px;
        py->villeSuivante = px; // px est ajout�e � la poubelle

        ptlivraison pAvantfin = px->listeLivraison, pfinLivraisonPoubelle = pdebutLivraisonPoubelle, pAvantfinLivraisonPoubelle;
        while(pAvantfin->livraisonSuivante->livraisonSuivante != NULL)
        {
            pAvantfin = pAvantfin->livraisonSuivante;
        }
        while(pfinLivraisonPoubelle->livraisonSuivante != NULL)
        {
            pAvantfinLivraisonPoubelle = pfinLivraisonPoubelle;
            pfinLivraisonPoubelle = pfinLivraisonPoubelle->livraisonSuivante;
        }
        // on le bidon de fin de livraison poubelle et la derni�re livraison de px et la derni�re livraison de poubelle
        pAvantfinLivraisonPoubelle->livraisonSuivante = px->listeLivraison->livraisonSuivante;
        printf("[!!!] La ville a bien ete supprimee !\n\n");
        pAvantfin->livraisonSuivante = pfinLivraisonPoubelle;
    }
    else{
        printf("[!!!] Supression abandonnee !\n");
        return 0;}
}

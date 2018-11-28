void ajouterLivraison(ptville pdebutVille, int numVille){

        ptlivraison py = (ptlivraison)malloc(sizeof(tlivraison)), px;
        ptville ptest = rechercherVille(pdebutVille, numVille), pz;
        int postal, capacite;

        if(ptest == NULL){
            printf("Cette ville n'existe pas");
            return 0;
        }
        else
            printf("Quelle est la capacite du camion : ");
            scanf("%d", &capacite);
            pz = ptest;
            px = pz->listeLivraison;

        while(px->livraisonSuivante->livraisonSuivante != NULL)
        {
            px = px->livraisonSuivante;
        }

        printf("Où va la livraison : ");
        scanf("%d", &postal);
        ptest = rechercherVille(pdebutVille, postal);
        if(ptest == NULL){
            printf("Cette ville n'existe pas");
            return 0;
        }
        else{
            py->enLivraison = ptest;
            printf("[OK] Livraison en direction de %d ajoutée avec succès !", py->enLivraison->numVille);
        }

        py->chauffeur = rechercheNbChauffeur(pdebutVille) + 1; // fonction qui renvoie le numéro du dernier chauffeur + 1.
        py->livraisonSuivante = px->livraisonSuivante;
        px->livraisonSuivante = py;
        py->capacite = capacite;
        py->disponible = 1;
}

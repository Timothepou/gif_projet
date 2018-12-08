int modifierLivraison(ptville pdebutVille, int numVille)
{
    ptville pville = rechercherVille(pdebutVille, numVille), py;
    ptlivraison px;
    int numLivraison, newnumVille, newCapacite, disponible, choix;

    if(pville == NULL)
    {
        printf("[!!!] Cette ville n'existe pas !\n");
        return 0;
    }
    else
    {
        afficherLivraison(pdebutVille, numVille);
        printf("[?] Quelle est la livraison a modifier : ");
        scanf("%d", &numLivraison);
        px = pville->listeLivraison->livraisonSuivante;
        while(px->chauffeur != numLivraison && px->livraisonSuivante != NULL)
        {
            px = px->livraisonSuivante;
        }
        if(px->livraisonSuivante == NULL)
        {
        	printf("[!!!] Cette livraison n'existe pas !\n");
        	return 0;
		}
        while(choix != 4)
        {
            printf("[1] - Modifier la disponibilite\n"
               "[2] - Modifier la capacite\n"
               "[3] - Modifier la destination\n"
               "[4] - Quitter\n"
               "Votre choix : ");
            scanf("%d", &choix);

            switch(choix)
            {
                case(1):
                    printf("[INFO] Disponibilite de la livraison %d : %d\n", px->chauffeur, px->disponible);
                    printf("[?] Modifier la disponibilite : ");
                    scanf("%d", &disponible);
                    if(disponible == 0 || disponible == 1)
                        px->disponible = disponible;
                        if(disponible == 1){
                            px->enLivraison = NULL;
                            printf("[!!!] Cette ville est maintenant disponible, elle ne va donc nul part.\n");
                        }
                    else
                        printf("[!!!] Veuillez entrer un chiffre valide (0 ou 1)\n");
                    break;
                case(2):
                    printf("Capacite de la livraison %d : %d\n", px->chauffeur, px->capacite);
                    printf("[?] Modifier la capacite : ");
                    scanf("%d", &newCapacite);
                    if(newCapacite > 0)
                        px->capacite = newCapacite;
                    else
                        printf("[!!!] Veuillez entrer un chiffre valide ( >0 )\n");
                    break;
                case(3):
                    if(px->enLivraison == NULL)
                        printf("[INFO] Cette livraison n'a aucune destination\n");
                    else
                        printf("[INFO] Destination de la livraison %d : %d\n", px->chauffeur, px->enLivraison->numVille);
                    printf("[?] Modifier la destination : ");
                    scanf("%d", &newnumVille);
                    py = rechercherVille(pdebutVille, newnumVille);
                    if(py == NULL){
                        printf("[!!!]Cette ville n'existe pas !\n");
                        return 0;
                    }
                    else{
                        px->enLivraison = py;
                        px->disponible = 0;
                    }
                    break;
                case(4):
                    return 1;
                    break;
            }
        }
    }
}

void supprimerVille(ptville pvilleDebut, int numeroVille){

    ptville px = pvilleDebut;
    ptville pAvantx = (ptville)malloc(sizeof(tville));
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

    px = pvilleDebut;

    if(presence == 1)
    {
        while(px->numVille != numeroVille) // on trouve la ville à supprimer
        {
            pAvantx = px; // 0 1 2 3
            px = px->villeSuivante; // 1 2 3 4
        }
        pAvantx->villeSuivante = px->villeSuivante;
        px->villeSuivante->villePrecedente = pAvantx; // mettre en place un système de poubelle

        printf("[OK] Suppression de la ville %d avec succès !\n", px->numVille);
        px = NULL; // le ptr px ne pointe nulle part
    }
    else
        printf("[!!!] La ville %d n'existe pas !\n", numeroVille);

}

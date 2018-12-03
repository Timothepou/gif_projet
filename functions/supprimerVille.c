void supprimerVille(ptville pvilleDebut, ptville pdebutVillePoubelle, int numeroVille){

    ptville px = pvilleDebut, pz = pdebutVillePoubelle;
    ptville pAvantx = (ptville)malloc(sizeof(tville));
    int presence = 0;

    while(px->villeSuivante!= NULL) // On v�rifie que la ville � supprimer existe
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
        while(px->numVille != numeroVille) // on trouve la ville � supprimer
        {
            pAvantx = px; // 0 1 2 3
            px = px->villeSuivante; // 1 2 3 4
        }
        pAvantx->villeSuivante = px->villeSuivante;
        px->villeSuivante->villePrecedente = pAvantx; // mettre en place un syst�me de poubelle
		while(pz->villeSuivante->villeSuivante != NULL) // on va � la fin de la liste poubelle ville
		{
			pz = pz->villeSuivante;
		}
		px->villeSuivante = pz->villeSuivante;
		pz->villeSuivante = px; // ajout de la ville supprim�e � la poubelle
		px->villePrecedente = pz;

        printf("[OK] Suppression de la ville %d avec succes !\n", px->numVille);
        px = NULL; // le ptr px ne pointe nulle part
    }
    else
        printf("[!!!] La ville %d n'existe pas !\n", numeroVille);

}

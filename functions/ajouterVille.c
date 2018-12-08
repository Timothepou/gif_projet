int ajouterVille(ptville pdebutVille, ptville pdebutVillePoubelle, int postal){
	ptville px = pdebutVille, pz = pdebutVillePoubelle, pAvantz;

	while(px->villeSuivante->villeSuivante != NULL)
	{
		px = px->villeSuivante; // on trouve la dernière ville
		if(px->numVille == postal)
        {
            printf("[!!!] Cette ville existe deja !\n");
            return 0;
        }
	}
	while(pz->villeSuivante->villeSuivante != NULL) // on va à la fin de la liste ville poubelle
	{
		pAvantz = pz;
		pz = pz->villeSuivante;
	}

	if(pz != pdebutVillePoubelle) // donc la liste poubelle de ville n'est pas vide et on utilise la dernière ville de la liste poubelle ville
	{
		pAvantz->villeSuivante = pz->villeSuivante; // on retire la ville pz de la poubelle
		pz->numVille = postal;
		pz->villeSuivante = px->villeSuivante;
		pz->villePrecedente = px;
		px->villeSuivante = pz;

		ptlivraison livraisonDebut = (ptlivraison)malloc(sizeof(tlivraison)); /* Déclaration de la liste des livraisons pour cette ville */
		ptlivraison livraisonFin = (ptlivraison)malloc(sizeof(tlivraison));
		pz->listeLivraison = livraisonDebut;
		livraisonFin->livraisonSuivante = NULL;
		livraisonDebut->livraisonSuivante = livraisonFin;
		livraisonDebut->chauffeur = 0;
		livraisonFin->chauffeur = 0;
		printf("[OK] Ville %d ajoutee avec succes !\n", pz->numVille);
	}
	else // sinon on crée un ptr (nouvelle ville)
	{
		ptville py = (ptville)malloc(sizeof(tville));
		py->numVille = postal;
		py->villeSuivante = px->villeSuivante;
		py->villePrecedente = px;
		px->villeSuivante = py;

		ptlivraison livraisonDebut = (ptlivraison)malloc(sizeof(tlivraison)); /* Déclaration de la liste des livraisons pour cette ville */
		ptlivraison livraisonFin = (ptlivraison)malloc(sizeof(tlivraison));
		py->listeLivraison = livraisonDebut;
		livraisonFin->livraisonSuivante = NULL;
		livraisonDebut->livraisonSuivante = livraisonFin;
		livraisonDebut->chauffeur = 0;
		livraisonFin->chauffeur = 0;
		printf("[OK] Ville %d ajoutee avec succes !\n", py->numVille);
	}
	return 1;
}

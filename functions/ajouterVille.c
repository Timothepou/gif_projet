void ajouterVille(ptville pdebut, int postal){
	ptville py = (ptville)malloc(sizeof(tville)), px = pdebut;

	while(px->villeSuivante->villeSuivante != NULL)
	{
		px = px->villeSuivante; // on trouve la dernière ville
	}

	/* Ajout de py à la fin de la liste ville */
	py->numVille = postal;
	py->villeSuivante = px->villeSuivante;
	py->villePrecedente = px;
	px->villeSuivante = py;

	/* Déclaration de la liste des livraisons pour cette ville */

    ptlivraison livraisonDebut = (ptlivraison)malloc(sizeof(tlivraison));
	ptlivraison livraisonFin = (ptlivraison)malloc(sizeof(tlivraison));
	py->listeLivraison = livraisonDebut;
	livraisonFin->livraisonSuivante = NULL;
	livraisonDebut->livraisonSuivante = livraisonFin;
	livraisonDebut->chauffeur = 0;
	livraisonFin->chauffeur = 0;

	printf("[OK] Ville %d ajoutée avec succès !", py->numVille);
}

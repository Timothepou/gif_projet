void ajouterVille(ptville pdebut){
	ptville py = (ptville)malloc(sizeof(tville));
	ptville px = pdebut;

	while(px->villeSuivante->villeSuivante != NULL)
	{
		px = px->villeSuivante; // on trouve la dernière ville
	}

	/* Ajout de py à la fin de la liste ville */
	py->numVille = px->numVille + 1;
	py->villeSuivante = px->villeSuivante;
	py->villePrecedente = px;
	px->villeSuivante = py;

	/* Déclaration de la liste des livraisons pour cette ville */
	ptlivraison livraisonFin = NULL;

	ptlivraison livraisonDebut = (ptlivraison)malloc(sizeof(tlivraison));
	livraisonDebut->livraisonSuivante = livraisonFin;

	py->listeLivraison = livraisonDebut;

	printf("[OK] Ville %d ajoutée avec succès !", py->numVille);
}

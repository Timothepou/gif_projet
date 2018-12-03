void afficherLivraison(ptville pdebutVille, int numVille){

    ptville px = rechercherVille(pdebutVille, numVille);
    ptlivraison plivraison = px->listeLivraison;

    while(plivraison->livraisonSuivante->livraisonSuivante != NULL)
    {
        plivraison = plivraison->livraisonSuivante;
        printf("[OK] Livraison n°%d\n", plivraison->chauffeur);
    }
}

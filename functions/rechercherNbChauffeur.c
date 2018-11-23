int rechercheNbChauffeur(ptville pdebutVille){

    int numChauffeur = 0;
    ptville px = pdebutVille->villeSuivante;
    ptlivraison plivraison;

    while(px->villeSuivante != NULL)
    {
        plivraison = px->listeLivraison->livraisonSuivante;
        while(plivraison->livraisonSuivante != NULL)
        {
            if(plivraison->chauffeur > numChauffeur){
                numChauffeur = plivraison->chauffeur;
            }
            plivraison = plivraison->livraisonSuivante;
        }
        px = px->villeSuivante;
    }
    return numChauffeur;
}

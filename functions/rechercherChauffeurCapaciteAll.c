void rechercheChauffeurCapaciteAll(ptville pdebutVille, int capacite)
{
    ptville px = pdebutVille->villeSuivante;
    ptlivraison py;

    while(px->villeSuivante != NULL)
    {
        py = px->listeLivraison->livraisonSuivante;
        while(py->livraisonSuivante != NULL)
        {
            if(py->capacite == capacite && py->disponible == 1)
                printf("Le chauffeur %d est disponible dans la ville %d et a une capacite %d\n", py->chauffeur, px->numVille, py->capacite);
            py = py->livraisonSuivante;
        }
        px = px->villeSuivante;
    }
}

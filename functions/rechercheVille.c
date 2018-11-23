ptville rechercherVille(ptville pdebutVille, int numVille){

    ptville px = pdebutVille->villeSuivante;

    while(px->villeSuivante != NULL)
    {
        if(px->numVille == numVille)
            return px;
        else
            px = px->villeSuivante;
    }
    return NULL;
}

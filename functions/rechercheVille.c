ptville rechercherVille(ptville pdebut, int numVille){

    ptville px = pdebut->villeSuivante;
    int presence = 0;

    while(px->numVille != numVille)
    {
        px = px->villeSuivante;
        if(px->numVille == numVille)
            presence = 1;
    }
    if(presence == 1){return px;}
    else{return 0;}
}

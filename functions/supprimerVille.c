#include "../structures.c"

void supprimerVille(ptville pvilleDebut, int numVille){

    ptville px = pvilleDebut->villeSuivante;
    ptville pAvantx;

    while(px->numVille != numVille)
    {
        pAvantx = px;
        px = px->villeSuivante; // on trouve la ville à supprimer
    }

    px->villeSuivante->villePrecedente = pAvantx;
    pAvantx->villeSuivante = px->villeSuivante;
    px = NULL;
    
    printf("[OK] Suppression de la ville %d avec succès !", px->numVille);
}

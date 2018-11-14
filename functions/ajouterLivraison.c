#include "../structures.c"
#include "rechercheVille.c"

void ajouterLivraison(ptlivraison plivraisonDebut, int numVille, int chauffeur, int capacite, int disponible){

        ptlivraison py=(ptlivraison)malloc(sizeof(tlivraison);
        ptlivraison px=plivraisonDebut;
        ptville ptest=(ptville)malloc(sizeof(tville);
        int postal;

        ptville pz = rechercheVille(numVille);
        ptest = rechercheVille(postal);
        if(ptest == NULL)
        {
            printf("Cette ville n'existe pas");
        }
        else
        {
            pz = ptest;
        }

        while(px->livraisonSuivante->livraisonSuivante != NULL)
        {
            px = px->livraisonSuivante;
        }

        py->livraisonSuivante = px->livraisonSuivante;
        px->livraisonSuivante = py;
        py->chauffeur = chauffeur;
        py->capacite = capacite;
        py->disponible = disponible;

        if(py->disponible == 0)
        {
            printf("Où va la livraison : ");
            scanf("%d", &postal);
            ptest = rechercheVille(postal);
            if(ptest == NULL)
            {
                printf("Cette ville n'existe pas");
            }
            else
            {
                py->enLivraison = ptest;
            }
        }

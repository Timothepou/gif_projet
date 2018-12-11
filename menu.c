// POUYET Timothé & LE ROY Tanguy
// PEI 2 /-- 2018/2019 --/
// GIF 1301

#include "structures.c"
#include "functions/rechercheVille.c"
#include "functions/ajouterVille.c"
#include "functions/modifierVille.c"
#include "functions/supprimerVille.c"
#include "functions/ajouterLivraison.c"
#include "functions/rechercherNbChauffeur.c"
#include "functions/afficherLivraison.c"
#include "functions/supprimerLivraison.c"
#include "functions/rechercherChauffeurCapacite.c"
#include "functions/rechercherChauffeurCapaciteAll.c"
#include "functions/modifierLivraison.c"
#include "functions/transfert.c"

void afficherPoubelleLivraison(ptlivraison pdebutLivraisonPoubelle){

    ptlivraison px = pdebutLivraisonPoubelle->livraisonSuivante;

    while(px->livraisonSuivante != NULL)
    {
        printf("[OK] Livraison %d\n", px->chauffeur);
        px = px->livraisonSuivante;
    }
}

void afficherVille(ptville pdebutVille){

    ptville px = pdebutVille;

    while(px->villeSuivante->villeSuivante != NULL)
    {
        px = px->villeSuivante;
        printf("[OK] Ville %d\n", px->numVille);
    }
}

int main(){

  system("color 3F  ");
  system("cls");

  ptville pdebutVille = (ptville)malloc(sizeof(tville));
  ptville pfinVille = (ptville)malloc(sizeof(tville));
  pdebutVille->numVille = 0;
  pfinVille->numVille = 0;
  pdebutVille->villeSuivante = pfinVille;
  pdebutVille->villePrecedente = NULL;
  pfinVille->villePrecedente = pdebutVille;
  pfinVille->villeSuivante = NULL;

  ptville pdebutVillePoubelle = (ptville)malloc(sizeof(tville));
  ptville pfinVillePoubelle= (ptville)malloc(sizeof(tville));
  pdebutVillePoubelle->villeSuivante = pfinVillePoubelle;
  pdebutVillePoubelle->villePrecedente = NULL;
  pfinVillePoubelle->villePrecedente = pdebutVillePoubelle;
  pfinVillePoubelle->villeSuivante = NULL;

  ptlivraison pdebutLivraisonPoubelle = (ptlivraison)malloc(sizeof(tlivraison));
  ptlivraison pfinLivraisonPoubelle = (ptlivraison)malloc(sizeof(tlivraison));
  pdebutLivraisonPoubelle->livraisonSuivante = pfinLivraisonPoubelle;
  pfinLivraisonPoubelle->livraisonSuivante = NULL;


  int numVille, numVilleA, numVilleB, newnumVille, nbChauffeur, postal, capacite, a = -1;

  while(a != 0)
  {
    printf("[1]- Ajouter une ville. \n[2]- Modifier une ville. \n[3]- Supprimer une ville. \n[4]- Ajouter une livraison dans une ville. \n[5]- Supprimer une livrasion dans une ville. \n[6]- Modifier une livraison dans une ville. \n[7]- Rechercher un chauffeur disponible ayant une capacite N dans une ville V. \n[8]- Rechercher un chauffeur disponible ayant une capacite N dans toutes les villes. \n[9]- Transferer un chauffeur X d'une ville A a une ville B. \n[0]- Quitter. \n\nChoissisez l'operation a effectuer: ");
    scanf("%d", &a);
    switch(a)
    {
      case 1:
        system("cls");
        printf("[?] Quel est le code postal de la ville : ");
        scanf("%d", &postal);
        ajouterVille(pdebutVille, pdebutVillePoubelle, postal);
        printf("\n");
        break;

      case 2:
        system("cls");
        afficherVille(pdebutVille);
        printf("[?] Quelle ville voulez-vous modifier : ");
        scanf("%d", &numVille);
        modifierVille(pdebutVille, numVille);
        printf("\n");
        break;

      case 3:
        system("cls");
        afficherVille(pdebutVille);
        printf("[?] Quelle ville voulez-vous supprimez : ");
        scanf("%d", &numVille);
        supprimerVille(pdebutVille, pdebutVillePoubelle, pdebutLivraisonPoubelle, numVille);
        printf("\n");
        break;

      case 4:
        system("cls");
        afficherVille(pdebutVille);
        printf("[?] Dans quelle ville ajouter la livraison : ");
        scanf("%d", &numVille);
        ajouterLivraison(pdebutVille, pdebutLivraisonPoubelle, numVille);
        printf("\n");
        break;

      case 5:
        system("cls");
        afficherVille(pdebutVille);
      	printf("[?] Dans quelle ville se trouve la livraison a supprimer : ");
      	scanf("%d", &numVille);
      	supprimerLivraison(pdebutVille, pdebutLivraisonPoubelle, numVille);
      	printf("\n");
        break;

      case 6:
        system("cls");
        afficherVille(pdebutVille);
        printf("[?] Dans quelle ville se trouve la livraison : ");
        scanf("%d", &numVille);
        modifierLivraison(pdebutVille, numVille);
        printf("\n");
        break;

      case 7:
        system("cls");
        afficherVille(pdebutVille);
      	printf("[?] Dans quelle ville rechercher une livraison: ");
      	scanf("%d", &numVille);
      	rechercheChauffeurCapacite(pdebutVille, numVille);
      	printf("\n");
        break;

      case 8:
        system("cls");
        printf("[?] Capacite de la livraison : ");
      	scanf("%d", &capacite);
      	rechercheChauffeurCapaciteAll(pdebutVille, capacite);
      	printf("\n");
        break;

      case 9:
        system("cls");
        afficherVille(pdebutVille);
        printf("[?] Numero de la ville A : ");
        scanf("%d", &numVilleA);
        printf("[?] Numero de la ville B : ");
        scanf("%d", &numVilleB);
        transfert(pdebutVille, numVilleA, numVilleB);
        printf("\n");
        break;

      case 0:
        system("cls");
        printf("[***] FERMETURE DU PROGRAMME [***]");
        return 0;

      default:
          system("cls");
          printf("[!!!] Veuillez entrer un chiffre entre 0 et 9\n");
     }
  }
}

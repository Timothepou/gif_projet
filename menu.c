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

void afficherVille(ptville pdebutVille){

    ptville px = pdebutVille;

    while(px->villeSuivante->villeSuivante != NULL)
    {
        px = px->villeSuivante;
        printf("[OK] Ville n°%d\n", px->numVille);
    }
}

int main(){
	
  system("color 2A");

  char T[1];
  int a = 0;
  printf("\n[1]- Ajouter une ville. \n[2]- Modifier une ville. \n[3]- Supprimer une ville. \n[4]- Ajouter une livraison dans une ville. \n[5]- Supprimer une livrasion dans une ville. \n[6]- Modifier une livraison dans une ville. \n[7]- Rechercher un chauffeur disponible ayant une capacite N dans une ville V. \n[8]- Rechercher un chauffeur disponible ayant une capacite N dans toutes les villes. \n[9]- Transférer un chauffeur X dune ville A a  une ville B. \n[0]- Quitter. \n\nChoissisez l'operation a effectuer: ");
  scanf("%c", &T[0]);
  system("cls");
  if( ((int)T[0] >= 48) && ((int)T[0] <= 57) )
    printf("");
  else
    printf("[!!!] Veuillez entrer un chiffre entre 0 et 9\n");

  a = (int)T[0] - 48;

  if(a <= 0 || a > 9){
        printf("[***] Fermeture du programme."); // TODO: Gérer les erreurs, ex: scanf un caractère
        return 0;
  }

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
  

  int numVille, newnumVille, nbChauffeur, postal, capacite;

  while(a != 0)
  {
    switch(a)
    {
      case 1:
        printf("[?] Quel est le code postal de la ville : ");
        scanf("%d", &postal);
        ajouterVille(pdebutVille, pdebutVillePoubelle, postal);
        break;

      case 2:
        printf("[?] Quelle ville voulez-vous modifier : ");
        scanf("%d", &numVille);
        modifierVille(pdebutVille, numVille);
        break;

      case 3:
        printf("[?] Quelle ville voulez-vous supprimez : ");
        scanf("%d", &numVille);
        supprimerVille(pdebutVille, pdebutVillePoubelle, numVille);
        break;

      case 4:
        printf("[?] Dans quelle ville ajouter la livraison : ");
        scanf("%d", &numVille);
        ajouterLivraison(pdebutVille, numVille);
        break;

      case 5:
      	printf("[?] Dans quelle ville se trouve la livraison à supprimer : ");
      	scanf("%d", &numVille);
      	supprimerLivraison(pdebutVille, numVille);
        break;

      case 6:
        printf("[?] Dans quelle ville se trouve la livraison : ");
        scanf("%d", &numVille);
        modifierLivraison(pdebutVille, numVille);
        break;

      case 7:
      	printf("[?] Dans quelle ville rechercher une livraison: ");
      	scanf("%d", &numVille);
      	rechercheChauffeurCapacite(pdebutVille, numVille);
        break;

      case 8:
        printf("[?] Capacite de la livraison : ");
      	scanf("%d", &capacite);
      	rechercheChauffeurCapaciteAll(pdebutVille, capacite);
        break;

      case 9:
        afficherVille(pdebutVillePoubelle);
        break;
     }

     printf("\n[1]- Ajouter une ville. \n[2]- Modifier une ville. \n[3]- Supprimer une ville. \n[4]- Ajouter une livraison dans une ville. \n[5]- Supprimer une livrasion dans une ville. \n[6]- Modifier une livraison dans une ville. \n[7]- Rechercher un chauffeur disponible ayant une capacite N dans une ville V. \n[8]- Rechercher un chauffeur disponible ayant une capacite N dans toutes les villes. \n[9]- Transférer un chauffeur X dune ville A Ã  une ville B. \n[0]- Quitter. \n\nChoissisez l'operation a effectuer: ");
     scanf("%d", &a);
     system("cls");
     if(a <= 0 || a > 9){
        printf("[***] Fermeture du programme.");
        return 0;
     }
  }
}

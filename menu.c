#include "structures.c"
#include "functions/ajouterVille.c"
#include "functions/supprimerVille.c"

void afficherVille(ptville pdebutVille){

    ptville px = pdebutVille;

    while(px->villeSuivante->villeSuivante != NULL)
    {
        px = px->villeSuivante;
        printf("[OK] Ville n°%d\n", px->numVille);
    }
}

int main(){

  char T[1];
  int a = 0;
  printf("[1]- Ajouter une ville. \n"
         "[2]- Modifier une ville. \n"
         "[3]- Supprimer une ville. \n"
         "[4]- Ajouter une livraison dans une ville. \n"
         "[5]- Supprimer une livrasion dans une ville. \n"
         "[6]- Modifier une livraison dans une ville. \n"
         "[7]- Rechercher un chauffeur disponible ayant une capacité N dans une ville V. \n"
         "[8]- Rechercher un chauffeur disponible ayant une capacité N dans toutes les villes. \n"
         "[9]- Afficher les villes. \n"
         "[0]- Quitter. \n\n"
         "Choissisez l'opération à effectuer: ");

  scanf("%c", &T[0]);
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
  int numVille;
  int postal;



  while(a != 0)
  {
    switch(a)
    {
      case 1:
        printf("Quel est le code postal de la ville : ");
        scanf("%d", &postal);
        ajouterVille(pdebutVille, postal);
        break;

      case 2:
      printf("[OK] Test : Succes");
        break;

      case 3:
        printf("[?] Quelle ville voulez-vous supprimez : ");
        scanf("%d", &numVille);
        supprimerVille(pdebutVille, numVille);
        break;

      case 4:
        break;

      case 5:
        break;

      case 6:
        break;

      case 7:
        break;

      case 8:
        break;

      case 9:
        afficherVille(pdebutVille);
        break;
     }

     printf("\n[1]- Ajouter une ville. \n"
            "[2]- Modifier une ville. \n"
            "[3]- Supprimer une ville. \n"
            "[4]- Ajouter une livraison dans une ville. \n"
            "[5]- Supprimer une livrasion dans une ville. \n"
            "[6]- Modifier une livraison dans une ville. \n"
            "[7]- Rechercher un chauffeur disponible ayant une capacité N dans une ville V. \n"
            "[8]- Rechercher un chauffeur disponible ayant une capacité N dans toutes les villes. \n"
            "[9]- Transférer un chauffeur X dune ville A à une ville B. \n"
            "[0]- Quitter. \n\n"
            "Choissisez l'opération à effectuer: ");
     scanf("%d", &a);
     if(a <= 0 || a > 9){
        printf("[***] Fermeture du programme.");
        return 0;
     }
  }
}

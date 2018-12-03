#include <stdlib.h>
#include <stdio.h>
#include <dos.h>

typedef struct livraison tlivraison;
typedef struct ville tville;

typedef struct ville{
	int numVille;
	struct ville *villeSuivante;
	struct ville *villePrecedente;
	tlivraison *listeLivraison;
}tville;

typedef struct livraison{
	int chauffeur;
	int capacite;
	int disponible;
	struct livraison *livraisonSuivante;
	tville *enLivraison;
}tlivraison;

typedef tville *ptville;
typedef tlivraison *ptlivraison;

#include "../structures.cpp"
void rechercheChauffeur(ptville ptdebutVille,int numeroVille,int capacite){
	ptville px=ptdebutVille->villeSuivante;
	ptlivraison py;
	
	while(px->numVille!=numeroVille){
		px=px->villeSuivante;
	}
	
	if(px->numVille==numeroVille){
	   while(py->capacite!=capacite || py->disponible==0 ){
	   		py=py->livraisonSuivante;
	   }
	   if(py->capacite==capacite && py->disponible==1){
	   		printf("Le chauffeur disponible est %d ayant une capacite %d dans la ville %d",py->chauffeur,capacite,numeroVille);
	   }
	}
}

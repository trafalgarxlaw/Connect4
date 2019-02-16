#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *Verification du choix de la colonne entree.
 *
 * Si la colonne choisi nest pas entre 0 et 7, la methode
 * affiche un message derreur jusqua temps que la colonne sois
 * valide.
 *
 * @param choixcol le choix de la colonne entree
 * @return le choixcolvalide
 */
int verifiercol(int choixcol){
while(choixcol<0||choixcol>7){
fprintf(stderr,"Error: action should be an integer between `1` and `7`.\n");
scanf("%d",&choixcol);// on demande  lutilisateur dentree une action valide
}
return choixcol;
}

/**
 * Verifie si la colonne choisi est pleine
 *
 * Verifie dans le tableau de jeu si la colonne choisi par 
 * le joueur est pleine. Si cest le cas, un message derreur
 * est affichee.
 *
 * @param tableau[][9] Le tableau de jeu
 * @param choixcol    la colonne ou le joueur veut entree la piece
 * @return choixcol   le numero de colonne entree valide 
 */
int verifiercolonne(char tableau[][9],int  choixcol){
while(tableau[1][choixcol]=='X'||tableau[1][choixcol]=='O'){
fprintf(stderr,"Error: the column `%d` is full.\n",choixcol);// message derreur
scanf("%d",&choixcol);//on demande une nouvelle colonne
}
return choixcol;

}

/**
 * Modifie le tableau selon les pieces de jeu entree.
 *
 * Place la piece de jeu 'X' ou 'O', selon le tour du
 * joueur, dans le tableau de jeu et retourne le tableau modifie.
 *
 * @param tableau[][9] le tableau a modifier
 * @param choixcol     le numero de colonne ou la piece est entree
 * @param tourdujoueur le tour du joueur actuel
 * @return tableau[][9]le tableau apres la modification
 */
void modifiertableau(char tableau[][9],int choixcol,int tourdujoueur){

//placer la piece a la colonne demandee

//verifier a partir de la base du tableau si les cases a la colonne choisi sont utilisee
	int ligne=6;// initialise au pied du tableau de jeu
	while((tableau[ligne][choixcol]=='X'||tableau[ligne][choixcol]=='O')){
		ligne--;// on incremente la ligne ou on insere la piece
	}

//si cest le tour du joueur1
if(tourdujoueur==1){
tableau[ligne][choixcol]='X';
}//si cest le tour du joueur2
else if(tourdujoueur==2){
  tableau[ligne][choixcol]='O';
}
}

/**
 *Methode qui verifie si lutilisateur entre autre chose que la col
 */

/**
 * Tour suivant
 *
 * Deplace le tour courant au suivant.
 *
 * @param tourdujoueur le tour actuel du joueur
 * @return tourdujoueur le tour suivant
 */
int toursuivant(int tourdujoueur){
 
	if(tourdujoueur==1){
            tourdujoueur=2;
        }else if(tourdujoueur==2){
           tourdujoueur=1;}
     
	return tourdujoueur;
}

/**
 * Affiche le tableau
 * 
 * Affiche toutes la table de jeu avec ses pieces.
 *
 * @param tableau[][9] le tableau de jeu
 */
void AfficherTab(char tableau[][9]){//format pour param tab 2D
 //on agit sur le tableau par ladresse donnee en param
 
 //variables pour parcourir le tableau de jeu
  int i=0;
  int j=0;
  
  // Parcourir chaque cases pour afficher
  for(i=0;i<7;i++){
 
    for(j=0;j<9;j++){
   printf("%c",tableau[i][j]);
   printf(" ");
    }
    printf("\n");//retour a la ligne
  }
printf("-----------------\n");
}

/**
 * Verification de letat de la partie en cour
 *
 * Verifie dans le tableau de jeu sil y a un gagnat.
 * Si un des joueurs place 4 pieces consecutive horizontalement,
 * verticalement ou en diagonale dans le tableau, il gagne.
 * Sil y a un gagnat, la methode returne la valeur 1 si cest
 * le joueur X, la valeur 2 si cest le jouer O.
 *
 * @param tableau[][9] le tableau de jeu
 * @return partiegagne le numero du joueur gagnant
 */
int verifierpartie(char tableau[][9]){

int i=0;
int j;
int z;
int ligne=6;
int colonne=1;
int partiegagne=0;//


//******verification verticale dans chaque colonnes du tableau de jeu******
while(colonne<8){
   while(i<3){
	        
                 if(tableau[ligne][colonne]==tableau[ligne-1][colonne]&&tableau[ligne-1][colonne]==tableau[ligne-2][colonne] &&                               tableau[ligne-2][colonne]==tableau[ligne-3][colonne]&& tableau[ligne-3][colonne]=='X'){
             	     
			 partiegagne=1;
	   
		}else if(tableau[ligne][colonne]==tableau[ligne-1][colonne]&&tableau[ligne-1][colonne]==tableau[ligne-2][colonne] &&                               tableau[ligne-2][colonne]==tableau[ligne-3][colonne]&& tableau[ligne-3][colonne]=='O'){

			partiegagne=2;
		    }
	   
	
	ligne--;
     i++;
}
colonne++;//on passe a la colonnne suivante

//reinitialise le compteur i a 0
i=0;
ligne=6;
}

colonne=1;// on se replace a la colonne 1 pour les autres verifications

//*******verification horizontale*******
       while(ligne>0){// tant quon a pas parcouru toutes les lignes du tableau
         
	       while(i<4){       
                  if(tableau[ligne][colonne]==tableau[ligne][colonne+1] && tableau[ligne][colonne+1]==tableau[ligne][colonne+2] &&                             tableau[ligne][colonne+2]==tableau[ligne][colonne+3] && tableau[ligne][colonne+3]=='X'){
			  
			  partiegagne=1;

		  }else if(tableau[ligne][colonne]==tableau[ligne][colonne+1] && tableau[ligne][colonne+1]==tableau[ligne][colonne+2] &&                                 tableau[ligne][colonne+2]==tableau[ligne][colonne+3] && tableau[ligne][colonne+3]=='O'){
		  
          		    partiegagne=2;

		  }
		   i++;
                   colonne++;
	       }
	  i=0;
	  colonne=1;
      
	ligne--;
       }
//***************verification diagonale*************
// on se replace a ligne=6,colonne=1
ligne=6;
colonne=1;
i=0;
//verification diagonale ascendante
while(ligne>3){
  while(i<4){
       if(tableau[ligne][colonne]==tableau[ligne-1][colonne+1] && tableau[ligne-1][colonne+1]==tableau[ligne-2][colonne+2] &&
		       tableau[ligne-2][colonne+2]==tableau[ligne-3][colonne+3] && tableau[ligne-3][colonne+3]=='X'){
	       partiegagne=1;
       
       }else if(tableau[ligne][colonne]==tableau[ligne-1][colonne+1] && tableau[ligne-1][colonne+1]==tableau[ligne-2][colonne+2] &&
                  tableau[ligne-2][colonne+2]==tableau[ligne-3][colonne+3] && tableau[ligne-3][colonne+3]=='O'){
       
	       partiegagne=2;

       }
       colonne++;
       i++;
  }
i=0;
colonne=1;
ligne--;

}


//verification diagonale descendante
colonne=1;
ligne=3;
while(ligne>0){
 while(i<4){
         if(tableau[ligne][colonne]==tableau[ligne+1][colonne+1] && tableau[ligne+1][colonne+1]==tableau[ligne+2][colonne+2] &&
                        tableau[ligne+2][colonne+2]==tableau[ligne+3][colonne+3] && tableau[ligne+3][colonne+3]=='X'){
                partiegagne=1;
 
        }else if(tableau[ligne][colonne]==tableau[ligne+1][colonne+1] && tableau[ligne+1][colonne+1]==tableau[ligne+2][colonne+2] &&                      tableau[ligne+2][colonne+2]==tableau[ligne+3][colonne+3] && tableau[ligne+3][colonne+3]=='O'){
 
                partiegagne=2;
 
        }
colonne++;	 
i++;
}
i=0;
colonne=1;
ligne--;
}
return partiegagne;
}



/**
 *Fonction main()
 */
   int main(){
// initialisation du tableau de jeu
	   
char tableau[7][9]={{' ','1','2','3','4','5','6','7',' '},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'},
                    {'|',' ',' ',' ',' ',' ',' ',' ','|'}};
//Variables
int choixcol=2;
int tourdujoueur=1;
int partiegagne=0;
int partieperdu=0;
int compteurpartie=0;//si le compteur de partie  atteint 42, la partie est nulle.

//la partie commence

do{//Tant que la partie nest nest pas gagnee ou perdu

	printf("Player action:");
	//on demande on joueur dentree son choix
	scanf("%d",&choixcol);
	printf("\n");
        choixcol=verifiercol(choixcol);
	
	if(choixcol!=0){// si lutilisateur entre 0, on nexecute pas ce qui suit
        choixcol=verifiercolonne(tableau,choixcol);
	compteurpartie++;// +1 tour
	modifiertableau(tableau,choixcol,tourdujoueur);
        AfficherTab(tableau);
	partiegagne=verifierpartie(tableau);// on verifie si il y a un gagnant
	tourdujoueur=toursuivant(tourdujoueur);
	}else{
	     printf("exit\n");
	}
}while (choixcol!=0 && partiegagne!=1 && partiegagne!=2 && compteurpartie!=42);
//sil y a un gagant
if(partiegagne==1){//joueur X
	printf("Player X wins!\n");

}else if(partiegagne==2){//joueur O
  printf("Player O wins!\n");

}else if(compteurpartie==42){printf("It's a draw...\n");}// match nulle

return (0);
   }                                                           


#include <stdio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int ** reserver( int l, int c){
    int i;
    int **prod;

    prod = malloc(l * sizeof(int *));
    for(int i=0;i<l; i++){
        prod[i]=malloc(c * sizeof(int));
    }
    return prod;
}

void ajouter(int **prod, int *l , int code, int q) {
   int c=1;
   int existe =0;
   for (int i=0; i<*l; i++){
      if (prod[i][0] == code){
         prod[i][1] += q;
         existe=1;
         break;
      }
   }
    if (existe!=1){
        (*l)++;
        prod=realloc(prod,(*l) * sizeof(int *));
        prod[*l-1] = malloc(2 * sizeof(int));

        prod[*l -1][0]= code;
        prod[*l -1][1]= q;
    }

}


void retirer (int **prod, int *l,int code, int q){
       int c=1,i;
       int existe = 0;
       for( i=0;i<*l ; i++){
            if(prod[i][0] == code){
                existe=1;
                break;
            }
       }

       if(existe!=1){
           printf("l'produit n'est existe pas ");
       }else{
         if(prod[i][c] < q){
            printf("qt a retirer et sup de qt de stock\n");
         }else{
            prod[i][c]-= q ;
            printf("quantite retiree avec succès.\n");
         }
       }
}

void afficher(int** prod, int l) {
    if (l == 0) {
        printf("Le stock est vide.\n");
    }else{
     printf("Liste des produits est :\n");
      for (int i = 0; i < l; i++) {
printf("le Code: %d, la quantité: %d\n", prod[i][0] , prod[i][1]);
       }
    }
}
int main () {

    int l = 0;
    int code, q;
    int choice;
    int **prod;
    prod=reserver(l,2);
    while(1){
    printf("........ 1 ajouter le produit au stock..........\n ");
    printf("........ 2 Retirer un produit du stock..........\n ");
    printf("........ 3 Affiche le stock ....................\n ");
    printf("........ 4 exist ...............................\n ");
    printf("Entrez votre choix: ");
    scanf("%d", &choice);

    switch(choice){
    case 1:
                printf("Entrez le code du produit: ");
                scanf("%d", &code);
                printf("Entrez la quantité : ");
                scanf("%d", &q);
                ajouter(prod, &l, code, q);
                afficher(prod, l);
                break;
    case 2:
                printf("Entrez le code du produit: ");
                scanf("%d", &code);
                printf("Entrez la quantité : ");
                scanf("%d", &q);
                retirer(prod, &l, code, q);
                break;
    case 3:
                afficher(prod, l);
                break;
    case 4:
                exit(0);
    default:
                printf("invalide choix ");
                break;
}
    }

    return 0;
}

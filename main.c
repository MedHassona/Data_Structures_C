#include <stdio.h>  // Directives de préprocesseur
#include <stdlib.h>
#include <string.h>
#include "myliste.h" //declaraion de l'en tete qui contint les prototypes des fonctions


int nbre; //declaration du nombre des etudiants
int j; //declaration du contour
Liste *controle1, *controle2; //dclaration des listes chainées
char ans1[20],ans2[20],ans3[20],CNE_Del[20]; // declaration des variables pour aider d'aminer les informations
HELP help; //declaration de variable de type HELP pour aider à remplir les information de chaque etudiant

int main()
{
     controle1=initialize_of_list(); //initialiser la liste
      printf("enter the number of students !!\n ");
     scanf("%d",&nbre); //savoire le nombre des etudiants pour les ajouter de=ans la liste
     for(j=0;j<nbre;j++)
     {
         printf("student %d\n",j+1);
          help = write(); //remplir les informations de chaque etudiant par la fonction Write
         addition(controle1,&help); //envoyer les informations de chaque etudiant dans la lste par la fonction Addition
     }
          system("cls");
          printf("the new list :");
          display(controle1); //affichage de la liste par la fonction Dsplay
          printf("\n\n");

  do{
          printf("do you want to add some students to the list ? (yes) or (not)\n"); //demander à l'utilisateur si il veut ajouter encore des etudints dans la liste !!
          scanf("%s",&ans1);

          if(strcmp(ans1,"yes") == 0) // si il veut ajouter
     {
         int an;
         printf("how many ?\n"); //demander le nombre des etudiants à ajouter
         scanf("%d",&an);
          for(j=0;j<an;j++)
      {
         printf("student %d\n",j+1);
          help = write(); //remplir les informations de chaque etudiant par la fonction Write
         addition(controle1,&help); //envoyer les informations de chaque etudiant dans la lste par la fonction Addition
      }
     }

     system("cls");
    printf("the new list :");
     display(controle1); // affichage de la nouvelle liste

     printf("do you want to delete a students from the list ? (yes) or (not)\n"); //demander a l'utilisateur s'il veut supprimer un etudiant de la liste !!
          scanf("%s",ans2);
             if(strcmp(ans2,"yes") == 0) // si il veut supprimer
                {
                    int ann;
                    printf("how many ?\n"); //savoir le nombre des etudiants à supprimer
                    scanf("%d",&ann);
                    for(j=0;j<ann;j++)
                    {
                        printf("enter the CNE of the student to delete !!\n"); // pour entrer le CNE des etudiants demandés à supprimer
                        scanf("%s",CNE_Del);
                        student *p=recherche_to_delete(controle1,CNE_Del); //declaration d'une variable ,qui prendra l'address de l'etudiant à supprimer par la fonction Recherche_to_delete
                        delete2(controle1,p);
                    }
                }

     system("cls");
     printf("the new list :");
     display(controle1);
      system("cls");

     printf("\n\n----------------------------------------------------------------\n"); //affichage par le triage de l'alphabet
     tri(controle1);
     printf("displaying by alphabet :)\n");
     display(controle1);
     printf("\n\n----------------------------------------------------------------\n"); //affichage en renversant la listede l'alphabet
     controle2 = initialize_of_list(); //initialisatin d'une nouvelle liste pour renverser la liste
     controle2 = reverse_list(controle1); //garder la derniere liste après la renverser par la fonction reverse_list
     controle1 = controle2; //envoyer la liste renversé vers la liste conrole1 pour l'afficher
     printf("displaying by reversing the list of alphabet :)\n");
     display(controle1);
     printf("\n\n----------------------------------------------------------------\n"); //affichage par le triage des moyens
     tribyaverage(controle1);
     printf("displaying by average :)\n");
     display(controle1);
     printf("\n\n----------------------------------------------------------------\n"); //afichge des etudiants qui ont réussi (ont eu plus de 10)
     successful(controle1);
     printf("The list of successful student ;)\n");
     display(controle1);

     printf("do you want to reuse the list ??   (yes) or (not) \n"); //demande l'utilisateur si il veut rester dans le programme ou non  !!
     scanf("%s",ans3);
     if(strcmp(ans3,"yes") != 0) // si il a repondue ( non ) on le covonque qu'il va quitter le programme !
     {
         printf ("you're going to leave the programme !!\n");
     }
     if(strcmp(ans3,"yes") == 0) // si il a repondue ( non ) on le covonque qu'il va quitter le programme !
     {
         system("cls");
         printf ("the last list !!\n");
         display(controle1);
     }
 }while(strcmp(ans3,"yes") == 0); // la boucle va travaillersi la repence est ( yes ) !

return 0;
}

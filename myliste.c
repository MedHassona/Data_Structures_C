#include <stdlib.h>    // Directives de préprocesseur
#include <string.h>
#include <malloc.h>
#include "myliste.h"  //declaraion de l'en tete qui contint les prototypes des fonctions



HELP write() //la fonction Write pour saisir les inforlation de chaque etudiant
{
    char chaine[20],CN[20]; //declaration des variables pour aider
    HELP get; //declaration de variable Get de type HELP pour garder les information des chaque etudiant et les envoyer à la liste

        printf("enter the student name :   (max 20 char) !!\n");
        scanf("%s",chaine);
        get.h_name=malloc(strlen(chaine)+1); //reservation de la memoire pour le nom de type char
        strcpy(get.h_name,chaine);
        printf("enter the student's last name :   (max 20 char) !!\n");
        scanf("%s",chaine);
        get.h_last_name=malloc(strlen(chaine)+1); // //reservation de la memoire pour le prenom de type char
        strcpy(get.h_last_name,chaine);
        printf("enter the CNE of the student :\n");
        scanf("%s",CN);
        get.h_cne=malloc(strlen(CN)+1); // //reservation de la memoire pour le CNE de l'etudiant de type char
        strcpy(get.h_cne,CN);
        printf("enter the average student notes : \n");
        scanf("%f",&get.h_aver);
        return get;

}

Liste *initialize_of_list() //la fonction Initialize_of_list pour initialiser la liste
{
    Liste *controle=malloc(sizeof(*controle)); //reservation de la memoire pour le variable Controle de type Liste
    student *first_student=malloc(sizeof(*first_student)); //reservation de la memoire pour le premier element dans la liste

    if(emptylist(controle)) //si la condition est vrai => la lise est déja vide
        {
        exit(0);
       }
    controle->first=NULL; //Mettre le variable First = NULL au debut de la liste
    return controle; //la fonction Initialize_of_list returne la liste = controle qui contient la prelier element = NULL
}

void addition(Liste *controle,HELP *info) // la fonction Addition pour remplir la liste et ajouter des nouveaux élément

{
    student *new_student=malloc(sizeof(*new_student)); //reservation de la memoir pour chaque novel etudiant dans la liste
    if(controle==NULL || new_student==NULL || info==NULL) //il faut sortir de la fonction si ( il n'y a pas d'espace dans la memoir ,il n'y a pas des information sur la variable Info ou la liste ets vide
        {
            exit(0);

        }
    new_student->name=malloc(strlen(info->h_name)+1);
    new_student->last_name=malloc(strlen(info->h_last_name)+1);
    new_student->cne=malloc(strlen(info->h_cne)+1);
    if(new_student->name ==NULL) //la fonction remplir les information de chaque etudiant à condition d'avoir au moins son nom !!
        {
          exit(0);
        }
    strcpy(new_student->name,info->h_name);  //remplir les information de chaque etudiant

    strcpy(new_student->last_name,info->h_last_name);

    strcpy(new_student->cne,info->h_cne);

    new_student->aver=info->h_aver;

    new_student->next=controle->first;

    controle->first=new_student; // remplir la liste tel que le dernier etudiant sera au début de la liste
    }

void display(Liste *controle) // la fonction Display pour afficher les informatojn de chaque etudiant
{
	if(!emptylist(controle)) // pour que la fonction affiche ; il faut au moins avoir un etudiant
	{
		student *nc=controle->first;

		printf("\n\tCNE\t\tName\t\tLast Name \tAverage\n");
		int i=1;
		while( nc != NULL ) // Tant que l'on n'est pas au bout de la liste
		{

			  printf("%d\t%s\t\t%s\t\t%s\t\t%.2f",i,nc->cne,nc->name,nc->last_name,nc->aver);
              printf("\n");
			nc=nc->next; //On assigne l'adresse de l'élément suivant au nouvel élément
			i++;
		}

	}
	system("pause > NULL");
}

void delete1(Liste *controle) //la fonction Delete1 pour surimer si l'etudiant est au debut de la liste
      {

            if(emptylist(controle)) //pour pouvoire suprimer il faut au moins avoir un etudiant dans la liste
                {
                    exit(0);
                }

       student *to_delete=controle->first; //affecter les information de le premier etudiant dans la lste
       controle->first=controle->first->next; // affecter les information de le deuxieme etudiant à le premier etudant
       free(to_delete); // suprimer le variable Corbeille et le deuxieme etudiant devient le premier dans la liste
    }

void delete2(Liste *controle,student *position) // la fonction Delete2 pour supprimer au milieu ou à la fin de la liste
{

    if(emptylist(controle) || position==NULL) //tjs la condition est d'avoir au moins un etudiant dans la liste si non  il faut sortir de la fonction
        {
       exit(0);
        }

    if(position==controle->first) // si l'etudiant demandé est au debut de la liste on appelra la fonction Delete1
    	delete1(controle);
    else
	{

		student* nc=controle->first; // si non on mettre un variable au debut pour comparer l'etudiantdemandé avec tous les etudiants dans la liste

		while(nc!=NULL) //Tant que l'on n'est pas au bout de la liste
		{
			if(nc->next==position) //si on trouve l'etudiant dmandé on arrite le reche le recherche ;
				break;
                nc=nc->next; //On assigne l'adresse de l'élément suivant au nouvel élément
		}

		student *to_delete=position; //affecter les information de l'etudiant demandé à la variable Corbeille pour supprimer
        nc->next=to_delete->next; // on change l'etudiant suivant qu'on vas le supprimer par l'etudiant après
        free(to_delete);
	}

}



void tri(Liste *controle) // la fonction Tri pour trier les étudiants en Alphabet
{

  if(!emptylist(controle)) // la condition pour pouvoir trier
    {
       int etat=1; // un variable pour aider comme condition de la boucle While
        while(etat==1) // la condition sera vrai si le variable NS ne depasse pas la fin de la liste
        {
            student *nc,*ns; //declaration de deux variables de tupe etudiant
            nc=controle->first; //mettre le variable NC au debut de la liste
            ns=nc->next; // mettre le variable NS suivant à la variable NC
            etat=0; //initialiser le variable de la condition

            while(ns!=NULL) //puis que la variable NS n'apas depassé pas la fin de la liste
              {
                if(strcmp(nc->name,ns->name)>0) // si le nom de l'etudiant qui est sur la variable NS est avant le nom de letudint qui ets sur le variable NC en ordre de l'Alhabet ; alors on faint l'echangement des places dans la liste
                 {
                     student tmp;
                     tmp.name=nc->name;
                     tmp.last_name=nc->last_name;
                     tmp.aver=nc->aver;
                     tmp.cne=nc->cne;
                     nc->aver=ns->aver;
                     nc->name=ns->name;
                     nc->last_name=ns->last_name;
                     nc->cne=ns->cne;
                     ns->aver=tmp.aver;
                     ns->name=tmp.name;
                     ns->last_name=tmp.last_name;
                     ns->cne=tmp.cne;

                    etat=1;

                 }
                nc=ns;
                ns=ns->next; //On assigne l'adresse de l'élément suivant au nouvel élément
             }
        }
   }
}

void tribyaverage(Liste *controle) //la fonction Tribyavrage fait le triage selon les moyens des notes des etudiant
{

  if(!emptylist(controle))      //le meme travail que la fonction Tri

    {
       int etat=1;
        while(etat==1){
            student *nc,*ns;
            nc=controle->first;
            ns=nc->next;
            etat=0;

            while(ns!=NULL){
                if(nc->aver<=ns->aver){
                     student tmp;
                     tmp.name=nc->name;
                     tmp.last_name=nc->last_name;
                     tmp.aver=nc->aver;
                     tmp.cne=nc->cne;
                     nc->aver=ns->aver;
                     nc->name=ns->name;
                     nc->last_name=ns->last_name;
                     nc->cne=ns->cne;
                     ns->aver=tmp.aver;
                     ns->name=tmp.name;
                     ns->last_name=tmp.last_name;
                     ns->cne=tmp.cne;

                    etat=1;

                }
                nc=ns;
                ns=ns->next; //On assigne l'adresse de l'élément suivant au nouvel élément
            }
        }
   }
}

   Liste* reverse_list(Liste* controle) // la fonction reverse_list pour renverser la liste
   {
   		if(emptylist(controle)) //si la liste envoyé pour renverser est vide la fonction ne marchera pas
            {
   			exit(0);
   			}

   		Liste* lst=initialize_of_list(); //declaration et initialisation d'une liste pour enenvoyer à la quelle la liste renversé
   		student* nc=controle->first;
   		HELP help;

   		while(nc!=NULL) // Tant que l'on n'est pas au bout de la liste
   		{
		   	help.h_name=malloc(sizeof(nc->name)+1);
		    if(help.h_name == NULL){
		        exit(0);
		    }
		    help.h_last_name=malloc(sizeof(nc->last_name)+1);
		    help.h_cne=malloc(sizeof(nc->cne)+1);
		    strcpy(help.h_name,nc->name);
		    strcpy(help.h_last_name,nc->last_name);
            strcpy(help.h_cne,nc->cne);
		    help.h_aver=nc->aver;


		    addition(lst,&help); //on envoit le 1er etudiant à la derniere lace dans la liste (lst)
		    nc=nc->next; //On assigne l'adresse de l'élément suivant au nouvel élément
   		}
   		return lst;
   }


void successful(Liste* controle)     //la fonction Successful pour suprimer les etudiants qui ont pas réussi (avoir de moyen mons de 10)
{
         if(emptylist(controle))     //si la liste est vide la fonction ne marchera pas
            {
              exit(0);
             }
        student *nc;
        nc=controle->first;

       do{
        if(nc->aver <12){
            delete2(controle,nc);   //si un etudiant a moins de 10 comme moyen  on appelra la fonctio Delete2 pour le supprimer de la liste
        }
        nc=nc->next;
  }while(nc!=NULL); //tan qu'on l'est pas au bout de la liste


}

   int emptylist(Liste * controle)      //la fonction Emptylist pour savoir si la liste est vide ou non !
   {
   if (controle == NULL || controle->first == NULL)             //les condition pour que la liste soit pas vide
        return 1;                                          // si la liste et la liste est vide la fonction Emptylidt renvoit 1
    return 0 ;                                          //si la liste n'est pas vide la fonction renvoit 0
   }

student* recherche_to_delete(Liste *controle,char *cne) //la fonction Recherche to delete pout savoir la position de l'etudiant pour suprimer
{
		if( !emptylist(controle) ) //la condition pour que la fonction peut marcher
			{
				student* wanted=controle->first; //mettre la variable au debaut de la liste

				while( wanted != NULL ) // Tant que l'on n'est pas au bout de la liste
				{
					if(strcmp(wanted->cne,cne)==0) //on compare le CNE de l'etudiant demandé avec chaque etudiant dans la liste
					{
						return wanted; //Si l'étudiant avec le CNE recherchée, on renvoie son adresse
					}
					wanted=wanted->next; //le contour de la boucle
				}
			}
		return NULL;
   }

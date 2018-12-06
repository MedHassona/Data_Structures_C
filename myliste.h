#ifndef MYLISTE_H_INCLUDED
#define MYLISTE_H_INCLUDED


typedef struct student //déclaration d'une structure etudiant
{
    char *name;
    char *last_name;
    char *cne;
    float aver;
    struct student *next; //declaration d'un pointeur sur Student (nxt), qui contiendra l'adresse de l'élément suivant
}student;


typedef struct Liste //declararion de la liste qui qontient les information de chaque etudianr
{
    student *first; //declaration de le premier elemenet dans la liste
}Liste;


typedef struct HELP //declaration d'une strucure semblable à student pour aider
{
    char *h_name;
    char *h_last_name;
    char *h_cne;
    float h_aver;
}HELP;

Liste *initialize_of_list(); //declaration d'une fonction pour initialiser la liste

HELP write(); //declaraton d'une fonction Write pour saisir les inforlation de chaque etudiant

void addition(Liste *controle,HELP *info); //declaraton d'une fonction Addition pour remplir la liste et ajouter des nouveaux élément

void delete2(Liste *controle,student *position); //declaraton d'une fonction Delete1 pour supprimer au debut

void delete1(Liste *controle); //declaraton d'une fonction Delete2 pour supprimer au milieu ou a la fin de la liste

void tri(Liste *controle); //declaraton d'une fonction  Tri pour le triage en Alphabet

void tribyaverage(Liste *controle); //declaraton d'une fonction Tribyaverage pour trier selon le moyen des notes de chaque etudiant

Liste* reverse_list(Liste* controle); //declaration d'une fonction pour renverser la la liste

void successful(Liste* controle); //declaraton d'une fonction Successful pour éléminer les etudiants qu'ont des moyens mois de 10

int emptylist(Liste * controle); //declaraton d'une fonction Emptylist pour savoir si la liste est vide ou non !

student* recherche_to_delete(Liste *controle,char *cne); //declaraton d'une fonction Recherche to delete pout savoir la position de l'etudiant pour suprimer

void display (Liste *controle); // declaraton d'une fonction Display pour l'affichage


#endif // MYLISTE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<string.h>
#define MAXELEMENTS 1000
#define CMAX 500


//les fonctions que je vais definir a la fin du programme

void Window_location(GtkWidget * ,gpointer );
void Window_gestion_voitures(GtkWidget * ,gpointer );
void Window_gestion_clients(GtkWidget * ,gpointer );
//void Quitter();

//Fonction liees au signaux des bouttons du menu gestion location

void afficher_listes_contrats(void );
void add_in_contract_list(void );
void load_contract(void );
void load_voitures(void );

void save_contract(void );
/*void Lou_voit(FILE*);
void Ret_voit(FILE*);
void Modif_cont(FILE*);
void Supp_cont(FILE*);*/

//Fonction liees au signaux des bouttons du menu gestion des voitures

void Aff_list_voit(FILE*);
void Ajout_voit(FILE*);
void Modif_voit(FILE*);
void Supp_voit(FILE*);

//Fonction liees au signaux des bouttons du menu gestion des clients

void aff_list_cl(FILE*);
void Ajout_cl(FILE*);
void Modif_cl(FILE*);
void Supp_client(FILE*);
*/

//Main project functions(pointeur vers les fonctions si possible)


//Espace Structures

typedef struct Date
{
int jj[3];
int mm[3];
int aa[5];
} date;


typedef struct Voiture
{
int idVoiture[20];
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces[20];
int prixJour[20];
char EnLocation[4];
} voiture;


typedef struct contratLocation
{
float numContrat[20];
int idVoiture[20];
int idClient[20];
date debut[20];
date fin[20];
int cout[20];
} contrat;


/*typedef struct Client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}client;

*/












//Variables globales

GtkBuilder *projet;
GtkWidget *window_ajout_contrat;
GtkWidget *window_list_contrat;
GtkWidget *window_liste_voitures;
//declaration des entrees:
//pour la location:

GtkWidget *numC1,*numC2,*numC3,*numC4,*numC5,*numC6,*numC7,*numC8,*numC9,*numC10;
GtkWidget *idV1,*idV2,*idV3,*idV4,*idV5,*idV6,*idV7,*idV8,*idV9,*idV10;
GtkWidget *idC1,*idC2,*idC3,*idC4,*idC5,*idC6,*idC7,*idC8,*idC9,*idC10;
GtkWidget *jj_d1,*jj_d2,*jj_d3,*jj_d4,*jj_d5,*jj_d6,*jj_d7,*jj_d8,*jj_d9,*jj_d10;
GtkWidget *mm_d1,*mm_d2,*mm_d3,*mm_d4,*mm_d5,*mm_d6,*mm_d7,*mm_d8,*mm_d9,*mm_d10;
GtkWidget *aa_d1,*aa_d2,*aa_d3,*aa_d4,*aa_d5,*aa_d6,*aa_d7,*aa_d8,*aa_d9,*aa_d10;
GtkWidget *jj_f1,*jj_f2,*jj_f3,*jj_f4,*jj_f5,*jj_f6,*jj_f7,*jj_f8,*jj_f9,*jj_f10;
GtkWidget *mm_f1,*mm_f2,*mm_f3,*mm_f4,*mm_f5,*mm_f6,*mm_f7,*mm_f8,*mm_f9,*mm_f10;
GtkWidget *aa_f1,*aa_f2,*aa_f3,*aa_f4,*aa_f5,*aa_f6,*aa_f7,*aa_f8,*aa_f9,*aa_f10;
GtkWidget *cout1,*cout2,*cout3,*cout4,*cout5,*cout6,*cout7,*cout8,*cout9,*cout10;
GtkWidget *add_numC, *add_idV, *add_idC, *add_jj_d,*add_mm_d,*add_aa_d, *add_jj_f, *add_mm_f, *add_aa_f, *add_cout;
//pour les voitures:

GtkWidget *idvv1, *idvv2, *idvv3, *idvv4, *idvv5, *idvv6, *idvv7, *idvv8, *idvv9, *idvv10;
GtkWidget *m1, *m2, *m3, *m4, *m5, *m6, *m7, *m8, *m9, *m10;
GtkWidget *nomv1, *nomv2, *nomv3, *nomv4, *nomv5, *nomv6, *nomv7, *nomv8, *nomv9, *nomv10;
GtkWidget *color1, *color2, *color3, *color4, *color5, *color6, *color7, *color8, *color9, *color10;
GtkWidget *nbp1, *nbp2, *nbp3, *nbp4, *nbp5, *nbp6, *nbp7, *nbp8, *nbp9, *nbp10;
GtkWidget *pj1, *pj2, *pj3, *pj4, *pj5, *pj6, *pj7, *pj8, *pj9, *pj10;
GtkWidget *enloc1, *enloc2, *enloc3, *enloc4, *enloc5, *enloc6, *enloc7, *enloc8, *enloc9, *enloc10;
GtkWidget *add_idvv, *add_m, *add_nomv, *add_color, *add_nbp, *add_pj, *add_enloc;
//pour les clients:


//Les tableaux de structures:
voiture TabVoiture[MAXELEMENTS];
contrat TabContrat[MAXELEMENTS];
//client TabClient[MAXELEMENTS];

int main(int argc, char **argv){
    gtk_init(&argc,&argv);

    GtkWidget *window, *button_gestion_clients, *button_location, *button_gestion_voitures, *button_exit1, *text;
    //La page du menu principale
    projet=GTK_WIDGET(gtk_builder_new_from_file("C:\\Users\\hp\\Desktop\\All_Windows.glade"));
    window=GTK_WIDGET(gtk_builder_get_object(projet, "Window_MenuPrincipale"));
    text=GTK_WIDGET(gtk_builder_get_object(projet, "label1"));
    button_location=GTK_WIDGET(gtk_builder_get_object(projet, "button_location"));
    button_gestion_voitures=GTK_WIDGET(gtk_builder_get_object(projet, "button_gestion_voitures"));
    button_gestion_clients=GTK_WIDGET(gtk_builder_get_object(projet, "button_gestion_clients"));
    button_exit1=GTK_WIDGET(gtk_builder_get_object(projet, "Exit1"));





    //La connection des signals des buttons

    g_signal_connect(button_location,"clicked", G_CALLBACK(Window_location) , NULL);
    g_signal_connect(button_gestion_voitures,"clicked", G_CALLBACK(Window_gestion_voitures) , NULL);
    g_signal_connect(button_gestion_clients,"clicked", G_CALLBACK(Window_gestion_clients) , NULL);
    g_signal_connect_swapped (button_exit1, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    g_signal_connect_swapped(button_location,"clicked", G_CALLBACK(gtk_widget_destroy) , window);
    g_signal_connect_swapped(button_gestion_clients,"clicked", G_CALLBACK(gtk_widget_destroy) , window);
    g_signal_connect_swapped(button_gestion_voitures,"clicked", G_CALLBACK(gtk_widget_destroy) , window);








    gtk_widget_show_all(window);
    gtk_main();



    return 0;
}



//Espace definitions des fonctions


// Window 1
void Window_location(GtkWidget *widget ,gpointer data )
{

  GtkWidget *windowLoc, *text1, *button_visual_contrat, *button_louer;
  GtkWidget *button_retour_voiture, *button_modif_contrat, *button_supp_client, *button_exit2;

  projet=                GTK_WIDGET(gtk_builder_new_from_file("C:\\Users\\hp\\Desktop\\All_Windows.glade"));
  windowLoc=             GTK_WIDGET(gtk_builder_get_object(projet, "Window_MenuLocation"));
  text1=                 GTK_WIDGET(gtk_builder_get_object(projet, "label2"));
  button_visual_contrat= GTK_WIDGET(gtk_builder_get_object(projet, "Visualiser_contrat"));
  button_louer=          GTK_WIDGET(gtk_builder_get_object(projet, "Louer_voiture"));
  button_retour_voiture= GTK_WIDGET(gtk_builder_get_object(projet, "Retourner_voiture"));
  button_modif_contrat=  GTK_WIDGET(gtk_builder_get_object(projet, "Modifier_contrat"));
  button_exit2=          GTK_WIDGET(gtk_builder_get_object(projet, "Exit2"));
  button_supp_client=    GTK_WIDGET(gtk_builder_get_object(projet, "Supprimer_contrat"));


  g_signal_connect(button_visual_contrat, "clicked" , G_CALLBACK(afficher_listes_contrats) , NULL);
  g_signal_connect(button_louer, "clicked", G_CALLBACK(add_in_contract_list), NULL)
  g_signal_connect(button_exit2,"clicked", G_CALLBACK(main) , NULL);
  g_signal_connect(button_exit2,"clicked", G_CALLBACK(gtk_widget_destroy) , windowLoc);


  gtk_widget_show_all(windowLoc);




}

//Window 2
void Window_gestion_voitures(GtkWidget *widget ,gpointer data)
{

  GtkWidget *windowVoit, *text2, *button_list_voit, *button_ajout_voit, *button_modif_voit;
  GtkWidget *button_Supp_voit, *button_exit3;


  windowVoit=        GTK_WIDGET(gtk_builder_get_object(projet, "Window_GestionVoiture"));
  text2=             GTK_WIDGET(gtk_builder_get_object(projet, "label3"));
  button_list_voit=  GTK_WIDGET(gtk_builder_get_object(projet, "Liste_voitures"));
  button_ajout_voit= GTK_WIDGET(gtk_builder_get_object(projet, "Ajouter_voiture"));
  button_modif_voit= GTK_WIDGET(gtk_builder_get_object(projet, "Modifier_voiture"));
  button_Supp_voit=  GTK_WIDGET(gtk_builder_get_object(projet, "Supprimer_voiture"));
  button_exit3=      GTK_WIDGET(gtk_builder_get_object(projet, "Exit3"));

  g_signal_connect(button_exit3,"clicked", G_CALLBACK(main) , NULL);
  g_signal_connect(button_exit3,"clicked", G_CALLBACK(gtk_widget_destroy) , windowVoit);
  g_signal_connect(button_list_voit, "clicked", G_CALLBACK(Aff_list_voit), NULL);
  gtk_widget_show_all(windowVoit);

}

//Window3
void Window_gestion_clients(GtkWidget *widget ,gpointer data)
{

  GtkWidget *windowCl , *text3 ,*button_list_cl , *button_ajout_cl , *button_modif_cl;
  GtkWidget *button_supp_cl, *button_exit4;


  windowCl=         GTK_WIDGET(gtk_builder_get_object(projet, "Window_GestionClients"));
  text3=            GTK_WIDGET(gtk_builder_get_object(projet, "label4"));
  button_list_cl=   GTK_WIDGET(gtk_builder_get_object(projet, "Liste_desClients"));
  button_ajout_cl=  GTK_WIDGET(gtk_builder_get_object(projet, "Ajouter_client"));
  button_modif_cl=  GTK_WIDGET(gtk_builder_get_object(projet, "Modifier_client"));
  button_supp_cl=   GTK_WIDGET(gtk_builder_get_object(projet, "Supprimer_client"));
  button_exit4=     GTK_WIDGET(gtk_builder_get_object(projet, "exit4"));

  g_signal_connect(button_exit4,"clicked", G_CALLBACK(main) , NULL);
  g_signal_connect(button_exit4,"clicked", G_CALLBACK(gtk_widget_destroy) , windowCl);
  gtk_widget_show_all(windowCl);

}


//afficher listes
void afficher_listes_contrats(){


projet=             GTK_WIDGET(gtk_builder_new_from_file("C:\\Users\\hp\\Desktop\\All_Windows.glade"));
window_list_contrat=GTK_WIDGET(gtk_builder_get_object(projet, "window_liste_contrats"));

numC1=              GTK_WIDGET(gtk_builder_get_object(projet, "numC1"));
numC2=              GTK_WIDGET(gtk_builder_get_object(projet, "numC2"));
numC3=              GTK_WIDGET(gtk_builder_get_object(projet, "numC3"));
numC4=              GTK_WIDGET(gtk_builder_get_object(projet, "numC4"));
numC5=              GTK_WIDGET(gtk_builder_get_object(projet, "numC5"));
numC6=              GTK_WIDGET(gtk_builder_get_object(projet, "numC6"));
numC7=              GTK_WIDGET(gtk_builder_get_object(projet, "numC7"));
numC8=              GTK_WIDGET(gtk_builder_get_object(projet, "numC8"));
numC9=              GTK_WIDGET(gtk_builder_get_object(projet, "numC9"));
numC10=             GTK_WIDGET(gtk_builder_get_object(projet, "numC10"));

idV1=               GTK_WIDGET(gtk_builder_get_object(projet, "idV1"));
idV2=               GTK_WIDGET(gtk_builder_get_object(projet, "idV2"));
idV3=               GTK_WIDGET(gtk_builder_get_object(projet, "idV3"));
idV4=               GTK_WIDGET(gtk_builder_get_object(projet, "idV4"));
idV5=               GTK_WIDGET(gtk_builder_get_object(projet, "idV5"));
idV6=               GTK_WIDGET(gtk_builder_get_object(projet, "idV6"));
idV7=               GTK_WIDGET(gtk_builder_get_object(projet, "idV7"));
idV8=               GTK_WIDGET(gtk_builder_get_object(projet, "idV8"));
idV9=               GTK_WIDGET(gtk_builder_get_object(projet, "idV9"));
idV10=              GTK_WIDGET(gtk_builder_get_object(projet, "idV10"));

idC1=               GTK_WIDGET(gtk_builder_get_object(projet, "idC1"));
idC2=               GTK_WIDGET(gtk_builder_get_object(projet, "idC2"));
idC3=               GTK_WIDGET(gtk_builder_get_object(projet, "idC3"));
idC4=               GTK_WIDGET(gtk_builder_get_object(projet, "idC4"));
idC5=               GTK_WIDGET(gtk_builder_get_object(projet, "idC5"));
idC6=               GTK_WIDGET(gtk_builder_get_object(projet, "idC6"));
idC7=               GTK_WIDGET(gtk_builder_get_object(projet, "idC7"));
idC8=               GTK_WIDGET(gtk_builder_get_object(projet, "idC8"));
idC9=               GTK_WIDGET(gtk_builder_get_object(projet, "idC9"));
idC10=              GTK_WIDGET(gtk_builder_get_object(projet, "idC10"));

jj_d1=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d1"));
jj_d2=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d2"));
jj_d3=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d3"));
jj_d4=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d4"));
jj_d5=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d5"));
jj_d6=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d6"));
jj_d7=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d7"));
jj_d8=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d8"));
jj_d9=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_d9"));
jj_d10=           GTK_WIDGET(gtk_builder_get_object(projet, "jj_d10"));

mm_d1=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d1"));
mm_d2=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d2"));
mm_d3=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d3"));
mm_d4=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d4"));
mm_d5=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d5"));
mm_d6=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d6"));
mm_d7=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d7"));
mm_d8=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d8"));
mm_d9=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_d9"));
mm_d10=           GTK_WIDGET(gtk_builder_get_object(projet, "mm_d10"));

aa_d1=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d1"));
aa_d2=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d2"));
aa_d3=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d3"));
aa_d4=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d4"));
aa_d5=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d5"));
aa_d6=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d6"));
aa_d7=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d7"));
aa_d8=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d8"));
aa_d9=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_d9"));
aa_d10=           GTK_WIDGET(gtk_builder_get_object(projet, "aa_d10"));

jj_f1=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f1"));
jj_f2=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f2"));
jj_f3=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f3"));
jj_f4=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f4"));
jj_f5=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f5"));
jj_f6=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f6"));
jj_f7=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f7"));
jj_f8=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f8"));
jj_f9=            GTK_WIDGET(gtk_builder_get_object(projet, "jj_f9"));
jj_f10=           GTK_WIDGET(gtk_builder_get_object(projet, "jj_f10"));

mm_f1=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f1"));
mm_f2=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f2"));
mm_f3=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f3"));
mm_f4=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f4"));
mm_f5=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f5"));
mm_f6=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f6"));
mm_f7=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f7"));
mm_f8=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f8"));
mm_f9=            GTK_WIDGET(gtk_builder_get_object(projet, "mm_f9"));
mm_f10=           GTK_WIDGET(gtk_builder_get_object(projet, "mm_f10"));

aa_f1=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f1"));
aa_f2=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f2"));
aa_f3=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f3"));
aa_f4=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f4"));
aa_f5=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f5"));
aa_f6=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f6"));
aa_f7=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f7"));
aa_f8=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f8"));
aa_f9=            GTK_WIDGET(gtk_builder_get_object(projet, "aa_f9"));
aa_f10=           GTK_WIDGET(gtk_builder_get_object(projet, "aa_f10"));

cout1=              GTK_WIDGET(gtk_builder_get_object(projet, "cout1"));
cout2=              GTK_WIDGET(gtk_builder_get_object(projet, "cout2"));
cout3=              GTK_WIDGET(gtk_builder_get_object(projet, "cout3"));
cout4=              GTK_WIDGET(gtk_builder_get_object(projet, "cout4"));
cout5=              GTK_WIDGET(gtk_builder_get_object(projet, "cout5"));
cout6=              GTK_WIDGET(gtk_builder_get_object(projet, "cout6"));
cout7=              GTK_WIDGET(gtk_builder_get_object(projet, "cout7"));
cout8=              GTK_WIDGET(gtk_builder_get_object(projet, "cout8"));
cout9=              GTK_WIDGET(gtk_builder_get_object(projet, "cout9"));
cout10=             GTK_WIDGET(gtk_builder_get_object(projet, "cout10"));

gtk_widget_show_all(window_list_contrat);

}
void load_contract(){
//copie du num contrat
strcpy(TabContrat[0].numContrat,gtk_entry_get_text(numC1));
strcpy(TabContrat[1].numContrat,gtk_entry_get_text(numC2));
strcpy(TabContrat[2].numContrat,gtk_entry_get_text(numC3));
strcpy(TabContrat[3].numContrat,gtk_entry_get_text(numC4));
strcpy(TabContrat[4].numContrat,gtk_entry_get_text(numC5));
strcpy(TabContrat[5].numContrat,gtk_entry_get_text(numC6));
strcpy(TabContrat[6].numContrat,gtk_entry_get_text(numC7));
strcpy(TabContrat[7].numContrat,gtk_entry_get_text(numC8));
strcpy(TabContrat[8].numContrat,gtk_entry_get_text(numC6));
strcpy(TabContrat[9].numContrat,gtk_entry_get_text(numC10));

//copie du id voiture
strcpy(TabContrat[0].idVoiture,gtk_entry_get_text(idV1));
strcpy(TabContrat[1].idVoiture,gtk_entry_get_text(idV2));
strcpy(TabContrat[2].idVoiture,gtk_entry_get_text(idV3));
strcpy(TabContrat[3].idVoiture,gtk_entry_get_text(idV4));
strcpy(TabContrat[4].idVoiture,gtk_entry_get_text(idV5));
strcpy(TabContrat[5].idVoiture,gtk_entry_get_text(idV6));
strcpy(TabContrat[6].idVoiture,gtk_entry_get_text(idV7));
strcpy(TabContrat[7].idVoiture,gtk_entry_get_text(idV8));
strcpy(TabContrat[8].idVoiture,gtk_entry_get_text(idV6));
strcpy(TabContrat[9].idVoiture,gtk_entry_get_text(idV10));

//copie du id client
strcpy(TabContrat[0].idClient,gtk_entry_get_text(idC1));
strcpy(TabContrat[1].idClient,gtk_entry_get_text(idC2));
strcpy(TabContrat[2].idClient,gtk_entry_get_text(idC3));
strcpy(TabContrat[3].idClient,gtk_entry_get_text(idC4));
strcpy(TabContrat[4].idClient,gtk_entry_get_text(idC5));
strcpy(TabContrat[5].idClient,gtk_entry_get_text(idC6));
strcpy(TabContrat[6].idClient,gtk_entry_get_text(idC7));
strcpy(TabContrat[7].idClient,gtk_entry_get_text(idC8));
strcpy(TabContrat[8].idClient,gtk_entry_get_text(idC6));
strcpy(TabContrat[9].idClient,gtk_entry_get_text(idC10));

//copie Date debut
//jj
strcpy(TabContrat[0].debut->jj,gtk_entry_get_text(jj_d1));
strcpy(TabContrat[1].debut->jj,gtk_entry_get_text(jj_d2));
strcpy(TabContrat[2].debut->jj,gtk_entry_get_text(jj_d3));
strcpy(TabContrat[3].debut->jj,gtk_entry_get_text(jj_d4));
strcpy(TabContrat[4].debut->jj,gtk_entry_get_text(jj_d5));
strcpy(TabContrat[5].debut->jj,gtk_entry_get_text(jj_d6));
strcpy(TabContrat[6].debut->jj,gtk_entry_get_text(jj_d7));
strcpy(TabContrat[7].debut->jj,gtk_entry_get_text(jj_d8));
strcpy(TabContrat[8].debut->jj,gtk_entry_get_text(jj_d6));
strcpy(TabContrat[9].debut->jj,gtk_entry_get_text(jj_d10));
//mm
strcpy(TabContrat[0].debut->mm,gtk_entry_get_text(mm_d1));
strcpy(TabContrat[1].debut->mm,gtk_entry_get_text(mm_d2));
strcpy(TabContrat[2].debut->mm,gtk_entry_get_text(mm_d3));
strcpy(TabContrat[3].debut->mm,gtk_entry_get_text(mm_d4));
strcpy(TabContrat[4].debut->mm,gtk_entry_get_text(mm_d5));
strcpy(TabContrat[5].debut->mm,gtk_entry_get_text(mm_d6));
strcpy(TabContrat[6].debut->mm,gtk_entry_get_text(mm_d7));
strcpy(TabContrat[7].debut->mm,gtk_entry_get_text(mm_d8));
strcpy(TabContrat[8].debut->mm,gtk_entry_get_text(mm_d6));
strcpy(TabContrat[9].debut->mm,gtk_entry_get_text(mm_d10));
//aa
strcpy(TabContrat[0].debut->aa,gtk_entry_get_text(aa_d1));
strcpy(TabContrat[1].debut->aa,gtk_entry_get_text(aa_d2));
strcpy(TabContrat[2].debut->aa,gtk_entry_get_text(aa_d3));
strcpy(TabContrat[3].debut->aa,gtk_entry_get_text(aa_d4));
strcpy(TabContrat[4].debut->aa,gtk_entry_get_text(aa_d5));
strcpy(TabContrat[5].debut->aa,gtk_entry_get_text(aa_d6));
strcpy(TabContrat[6].debut->aa,gtk_entry_get_text(aa_d7));
strcpy(TabContrat[7].debut->aa,gtk_entry_get_text(aa_d8));
strcpy(TabContrat[8].debut->aa,gtk_entry_get_text(aa_d6));
strcpy(TabContrat[9].debut->aa,gtk_entry_get_text(aa_d10));

//copie date fin
//jj
strcpy(TabContrat[0].fin->jj,gtk_entry_get_text(jj_f1));
strcpy(TabContrat[1].fin->jj,gtk_entry_get_text(jj_f2));
strcpy(TabContrat[2].fin->jj,gtk_entry_get_text(jj_f3));
strcpy(TabContrat[3].fin->jj,gtk_entry_get_text(jj_f4));
strcpy(TabContrat[4].fin->jj,gtk_entry_get_text(jj_f5));
strcpy(TabContrat[5].fin->jj,gtk_entry_get_text(jj_f6));
strcpy(TabContrat[6].fin->jj,gtk_entry_get_text(jj_f7));
strcpy(TabContrat[7].fin->jj,gtk_entry_get_text(jj_f8));
strcpy(TabContrat[8].fin->jj,gtk_entry_get_text(jj_f6));
strcpy(TabContrat[9].fin->jj,gtk_entry_get_text(jj_f10));
//mm
strcpy(TabContrat[0].fin->mm,gtk_entry_get_text(mm_f1));
strcpy(TabContrat[1].fin->mm,gtk_entry_get_text(mm_f2));
strcpy(TabContrat[2].fin->mm,gtk_entry_get_text(mm_f3));
strcpy(TabContrat[3].fin->mm,gtk_entry_get_text(mm_f4));
strcpy(TabContrat[4].fin->mm,gtk_entry_get_text(mm_f5));
strcpy(TabContrat[5].fin->mm,gtk_entry_get_text(mm_f6));
strcpy(TabContrat[6].fin->mm,gtk_entry_get_text(mm_f7));
strcpy(TabContrat[7].fin->mm,gtk_entry_get_text(mm_f8));
strcpy(TabContrat[8].fin->mm,gtk_entry_get_text(mm_f6));
strcpy(TabContrat[9].fin->mm,gtk_entry_get_text(mm_f10));
//aa
strcpy(TabContrat[0].fin->aa,gtk_entry_get_text(aa_f1));
strcpy(TabContrat[1].fin->aa,gtk_entry_get_text(aa_f2));
strcpy(TabContrat[2].fin->aa,gtk_entry_get_text(aa_f3));
strcpy(TabContrat[3].fin->aa,gtk_entry_get_text(aa_f4));
strcpy(TabContrat[4].fin->aa,gtk_entry_get_text(aa_f5));
strcpy(TabContrat[5].fin->aa,gtk_entry_get_text(aa_f6));
strcpy(TabContrat[6].fin->aa,gtk_entry_get_text(aa_f7));
strcpy(TabContrat[7].fin->aa,gtk_entry_get_text(aa_f8));
strcpy(TabContrat[8].fin->aa,gtk_entry_get_text(aa_f6));
strcpy(TabContrat[9].fin->aa,gtk_entry_get_text(aa_f10));

//copie cout
strcpy(TabContrat[0].cout,gtk_entry_get_text(cout1));
strcpy(TabContrat[1].cout,gtk_entry_get_text(cout2));
strcpy(TabContrat[2].cout,gtk_entry_get_text(cout3));
strcpy(TabContrat[3].cout,gtk_entry_get_text(cout4));
strcpy(TabContrat[4].cout,gtk_entry_get_text(cout5));
strcpy(TabContrat[5].cout,gtk_entry_get_text(cout6));
strcpy(TabContrat[6].cout,gtk_entry_get_text(cout7));
strcpy(TabContrat[7].cout,gtk_entry_get_text(cout8));
strcpy(TabContrat[8].cout,gtk_entry_get_text(cout6));
strcpy(TabContrat[9].cout,gtk_entry_get_text(cout10));






}
void save_contract(){

  gtk_entry_set_text(numC1, TabContrat[0].numContrat);
  gtk_entry_set_text(numC2, TabContrat[1].numContrat);
  gtk_entry_set_text(numC3, TabContrat[2].numContrat);
  gtk_entry_set_text(numC4, TabContrat[3].numContrat);
  gtk_entry_set_text(numC5, TabContrat[4].numContrat);
  gtk_entry_set_text(numC6, TabContrat[5].numContrat);
  gtk_entry_set_text(numC7, TabContrat[6].numContrat);
  gtk_entry_set_text(numC8, TabContrat[7].numContrat);
  gtk_entry_set_text(numC9, TabContrat[8].numContrat);
  gtk_entry_set_text(numC10,TabContrat[9].numContrat);

  gtk_entry_set_text(idV1, TabContrat[0].idVoiture);
  gtk_entry_set_text(idV2, TabContrat[1].idVoiture);
  gtk_entry_set_text(idV3, TabContrat[2].idVoiture);
  gtk_entry_set_text(idV4, TabContrat[3].idVoiture);
  gtk_entry_set_text(idV5, TabContrat[4].idVoiture);
  gtk_entry_set_text(idV6, TabContrat[5].idVoiture);
  gtk_entry_set_text(idV7, TabContrat[6].idVoiture);
  gtk_entry_set_text(idV8, TabContrat[7].idVoiture);
  gtk_entry_set_text(idV9, TabContrat[8].idVoiture);
  gtk_entry_set_text(idV10, TabContrat[9].idVoiture);

  gtk_entry_set_text(idC1, TabContrat[0].idClient);
  gtk_entry_set_text(idC2, TabContrat[1].idClient);
  gtk_entry_set_text(idC3, TabContrat[2].idClient);
  gtk_entry_set_text(idC4, TabContrat[3].idClient);
  gtk_entry_set_text(idC5, TabContrat[4].idClient);
  gtk_entry_set_text(idC6, TabContrat[5].idClient);
  gtk_entry_set_text(idC7, TabContrat[6].idClient);
  gtk_entry_set_text(idC8, TabContrat[7].idClient);
  gtk_entry_set_text(idC9, TabContrat[8].idClient);
  gtk_entry_set_text(idC10, TabContrat[9].idClient);

  gtk_entry_set_text(jj_d1, TabContrat[0].debut->jj);
  gtk_entry_set_text(jj_d2, TabContrat[1].debut->jj);
  gtk_entry_set_text(jj_d3, TabContrat[2].debut->jj);
  gtk_entry_set_text(jj_d4, TabContrat[3].debut->jj);
  gtk_entry_set_text(jj_d5, TabContrat[4].debut->jj);
  gtk_entry_set_text(jj_d6, TabContrat[5].debut->jj);
  gtk_entry_set_text(jj_d7, TabContrat[6].debut->jj);
  gtk_entry_set_text(jj_d8, TabContrat[7].debut->jj);
  gtk_entry_set_text(jj_d9, TabContrat[8].debut->jj);
  gtk_entry_set_text(jj_d10, TabContrat[9].debut->jj);

  gtk_entry_set_text(mm_d1, TabContrat[0].debut->mm);
  gtk_entry_set_text(mm_d2, TabContrat[1].debut->mm);
  gtk_entry_set_text(mm_d4, TabContrat[3].debut->mm);
  gtk_entry_set_text(mm_d5, TabContrat[4].debut->mm);
  gtk_entry_set_text(mm_d6, TabContrat[5].debut->mm);
  gtk_entry_set_text(mm_d7, TabContrat[6].debut->mm);
  gtk_entry_set_text(mm_d8, TabContrat[7].debut->mm);
  gtk_entry_set_text(mm_d9, TabContrat[8].debut->mm);
  gtk_entry_set_text(mm_d10, TabContrat[9].debut->mm);

  gtk_entry_set_text(aa_d1, TabContrat[0].debut->aa);
  gtk_entry_set_text(aa_d2, TabContrat[1].debut->aa);
  gtk_entry_set_text(aa_d3, TabContrat[2].debut->aa);
  gtk_entry_set_text(aa_d4, TabContrat[3].debut->aa);
  gtk_entry_set_text(aa_d5, TabContrat[4].debut->aa);
  gtk_entry_set_text(aa_d6, TabContrat[5].debut->aa);
  gtk_entry_set_text(aa_d7, TabContrat[6].debut->aa);
  gtk_entry_set_text(aa_d8, TabContrat[7].debut->aa);
  gtk_entry_set_text(aa_d9, TabContrat[8].debut->aa);
  gtk_entry_set_text(aa_d10, TabContrat[9].debut->aa);

  gtk_entry_set_text(jj_f1, TabContrat[0].fin->jj);
  gtk_entry_set_text(jj_f2, TabContrat[1].fin->jj);
  gtk_entry_set_text(jj_f3, TabContrat[2].fin->jj);
  gtk_entry_set_text(jj_f5, TabContrat[4].fin->jj);
  gtk_entry_set_text(jj_f6, TabContrat[5].fin->jj);
  gtk_entry_set_text(jj_f7, TabContrat[6].fin->jj);
  gtk_entry_set_text(jj_f8, TabContrat[7].fin->jj);
  gtk_entry_set_text(jj_f9, TabContrat[8].fin->jj);
  gtk_entry_set_text(jj_f10, TabContrat[9].fin->jj);

  gtk_entry_set_text(mm_f1, TabContrat[0].fin->mm);
  gtk_entry_set_text(mm_f2, TabContrat[1].fin->mm);
  gtk_entry_set_text(mm_f3, TabContrat[2].fin->mm);
  gtk_entry_set_text(mm_f4, TabContrat[3].fin->mm);
  gtk_entry_set_text(mm_f5, TabContrat[4].fin->mm);
  gtk_entry_set_text(mm_f6, TabContrat[5].fin->mm);
  gtk_entry_set_text(mm_f7, TabContrat[6].fin->mm);
  gtk_entry_set_text(mm_f8, TabContrat[7].fin->mm);
  gtk_entry_set_text(mm_f9, TabContrat[8].fin->mm);
  gtk_entry_set_text(mm_f10, TabContrat[9].fin->mm);

  gtk_entry_set_text(aa_f1, TabContrat[0].fin->aa);
  gtk_entry_set_text(aa_f2, TabContrat[1].fin->aa);
  gtk_entry_set_text(aa_f3, TabContrat[2].fin->aa);
  gtk_entry_set_text(aa_f4, TabContrat[3].fin->aa);
  gtk_entry_set_text(aa_f5, TabContrat[4].fin->aa);
  gtk_entry_set_text(aa_f6, TabContrat[5].fin->aa);
  gtk_entry_set_text(aa_f7, TabContrat[6].fin->aa);
  gtk_entry_set_text(aa_f8, TabContrat[7].fin->aa);
  gtk_entry_set_text(aa_f9, TabContrat[8].fin->aa);
  gtk_entry_set_text(aa_f10, TabContrat[9].fin->aa);



}





void add_contract(){

  int i;
  GtkWidget *submit;
  projet=GTK_WIDGET(gtk_builder_new_from_file("C:\\Users\\hp\\Desktop\\All_Windows.glade"));
  window_ajout_contrat=GTK_WIDGET(gtk_builder_get_object(projet, "window_ajout_contrat"));
  //text4=               GTK_WIDGET(gtk_builder_get_object(projet, ""));
  add_numC=            GTK_WIDGET(gtk_builder_get_object(projet, "add_numC"));
  add_idV=             GTK_WIDGET(gtk_builder_get_object(projet, "add_idV"));
  add_idC=             GTK_WIDGET(gtk_builder_get_object(projet, "add_idC"));
  add_jj_d=            GTK_WIDGET(gtk_builder_get_object(projet, "add_jj_d"));
  add_mm_d=            GTK_WIDGET(gtk_builder_get_object(projet, "add_mm_d"));
  add_aa_d=            GTK_WIDGET(gtk_builder_get_object(projet, "add_aa_d"));
  add_jj_f=            GTK_WIDGET(gtk_builder_get_object(projet, "add_jj_f"));
  add_mm_f=            GTK_WIDGET(gtk_builder_get_object(projet, "add_mm_f"));
  add_aa_f=            GTK_WIDGET(gtk_builder_get_object(projet, "add_aa_f"));
  add_cout=            GTK_WIDGET(gtk_builder_get_object(projet, "add_cout"));
  submit=              GTK_WIDGET(gtk_builder_get_object(projet, "submit"));

  gtk_widget_show_all(window_ajout_contrat);
  
  load();
  for(i=0;i<10;i++){


    if(TabContrat[i].idClient==""){
      strcpy(TabContrat[i].numContrat,gtk_entry_get_text(add_numC));
      strcpy(TabContrat[i].idVoiture,gtk_entry_get_text(add_idV));
      strcpy(TabContrat[i].idClient,gtk_entry_get_text(add_idC));
      strcpy(TabContrat[i].debut->jj,gtk_entry_get_text(add_jj_d));
      strcpy(TabContrat[i].debut->mm,gtk_entry_get_text(add_mm_d));
      strcpy(TabContrat[i].debut->aa,gtk_entry_get_text(add_aa_d));
      strcpy(TabContrat[i].fin->jj,gtk_entry_get_text(add_jj_f));
      strcpy(TabContrat[i].fin->mm,gtk_entry_get_text(add_jj_f));
      strcpy(TabContrat[i].fin->aa,gtk_entry_get_text(add_jj_f));
      strcpy(TabContrat[i].cout,gtk_entry_get_text(add_cout));
      break;

    }
  for(i=0;i<10;i++){
    if(TabContrat[i].idVoiture==gtk_entry_get_text(add_idV))
      gtk_entry_set_text(add_idV, "voiture deja utilisée");
      strcpy(TabContrat[i].idVoiture,gtk_entry_get_text(add_idV));
  }
  }
  save();
  afficher_listes_contrats();


}

// veuillez saisir l'id de l utilisateur que vois voulez ajouter: if(id existe deja); break; le client existe deja-- else continue;
void modify_contract{

}

void delete_contract{

}

Aff_list_voit(){

projet=              GTK_WIDGET(gtk_builder_new_from_file("C:\\Users\\hp\\Desktop\\All_Windows.glade"));
window_liste_voitures=GTK_WIDGET(gtk_builder_get_object(projet, "window_liste_voitures"));


idv1=              GTK_WIDGET(gtk_builder_get_object(projet, "idv1"));
idv2=              GTK_WIDGET(gtk_builder_get_object(projet, "idv2"));
idv3=              GTK_WIDGET(gtk_builder_get_object(projet, "idv3"));
idv4=              GTK_WIDGET(gtk_builder_get_object(projet, "idv4"));
idv5=              GTK_WIDGET(gtk_builder_get_object(projet, "idv5"));
idv6=              GTK_WIDGET(gtk_builder_get_object(projet, "idv6"));
idv7=              GTK_WIDGET(gtk_builder_get_object(projet, "idv7"));
idv8=              GTK_WIDGET(gtk_builder_get_object(projet, "idv8"));
idv9=              GTK_WIDGET(gtk_builder_get_object(projet, "idv9"));
idv10=             GTK_WIDGET(gtk_builder_get_object(projet, "idv10"));

m1=              GTK_WIDGET(gtk_builder_get_object(projet, "m1"));
m2=              GTK_WIDGET(gtk_builder_get_object(projet, "m2"));
m3=              GTK_WIDGET(gtk_builder_get_object(projet, "m3"));
m4=              GTK_WIDGET(gtk_builder_get_object(projet, "m4"));
m5=              GTK_WIDGET(gtk_builder_get_object(projet, "m5"));
m6=              GTK_WIDGET(gtk_builder_get_object(projet, "m6"));
m7=              GTK_WIDGET(gtk_builder_get_object(projet, "m7"));
m8=              GTK_WIDGET(gtk_builder_get_object(projet, "m8"));
m9=              GTK_WIDGET(gtk_builder_get_object(projet, "m9"));
m10=             GTK_WIDGET(gtk_builder_get_object(projet, "m10"));

nomv1=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv1"));
nomv2=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv2"));
nomv3=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv3"));
nomv4=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv4"));
nomv5=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv5"));
nomv6=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv6"));
nomv7=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv7"));
nomv8=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv8"));
nomv9=              GTK_WIDGET(gtk_builder_get_object(projet, "nomv9"));
nomv10=             GTK_WIDGET(gtk_builder_get_object(projet, "nomv10"));

color1=              GTK_WIDGET(gtk_builder_get_object(projet, "color1"));
color2=              GTK_WIDGET(gtk_builder_get_object(projet, "color2"));
color3=              GTK_WIDGET(gtk_builder_get_object(projet, "color3"));
color4=              GTK_WIDGET(gtk_builder_get_object(projet, "color4"));
color5=              GTK_WIDGET(gtk_builder_get_object(projet, "color5"));
color6=              GTK_WIDGET(gtk_builder_get_object(projet, "color6"));
color7=              GTK_WIDGET(gtk_builder_get_object(projet, "color7"));
color8=              GTK_WIDGET(gtk_builder_get_object(projet, "color8"));
color9=              GTK_WIDGET(gtk_builder_get_object(projet, "color9"));
color10=             GTK_WIDGET(gtk_builder_get_object(projet, "color10"));

nbp1=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp1"));
nbp2=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp2"));
nbp3=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp3"));
nbp4=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp4"));
nbp5=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp5"));
nbp6=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp6"));
nbp7=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp7"));
nbp8=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp8"));
nbp9=              GTK_WIDGET(gtk_builder_get_object(projet, "nbp9"));
nbp10=             GTK_WIDGET(gtk_builder_get_object(projet, "nbp10"));

pj1=              GTK_WIDGET(gtk_builder_get_object(projet, "pj1"));
pj2=              GTK_WIDGET(gtk_builder_get_object(projet, "pj2"));
pj3=              GTK_WIDGET(gtk_builder_get_object(projet, "pj3"));
pj4=              GTK_WIDGET(gtk_builder_get_object(projet, "pj4"));
pj5=              GTK_WIDGET(gtk_builder_get_object(projet, "pj5"));
pj6=              GTK_WIDGET(gtk_builder_get_object(projet, "pj6"));
pj7=              GTK_WIDGET(gtk_builder_get_object(projet, "pj7"));
pj8=              GTK_WIDGET(gtk_builder_get_object(projet, "pj8"));
pj9=              GTK_WIDGET(gtk_builder_get_object(projet, "pj9"));
pj10=             GTK_WIDGET(gtk_builder_get_object(projet, "pj10"));

enloc1=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc1"));
enloc2=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc2"));
enloc3=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc3"));
enloc4=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc4"));
enloc5=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc5"));
enloc6=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc6"));
enloc7=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc7"));
enloc8=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc8"));
enloc9=              GTK_WIDGET(gtk_builder_get_object(projet, "enloc9"));
enloc10=             GTK_WIDGET(gtk_builder_get_object(projet, "enloc10"));

gtk_widget_show_all(window_liste_voitures);

}



void load_voitures(){

strcpy(TabVoiture[0].idVoiture,gtk_entry_get_text(idvv1));
strcpy(TabVoiture[1].idVoiture,gtk_entry_get_text(idvv2));
strcpy(TabVoiture[2].idVoiture,gtk_entry_get_text(idvv3));
strcpy(TabVoiture[3].idVoiture,gtk_entry_get_text(idvv4));
strcpy(TabVoiture[4].idVoiture,gtk_entry_get_text(idvv5));
strcpy(TabVoiture[5].idVoiture,gtk_entry_get_text(idvv6));
strcpy(TabVoiture[6].idVoiture,gtk_entry_get_text(idvv7));
strcpy(TabVoiture[7].idVoiture,gtk_entry_get_text(idvv8));
strcpy(TabVoiture[8].idVoiture,gtk_entry_get_text(idvv6));
strcpy(TabVoiture[9].idVoiture,gtk_entry_get_text(idvv10));

strcpy(TabVoiture[0].marque,gtk_entry_get_text(m1));
strcpy(TabVoiture[1].marque,gtk_entry_get_text(m2));
strcpy(TabVoiture[2].marque,gtk_entry_get_text(m3));
strcpy(TabVoiture[3].marque,gtk_entry_get_text(m4));
strcpy(TabVoiture[4].marque,gtk_entry_get_text(m5));
strcpy(TabVoiture[5].marque,gtk_entry_get_text(m6));
strcpy(TabVoiture[6].marque,gtk_entry_get_text(m7));
strcpy(TabVoiture[7].marque,gtk_entry_get_text(m8));
strcpy(TabVoiture[8].marque,gtk_entry_get_text(m6));
strcpy(TabVoiture[9].marque,gtk_entry_get_text(m10));

strcpy(TabVoiture[0].nomVoiture,gtk_entry_get_text(nomv1));
strcpy(TabVoiture[1].nomVoiture,gtk_entry_get_text(nomv2));
strcpy(TabVoiture[2].nomVoiture,gtk_entry_get_text(nomv3));
strcpy(TabVoiture[3].nomVoiture,gtk_entry_get_text(nomv4));
strcpy(TabVoiture[4].nomVoiture,gtk_entry_get_text(nomv5));
strcpy(TabVoiture[5].nomVoiture,gtk_entry_get_text(nomv6));
strcpy(TabVoiture[6].nomVoiture,gtk_entry_get_text(nomv7));
strcpy(TabVoiture[7].nomVoiture,gtk_entry_get_text(nomv8));
strcpy(TabVoiture[8].nomVoiture,gtk_entry_get_text(nomv6));
strcpy(TabVoiture[9].nomVoiture,gtk_entry_get_text(nomv10));

strcpy(TabVoiture[0].couleur,gtk_entry_get_text(color1));
strcpy(TabVoiture[1].couleur,gtk_entry_get_text(color2));
strcpy(TabVoiture[2].couleur,gtk_entry_get_text(color3));
strcpy(TabVoiture[3].couleur,gtk_entry_get_text(color4));
strcpy(TabVoiture[4].couleur,gtk_entry_get_text(color5));
strcpy(TabVoiture[5].couleur,gtk_entry_get_text(color6));
strcpy(TabVoiture[6].couleur,gtk_entry_get_text(color7));
strcpy(TabVoiture[7].couleur,gtk_entry_get_text(color8));
strcpy(TabVoiture[8].couleur,gtk_entry_get_text(color6));
strcpy(TabVoiture[9].couleur,gtk_entry_get_text(color10));

strcpy(TabVoiture[0].nbplaces,gtk_entry_get_text(nbp1));
strcpy(TabVoiture[1].nbplaces,gtk_entry_get_text(nbp2));
strcpy(TabVoiture[2].nbplaces,gtk_entry_get_text(nbp3));
strcpy(TabVoiture[3].nbplaces,gtk_entry_get_text(nbp4));
strcpy(TabVoiture[4].nbplaces,gtk_entry_get_text(nbp5));
strcpy(TabVoiture[5].nbplaces,gtk_entry_get_text(nbp6));
strcpy(TabVoiture[6].nbplaces,gtk_entry_get_text(nbp7));
strcpy(TabVoiture[7].nbplaces,gtk_entry_get_text(nbp8));
strcpy(TabVoiture[8].nbplaces,gtk_entry_get_text(nbp6));
strcpy(TabVoiture[9].nbplaces,gtk_entry_get_text(nbp10));

strcpy(TabVoiture[0].prixJour,gtk_entry_get_text(pj1));
strcpy(TabVoiture[1].prixJour,gtk_entry_get_text(pj2));
strcpy(TabVoiture[2].prixJour,gtk_entry_get_text(pj3));
strcpy(TabVoiture[3].prixJour,gtk_entry_get_text(pj4));
strcpy(TabVoiture[4].prixJour,gtk_entry_get_text(pj5));
strcpy(TabVoiture[5].prixJour,gtk_entry_get_text(pj6));
strcpy(TabVoiture[6].prixJour,gtk_entry_get_text(pj7));
strcpy(TabVoiture[7].prixJour,gtk_entry_get_text(pj8));
strcpy(TabVoiture[8].prixJour,gtk_entry_get_text(pj6));
strcpy(TabVoiture[9].prixJour,gtk_entry_get_text(pj10));

strcpy(TabVoiture[0].EnLocation,gtk_entry_get_text(enloc1));
strcpy(TabVoiture[1].EnLocation,gtk_entry_get_text(enloc2));
strcpy(TabVoiture[2].EnLocation,gtk_entry_get_text(enloc3));
strcpy(TabVoiture[3].EnLocation,gtk_entry_get_text(enloc4));
strcpy(TabVoiture[4].EnLocation,gtk_entry_get_text(enloc5));
strcpy(TabVoiture[5].EnLocation,gtk_entry_get_text(enloc6));
strcpy(TabVoiture[6].EnLocation,gtk_entry_get_text(enloc7));
strcpy(TabVoiture[7].EnLocation,gtk_entry_get_text(enloc8));
strcpy(TabVoiture[8].EnLocation,gtk_entry_get_text(enloc6));
strcpy(TabVoiture[9].EnLocation,gtk_entry_get_text(enloc10));

}

void save_voitures(){


  gtk_entry_set_text(idvv1, TabVoiture[0].idVoiture);
  gtk_entry_set_text(idvv2, TabVoiture[1].idVoiture);
  gtk_entry_set_text(idvv3, TabVoiture[2].idVoiture);
  gtk_entry_set_text(idvv4, TabVoiture[3].idVoiture);
  gtk_entry_set_text(idvv5, TabVoiture[4].idVoiture);
  gtk_entry_set_text(idvv6, TabVoiture[5].idVoiture);
  gtk_entry_set_text(idvv7, TabVoiture[6].idVoiture);
  gtk_entry_set_text(idvv8, TabVoiture[7].idVoiture);
  gtk_entry_set_text(idvv9, TabVoiture[8].idVoiture);
  gtk_entry_set_text(idvv10,TabVoiture[9].idVoiture);

  gtk_entry_set_text(m1, TabVoiture[0].marque);
  gtk_entry_set_text(m2, TabVoiture[1].marque);
  gtk_entry_set_text(m3, TabVoiture[2].marque);
  gtk_entry_set_text(m4, TabVoiture[3].marque);
  gtk_entry_set_text(m5, TabVoiture[4].marque);
  gtk_entry_set_text(m6, TabVoiture[5].marque);
  gtk_entry_set_text(m7, TabVoiture[6].marque);
  gtk_entry_set_text(m8, TabVoiture[7].marque);
  gtk_entry_set_text(m9, TabVoiture[8].marque);
  gtk_entry_set_text(m10,TabVoiture[9].marque);

  gtk_entry_set_text(nomv1, TabVoiture[0].nomVoiture);
  gtk_entry_set_text(nomv2, TabVoiture[1].nomVoiture);
  gtk_entry_set_text(nomv3, TabVoiture[2].nomVoiture);
  gtk_entry_set_text(nomv4, TabVoiture[3].nomVoiture);
  gtk_entry_set_text(nomv5, TabVoiture[4].nomVoiture);
  gtk_entry_set_text(nomv6, TabVoiture[5].nomVoiture);
  gtk_entry_set_text(nomv7, TabVoiture[6].nomVoiture);
  gtk_entry_set_text(nomv8, TabVoiture[7].nomVoiture);
  gtk_entry_set_text(nomv9, TabVoiture[8].nomVoiture);
  gtk_entry_set_text(nomv10,TabVoiture[9].nomVoiture);

  gtk_entry_set_text(color1, TabVoiture[0].couleur);
  gtk_entry_set_text(color2, TabVoiture[1].couleur);
  gtk_entry_set_text(color3, TabVoiture[2].couleur);
  gtk_entry_set_text(color4, TabVoiture[3].couleur);
  gtk_entry_set_text(color5, TabVoiture[4].couleur);
  gtk_entry_set_text(color6, TabVoiture[5].couleur);
  gtk_entry_set_text(color7, TabVoiture[6].couleur);
  gtk_entry_set_text(color8, TabVoiture[7].couleur);
  gtk_entry_set_text(color9, TabVoiture[8].couleur);
  gtk_entry_set_text(color10,TabVoiture[9].couleur);

  gtk_entry_set_text(nbp1, TabVoiture[0].nbplaces);
  gtk_entry_set_text(nbp2, TabVoiture[1].nbplaces);
  gtk_entry_set_text(nbp3, TabVoiture[2].nbplaces);
  gtk_entry_set_text(nbp4, TabVoiture[3].nbplaces);
  gtk_entry_set_text(nbp5, TabVoiture[4].nbplaces);
  gtk_entry_set_text(nbp6, TabVoiture[5].nbplaces);
  gtk_entry_set_text(nbp7, TabVoiture[6].nbplaces);
  gtk_entry_set_text(nbp8, TabVoiture[7].nbplaces);
  gtk_entry_set_text(nbp9, TabVoiture[8].nbplaces);
  gtk_entry_set_text(nbp10,TabVoiture[9].nbplaces);

  gtk_entry_set_text(pj1, TabVoiture[0].prixJour);
  gtk_entry_set_text(pj2, TabVoiture[1].prixJour);
  gtk_entry_set_text(pj3, TabVoiture[2].prixJour);
  gtk_entry_set_text(pj4, TabVoiture[3].prixJour);
  gtk_entry_set_text(pj5, TabVoiture[4].prixJour);
  gtk_entry_set_text(pj6, TabVoiture[5].prixJour);
  gtk_entry_set_text(pj7, TabVoiture[6].prixJour);
  gtk_entry_set_text(pj8, TabVoiture[7].prixJour);
  gtk_entry_set_text(pj9, TabVoiture[8].prixJour);
  gtk_entry_set_text(pj10,TabVoiture[9].prixJour);

  gtk_entry_set_text(enloc1, TabVoiture[0].EnLocation);
  gtk_entry_set_text(enloc2, TabVoiture[1].EnLocation);
  gtk_entry_set_text(enloc3, TabVoiture[2].EnLocation);
  gtk_entry_set_text(enloc4, TabVoiture[3].EnLocation);
  gtk_entry_set_text(enloc5, TabVoiture[4].EnLocation);
  gtk_entry_set_text(enloc6, TabVoiture[5].EnLocation);
  gtk_entry_set_text(enloc7, TabVoiture[6].EnLocation);
  gtk_entry_set_text(enloc8, TabVoiture[7].EnLocation);
  gtk_entry_set_text(enloc9, TabVoiture[8].EnLocation);
  gtk_entry_set_text(enloc10,TabVoiture[9].EnLocation);



}

void add_voit(){






}





























//1--Comment ecrire dans un label(transmettre le contenu du fichier en une fenetre)
//1-Ajouter(a), 2-modifier(w), 3-supprimer(r+ et en utilisant les id des choses a supprimer)
// Le CSS

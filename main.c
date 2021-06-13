//Ajout bibliothèque
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//En-tête fonction et procédure
int nonautoriser(wchar_t *message,wchar_t *alphabetmin,wchar_t *alphabetmaj,wchar_t *alpahbetaccent);

int main(void){
	
	//Déclaration des variables
	int fflush (FILE *flux);
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();
	
	wchar_t  message[200]={0}; // message saisi par l'utilisateur
	wchar_t message_sans_accent[200]={0}; // variable qui contient le message sans accent
	wchar_t message_convertie[200]={0};//Message convertie par l'algoritme de cesar
	wchar_t clef[200]={0}; //clef pour vegenere
	wchar_t  message_convertie_vegenere[200]={0};
	wchar_t alphabetmin[]=L"abcdefghijklmnopqrstuvwxyz";
	wchar_t alphabetmaj[]=L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  	wchar_t alpahbetaccent[]=L"ÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÑñÒÓÔÕÖòóôõöÙÚÛÜùúûüÝýÿ";
  	int choix,choix_fichier;

	//La saisie du message par l'utilisateur
	
	wprintf(L"Saisir votre message : ");
	fgetws(message,200,stdin);
	wprintf(L"Votre message : %ls \n",message);
	
	//Vérification des caractères du message Saisi
	while(nonautoriser(message,alphabetmin,alphabetmaj,alpahbetaccent)==2){
		wprintf(L"!ERREUR! caractères non autorise \nResaisir votre message : ");
		fgetws(message,200,stdin);
	}
	
}

int nonautoriser(wchar_t *message,wchar_t *alphabetmin,wchar_t *alphabetmaj,wchar_t *alpahbetaccent){
  int contenir=0,i=0,j;
  while(message[i]!='\n'){
        j=0;
        //premier boucle qui verifie si la lettre du message appartient au minuscule ou au maj ou est un espace
        //si oui il ajoute 1 car le caractère est autorise
        while(j<26){
               
          if (message[i]==alphabetmin[j] || message[i]==alphabetmaj[j] || message[i]==' '){
            contenir+=1;
          }
          j++;
        }
        j=0;
        //deuxieme boucle si il y a pas de majuscule ou de minucusle ou d espace
        //on verifie si il y a accent
        while(j<wcslen(alpahbetaccent)){
          if (message[i]==alpahbetaccent[j] ){
           wprintf(L"caractere: %lc \n",alpahbetaccent[j]);
            contenir+=1;
          }
          j++;
        }
        if(contenir==0){
          return 2;
        }
        contenir=0;
        i++;
  }
  return 1;
}

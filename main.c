/*
	cd Documents*
	cd projet_c_iriart_ainhoa_tommy
	gcc main.c -o main
	./main
*/

//Ajout bibliothèque
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//En-tête fonction et procédure
int nonautoriser(wchar_t *message,wchar_t *alphabetmin,wchar_t *alphabetmaj,wchar_t *alpahbetaccent);
int verifexistaccent(wchar_t *message,wchar_t *alpahbetaccent);
void convertionMessage(wchar_t *message,wchar_t *message_sans_accent,wchar_t *alphabetmaj,wchar_t *alphabetmin);
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
	
	//Convertion message sans accent
	wprintf(L"REp reponse accentexistane = %ld\n",verifexistaccent(message,alpahbetaccent));
	convertionMessage(message,message_sans_accent,alphabetmaj,alphabetmin);
	wprintf(L"Votre message sans accent : %ls \n",message_sans_accent);
	
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

int verifexistaccent(wchar_t *message,wchar_t *alpahbetaccent){
	int i=0,j;
	while(message[i]!='\n'){
		j=0;
		while(j<wcslen(alpahbetaccent)){
			if(message[i]==alpahbetaccent[j]){
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}
void convertionMessage(wchar_t *message,wchar_t *message_sans_accent,wchar_t *alphabetmaj,wchar_t *alphabetmin){
	int i=0;
	while(message[i]!='\n'){
		switch(message[i]){
		//A majuscule position 0 dans l alphabet
		case L'À': case L'Á': case L'Â': case L'Ã': case L'Ä': case L'Å':
			message_sans_accent[i]=alphabetmaj[0];
			break;
		//A minuscule
		case L'à': case L'á': case L'â': case L'ã': case L'ä': case L'å':
			message_sans_accent[i]=alphabetmin[0];
			break;
		//C majuscule position 2 dans l alphabet
		case L'Ç':
			message_sans_accent[i]=alphabetmaj[2];
			break;
		//C minuscule
		case L'ç':
			message_sans_accent[i]=alphabetmin[2];
			break;
		// E majuscule position 4 dans l alphabet
		case L'È': case L'É': case L'Ê': case L'Ë':
			message_sans_accent[i]=alphabetmaj[4];
			break;
		//E minuscule
		case L'è': case L'é': case L'ê': case L'ë':
			message_sans_accent[i]=alphabetmin[4];
			break;
		// I majuscule position 8 dans l'alphabet
		case L'Ì': case L'Í': case L'Î': case L'Ï':
			message_sans_accent[i]=alphabetmaj[8];
			break;
		//I minuscule
		case L'ì': case L'í': case L'î': case L'ï':
			message_sans_accent[i]=alphabetmin[8];
			break;
			
		//N majuscule position 13 dans l'alphabet
		case L'Ñ':
			message_sans_accent[i]=alphabetmaj[13];
			break;
		//I minuscule
		case L'ñ':
			message_sans_accent[i]=alphabetmin[13];
			break;
		
		//o majuscule position 14 dans l'alphabet 
		case L'Ò': case L'Ó': case L'Ô': case L'Õ': case L'Ö':
			message_sans_accent[i]=alphabetmaj[14];
			break;
		//o minuscule 
		case L'ò': case L'ó': case L'ô': case L'õ': case L'ö':
			message_sans_accent[i]=alphabetmin[14];
			break;
		
		
		//u majuscule position 20 dans l'alphabet 
		case L'Ù': case L'Ú': case L'Û': case L'Ü':
			message_sans_accent[i]=alphabetmaj[20];
			break;
		//u minuscule 
		case L'ù': case L'ú': case L'û': case L'ü':
			message_sans_accent[i]=alphabetmin[20];
			break;
		//y majuscule positin 24
		case L'Ý':
			message_sans_accent[i]=alphabetmaj[24];
			break;
		//y minuscule 
		case L'ý': case L'ÿ':
			message_sans_accent[i]=alphabetmin[24];
			break;
		default:
			message_sans_accent[i]=message[i];
		}
		i++;
	}
}

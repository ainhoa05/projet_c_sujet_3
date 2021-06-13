/*
	cd Documents*
	cd projet_c_iriart_ainhoa_tommy
	gcc main.c -o main
	./main
	Exemple test
	Pour cesar :
	dCode César
	cBncd Bdrzq
	clef: -1
	
	Caé oui
	Ayc msg
	clef:24
	
	
*/

//Ajout bibliothèque
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//En-tête fonction
int nonautoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent);
int verifexistaccent(wchar_t *message,wchar_t *accent);
void convertionMessage(wchar_t *message,wchar_t *messageSansAccent,wchar_t *maj,wchar_t *min);
int estmaj(wchar_t *maj,wchar_t lettre);
int indice(wchar_t *min,wchar_t *maj,wchar_t lettre);
void cesar(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC);
int main(void){
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();
	// Déclaration des variables
	wchar_t  message[200]={0};
	wchar_t  messageSansAccent[200]={0};
	
	wchar_t min[]=L"abcdefghijklmnopqrstuvwxyz";
	wchar_t maj[]=L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  	wchar_t accent[]=L"ÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÑñÒÓÔÕÖòóôõöÙÚÛÜùúûüÝýÿ";
	
	wchar_t messageConvertie[200]={0};
	int choixAlgo;
	int clefC;
	// Demande de saisir le message
	wprintf(L"\n - Saisir votre message : ");
	fgetws(message,200,stdin);
	
	// Vérification caractère non autoriser
	while(nonautoriser(message,min,maj,accent)==2){
		wprintf(L" -! ERREUR : caractere non autorise !-\n");
		wprintf(L"    Resaisir votre message : ");
		fgetws(message,200,stdin);
	}
	
	// Convertion message
	if(verifexistaccent(message,accent)==1){
		wprintf(L" - Votre message contient des accents. \n");
		wprintf(L"   Convertion en cour ... \n");
	}else{
		wprintf(L" - Votre message ne contient pas d'accent. \n");
	}
	convertionMessage(message,messageSansAccent,maj,min);
	wprintf(L"   Votre message : %ls \n",messageSansAccent);
	
	// Choix de l'algorithme
	wprintf(L" - Veuillez choisir un algorithme :  \n");
	wprintf(L"  	1) Chiffrement Cesar  \n");
	wprintf(L"  	2) Chiffrement Vigenere\n");
	wprintf(L"  	3) Dechiffrement Vigenere\n");
	wprintf(L"\n   Saisir votre algorithme : ");
	wscanf(L"%d",&choixAlgo);
	wprintf(L"   Votre choix : %d \n",choixAlgo);
	
	// Verification 
	while(choixAlgo<1 || choixAlgo>3){
		wprintf(L"\n -! ERREUR : Votre choix doit etre 1, 2 ou 3 !-\n");
		wprintf(L"    Resaisir votre choix : ");
		wscanf(L"%d",&choixAlgo);
	}
	//selection de l'algoritme
	switch(choixAlgo){
		case 1:
			wprintf(L"\n ------   Chiffrement Cesar   ------\n\n");
			wprintf(L"\n - Saisir votre clef : ");
			wscanf(L"%d",&clefC);
			wprintf(L"   Votre Clef : %d \sn",clefC);
			cesar(messageSansAccent,messageConvertie,min,maj,clefC);
			wprintf(L"   Votre message convertie: %ls \n",messageConvertie);
			break;
		case 2:
			wprintf(L"\n ------   Chiffrement Vigenere   ------\n\n");
			//wprintf(L"\n - Saisir votre clef : ");
			//wscanf(L"%d",&clefC);
			//wprintf(L"   Votre Clef : %d \n",clefC);
			//break;
		case 3:
			wprintf(L"\n ------   Dechiffrement Vigenere   ------\n\n");
			//wprintf(L"\n - Saisir votre clef : ");
			//wscanf(L"%d",&clefC);
			//wprintf(L"   Votre Clef : %d \n",clefC);
			//break;
		
	}
}
s
int nonautoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent){
	// Déclaration des variables
	int contenir=0,i=0,j,v;
		
	// Boucle de vérification
	while(message[i]!='\n'){
		j=0;
		while(j<26){
			if (message[i]==min[j] || message[i]==maj[j] || message[i]==' '){
				contenir+=1;
			}
			j++;
		}
		v=0;
		while(v<wcslen(accent)){
			if (message[i]==accent[v] ){
				contenir+=1;
			}
			v++;
		}
		if(contenir==0){
			return 2;
		}else{
			contenir=0;
		}
		i++;
	}
	return 1;
}
int verifexistaccent(wchar_t *message,wchar_t *accent){
	// Déclaration des variables
	int i=0,j;
	
	// Boucle de vérification
	while(message[i]!='\n'){
		j=0;
		while(j<wcslen(accent)){
			if(message[i]==accent[j]){
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}
void convertionMessage(wchar_t *message,wchar_t *messageSansAccent,wchar_t *maj,wchar_t *min){
	// Déclaration des variables
	int i=0;
	
	// Boucle de convertions
	while(message[i]!='\n'){
		switch(message[i]){
		//A majuscule position 0 dans l alphabet
		case L'À': case L'Á': case L'Â': case L'Ã': case L'Ä': case L'Å':
			messageSansAccent[i]=maj[0];
			break;
		//A minuscule
		case L'à': case L'á': case L'â': case L'ã': case L'ä': case L'å':
			messageSansAccent[i]=min[0];
			break;
		//C majuscule position 2 dans l alphabet
		case L'Ç':
			messageSansAccent[i]=maj[2];
			break;
		//C minuscule
		case L'ç':
			messageSansAccent[i]=min[2];
			break;
		// E majuscule position 4 dans l alphasbet
		case L'È': case L'É': case L'Ê': case L'Ë':
			messageSansAccent[i]=maj[4];
			break;
		//E minuscule
		case L'è': case L'é': case L'ê': case L'ë':
			messageSansAccent[i]=min[4];
			break;
		// I majuscule position 8 dans l'alphabet
		case L'Ì': case L'Í': case L'Î': case L'Ï':
			messageSansAccent[i]=maj[8];
			break;
		//I minuscule
		case L'ì': case L'í': case L'î': case L'ï':
			messageSansAccent[i]=min[8];
			break;
		//N majuscule position 13 dans l'alphabet
		case L'Ñ':
			messageSansAccent[i]=maj[13];
			break;
		//I minuscule
		case L'ñ':
			messageSansAccent[i]=min[13];
			break;
		//o majuscule position 14 dans l'alphabet 
		case L'Ò': case L'Ó': case L'Ô': case L'Õ': case L'Ö':
			messageSansAccent[i]=maj[14];
			break;
		//o minuscule 
		case L'ò': case L'ó': case L'ô': case L'õ': case L'ö':
			messageSansAccent[i]=min[14];
			break;
		//u majuscule position 20 dans l'alphabet 
		case L'Ù': case L'Ú': case L'Û': case L'Ü':
			messageSansAccent[i]=maj[20];
			break;
		//u minuscule 
		case L'ù': case L'ú': case L'û': case L'ü':
			messageSansAccent[i]=min[20];
			break;
		//y majuscule positin 24
		case L'Ý':
			messageSansAccent[i]=maj[24];
			break;
		//y minuscule 
		case L'ý': case L'ÿ':
			messageSansAccent[i]=min[24];
			break;
		default:
			messageSansAccent[i]=message[i];
		}
		i++;
	}
}
int estmaj(wchar_t *maj,wchar_t lettre){
	// Déclaration des variables
	int i=0;
  
  	//Boucle qui verifie si la lettre est une majuscule 
	while(i<26){
		if(lettre==maj[i]){
			return 0;
		}
		i++;
	}
	return 1;
}
int indice(wchar_t *min,wchar_t *maj,wchar_t lettre){
	// Déclaration des variables
	int i=0;
	
	//Boucle qui retourne l'indice de la lettre si elle est dans l'alphabet des minuscules ou des majuscules  
	while(i<26){
		if(lettre==min[i]){
			return i;
		}
		i++;
	}
	i=0;
	while(i<26){
		if(lettre==maj[i]){
			return i;
		}
		i++;
	}
}

void cesar(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC){
	// Déclaration des variables
	int i,majOuMin,indiceLMessage,somme;

  	//debut programme
  	//Si clef est négatif on ajouter 26
  	while (clefC<0){
  		clefC+=26;
  	}
	i=0;
	while(i<wcslen(messageSansAccent)){
		if(messageSansAccent[i]==' '){
			messageConvertie[i]=' ';
		}else{
			majOuMin=estmaj(maj,messageSansAccent[i]);
			indiceLMessage=indice(min,maj,messageSansAccent[i]);
			somme=indiceLMessage+clefC;
			if(somme>=26){
				somme%=26;
			}
			if(majOuMin==0){
				messageConvertie[i]=maj[somme];
			}else{
				messageConvertie[i]=min[somme];
	      		}
		}
		i++;
  	}
}

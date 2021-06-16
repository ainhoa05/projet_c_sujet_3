#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"

int nonAutoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent){
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
int verifExistaccent(wchar_t *message,wchar_t *accent){
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
int estMaj(wchar_t *maj,wchar_t lettre){
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
			majOuMin=estMaj(maj,messageSansAccent[i]);
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
void copieClef(wchar_t *messageSansAccent,wchar_t *clefV,wchar_t *copieClefT){
	
	int i=0,k=0;
	while(i<wcslen(messageSansAccent)){
		if(messageSansAccent[i]==' '){
			copieClefT[i]=' ';
		}else{
			if(k<wcslen(clefV)){
				copieClefT[i]=clefV[k];
				k++;
			}else{
				k=0;
				copieClefT[i]=clefV[k];
				k++;
			}
		}
		i++;
	}
}
void vigenere(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV){
	// Déclaration des variables
	wchar_t copieClefT[300]={0};
	int indiceMessage,indiceClef,somme=0,w=0;
	
	//debut programme
	
	//copie la clef dans ce tableau
	copieClef(messageSansAccent,clefV,copieClefT);
	
	
	//debut Boucle
	while(w<wcslen(messageSansAccent)){
		if(messageSansAccent[w]==' '){
			messageConvertie[w]=' ';   
		}else{
			indiceMessage=indice(min,maj,messageSansAccent[w]);
			indiceClef=indice(min,maj,copieClefT[w]);
			somme=indiceMessage+indiceClef;
			if(somme>=26){
				somme%=26;
			}
			if(estMaj(maj,messageSansAccent[w])==0){
				messageConvertie[w]=maj[somme];
			}else{
				messageConvertie[w]=min[somme];
			}
		}   
		w++;
	}
  
}
void vigenereDechiffrement(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV){
	// Déclaration des variables
	wchar_t copieClefT[300]={0};
	int indiceMessage,indiceClef,somme=0,w=0;
		
	//debut programme
	
	//copie la clef dans ce tableau
	copieClef(messageSansAccent,clefV,copieClefT);
	
	//debut Boucle
	while(w<wcslen(messageSansAccent)){
		if(messageSansAccent[w]==' '){
			messageConvertie[w]=' ';   
		}else{
			indiceMessage=indice(min,maj,messageSansAccent[w]);
			indiceClef=indice(min,maj,copieClefT[w]);
			somme=indiceMessage-indiceClef;
			if(somme<0){
				somme+=26;
			}
			if(estMaj(maj,messageSansAccent[w])==0){
				messageConvertie[w]=maj[somme];
			}else{
				messageConvertie[w]=min[somme];
			}
		}   
		w++;
	}
  
}

void cartourche(){
	wprintf(L"/******************************************************************************\n");
	wprintf(L"*  ASR => M2101                                                               *\n");
	wprintf(L"*******************************************************************************\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*  N° de Sujet : 3                                                            *\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*******************************************************************************\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*  Intitulé : Chiffrement de messages                                         *\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*******************************************************************************\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*  Nom-prénom1 : IRIART Ainhoa                                                *\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*  Nom-prénom2 : Philippe Tom                                                 *\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*******************************************************************************\n");
	wprintf(L"*                                                                             *\n");
	wprintf(L"*  Nom du fichier : main.c                                                    *\n");
	wprintf(L"******************************************************************************/\n\n");
}
}

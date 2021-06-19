
//Ajout bibliothèque
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"

//Programme main
int main(void){

	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();
	
	// Déclaration des variables
	wchar_t message[300]={0};
	wchar_t messageSansAccent[300]={0};
	wchar_t messageConvertie[300]={0};
	
	wchar_t min[]=L"abcdefghijklmnopqrstuvwxyz";
	wchar_t maj[]=L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  	wchar_t accent[]=L"ÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÑñÒÓÔÕÖòóôõöÙÚÛÜùúûüÝýÿ";
	
	
	int choixAlgo,clefC,choixRF;
	wchar_t clefV[300]={0};
	// Cartouche 
	cartourche();
	
	// Demande de saisir le message
	wprintf(L"\n\n ----------- La saisie du message -----------\n\n");
	wprintf(L"   Saisir votre message : ");
	fgetws(message,300,stdin);
	
	// Vérification caractère non autoriser
	while(nonAutoriser(message,min,maj,accent)==2){
		wprintf(L"\n   ! ERREUR ! : caractere non autorise ");
		wprintf(L"\n   Ressaisir votre message : ");
		fgetws(message,300,stdin);
	}
	
	// Convertion message
	if(verifExistaccent(message,accent)==1){
		wprintf(L"\n   Votre message contient des accents. \n");
		wprintf(L"   Convertion en cour ... \n\n");
	}else{
		wprintf(L"\n   Votre message ne contient pas d'accent. \n");
	}
	convertionMessage(message,messageSansAccent,maj,min);
	wprintf(L"\n   Votre message : %ls \n",messageSansAccent);
	
	
	// Choix de l'algorithme
	wprintf(L"\n ----------- La saisie de l'algorithme -----------\n");
	wprintf(L"\n   Veuillez choisir un algorithme :  \n");
	wprintf(L"  	1) Chiffrement Cesar  \n");
	wprintf(L"  	2) Dechiffrement Cesar\n");
	wprintf(L"  	3) Chiffrement Vigenere\n");
	wprintf(L"  	4) Dechiffrement Vigenere\n");
	wprintf(L"\n   Saisir votre algorithme : ");
	wscanf(L"%d",&choixAlgo);
	
	
	// Verification 
	while(choixAlgo<1 || choixAlgo>4){
		wprintf(L"\n  ! ERREUR ! : Votre choix doit etre 1, 2 ou 3  \n");
		wprintf(L"    Ressaisir votre choix : ");
		wscanf(L"%d",&choixAlgo);
	}
	wprintf(L"\n   Votre choix : %d \n",choixAlgo);
	//selection de l'algoritme
	switch(choixAlgo){
		case 1:
			wprintf(L"\n ----------- Chiffrement Cesar ----------- \n");
			wprintf(L"\n   Saisir la clef : ");
			wscanf(L"%d",&clefC);
			wprintf(L"\n   Votre Clef : %d \n\n",clefC);
			cesar(messageSansAccent,messageConvertie,min,maj,clefC);
			wprintf(L"   Votre message convertie: %ls \n\n",messageConvertie);
			break;
		case 2:
			wprintf(L"\n ----------- Dechiffrement Cesar ----------- \n");
			wprintf(L"\n   Saisir la clef : ");
			wscanf(L"%d",&clefC);
			wprintf(L"\n   Votre Clef : %d \n\n",clefC);
			cesarDechiffrement(messageSansAccent,messageConvertie,min,maj,clefC);;
			wprintf(L"   Votre message convertie: %ls \n",messageConvertie);
			break;
		case 3:
			wprintf(L"\n ----------- Chiffrement Vigenere ----------- \n");
			wprintf(L"\n   Saisir la clef(un mot) : ");
			wscanf(L"%ls",&clefV);
			wprintf(L"\n   Votre Clef : %ls \n",clefV);
			vigenere(messageSansAccent,min,maj,messageConvertie,clefV);
			wprintf(L"   Votre message convertie: %ls \n",messageConvertie);
			break;
		case 4:
			wprintf(L"\n ----------- Dechiffrement Vigenere ----------- \n");
			wprintf(L"\n   Saisir la clef(un mot) : ");
			wscanf(L"%ls",&clefV);
			wprintf(L"\n   Votre Clef : %ls \n",clefV);
	      		vigenereDechiffrement(messageSansAccent,min,maj,messageConvertie,clefV);
			wprintf(L"   Votre message convertie: %ls \n",messageConvertie);
			break;
		default:
			break;
		
	}
	//proposer à l'utilisateur de mettre le resultat dans un fichier 
	wprintf(L"\n ----------- Resultat dans un fichier .txt ----------- \n");
	wprintf(L"\n   Voulez-vous mettre le resultat dans un fichier votreConvertion.txt ? \n");
	wprintf(L"  	Taper 0 pour oui.\n");
	wprintf(L"  	Taper 1 pour non.\n");
	wprintf(L"\n   Votre reponse : ");
	wscanf(L"%d",&choixRF);
	
	// Verification 
	while(choixRF<0 || choixRF>1){
		wprintf(L"\n  ! ERREUR ! : Votre choix doit 0(pour oui) ou 1(pour non) !-\n");
		wprintf(L"   Ressaisir votre choix : ");
		wscanf(L"%d",&choixRF);
	}
	// Resultat dans un fichier
	if(choixRF==0){
		FILE* fichier = NULL;
		fichier = fopen("votreConvertion.txt", "a");
		switch(choixAlgo){
			case 1:
				fwprintf(fichier,L"\n\n ------   Chiffrement Cesar   ------\n\n");
				fwprintf(fichier,L"   Votre message : %ls \n",messageSansAccent);
				fwprintf(fichier,L"   Votre Clef : %d \n",clefC);
				fwprintf(fichier,L"   Votre message convertie: %ls \n",messageConvertie);
				
				break;
			case 2:
				fwprintf(fichier,L"\n ------   Dechiffrement Cesar   ------\n\n");
				fwprintf(fichier,L"   Votre message : %ls \n",messageSansAccent);
				fwprintf(fichier,L"   Votre Clef : %d \n",clefC);
				fwprintf(fichier,L"   Votre message convertie: %ls \n",messageConvertie);
				break;
			case 3:
				fwprintf(fichier,L"\n ------   Chiffrement Vigenere   ------\n\n");
				fwprintf(fichier,L"   Votre message : %ls \n",messageSansAccent);
				fwprintf(fichier,L"   Votre Clef : %ls \n",clefV);
				fwprintf(fichier,L"   Votre message convertie: %ls \n",messageConvertie);
				break;
			case 4:
				fwprintf(fichier,L"\n ------   Dechiffrement Vigenere   ------\n\n");
				fwprintf(fichier,L"   Votre message : %ls \n",messageSansAccent);
				fwprintf(fichier,L"   Votre Clef : %ls \n",clefV);
				fwprintf(fichier,L"   Votre message convertie: %ls \n",messageConvertie);
				break;
			default:
				break;
			
		}
		fclose(fichier);
	}
	wprintf(L"\n ----------- FIN DU PROGRAMME -----------\n");
	
}



/*
	cd Documents/projet_c_iriart_ainhoa_tommy
	gcc main.c -o main
	./main
	Exemple test:
	
	Pour cesar :
	-------------------------
	code :dCode César
	clef:-1
	resultat :cBncd Bdrzq
	-----------------------
	code :Caé oui
	clef:24
	resultat :Ayc msg
	
	-----------------------
	code: ÀÁÂÃÄÅ àáâãäå Çç ÈÉÊË èéêë ÌÍÎÏ ìíîï Ññ ÒÓÔÕÖ òóôõö ÙÚÛÜ ùúûü Ýýÿ
	clef:-20
	resultat:GGGGGG gggggg Ii KKKK kkkk OOOO oooo Tt UUUUU uuuuu AAAA aaaa Eee
   code_resultat:
	
	------------------------
	code:ÀÁÂÃÄÅ àáâãäå Çç ÈÉÊË èéêë ÌÍÎÏ ìíîï Ññ ÒÓÔÕÖ òóôõö ÙÚÛÜ ùúûü Ýýÿ
	clef: 25
	resultat:ZZZZZZ zzzzzz Bb DDDD dddd HHHH hhhh Mm NNNNN nnnnn TTTT tttt Xxx
	
	
	Pour vigenere chiffrement:
	--------------------------------------
	code :dCode Vigenere automatiquement
	clef:CLE
	resultat :fNsfp Zkrippvg lyvzqcemsfioprv
	
	---------------------------------------
	code : Hamtaro est trop mimi
	clef: MIMI
	resultat Tiybmza meb fzax yqyq
	---------------------------------------
	
	code:ÀÁÂÃÄÅ àáâãäå Çç ÈÉÊË èéêë ÌÍÎÏ ìíîï Ññ ÒÓÔÕÖ òóôõö ÙÚÛÜ ùúûü Ýýÿ
	clef:CLE
	resultat:CLECLE clecle En IGPI gpig TMKT mktm Py SQZSQ zsqzs WFYW fywf Caj
		 CLECL eclecl Ge PIGP igpi KTMK tmkt Rp ZSQZS qzsqz YWFY wfyw Jca
	
	Pour vigenere dechiffrement:
	------------------------------------------------
	code :JBCWLCWGCWCICWXBNZUSVSWH JPLR EWPSWSAS FCF
	cle:JOJO
	resultat:ANTICONSTITUTIONELLEMENT ABCD VIGENERE WOW
	
	---------------------------------------------------
	code: LW FU OSBH OE FILGMGX IVFUS MSFOFE XX BZ RANX FOZGXV WSE THQTHQS VILH FRXW MFQS MVXG UMISKHMNM THID LT WTBFE GSNPXIX TTG ZOG TEIE DX QTBSEK GBBC FKYBH QT EIZIYE IEK XAUKW LWZOG XN GQRTW IOE EG FHBZE LEGHQE IPNG FAKH OSDY BQICDTTRM RANM JHFSEM XAWE PEITGQ
	cle:TOMATE
	resultat: SI TU VOIT CE MESSAGE ECRIS TOMATE ET IL FAUT MANGER DES TOMATES CEST TRES TRES TRES IMPORTANT POUR LA SANTE NOUBLIE PAS NON PLUS DE MANGER CINQ FRUIT ET LEGUME PAR JOURS SINON TU SERAS PAS EN BONNE SANTEE PLUS TARD VERY IMPORTANT DONT FORGET THIS PLEASE

*/

//Ajout bibliothèque
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//En-tête fonction
int nonAutoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent);
int verifExistaccent(wchar_t *message,wchar_t *accent);
void convertionMessage(wchar_t *message,wchar_t *messageSansAccent,wchar_t *maj,wchar_t *min);
int estMaj(wchar_t *maj,wchar_t lettre);
int indice(wchar_t *min,wchar_t *maj,wchar_t lettre);
void cesar(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC);
void vigenere(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);
void copieClef(wchar_t *messageSansAccent,wchar_t *clefV,wchar_t *copieClef);
void vigenereDechiffrement(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);

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

	// Demande de saisir le message
	wprintf(L"\n\n ----------- La saisie du message -----------\n\n");
	wprintf(L"   Saisir votre message : ");
	fgetws(message,300,stdin);
	
	// Vérification caractère non autoriser
	while(nonAutoriser(message,min,maj,accent)==2){
		wprintf(L"\n   ! ERREUR ! : caractere non autorise ");
		wprintf(L"   Resaisir votre message : ");
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
	wprintf(L"  	2) Chiffrement Vigenere\n");
	wprintf(L"  	3) Dechiffrement Vigenere\n");
	wprintf(L"\n   Saisir votre algorithme : ");
	wscanf(L"%d",&choixAlgo);
	
	
	// Verification 
	while(choixAlgo<1 || choixAlgo>3){
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
			wprintf(L"\n ----------- Chiffrement Vigenere ----------- \n");
			wprintf(L"\n   Saisir la clef(un mot) : ");
			wscanf(L"%ls",&clefV);
			wprintf(L"\n   Votre Clef : %ls \n",clefV);
			vigenere(messageSansAccent,min,maj,messageConvertie,clefV);
			wprintf(L"   Votre message convertie: %ls \n",messageConvertie);
			break;
		case 3:
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
				fwprintf(fichier,L"\n ------   Chiffrement Vigenere   ------\n\n");
				fwprintf(fichier,L"   Votre message : %ls \n",messageSansAccent);
				fwprintf(fichier,L"   Votre Clef : %ls \n",clefV);
				fwprintf(fichier,L"   Votre message convertie: %ls \n",messageConvertie);
				break;
			case 3:
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

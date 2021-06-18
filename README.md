# projet_c_sujet_3
### Le but

Développer une application qui permet de crypter ou de décrypter un message saisi par l'utilisateur à l'aide de deux algoritmes : 
1. Cesar
2. vigenere

### Comment compiler ou exécuter le programme
- Compiler : make all
- Exécuter : ./main
- Supprimer les .o et votreConvertion.txt : make clean

### Desciption de chaque fontion

#### Fichier fonctions.h

```c
// Fonction nonAutoriser
// Les paramètres : message utilisateur, tableau des minuscules, tableau des majuscules et le tableau des accents
// Retourne 2 si le caractère n'est pas une minuscule,  une majuscule,  un accent ou un espace
// Sinon retourne 1
int nonAutoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent);
```
```c
// Fonction verifExistaccent
// Les paramètres : message utilisateur et le tableau des accents 
// Retourne 1 si il y a un accent
// Sinon retourne 0
int verifExistaccent(wchar_t *message,wchar_t *accent);
```

```c
// Procedure convertionMessage
// Les paramètres: message utilisateur, message sans accent de l'utilisateur(sortie), tableau des minuscules et tableau des majuscules 
// Stock dans le tableau messageSansAccent le message de l'utilisateur sans accent
void convertionMessage(wchar_t *message,wchar_t *messageSansAccent,wchar_t *maj,wchar_t *min);
```

```c
// Fonction verifExistaccent
// les paramètres : tableau des majuscules et la lettre à l'indice i du message
// Retourne 0 si la lettre est une majuscule
// Sinon retourne 1
int estMaj(wchar_t *maj,wchar_t lettre);
```

```c
// Fonction indice
// les paramètres : tableau des minuscules, tableau des majuscules et la lettre à l'indice i du message
// Retourne indice en fonction du tableau minucules et majuscules
int indice(wchar_t *min,wchar_t *maj,wchar_t lettre);

```

```c
// Procedure cesar
// Les paramètres:  message sans accent de l'utilisateur, message convertie(sortie), tableau des minuscules et tableau des majuscules et la clef saisie par l'utiisateur dans le main
// Stock dans le resultat dans message convertie 
void cesar(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC);
```
```c
// Procedure cesarDechiffrement
// Les paramètres:  message sans accent de l'utilisateur, message convertie(sortie), tableau des minuscules et tableau des majuscules et la clef saisie par l'utiisateur dans le main
// Stock dans le resultat dans message convertie 
void cesarDechiffrement(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC);
```

```c
// Procedure vigenere
// Les paramètres:  message sans accent de l'utilisateur,  tableau des minuscules et tableau des majuscules, message convertie(sortie) et la clef saisie par l'utiisateur dans le main
// Stock dans le resultat dans message convertie 
void vigenere(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);
```

```c
// Procedure copieClef
// Les paramètres:  message sans accent de l'utilisateur, La clef saisie par l'utilisateur dans le main, tableau de la clef en fonction du nombre d'élement du message de l'utilisateur
// Stock dans le resultat dans copie clef
void copieClef(wchar_t *messageSansAccent,wchar_t *clefV,wchar_t *copieClef);
```

```c
// Procedure vigenereDechiffrement
// Les paramètres:  message sans accent de l'utilisateur,  tableau des minuscules et tableau des majuscules, message convertie(sortie) et la clef saisie par l'utiisateur dans le main
// Stock dans le resultat dans message convertie 
void vigenereDechiffrement(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);
```

```c
// Procedure cartourche
// Affiche la cartouche
void cartourche();
```
### Un exemple de déroulement

1- Affiche de la cartouche
<pre>
/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : IRIART Ainhoa                                                *
*                                                                             *
*  Nom-prénom2 : Philippe Tom                                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
******************************************************************************/
</pre>
2- Demande de la saisie du message, vous rentrez : ÀÁÂÃÄÅ àáâãäå Çç,
<pre>
----------- La saisie du message -----------

   Saisir votre message : ÀÁÂÃÄÅ àáâãäå Çç,
   
</pre>
3- Il vous affiche une erreur vous ressaisissez le message : ÀÁÂÃÄÅ àáâãäå Çç
<pre>
 ! ERREUR ! : caractere non autorise 
   Resaisir votre message : ÀÁÂÃÄÅ àáâãäå Çç 

   Votre message contient des accents. 
   Convertion en cour ... 


   Votre message : AAAAAA aaaaaa Cc 
   
</pre>
4- Choix de l'algorithme: 
<pre>
Veuillez choisir un algorithme :  
  	1) Chiffrement Cesar  
  	2) Dechiffrement Cesar
  	3) Chiffrement Vigenere
  	4) Dechiffrement Vigenere
</pre>
5- Vous saisissez 3 qui correspond au chiffrement vigenère
<pre>
Saisir votre algorithme : 3

   Votre choix : 3
  	
</pre>
6- Vous saisissez la clef: cle
<pre>
----------- Chiffrement Vigenere ----------- 

   Saisir la clef(un mot) : cle

   Votre Clef : cle 
   Votre message convertie: CLECLE clecle En
</pre>
7- Vous choisissez de ne pas enregistrer le fichier 
<pre>
----------- Resultat dans un fichier .txt ----------- 

   Voulez-vous mettre le resultat dans un fichier votreConvertion.txt ? 
  	Taper 0 pour oui.
  	Taper 1 pour non.

   Votre reponse : 1

 ----------- FIN DU PROGRAMME -----------
</pre>

  

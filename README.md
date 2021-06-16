# projet_c_sujet_3
### Le but

Développer une application qui permet de crypter ou de decrypter un message saisie par l'utilisateur à l'aide de deux algoritmes : 
1. Cesar
2. vigenere

### Comment compiler ou exécuter le programme
- Compiler : make all
- Exécuter : ./main
- supprimer les .o et votreConvertion.txt : make clean

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
### Un exemple
  

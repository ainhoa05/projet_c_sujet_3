#include <stddef.h>
int nonAutoriser(wchar_t *message,wchar_t *min,wchar_t *maj,wchar_t *accent);
int verifExistaccent(wchar_t *message,wchar_t *accent);
void convertionMessage(wchar_t *message,wchar_t *messageSansAccent,wchar_t *maj,wchar_t *min);
int estMaj(wchar_t *maj,wchar_t lettre);
int indice(wchar_t *min,wchar_t *maj,wchar_t lettre);
void cesar(wchar_t *messageSansAccent,wchar_t *messageConvertie, wchar_t *min,wchar_t *maj,int clefC);
void vigenere(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);
void copieClef(wchar_t *messageSansAccent,wchar_t *clefV,wchar_t *copieClef);
void vigenereDechiffrement(wchar_t *messageSansAccent,wchar_t *min,wchar_t *maj,wchar_t *messageConvertie, wchar_t *clefV);

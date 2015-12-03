# libft
Premier projet de l'école 42 : coder une librairie `libft.a` à l'identique pour les fonctions de la première partie et en suivant les recommendations dans la seconde partie.
## Partie 1  
Consulter le `man` pour la description des fonctions suivantes :
* ft_memset
* ft_bzero  
* ft_memcpy
* ft_memccpy
* ft_memmove
* ft_memchr 
* ft_memcmp
* ft_strlen
* ft_strdup
* ft_strcpy
* ft_strncpy
* ft_strcat
* ft_strncat
* ft_strlcat
* ft_strchr
* ft_strrchr
* ft_strstrs
* ft_strnstr
* ft_strcmp
* ft_strncmp
* ft_atoi
* ft_isalpha
* ft_isdigit
* ft_isalnum
* ft_isascii
* ft_isprint
* ft_toupper
* ft_tolower


## Partie 2
* ft_memalloc  
   Alloue avec `malloc(3)` et retourne une zone de mémoire "fraiche". La mémoire allouée est intialisée à 0. Si l'allocation échoue, la fonction renvoie NULL.
* ft_memdel  
   Prend en paramètre l’adresse d’un pointeur dont la zone poin- tée doit être libéée avec `free(3)`, puis le pointeur est mis à NULL.
* ft_strnew  
   Alloue avec `malloc(3)` et retourne une chaine de caractère “fraiche” terminée par un `’\0’`. Chaque caractère de la chaine est initialisé à ’\0’. Si l’allocation echoue, la fonction renvoie NULL.
* ft_strdel  
   Prend en paramètre l’adresse d’une chaine de caractères qui doit être libérée avec `free(3)` et son pointeur mis à NULL.
* ft_strclr  
   Assigne la valeur `’\0’` à tous les caractères de la chaine passée en paramètre.
* ft_striter  
   Applique la fonction f à chaque caractère de la chaine de caractères passée en paramètre. Chaque caractère est passé par adresse à la fonction f afin de pouvoir être modifié si nécéssaire.
* ft_striteri
   Applique la fonction f à chaque caractère de la chaine de caractères passée en paramètre en précisant son index en pre- mier argument. Chaque caractère est passé par adresse à la fonction f afin de pouvoir être modifié si nécéssaire 
* ft_strmap
   Applique la fonction f à chaque caractère de la chaine de ca- ractères passée en paramètre pour créer une nouvelle chaine “fraiche” avec `malloc(3)` résultant des applications successives de f.
* ft_strmapi  
   Applique la fonction f à chaque caractère de la chaine de caractères passée en paramètre en précisant son index pour créer une nouvelle chaine “fraiche” avec `malloc(3)` résultant des applications successives de f.
* ft_strequ  
   Compare lexicographiquement s1 et s2. Si les deux chaines sont égales, la fonction retourne 1, ou 0 sinon.
* ft_strnequ  
   Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum ou bien qu’un `’\0’` ait été rencontré. Si les deux chaines sont égales, la fonction retourne 1, ou 0 sinon.

# libft
Premier projet de l'ecole 42 : coder une librairie `libft.a` à l'identique pour les fonctions de la premiere partie et en suivant les recommendations dans la seconde partie.
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
#### ft_memalloc
> Alloue avec `malloc(3)` et retourne une zone de memoire "fraiche". La memoire allouee est intialisee a 0. Si l'allocation echoue, la fonction renvoie `NULL`.

#### ft_memdel
> Prend en parametre l’adresse d’un pointeur dont la zone pointee doit etre liberee avec `free(3)`, puis le pointeur est mis a `NULL`.

#### ft_strnew
> Alloue avec `malloc(3)` et retourne une chaine de caractere “fraiche” terminee par un `’\0’`. Chaque caractere de la chaine est initialise a `’\0’`. Si l’allocation echoue, la fonction renvoie `NULL`.

#### ft_strdel
> Prend en parametre l’adresse d’une chaine de caracteres qui doit etre liberee avec `free(3)` et son pointeur mis a `NULL`.

#### ft_strclr
> Assigne la valeur `’\0’` a tous les caracteres de la chaine passee en parametre.

#### ft_striter
> Applique la fonction `f` a chaque caractere de la chaine de caracteres passee en parametre. Chaque caractere est passe par adresse a la fonction `f` afin de pouvoir être modifie si necessaire.

#### ft_striteri
> Applique la fonction `f` a chaque caractere de la chaine de caracteres passee en parametre en precisant son index en premier argument. Chaque caractere est passe par adresse a la fonction `f` afin de pouvoir etre modifie si necessaire.

#### ft_strmap
> Applique la fonction `f` a chaque caractere de la chaine de caracteres passee en parametre pour creer une nouvelle chaine “fraiche” avec `malloc(3)` resultant des applications successives de `f`.

#### ft_strmapi
> Applique la fonction `f` a chaque caractere de la chaine de caracteres passee en parametre en precisant son index pour creer une nouvelle chaine “fraiche” avec `malloc(3)` resultant des applications successives de `f`.

#### ft_strequ
> Compare lexicographiquement s1 et s2. Si les deux chaines sont egales, la fonction retourne 1, ou 0 sinon.

#### ft_strnequ
> Compare lexicographiquement s1 et s2 jusqu’a n caracteres maximum ou bien qu’un `’\0’` ait ete rencontre. Si les deux chaines sont egales, la fonction retourne 1, ou 0 sinon.


## Partie bonus
#### ft_lstnew
> Alloue avec `malloc(3)` et retourne un maillon “frais”. Les champs content et content_size du nouveau maillon sont initialises par copie des parametres de la fonction. Si le parametre `content` est nul, le champs `content` est initialise a `NULL` et le champs `content_size` est initialise a 0 quelque soit la valeur du parametre `content_size`. Le champ `next` est initialise a `NULL`. Si l’allocation echoue, la fonction renvoie `NULL`.

#### ft_lstdelone
> Prend en parametre l’adresse d’un pointeur sur un maillon et libere la memoire du contenu de ce maillon avec la fonction `del` passee en parametre puis libere la memoire du maillon en lui meme avec `free(3)`. La memoire du champ `next` ne doit en aucun cas être liberee. Pour terminer, le pointeur sur le maillon maintenant libere doit etre mis a `NULL` (de maniere similaire à la fonction ft_memdel).

#### ft_lstdel
> Prend en parametre l’adresse d’un pointeur sur un maillon et libere la memoire de ce
maillon et celle de tous ses successeurs l’un apres l’autre avec `del` et `free(3)`. Pour terminer, le pointeur sur le premier maillon maintenant libere doit etre mis à `NULL` (de maniere similaire à la fonction ft_memdel).

#### ft_lstadd
> Ajoute l'element `new` en tete de la liste.

#### ft_lstiter
> Parcourt la liste `lst` en appliquant a chaque maillon la fonction `f`.

#### ft_lstmap
> Parcourt la liste lst en appliquant à chaque maillon la fonction f et cree une nouvelle liste “fraiche” avec `malloc(3)` resultant des applications successives. Si une allocation echoue, la fonction renvoie `NULL`.

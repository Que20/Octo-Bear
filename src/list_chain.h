#ifndef LIST_CHAIN_H_INCLUDED
#define LIST_CHAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*
2 Repr�sentation chain�e
    * Permets de stacker un nombre infinite de donn�es sans avoir � r�allouer et d�placer les �l�ments d�j� stock�s
    * Utilise les pointeurs
    * La manipulation programmatique demande plus de rigueur puisqu'elle demande d'allouer et lib�rer fr�quemment de la m�moire

    Les listes chain�es sont un exemple canonique des structures auto-r�fer�es
    Une structure autorefer�e n'est rien d'autre qu'une structure qui s'utilise elle meme dans sa definition
*/

typedef struct s_list_chain {
    Variable * value;
    struct s_list_chain * next;
} t_list_chain;

/*
    On voit bien que le nombre next est du type que l'on est en train de definire. C'est le principe de l'autorefer�
    La representation chain�e utilise cette structure pour chainer les elements de la list en eux

    Contrairement aux representation contiques qui permet un acc�s aleatoi direct ( puisque calculable par offset * sizeof(type))
    La representation ne permet d'acceder � un element que de maniere sequentiel. C'est a dire que pour acceder au
    dernier element, il aura fallu visiter tous ls precedents

    schema representatif

    8 -> 7 -> 12
    |---|---|    |---|---|    |----|---|
    | 8 |  ----> | 7 |  ----> | 12 | x |
    |---|---|    |---|---|    |----|---|

*/

/** \brief Cr�e une nouvelle liste
 *
 * \param la valeur de la liste
 * \return un nouvelle maillon de la liste
 *
 */
t_list_chain * list_chain_new(Variable value);

/** \brief Affiche les valeur de la liste
 *
 * \param la liste chaine a afficher
 *
 */
//void list_chain_dispaly(t_list_chain * list_chain);

/** \brief Donne la taille de la liste
 *
 * \param la liste chaine a mesurer
 * \return la tille de la liste
 *
 */
unsigned int list_chain_size(t_list_chain * list_chain);

/** \brief Permet d'ajouter une valeur a la liste
 *
 * \param list_chain
 * \param value la valeur a ajouter
 * \return list_chain
 *
 */
t_list_chain * list_chain_append(t_list_chain * list_chain, Variable value);


#endif // LIST_CHAIN_H_INCLUDED

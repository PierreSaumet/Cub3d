/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:53:37 by psaumet           #+#    #+#             */
/*   Updated: 2020/03/12 19:43:44 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main: checks args, if == 2 checks the first args
** then start the parsing.
*/
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "gnl/get_next_line.h"
#include "../Cub3d/Cub3D/headers/cub3D.h"
#include "../Cub3d/Cub3D/headers/libft.h"

/*
La map doit être composée d uniquement ces 4 caractères : 0 pour les espaces
vides, 1 pour les murs, 2 pour un objet, N,S,E ou W qui représe
*/


// Tab contient le tableau 
// start la valeur de depart (1 ou 0 )
// val pour la direction ( N, S , E ,W )
typedef struct      s_pars2
{
    char        **tab;
    int         start;
    int         *pt_start;
    char        val;
    char        *pt_val;
}               t_pars2;

/*
void        ft_test(char *line, t_pars2 pars, int i)
{
    printf("Debut du parsing, i = %d=\n", i);

}*/

void        ft_init(t_pars2 *pars)
{
    printf("dans init pars\n");
    pars->tab = NULL;
    pars->start = 0;
    pars->pt_start = &pars->start;
    pars->val = '\0';
    pars->pt_val = &pars->val;
}


/*******************************************************
** TEST DE LISTE CHAINEES ET DE FILES
*******************************************************/

typedef struct Element Element;
struct Element
{
	char *line;
	Element *next;
};

typedef struct File File;
struct File
{
	Element *first;
};

File *initialize()
{
	File *file = malloc(sizeof(*file));
	file->first = NULL;

	return file;
}

/* This function will put a new element in the list
** 1) check the malloc -1 if it failed.
** 2) create new element
** 3) if the element is not he first element, put after all of them
** 4) if the element is the first one
*/

int	ft_putfile(File *file, char *str)
{
	Element *new = malloc(sizeof(*new));
	if (file == NULL || new == NULL)
		return -1;
	if (!(new->line = malloc(strlen(str) +1)))
		return -1;
	strcpy(new->line, str);
	new->next = NULL;
	if (file->first != NULL)
	{
		Element *actualelement = file->first;
		while (actualelement->next != NULL)
			actualelement = actualelement->next;
		actualelement->next = new;
	}
	else
	{
		file->first = new;
	}
	return 0;
}

int ft_deletefile(File *file)
{
	if (file == NULL)
		return -1;
	char *tmp;
	if (file->first != NULL)
	{
		Element *fileelement = file->first;
		tmp = fileelement->line;
		file->first = fileelement->next;
		free(fileelement->line);
		free(fileelement);
	}
	return 0;
}

int	ft_displayfile(File *file)
{
	if (file == NULL)
		return -1;
	Element *element = file->first;
	while (element != NULL)
	{
		printf("%s\n", element->line);
		element = element->next;
	}
	printf("\n");
	return 0;
}




int		ft_test(File *file)
{
	// afficher chaque caractere d'un element
	printf("dans test\n");
	Element *element = file->first;
	/*
	printf("1) -%s-\n", element->line);
	while (*element->line)
	{
		printf("%c\n", *element->line);
		element->line++;
	}*/
	// Test : supprimer chaque ligne vide ou avec un espace
	int i = 0;
	int len = strlen(element->line);
	printf("len = %d\n", len);
	while (*element->line)
	{
		if (*element->line == ' ')
			i++;
		element->line++;
	}
	if (i == len)
		return 1;
	else
		return 0;
	/*
	while (element != NULL)
	{
		i = 0;
		len = strlen(element->line);
		while (*element->line)
		{
			if (*element->line == ' ')
				i++;
			element->line++;
		}
		printf("i = %d et len = %d\n", i, len);
		if (i == len)
			ft_deletefile(element);
		element = element->next;
	}*/
}




/************************************************************
 * TEST DOUBLE LISTE CHAINEE
 * *************************************************************/
typedef struct Elem Elem;
struct Elem
{
	char *line;
	Elem *prev;
	Elem *next;
};

typedef struct List List;
struct List
{
	Elem *first;
	Elem *last;
};

// Initialise la liste
List *lst_init()
{
	List *file = malloc(sizeof(*file));
	file->first = NULL;
	file->last = NULL;

	return file;
}

// Insere a la fin =)
int ft_pushback(List *lst, char *str)
{
	Elem *new;
	if (!(new = malloc(sizeof(Elem))) || lst == NULL)
		return -1;
	if (!(new->line = malloc(strlen(str) +1)))
		return -1;
	strcpy(new->line, str);
	new->prev = lst->last;
	new->next = NULL;
	if (lst->last)
		lst->last->next = new;
	else
		lst->first = new;
	lst->last = new;
	return 0;
}

int ft_pushfront(List *lst, char *str)
{
	//PAS COMPLET
	Elem *new;
	if (!(new = malloc(sizeof(Elem))))
		return 1;
	strcpy(new->line, str);
	new->next = lst->first;
	new->prev = NULL;
	if (lst->first)
		lst->first->prev = new;
	else
		lst->last = new;
	lst->first = new;
	return 0;

}

/* Delete first item of the list */
Elem  *ft_delfront(List **lst)
{
	Elem *tmp;
	Elem *del;
	char *val;
	/*
	tmp = (*lst)->first;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(*lst);
	*lst = NULL;*/
	
	tmp = (*lst)->first;
	val = "\n";
	if (*lst == NULL)
		return NULL;
	if (!tmp)
		return NULL;
	//val = tmp->line;
	(*lst)->first = tmp->next;
	if ((*lst)->first)
		(*lst)->first->prev = NULL;
	else
		(*lst)->last = NULL;
	free(tmp->line);
	tmp->line = NULL;
	free(tmp);
	return (*lst)->first;
}
/* Free a pointer*/
void	ft_freelem(void *pt)
{
	free(pt);
}

/* Delete One elem of the list*/
Elem	*ft_delone(void(*del)(void *), Elem *elem, List *lst)
{
	Elem *tmp;
	Elem *check;
	check = lst->first;
	if (del)
	{
		tmp = elem;
		elem = elem->prev;
		elem->next = tmp->next;
		free(tmp->line);
		tmp->line = NULL;
		free(tmp);
	}
	elem = elem->next;
	return elem;
}

/* Display All element in the list*/
void	View(List *lst)
{
	Elem *elem;
	elem = lst->first;
	while (elem)
	{
		printf("%s\n", elem->line);
		elem = elem->next;
	}
}

/* Delete All the List*/
void Clear(List *lst)
{
	Elem *tmp;
	Elem *elem;
	elem = lst->first;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		free(tmp->line);
		tmp->line = NULL;
		free(tmp);
	}
	lst->first = NULL;
	lst->last = NULL;
}

/* Count the items from a list*/
int		ft_lstcount(List *lst)
{
	Elem *elem;
	int i;

	elem = lst->first;
	i = 0;
	if (lst == NULL)
		return -1;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return i;
}

/* Count the character of a line's elem of a list*/
int		ft_lststrlen(Elem *elem)
{
	int  i;

	i = 0;
	if (elem->line == NULL)
		return -1;
	while (*elem->line)
	{
		i++;
		elem->line++;
	}
	return i;
}

int		ft_checkspace(char *str)
{
	int i = 0;
	int j = 0;
	int len = strlen(str);
	while (str[i])
	{
		if (isspace(str[i]))
			j++;
		i++;
	}
	printf("j = %d et len = %d et STR = %s\n", j, len, str);
	if (len == j)
		return 0;
	else
	{
		return 1;
	}
	
}

/* Open the file descriptor, and use a function to check the buffer */
void		ft_parsing(char *argv)
{
	List *mylst;
	int		fd;
	int		ret;
	char	*line;

	fd = open(argv, O_RDONLY);
	ret = 1;
	line = NULL;
	mylst = lst_init();
	if (fd == -1)
		printf("Error File Descriptor %d\n", fd);
	else
	{
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			ft_pushback(mylst, line);
			free(line);
		}
		line = NULL;
		close(fd);
	}
	/*
	Elem *elem;
	elem = mylst->first;
	while (elem)
	{
		if (strcmp(elem->line, "2") == 0)
			elem = ft_delone(ft_freelem, elem);
		else
			elem = elem->next;
	}*/
	int lst_len;
	lst_len = ft_lstcount(mylst);
	printf("Total elem = %d\n", lst_len);
	printf("\n\nAvant \n");
	View(mylst);


	// TEST supprimer un element = 3    == OK    
	// + test si ligne n'a que des espaces, la supprimer
	Elem *elem;
	elem = mylst->first;
	int i = 0;
	int len_line = 0;
	while (elem)
	{
		/*
		printf("result comparaison %d\n", strcmp(elem->line, "\n"));
		printf("result comparaison %d\n", strcmp(elem->line, " "));
		printf("result comparaison %d\n", strcmp(elem->line, "\t"));
		printf("result comparaison %d\n", strcmp(elem->line, ""));*/
		/*i = 0;
		len_line = strlen(elem->line);
		printf("len_line %d\n", len_line);
		while (*elem->line)
		{
			if (isspace(*elem->line))
				i++;
			elem->line++;
		}
		printf("len = %d et i = %d\n", len_line, i);
		if (len_line == i)
		{
			if (elem == mylst->first)
			{
				printf("OUI\n");
				int k = 0;
				elem = ft_delfront(&mylst);
				printf("k %d\n", k);
				//elem = elem->next;
				printf("SUIVANMT = %s\n", elem->line);
				//mylst->first = elem;
			}
			else
				elem = ft_delone(ft_freelem, elem, mylst);
		}
		else
		{
			printf("line = %s\n", elem->line);
			elem = elem->next;
		}*/
		printf("diff = %d\n", ft_checkspace(elem->line));
		if ((strcmp(elem->line, "") == 0) || (ft_checkspace(elem->line) == 0))
		{
			printf("line = -%s-\n", elem->line);
			if (elem == mylst->first)
			{
				printf("OUI\n");
				int k = 0;
				elem = ft_delfront(&mylst);
				printf("k %d\n", k);
				//elem = elem->next;
				printf("SUIVANMT = %s\n", elem->line);
				//mylst->first = elem;
			}
			else
				elem = ft_delone(ft_freelem, elem, mylst);
		}
		else
		{
			printf("line = -%s-\n", elem->line);
			elem = elem->next;
		}
		
	}
	printf("\n\nAPRES \n");
	View(mylst);
	Clear(mylst);
	free(mylst);
}


int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("ERROR need 1 argument with the extension '.cub'\n");
		return (-1);
	}
	else
	{
		ft_parsing(argv[1]);
	}
	return (0);
}

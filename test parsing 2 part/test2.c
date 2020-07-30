#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "gnl/get_next_line.h"




/*
int				ft_index(char const *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if ((!dest && !src) || dest == src)
		return (dest);
	cdest = dest;
	csrc = src;
	i = 0;
	if (dest <= src)
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	else
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	return (dest);
}

char			*ft_strnjoin(char *s1, char const *s2, long n)
{
	long			j;
	char			*new;
	unsigned long	i;

	i = s1 == ((void*)0) ? 0 : ft_strlen(s1);
	j = ft_strlen(s2);
	if (n == -1 || n > j)
		n = j;
	if (!(new = (char*)malloc(sizeof(char) * (i + n + 1))))
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i] != '\0')
			new[i] = s1[i];
		free(s1);
	}
	j = -1;
	while (j < n && s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[25 + 1];
	int			ret;
	int			i;

	if (!line || fd < 0 || 25 < 0 || read(fd, buf, 0) == -1)
		return (-1);
	i = ft_index(buf, '\n');
	*line = ft_strnjoin(((void*)0), buf, i);
	ft_memmove(buf, &buf[i + 1], 25 - i);
	if (i != -1)
		return (1);
	while ((ret = read(fd, buf, 25)) != -1)
	{
		buf[ret] = '\0';
		if (ret == 0)
			return (0);
		i = ft_index(buf, '\n');
		*line = ft_strnjoin(*line, buf, i);
		ft_memmove(buf, &buf[i + 1], (i == -1 ? 0 : 25 - i));
		if (i != -1)
			return (1);
	}
	return (ret);
}

*/




struct node
{
    char *data;
    struct node *p_next;
    struct node *p_prev;
};


typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
} Dlist;

Dlist *dlist_new(void)
{
    Dlist *p_new = malloc(sizeof *p_new);
    if (p_new != NULL)
    {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return p_new;
}

Dlist *dlist_remove_id(Dlist *p_list, int position)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        int i = 1;
        while (p_temp != NULL && i <= position)
        {
            if (position == i)
            {
                if (p_temp->p_next == NULL)
                {
                    printf("dernier elem \n");
                    p_list->p_tail = p_temp->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_temp->p_prev == NULL)
                {
                    printf("premier elemn\n");
                    p_list->p_head = p_temp->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    printf("au milieu elem\n");
                    p_temp->p_next->p_prev = p_temp->p_prev;
                    p_temp->p_prev->p_next = p_temp->p_next;
                }
                free(p_temp);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
            i++;
        }
    }
    return p_list;
}


Dlist *dlist_append(Dlist *p_list, char *data)
{
    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
    {
        struct node *p_new = malloc(sizeof *p_new); /* Création d'un nouveau node */
        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
        {
            p_new->data = data; /* On 'enregistre' notre donnée */
            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
            if (p_list->p_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
            {
                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
                p_list->p_head = p_new; /* On fait pointer la tête de liste vers le nouvel élément */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers le nouvel élément */
            }
            else /* Cas où des éléments sont déjà présents dans notre liste */
            {
                p_list->p_tail->p_next = p_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
                p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
            }
            p_list->length++; /* Incrémentation de la taille de la liste */
        }
    }
    return p_list; /* on retourne notre nouvelle liste */
}

Dlist *dlist_remove_all(Dlist *p_list, char *data)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            if (p_temp->data == data)
            {
                struct node *p_del = p_temp;
                p_temp = p_temp->p_next;
                if (p_del->p_next == NULL)
                {
                    p_list->p_tail = p_del->p_prev;
                    p_list->p_tail->p_next = NULL;
                }
                else if (p_del->p_prev == NULL)
                {
                    p_list->p_head = p_del->p_next;
                    p_list->p_head->p_prev = NULL;
                }
                else
                {
                    p_del->p_next->p_prev = p_del->p_prev;
                    p_del->p_prev->p_next = p_del->p_next;
                }
                free(p_del);
                p_list->length--;
            }
            else
            {
                p_temp = p_temp->p_next;
            }
        }
    }
    return p_list;
}

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void dlist_display(Dlist *p_list)
{
    if (p_list != NULL)
    {
        struct node *p_temp = p_list->p_head;
        while (p_temp != NULL)
        {
            printf("%s -> ", p_temp->data);
            //ft_putstr(p_temp->data);
            fflush(stdout);
            p_temp = p_temp->p_next;
        }
    }
    printf("NULL\n");
}

void dlist_delete(Dlist **p_list)
{
    if (*p_list != NULL)
    {
        struct node *p_temp = (*p_list)->p_head;
        while (p_temp != NULL)
        {
            struct node *p_del = p_temp;
            p_temp = p_temp->p_next;
            free(p_del);
        }
        free(*p_list), *p_list = NULL;
    }
}



/*
//FONCTIONNE
int main()
{
    Dlist *test = dlist_new();
    dlist_append(test, "line");
    dlist_append(test, "");
    dlist_append(test, "");
    dlist_append(test, "line");
    dlist_append(test, "");
    dlist_append(test, "");
    dlist_append(test, "line");
    dlist_append(test, "");
    dlist_append(test, "line");
    dlist_append(test, "");
    dlist_append(test, "");
    dlist_append(test, "");
    dlist_display(test);
    dlist_remove_all(test, "");
    dlist_display(test);
    dlist_delete(&test);
}*/


int main(int argc, char **argv)
{
    int		fd;
	int		ret;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	ret = 1;
	line = NULL;
	

    Dlist *test = dlist_new();

    Dlist *test2 = dlist_new();
    char *pd = "line";
    dlist_append(test2, "1");
    //free(pd);
    pd = "";
    dlist_append(test2, "2");
    dlist_append(test2, "3");
    dlist_append(test2, "4");
    dlist_append(test2, "5");
    dlist_append(test2, "6");
    dlist_append(test2, "7");
    dlist_append(test2, "8");
    dlist_append(test2, "9");
    dlist_append(test2, "10");
    dlist_append(test2, "11");
    dlist_append(test2, "12");
    dlist_append(test2, "13");
	if (fd == -1)
		printf("Error File Descriptor %d\n", fd);
	else
	{
        char *tmp;
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			dlist_append(test, line);
            dlist_display(test);
			//free(line);
		}
        //dlist_remove_id(test, 13);

        
        //free(line);
		line = NULL;
		close(fd);
	}


    printf("1\t");
    dlist_display(test);
    printf("\n2\t");
    dlist_display(test2);

    printf("longueur liste 1 = %ld et longueur liste 2 %ld\n", test->length, test2->length);
    //
    
    
    //dlist_remove_all(test, "");
    //dlist_display(test);
    //dlist_delete(&test);
}
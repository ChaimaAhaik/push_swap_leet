/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:38 by cahaik            #+#    #+#             */
/*   Updated: 2024/05/26 09:16:52 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct var_lst
{
	size_t	i;
	size_t	index;
	size_t	start;
}				t_help;

char	*get_next_line(int fd);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *sttc, char *buff);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	list_sorted(t_list *a, t_list *b);
int		list_is_sorted(t_list *a);
int		ft_lstsize(t_list *lst);
int		ft_atoi(char *str, int *err);
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		max_number(t_list *a, int size);
int		min_number(t_list *a, int size);
int		max_section(t_list *b, int max, int size);
int		ft_best_range(int size);
int		sign_checker(char *str, int i, char c, char a);
int		space_checker(char *str, int i);
int		check_input(t_list *lst, int nbr);
int		check_for_char(char *str);
int		ft_fill_free(char **t, size_t index);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
size_t	ft_strlen(char *str);
void	index_func(t_list **a);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		moves(t_list **a, t_list **b);
int		ft_strcmp(char *dest, char *src);
int		nbr(char *str, t_list **number);
int		moves_cmp(t_list **a, t_list **b, char *p);
int		ft_free_all(char **t, size_t index);
#endif

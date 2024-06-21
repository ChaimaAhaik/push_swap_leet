#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
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
size_t	ft_strlen(const char *str);
void	stack_3(t_list **a);
void	stack_5(t_list **a, t_list **b);
void	push_sorting(t_list **a, t_list **b);
void	my_stacks(t_list **a);
void	push_a(t_list **a, t_list **b, char c);
void	reverse_rotr(t_list **a, t_list **b);
void	reverse_rotab(t_list **a, int flag, char c);
void	swap_s(t_list **a, t_list **b);
void	swap_ab(t_list **a, int flag, char c);
void	rotate_ab(t_list **a, int flag, char c);
void	rotate_r(t_list **a, t_list **b);
void	push_to_b(t_list **a, t_list **b, int range_l);
void	index_func(t_list **a);
int		nbr(char *str, t_list **number);
int		ft_free_all(char **t, size_t index);

#endif

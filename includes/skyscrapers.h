#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	validate(int args_count, char **args);
char **get_tips(char *arg, int size);
int	get_size(char *str);
int	solve(char **tips, char **final_board, int size);
char **get_empt_brd(int	size);
void print_brd(char **arr, int size);
void free_brd(char **arr, int size);

#endif

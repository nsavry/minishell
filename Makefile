NAME = minishell

FTC =	ft_main.c\
		ft_env.c\
		ft_cmd.c\
		ft_builtin.c\
		ft_builtin_two.c\
		ft_integrity.c\
		ft_prompt.c\
		ft_generate_prompt.c\
		ft_signal.c\

FTCS = $(subst ft,srcs/ft,$(FTC))

FTO = $(subst .c,.o,$(FTCS))

#FLAGS = -Wall -Wextra -Werror
FLAGS = 

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@make -C ./libft
	@gcc -o $(NAME) $(FTO) -L./libft -lft
	@echo "\033[32m$(NAME) created!\033[0m"

%.o: %.c
	@gcc $(FLAGS) -I./libft/includes -I./includes -c $< -o $@
	@echo "\033[33m.\033[0m\c"

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)
	@echo "\033[33m$(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fcleana
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted!\033[0m"

re: fclean all

INCLUDE = minitalk.h
SRCS_SVR = server.c utils.c
SRCS_CLT = client.c utils.c
SRCS_SVR_BONUS = server_bonus.c utils.c
SRCS_CLT_BONUS = client_bonus.c utils.c

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/

SRCS_SVR_OBJS = $(addprefix $(OBJS_DIR), $(SRCS_SVR:.c=.o))
SRCS_CLT_OBJS = $(addprefix $(OBJS_DIR), $(SRCS_CLT:.c=.o))
SRCS_SVR_BONUS_OBJS = $(addprefix $(OBJS_BONUS_DIR), $(SRCS_SVR_BONUS:.c=.o))
SRCS_CLT_BONUS_OBJS = $(addprefix $(OBJS_BONUS_DIR), $(SRCS_CLT_BONUS:.c=.o))

NAME_SVR = server
NAME_CLT = client
NAME_SVR_BONUS = server_bonus
NAME_CLT_BONUS = client_bonus

CC = cc
CFLAGS = -Werror -Wextra -Wall

all: $(OBJS_DIR) $(NAME_CLT) $(NAME_SVR)

bonus: $(OBJS_BONUS_DIR) $(NAME_CLT_BONUS) $(NAME_SVR_BONUS)

$(OBJS_DIR):
	@$(CC) $(CFLAGS) -c $(SRCS_CLT) $(SRCS_SVR)
	@mkdir -p $@
	@mv *.o $@

$(OBJS_BONUS_DIR):
	@$(CC) $(CFLAGS) -c $(SRCS_CLT_BONUS) $(SRCS_SVR_BONUS)
	@mkdir -p $@
	@mv *.o $@

$(NAME_CLT): $(SRCS_CLT) Makefile minitalk.h
	@$(CC) $(CFLAGS) -o $@ $(SRCS_CLT_OBJS)
	@printf "\033[0;32mClient Complied\n\e[0m"

$(NAME_SVR): $(SRCS_SVR) Makefile minitalk.h
	@$(CC) $(CFLAGS) -o $@ $(SRCS_SVR_OBJS)
	@printf "\033[0;32mServer Complied\n\e[0m"

$(NAME_CLT_BONUS): $(SRCS_CLT_BONUS) Makefile minitalk.h
	@$(CC) $(CFLAGS) -o $@ $(SRCS_CLT_BONUS_OBJS)
	@printf "\033[0;32mClient Bonus Complied\n\e[0m"

$(NAME_SVR_BONUS): $(SRCS_SVR_BONUS) Makefile minitalk.h
	@$(CC) $(CFLAGS) -o $@ $(SRCS_SVR_BONUS_OBJS)
	@printf "\033[0;32mServer Bonus Complied\n\e[0m"

clean:
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@printf "\033[0;31mCleaning process done!\e[0m"

fclean:
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@rm -rf $(NAME_CLT) $(NAME_SVR) $(NAME_CLT_BONUS) $(NAME_SVR_BONUS)
	@printf "\033[0;31mFile cleaning process done!\n\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus
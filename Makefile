INCLUDE = minitalk.h
SRCS_SVR = server.c utils.c
SRCS_CLT = client.c utils.c

OBJS_DIR = objs/

SRCS_SVR_OBJS = $(addprefix $(OBJS_DIR), $(SRCS_SVR:.c=.o))
SRCS_CLT_OBJS = $(addprefix $(OBJS_DIR), $(SRCS_CLT:.c=.o))

NAME_SVR = server
NAME_CLT = client

CC = cc
CFLAGS = -Werror -Wextra -Wall

all: $(OBJS_DIR) $(NAME_CLT) $(NAME_SVR)

$(OBJS_DIR):
	@$(CC) $(CFLAGS) -c $(SRCS_CLT) $(SRCS_SVR)
	@mkdir -p $@
	@mv *.o $@

$(NAME_CLT):
	@$(CC) $(CFLAGS) -o $@ $(SRCS_CLT_OBJS)
	@printf "Client Complied\n"

$(NAME_SVR):
	@$(CC) $(CFLAGS) -o $@ $(SRCS_SVR_OBJS)
	@printf "Server Complied\n"

clean:
	@rm -rf $(OBJS_DIR)
	@printf "Cleaning process done!"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME_CLT) $(NAME_SVR)
	@printf "Fcleaning process done!\n"

re: fclean all

.PHONY: clean fclean re all
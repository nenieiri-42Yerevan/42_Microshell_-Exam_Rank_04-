NAME			= microshell

TMP				= tmp

SRCS			= $(wildcard ./srcs/*.c)

OBJS			= $(patsubst ./srcs/%.c, ./$(TMP)/%.o, $(SRCS))

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -rf

.PHONY:			all clean fclean re

./$(TMP)/%.o:	./srcs/%.c
				@$(CC) $(CFLAGS) -o $@ -c $<

all:			$(NAME)

$(NAME):		$(TMP) $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(TMP):
				@mkdir $(TMP)

clean:
				@$(RM) $(TMP)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

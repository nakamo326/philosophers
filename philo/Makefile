NAME = philo

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCFILE =	srcs/main.c \
					srcs/libft.c \
					srcs/parse_arg.c


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
DEPS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.d))

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	gcc -g $(CFLAGS) $(OBJS) $(INCLUDES) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(*D)
	gcc -g -MMD -MP $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

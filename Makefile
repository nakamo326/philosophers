NAME := philo

CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./includes -I.

LIBFT := ./libft/libft.a

SRCFILE :=	srcs/main.c \
						srcs/testdir/test.c


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
# BINDIRS = $(subst srcs/, $(OBJDIR)/, $(SRCDIRS))
# OBJECTS = $(subst srcs/, $(OBJDIR)/, $(SRCFILE:.c=.o))

all: $(NAME)

$(NAME): $(BINDIRS) $(OBJECTS) $(LIBFT)
	gcc -g $(CFLAGS) $(OBJECTS) $(LIBFT) $(INCLUDES) -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(BINDIRS):
	@mkdir -p $(BINDIRS)

$(OBJDIR)/%.o: %.c
	gcc -g $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)
	$(RM) -rf $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJECTS) $(NAME)
	$(RM) -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re

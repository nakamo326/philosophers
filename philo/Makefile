NAME = philo

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
LIBS = -lpthread

# SRCFILE = $(shell find srcs -type f)
SRCFILE =	srcs/init.c \
					srcs/libft.c \
					srcs/main.c \
					srcs/routine_utils.c \
					srcs/routine.c \
					srcs/sims.c


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
DEPS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.d))

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $@
#	gcc -fsanitize=thread $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(*D)
	gcc -MMD -MP $(CFLAGS) $(INCLUDES) -c $< $(LIBS) -o $@
#	gcc -fsanitize=thread -MMD -MP $(CFLAGS) $(INCLUDES) -c $< $(LIBS) -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

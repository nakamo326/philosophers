NAME = philo

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRCFILE =	srcs/main.c \
					srcs/testdir/func.c


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))
DEPS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.d))
# BINDIRS = $(subst srcs/, $(OBJDIR)/, $(SRCDIRS))
# OBJECTS = $(subst srcs/, $(OBJDIR)/, $(SRCFILE:.c=.o))

all: $(NAME)

-include $(DEPS)

# $(NAME): $(BINDIRS) $(OBJS)
$(NAME): $(OBJS)
	gcc -g $(CFLAGS) $(OBJS) $(INCLUDES) -o $@

# $(BINDIRS):
#	@mkdir -p $(BINDIRS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(*D)
	gcc -g -MMD -MP $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

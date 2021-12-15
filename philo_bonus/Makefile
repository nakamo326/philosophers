NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
LIBS = -lpthread

# SRCFILE = $(shell find srcs -type f)
SRCFILE =	srcs/init_bonus.c \
					srcs/kitchen_timer_bonus.c \
					srcs/log_bonus.c \
					srcs/main_bonus.c \
					srcs/monitor_bonus.c \
					srcs/parse_arg_bonus.c \
					srcs/routine_action_bonus.c \
					srcs/routine_bonus.c \
					srcs/routine_utils_bonus.c \
					srcs/sims_bonus.c


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

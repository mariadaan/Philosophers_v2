NAME =			philo
VPATH =			./src/ ./src/utils ./lib_utils/ ./obj/ ./debug
SRCS =			main.c				\
				init_input.c		\
				run_simulation.c	\
				routine.c			\
				fork_utils.c		\
				time_utils.c		\
				print_utils.c		\
				philo_utils.c		\
				death_check.c		\
				\
				ft_atoi.c			\
				is_pos_int.c		\
				is_all_pos_ints.c	\
				ft_strcmp.c			\
				ft_itoa.c			\
				ft_strlen.c			\
				ft_putstr_fd.c		\
				error_msg.c			\
				printvar.c			\
				print_philos.c

OBJS =			$(SRCS:.c=.o)
OBJ_DIR =		./obj/
INCL_DIR =		 ./includes
CFLAGS =		-fsanitize=thread -Wall -Werror -Wextra -I${INCL_DIR}
CC =			gcc

ifdef WITH_SANITIZER
	CFLAGS =	-fsanitize=thread -g -Wall -Wextra -I${INCL_DIR}
else
	CFLAGS =	-Wall -Wextra -I${INCL_DIR}
endif

all: $(NAME)

$(NAME): $(OBJS)
	mkdir -p $(OBJ_DIR)
	mv *.o $(OBJ_DIR)
	${CC} ${CFLAGS} $(addprefix $(OBJ_DIR), $(OBJS)) -o ${NAME}

clean:
	rm -f $(addprefix $(OBJ_DIR), $(OBJS))

fclean:	clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re:	fclean $(NAME)


# debug rules:
debug:	all
	./philo 3 205 200 200 3

# to do: zorgen dat ie oneindig door blijft gaan bij een lange time to die
# nu stopt ie altijd na dat aantal seconden.

sanitize:	all
	$(MAKE) WITH_SANITIZER=1 re

.PHONY: all clean fclean re

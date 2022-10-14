NAME =			philo
VPATH =			./src/ ./utils/ ./lib_utils/ ./obj/ ./debug
SRCS =			main.c				\
				save_input.c		\
				init.c				\
				simulation.c		\
				routine.c			\
				find_fork.c			\
				milli_to_micro.c	\
				current_time.c		\
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
CFLAGS =		-fsanitize=address -Wall -Werror -Wextra -I${INCL_DIR}
CC =			gcc

ifdef WITH_SANITIZER
	CFLAGS =	-fsanitize=thread -g -Wall -Wextra -I${INCL_DIR}
else
	CFLAGS =	-fsanitize=address -g -Wall -Wextra -I${INCL_DIR}
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
	./philo 3 200 400 150 3

sanitize:	all
	$(MAKE) WITH_SANITIZER=1 re
	./philo 3 200 400 150 3

.PHONY: all clean fclean re

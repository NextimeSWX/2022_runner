# E89 Pedagogical & Technical Lab
# project:     template C repo
# created on:  2022-09-14 - 16:36 +0200
# 1st author:  Élise C. Philippe - eriizu
# description: Building the project

NAME	=	runner

SRCS	=	src/runner.c		\
		src/put_pixel.c		\
		src/position.c		\
		src/wall.c		\
		src/move_forward.c	\
		src/deg_to_rads.c	\
		src/z_key.c		\
		src/s_key.c		\
		src/q_key.c		\
		src/d_key.c		\
		src/left_key.c		\
		src/right_key.c		\
		src/pos_from_accurate.c \
		src/send_ray_len.c	\
		src/send_ray.c		\
		src/get_ratio.c		\
		src/get_value.c		\
		src/3d.c		\
		src/fov.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=	-llapin -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -lm

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re

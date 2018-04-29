CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
NAME = libft.a
CFLAGS += -I libft.h
LIBFT_SRC = ./ft_strrchr.c \
./ft_putstr.c \
./ft_islower.c \
./ft_strcmp.c \
./ft_strlcat.c \
./ft_memcpy.c \
./ft_memmove.c \
./ft_strsplit.c \
./ft_isspace.c \
./ft_strncpy.c \
./ft_lstmap.c \
./ft_lstadd.c \
./ft_striter.c \
./ft_strstr.c \
./ft_isdigit.c \
./ft_putnbr.c \
./ft_isupper.c \
./ft_memccpy.c \
./ft_strdel.c \
./ft_memchr.c \
./ft_bzero.c \
./ft_isalnum.c \
./ft_putstr_fd.c \
./ft_lstiter.c \
./ft_lstdelone.c \
./ft_toupper.c \
./ft_strcpy.c \
./ft_lstnew.c \
./ft_strdup.c \
./ft_putnbr_fd.c \
./ft_striteri.c \
./ft_strmap.c \
./ft_putendl_fd.c \
./ft_memdel.c \
./ft_strnstr.c \
./ft_putchar.c \
./ft_isascii.c \
./ft_strlen.c \
./ft_strsub.c \
./ft_strnew.c \
./ft_memalloc.c \
./ft_putendl.c \
./ft_strncat.c \
./ft_itoa.c \
./ft_strncmp.c \
./ft_memcmp.c \
./ft_strtrim.c \
./ft_strequ.c \
./ft_putchar_fd.c \
./ft_memset.c \
./ft_isalpha.c \
./ft_strcat.c \
./ft_tolower.c \
./ft_strnequ.c \
./ft_strjoin.c \
./ft_atoi.c \
./ft_strclr.c \
./ft_strmapi.c \
./ft_isprint.c \
./ft_lstdel.c \
./ft_strchr.c \
./ft_realloc.c \
./ft_strccmp.c \
./get_next_line.c \
./ft_realloc_safe.c \
./ft_redblack.c \
./rb_family.c \
./tree_rotation.c \
./rb_cases.c \
./ft_queue.c \
./ft_pqueue.c \

LIBFT_OBJ = $(subst .c,.o, $(LIBFT_SRC))

all: $(NAME)

%.o: %.c \
	gcc $(CFLAGS) $(MALLOC_PATH) -c $? -o $@

$(NAME): $(LIBFT_OBJ)
	/bin/rm -f $(NAME)
	ar rcs $(NAME) $(LIBFT_OBJ)

re: fclean all

clean:
	/bin/rm -f $(LIBFT_OBJ)

fclean: clean
	/bin/rm -f $(NAME)
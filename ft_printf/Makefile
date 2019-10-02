C = gcc

NAME = libftprintf.a

LIBFT = libft

DIR_S = src

DIR_O = obj

SOURCES = ft_printf.c \
			first_flags.c \
			ft_itoal.c \
			handle_f.c \
			handle_d.c \
			handle_u.c \
			ft_itoal_u.c \
			unicode.c \
			handle_cs.c \
			handle_lcls.c \
			handle_x.c \
			handle_o.c \
			handle_b_x.c \
			setting.c \
			flags.c \
			ft_strjoin_free.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c ft_printf.h
	@mkdir -p obj
	@$(CC) -I . -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean re norme all clean
##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##
MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
NAME = libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRC	= my_compute_power_rec.c \
	  my_compute_square_root.c \
      my_find_prime_sup.c \
      my_getnbr.c \
      my_isneg.c \
      my_is_prime.c \
      my_putchar.c \
      my_put_nbr.c \
      my_putstr.c \
      my_revstr.c \
      my_showmem.c \
      my_showstr.c \
      my_sort_int_array.c \
      my_strcapitalize.c \
      my_strcat.c \
      my_strcmp.c \
      my_strcpy.c \
      my_strdup.c \
      my_str_isalpha.c \
      my_str_islower.c \
      my_str_isnum.c \
      my_str_isprintable.c \
      my_str_isupper.c \
      my_strlen.c \
      my_strlowcase.c \
      my_strncat.c \
      my_strncmp.c \
      my_strncpy.c \
      my_strndup.c \
      my_strstr.c \
      my_str_to_word_array.c \
      my_strupcase.c \
      my_swap.c \
      my_show_word_array.c \
      my_putnbr_base.c \
      my_put_float.c \
      my_nbr_to_str.c \
      my_char_isnum.c \
      my_char_is_specifier.c \
      len_nb.c \
      specifier_biga.c \
      specifier_a.c \
      specifier_b.c \
      specifier_bigb.c \
      specifier_c.c \
      specifier_di.c \
      specifier_bige.c \
      specifier_e.c \
      specifier_fbigf.c \
      specifier_bigg.c \
      specifier_g.c \
      specifier_m.c \
      specifier_n.c \
      specifier_o.c \
      specifier_p.c \
      specifier_po.c \
      specifier_bigs.c \
      specifier_s.c \
      specifier_u.c \
      specifier_bigx.c \
      specifier_x.c \
	  struct_prefill.c \
	  is_specifier.c \
	  fill_format_struct.c \
	  fill_specifier_struct.c \
	  fill_lenght_struct.c \
	  fill_width_struct.c \
	  fill_flag_struct.c \
	  erase_flags.c \
	  manage_spaces.c \
	  manage_zeros.c \
	  fill_precision_struct.c \
	  my_printf.c
# ─── Tools ───────────────────────────────────────────────────────────────
OBJ	= $(SRC:.c=.o)
RM = rm -rf
ECC = epiclang
%.o: %.c
	@$(ECC) -L../lib -lmy -Wno-unused-command-line-argument -c $< -o $@

# ─── Macro: Fancy Header ─────────────────────────────────────────────────
define pretty_header
	@echo "$(BOLD)$(GREEN)+========================================================+$(END)"
	@echo "$(BOLD)$(GREEN)|$(END)$(BOLD)$(WHITE)$(1)$(END)"
	@echo "$(BOLD)$(GREEN)+========================================================+$(END)"
endef

# ─── Rules ───────────────────────────────────────────────────────────────
all:	$(NAME)

$(NAME): $(OBJ)
	$(call pretty_header, 🚀 pre-Compiling : $(PROJECT) 🚀)
	@ar rc $(NAME) $(OBJ)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 copying libs 🚀)
	@cp $(NAME) ../
	@cp $(NAME) ../..
	@cp my.h ../../include/
	@echo "$(BOLD)$(WHITE) done $(END)"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

re: fclean all

# ─── Styles ──────────────────────────────────────────────────────────────
END = \033[0m
BOLD = \033[1m
ITALICS = \033[3m
UNDER = \033[4m
REV = \033[7m

# ─── Colors ──────────────────────────────────────────────────────────────
GREY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CYAN = \033[36m
WHITE = \033[37m
H_GREY = \033[90m
H_RED = \033[91m
H_GREEN = \033[92m
H_YELLOW = \033[93m
H_BLUE = \033[94m
H_PURPLE = \033[95m
H_CYAN = \033[96m
H_WHITE = \033[97m

# ─── Background ──────────────────────────────────────────────────────────
B_GREY = \033[40m
B_RED = \033[41m
B_GREEN = \033[42m
B_YELLOW = \033[43m
B_BLUE = \033[44m
B_PURPLE = \033[45m
B_CYAN = \033[46m
B_WHITE = \033[47m
HB_GREY = \033[100m
HB_RED = \033[101m
HB_GREEN = \033[102m
HB_YELLOW = \033[103m
HB_BLUE = \033[104m
HB_PURPLE = \033[105m
HB_CYAN = \033[106m
HB_WHITE = \033[107m

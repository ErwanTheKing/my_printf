##
## EPITECH PROJECT, 2025
## makefile
## File description:
## a banger
##

MAKEFLAGS += --no-print-directory

# ─── Project Info ────────────────────────────────────────────────────────
PROJECT = My_printf
NAME	= libmy.a

# ─── Sources ─────────────────────────────────────────────────────────────
SRCMANU =  lib/my/my_printf.c \
		    main.c

SRCTST = lib/my/my_printf.c \
	     lib/my/specifier_biga.c \
         lib/my/specifier_a.c \
         lib/my/specifier_b.c \
         lib/my/specifier_bigb.c \
         lib/my/specifier_c.c \
         lib/my/specifier_di.c \
         lib/my/specifier_bige.c \
         lib/my/specifier_e.c \
         lib/my/specifier_fbigf.c \
         lib/my/specifier_bigg.c \
         lib/my/specifier_g.c \
         lib/my/specifier_m.c \
         lib/my/specifier_n.c \
         lib/my/specifier_o.c \
         lib/my/specifier_p.c \
         lib/my/specifier_po.c \
         lib/my/specifier_bigs.c \
         lib/my/specifier_s.c \
         lib/my/specifier_u.c \
         lib/my/specifier_bigx.c \
         lib/my/specifier_x.c \
         lib/my/struct_prefill.c \
         lib/my/is_specifier.c \
         lib/my/fill_format_struct.c \
         lib/my/fill_specifier_struct.c \
         lib/my/fill_lenght_struct.c \
         lib/my/fill_width_struct.c \
         lib/my/fill_flag_struct.c \
         lib/my/erase_flags.c \
         lib/my/manage_spaces.c \
         lib/my/manage_zeros.c \
         lib/my/fill_precision_struct.c \
		 tests/unit_tests.c

# ─── Flags ───────────────────────────────────────────────────────────────
TESTSFLAGS = --coverage -lcriterion -lgcov
LIBSFLAGS = -L ./lib -I ./include -lmy -O3
DEBUGFLAGS = -L ./lib -I ./include -lmy -g3

# ─── Tools ───────────────────────────────────────────────────────────────
RM = rm -rf
ECC = epiclang
CC = clang
LIBS = -L ./lib -I ./include -lmy -g3

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

$(NAME): banner
	@make -C lib/my
	$(call pretty_header, 🚀 creating binary of : $(PROJECT) 🚀)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🚀 succesfuly compiled $(PROJECT)! 🚀)
	@make help

marie-camille:
	@cat peda/marie_camille.txt

eric:
	@cat peda/eric.txt

renaud:
	@cat peda/renaud.txt

darius:
	@cat peda/darius.txt
	@echo "\nça tourne !"

kristel:
	@cat peda/kristel.txt

banner:
	@echo ""
	@echo "$(GREEN)$(BOLD)======================================================"
	@echo "$(GREEN)$(BOLD)||  ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗  ||$(END)"
	@echo "$(GREEN)$(BOLD)||  ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝  ||$(END)"
	@echo "$(GREEN)$(BOLD)||  ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗    ||$(END)"
	@echo "$(GREEN)$(BOLD)||  ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝    ||$(END)"
	@echo "$(GREEN)$(BOLD)||  ██║     ██║  ██║██║██║ ╚████║   ██║   ██║       ||$(END)"
	@echo "$(GREEN)$(BOLD)||  ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝       ||$(END)"
	@echo "$(GREEN)$(BOLD)======================================================"
	@echo "         $(B_GREEN)$(ITALICS)$(BOLD)$(WHITE)Built with 💚 by Sacha🐈 and Erwan🙊 $(END)"
	@echo ""

manu_test:
	$(call pretty_header, 🚀 executing manual testing for : $(PROJECT) 🚀)
	@$(ECC) -o testing $(SRCMANU) $(LIBSFLAGS)
	@./testing

debug:
	$(call pretty_header, 🔎 compiling with debug flag for : $(PROJECT) 🔍)
	@$(CC) -o testing $(SRCMANU) $(DEBUGFLAGS)
	@echo "$(BOLD)$(WHITE) done $(END)"
	$(call pretty_header, 🐐 calling valgrind 🐐)
	@valgrind --leak-check=full --log-file=valgrind.log ./testing

unit_tests:
	@$(CC) -o unit_tests $(SRCTST) $(TESTSFLAGS) $(LIBSFLAGS)

tests_run: unit_tests
	@./unit_tests
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/unit_tests.c
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/unit_tests.c --branches

coverage: unit_tests
	@./unit_tests
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/unit_tests.c --html --html-details -o coverage.html
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/unit_tests.c --branches
	@xdg-open coverage.html

clean:
	$(call pretty_header, 🧹 Cleaning object files 🧹)
	@make clean -C lib/my/

fclean: clean
	$(call pretty_header, 🗑️ Full clean: objects binary tests coverage 🗑️)
	@$(RM) $(NAME) *.gcda *.gcno unit_tests testing testing *.html *.css *.log
	@make fclean -C lib/my/

re: fclean all

# ─── Help ────────────────────────────────────────────────────────────────
help:
	$(call pretty_header,📘 Available Commands 📘)
	@echo "$(GREEN)  make all        $(END)→ Compile the project"
	@echo "$(GREEN)  make debug      $(END)→ Compile with debug and run Valgrind"
	@echo "$(GREEN)  make manu_test  $(END)→ Run manual test binary"
	@echo "$(GREEN)  make tests_run  $(END)→ Run unit tests and coverage"
	@echo "$(GREEN)  make clean      $(END)→ Clean object files"
	@echo "$(GREEN)  make fclean     $(END)→ Clean all (bin/tests/coverage)"
	@echo "$(GREEN)  make re         $(END)→ Recompile everything"

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
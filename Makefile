##
## Makefile for Corewar in /CPE_2015_corewar
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Tue Feb 23 11:35:35 2016 Antoine Baché
## Last update Wed Mar 23 00:27:08 2016 Antoine Baché
##

DEBUG=			no

BONUS=			no

SRC_ASM_PREFIX=		src/asm/

SRC_ASM_FILES=		main.c			\
			header.c		\
			get_header.c		\
			parser.c		\
			write_file.c		\
			errors.c		\
			free.c			\
			getfunction.c		\
			getargs.c		\
			getvalue.c		\
			get_label.c		\
			select.c		\
			warnings.c		\
			bytecode.c		\
			epurstr.c		\
			epur_last.c		\
			check_str_tab.c		\
			check_label.c		\
			case/sti_write.c	\
			case/add_case.c		\
			case/ld_case.c		\
			case/live_case.c	\
			case/st_case.c		\
			case/sub_case.c		\
			case/and_case.c		\
			case/or_case.c		\
			case/xor_case.c		\
			case/zjmp_case.c	\
			case/ldi_case.c		\
			case/sti_case.c		\
			case/fork_case.c	\
			case/lfork_case.c	\
			case/lld_case.c		\
			case/lldi_case.c	\
			case/aff_case.c

SRC_CORE_PREFIX=	src/vm/

SRC_CORE_FILES=		main.c			\
			check_args.c		\
			errors.c		\
			init.c			\
			status_msg.c		\
			write_usage.c		\
			load_hero.c		\
			free.c			\
			debug.c			\
			vm.c			\
			place.c			\
			order.c			\
			dump.c			\
			exec.c			\
			select.c		\
			value.c			\
			bytecode.c		\
			options/n.c		\
			options/a.c		\
			options/dump.c		\
			case/add_case.c		\
			case/ld_case.c		\
			case/live_case.c	\
			case/st_case.c		\
			case/sub_case.c		\
			case/and_case.c		\
			case/or_case.c		\
			case/xor_case.c		\
			case/zjmp_case.c	\
			case/ldi_case.c		\
			case/sti_case.c		\
			case/fork_case.c	\
			case/lfork_case.c	\
			case/lld_case.c		\
			case/lldi_case.c	\
			case/aff_case.c		\
			case/load/add_case.c	\
			case/load/ld_case.c	\
			case/load/live_case.c	\
			case/load/st_case.c	\
			case/load/sub_case.c	\
			case/load/and_case.c	\
			case/load/or_case.c	\
			case/load/xor_case.c	\
			case/load/zjmp_case.c	\
			case/load/ldi_case.c	\
			case/load/sti_case.c	\
			case/load/fork_case.c	\
			case/load/lfork_case.c	\
			case/load/lld_case.c	\
			case/load/lldi_case.c	\
			case/load/aff_case.c

SRC_DECOMPILER_PREFIX=	src/decompiler/

SRC_DECOMPILER_FILES=	main.c			\
			check_file.c		\
			load_champ.c		\
			free.c			\
			loader.c		\
			bytecode.c		\
			select.c		\
			case/add_case.c		\
			case/ld_case.c		\
			case/live_case.c	\
			case/st_case.c		\
			case/sub_case.c		\
			case/and_case.c		\
			case/or_case.c		\
			case/xor_case.c		\
			case/zjmp_case.c	\
			case/ldi_case.c		\
			case/sti_case.c		\
			case/fork_case.c	\
			case/lfork_case.c	\
			case/lld_case.c		\
			case/lldi_case.c	\
			case/aff_case.c

SRC_TOOLS_PREFIX=	src/tools/

SRC_TOOLS_FILES=	my_bzero.c		\
			my_getnbr.c		\
			my_put_nbr.c		\
			my_putstr.c		\
			my_strcmp.c		\
			my_strcpy.c		\
			my_strlen.c		\
			my_strncat.c		\
			my_strncmp.c		\
			my_strncpy.c		\
			my_strndup.c		\
			my_write.c		\
			common_errors.c		\
			get_next_line.c		\
			is_num.c		\
			find_endian.c		\
			reverse_byte.c

SRC_ASM=		$(addprefix $(SRC_ASM_PREFIX),$(SRC_ASM_FILES))

SRC_CORE=		$(addprefix $(SRC_CORE_PREFIX),$(SRC_CORE_FILES))

SRC_DECOMPILER=		$(addprefix $(SRC_DECOMPILER_PREFIX),$(SRC_DECOMPILER_FILES))

SRC_TOOLS=		$(addprefix $(SRC_TOOLS_PREFIX),$(SRC_TOOLS_FILES))

SRC_CORE+=		$(SRC_TOOLS)

SRC_ASM+=		$(SRC_TOOLS)

SRC_DECOMPILER+=	$(SRC_TOOLS)

NAME_ASM=		asm/asm

NAME_CORE=		corewar/corewar

NAME_DECOMPILER=	bonus/decompiler

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

ifeq ($(BONUS), yes)
	CFLAGS+=	-D BONUS
endif

CC=			gcc

RM=			rm -f

OBJ_ASM=		$(SRC_ASM:.c=.o)

OBJ_CORE=		$(SRC_CORE:.c=.o)

OBJ_DECOMPILER=		$(SRC_DECOMPILER:.c=.o)

$(NAME_CORE):	$(SHOW_FLAGS) $(NAME_ASM) $(NAME_DECOMPILER) $(OBJ_CORE)
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled corewar"
	@$(CC) $(OBJ_CORE) -o $(NAME_CORE)


$(NAME_DECOMPILER):	$(OBJ_DECOMPILER)
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled decompiler"
	@$(CC) $(OBJ_DECOMPILER) -o $(NAME_DECOMPILER)

$(NAME_ASM):	$(OBJ_ASM)
ifeq ($(DEBUG), yes)
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
endif
	@echo -n "Flags: "
	@echo $(CFLAGS)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled asm"
	@$(CC) $(OBJ_ASM) -o $(NAME_ASM)

%.o:	%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME_ASM) $(NAME_CORE) $(NAME_DECOMPILER)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ_ASM)
	@$(RM) $(OBJ_CORE)
	@$(RM) $(OBJ_DECOMPILER)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME_ASM)
	@$(RM) $(NAME_CORE)
	@$(RM) $(NAME_DECOMPILER)

re:	fclean all

.PHONY:	all clean fclean re

##
## Makefile for Corewar in /CPE_2015_corewar
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Tue Feb 23 11:35:35 2016 Antoine Baché
## Last update Tue Feb 23 11:42:27 2016 Antoine Baché
##

DEBUG=			no

SRC_ASM_PREFIX=		src/asm/

SRC_ASM_FILES=		main.c

SRC_CORE_PREFIX=	src/corewar/

SRC_CORE_FILES=		main.c

SRC_ASM=		$(addprefix $(SRC_ASM_PREFIX),$(SRC_ASM_FILES))

SRC_CORE=		$(addprefix $(SRC_CORE_PREFIX),$(SRC_CORE_FILES))

NAME_ASM=		asm/asm

NAME_CORE=		corewar/corewar

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

OBJ_ASM=		$(SRC_ASM:.c=.o)

OBJ_CORE=		$(SRC_CORE:.c=.o)

$(NAME_CORE):	$(NAME_ASM) $(OBJ_CORE)
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled corewar"
	@$(CC) $(OBJ_CORE) -o $(NAME_CORE)

$(NAME_ASM):	$(OBJ_ASM)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ ";
	@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|";
	@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  ";
	@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ ";
	@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|";
	@echo "                                                           ";
	@tput sgr0
endif
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiled asm"
	@$(CC) $(OBJ_ASM) -o $(NAME_ASM)

%.o:	%.c
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME_ASM) $(NAME_CORE)

clean:
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK"; tput sgr0
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ_ASM)
	@$(RM) $(OBJ_CORE)

fclean:	clean
	@echo -n "[ "
	@tput setaf 2; tput bold; echo -n "OK" ; tput sgr0
	@echo -n " ] "
	@echo "Deleting binaries ..."
	@$(RM) $(NAME_ASM)
	@$(RM) $(NAME_CORE)

re:	fclean all

.PHONY:	all clean fclean re

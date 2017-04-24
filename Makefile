# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaborea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 10:16:34 by egaborea          #+#    #+#              #
#    Updated: 2017/02/23 16:37:13 by hchaucha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_PATH = ./asm
WAR_PATH = ./corewar

all:
	@make -C $(ASM_PATH) all
	@make -C $(WAR_PATH) all

asm:
	@make -C $(ASM_PATH) all

corewar: 
	@make -C $(WAR_PATH) all

clean: 
	@make -C $(ASM_PATH) clean
	@make -C $(WAR_PATH) clean

fclean:
	@make -C $(ASM_PATH) fclean
	@make -C $(WAR_PATH) fclean

re:
	@make -C $(ASM_PATH) re
	@make -C $(WAR_PATH) re

tests: all
	@cp ./asm/asm ./tests
	@cp ./corewar/corewar ./tests
	@sh ./tests/ressources/main_test.sh $(OPT)

clean_tests:
	@rm -rf ./tests/sandbox/
	@rm -rf ./tests/ressources/players/*.cor
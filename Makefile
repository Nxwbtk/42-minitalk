# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 00:19:37 by bsirikam          #+#    #+#              #
#    Updated: 2023/03/05 03:04:02 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server

SERVER = server.c
S_OB = $(SERVER:.c=.o)
OBJS_DIR = obj_server
OBJC_DIR = obj_client
S_OBJ := $(addprefix $(OBJS_DIR)/, $(S_OB))

CLIENT_NAME = client

CLIENT = client.c
C_OB = $(CLIENT:.c=.o)
C_OBJ := $(addprefix $(OBJC_DIR)/, $(C_OB))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = minitalk.h
RM = rm -rf
LIBFT_PATH = libft/
FT_PRINTF_PATH = ft_printf/
LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a

$(OBJS_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJC_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJC_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all :  libft ft_printf comp_serv comp_client

comp_serv: $(S_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) $(S_OBJ) $(LIBFT_A) $(FT_PRINTF_A) 1> /dev/null

comp_client: $(C_OBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(C_OBJ) $(LIBFT_A) $(FT_PRINTF_A) 1> /dev/null

libft :
	@make -C $(LIBFT_PATH) 1> /dev/null

ft_printf :
	@make -C $(FT_PRINTF_PATH) 1> /dev/null

norm :
	@norminette -R CheckForbiddenSourceHeader $(LIBFT_PATH)*.c
	@norminette -R CheckDefine $(LIBFT_PATH)*.h
	@norminette -R CheckForbiddenSourceHeader $(FT_PRINTF_PATH)*.c
	@norminette -R CheckDefine $(FT_PRINTF_PATH)*.h
	@norminette -R CheckForbiddenSourceHeader $(SRC)
	@norminette -R CheckDefine $(HEADER)


clean :
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@rm -rf $(OBJC_DIR)
	@rm -rf $(OBJS_DIR)

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@rm -rf $(OBJ_DIR)
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)

re : fclean all
.PHONY:libft ft_printf

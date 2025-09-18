CC = gcc
INC_DIR = includes
SRC_DIR = srcs
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
HEADER = $(INC_DIR)/skyscrapers.h
MY_SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/validate.c $(SRC_DIR)/parse.c
MY_OBJ = $(MY_SOURCES:.c=.o)
NAME = skyscrapers

all: $(NAME)

$(NAME): $(MY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(MY_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
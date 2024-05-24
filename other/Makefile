# ------- FONT AND COLORS ------- #
GREY		:= \e[1;30m
RED			:= \e[1;31m
GREEN		:= \e[1;32m
YELLOW		:= \e[1;33m
BLUE		:= \e[1;34m
MAGENTA		:= \e[1;35m
CYAN		:= \e[1;36m
WHITE		:= \e[1;37m

BOLD		:= \e[1m
DIM			:= \e[2m	
UNDERLINE	:= \e[4m
BLINK		:= \e[5m
INVERTED	:= \e[7m
END			:= \e[0m

# ------- COMMANDS ------- #
CC			= cc
AR			= ar rc
RM			= rm -rf
MKDIR_P		= mkdir -p

# ------- FLAGS ------- #
CFLAGS		= -Werror -Wextra -Wall -Ofast
CPPFLAGS	= -MMD -MP
MLX_FLAGS	= -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lpthread
MAKEFLAGS	+= --no-print-directory

# ------- PROJECT ------- #
NAME		= miniRT
NAME_BNS	= miniRT_bonus

# ------- INCLUDES ------- #
INCLUDES	= -I/usr/include -Imlx -I ./includes
BUILD_DIR	= .build

# ------- SOURCES ------- #
SRC			= main
SRC_CORE	= core/canvas core/computations core/world core/computations_utils \
				core/ray 
SRC_LIGHT	= light/lights light/shadow 
SRC_MATH	= math/vector_operations_aditional math/vector_operations \
				math/vector_criation 
SRC_MATRIX	= matrix/matrix_operations matrix/matrix_transformations \
				matrix/matrix_utils matrix/matrix_invertion
SRC_MODULES	= modules/camera modules/intersection modules/materials \
				modules/patterns modules/patterns_utils modules/reflection \
				modules/textures
SRC_PARSER	= parser/get_colour parser/get_coord parser/get_int parser/parse \
				parser/get_scene_elem parser/get_scene_objs parser/get_ratio \
				parser/parse_utils parser/get_scene_transf
SRC_SHAPES	= shapes/cylinder shapes/plane shapes/shapes shapes/create_objs \
				shapes/sphere 
SRC_UTILS	= utils/end_program utils/mlx_auxiliar utils/mlx_hook \
				utils/mlx_rotations utils/mlx_utils
SRC_BONUS	= core/computations_bonus core/ray_bonus utils/mlx_utils_bonus \
				shapes/triangle_bonus utils/threads_fun parser/get_scene_bonus \
				parser/get_scene_objs_bonus_2 parser/get_scene_transf_bonus \
				core/world_bonus shapes/create_objs_bonus shapes/cube_bonus \
				parser/parse_bonus shapes/cone_bonus light/lights_bonus \
				modules/reflection_bonus parser/get_scene_objs_bonus \
				shapes/shapes_bonus light/shadow_bonus \
				modules/camera_bonus modules/intersection_bonus main_bonus

SRCS		= $(SRC) $(SRC_CORE) $(SRC_LIGHT) $(SRC_MATH) $(SRC_MATRIX) \
				$(SRC_MODULES) $(SRC_PARSER) $(SRC_SHAPES) $(SRC_UTILS)

SRCS_BONUS	= $(SRC_BONUS) $(SRC_CORE) $(SRC_LIGHT) $(SRC_MATH) $(SRC_MATRIX) \
				$(SRC_MODULES) $(SRC_PARSER) $(SRC_SHAPES) $(SRC_UTILS)

LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

SRCS		:= $(SRCS:%=%.c)
SRCS_BONUS 	:= $(SRCS_BONUS:%=%.c)
OBJECTS 	:= $(SRCS:%.c=$(BUILD_DIR)/obj/%.o)
OBJ_BONUS 	:= $(SRCS_BONUS:%.c=$(BUILD_DIR)/obj/%.o)
DEPS		= $(OBJECTS:.o=.d)
DEPS_BNS	= $(OBJ_BONUS:.o=.d)

MLX_LIB		= $(BUILD_DIR)/libs/libmlx_Linux.a
LIBFT		= $(BUILD_DIR)/libs/libft.a

# ------- RULES ------- #
# ------- ALL ------- #
all: $(NAME)

# ------- $(NAME) ------- #
$(NAME): $(OBJECTS) $(MLX_LIB)
	@printf "\e[2K\r$(GREEN)Compiling LIBFT $(END)\n"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@printf "\e[2K\r$(GREEN)Created $(NAME)$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(MLX_LIB) $(MLX_FLAGS)

# ------- $(NAME_BNS) ------- #
$(NAME_BNS): $(OBJ_BONUS) $(MLX_LIB)
	@printf "\e[2K\r$(GREEN)Compiling LIBFT $(END)\n"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@printf "\e[2K\r$(GREEN)Created $(NAME_BNS)$(END)\n"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDES) $(LIBFT) -o $(NAME_BNS) \
	$(MLX_LIB) $(MLX_FLAGS)

# ------- OBJECTS ------- #
$(BUILD_DIR)/obj/%.o: %.c
	@$(MKDIR_P) $(BUILD_DIR)/libs $(dir $@)
	@printf "\e[2K\r$(YELLOW)Compiling $<$(END) \n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< $(INCLUDES)

# ------- MLX ------- #
$(MLX_LIB):
	@printf "\e[2K\r$(GREEN)Compiling minilibx$(END)...\n"
	@make -C $(MLX_DIR) > silent
	@cp $(MLX_DIR)/libmlx_Linux.a $(MLX_LIB)
	@printf "\e[2K\r$(BLUE)Created minilibx$(END)\n"
	@$(RM) silent

-include $(DEPS)

$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)/obj

clean:
	@printf "\e[2K\r$(RED)Cleaning objects from $(NAME)$(END)\n"
	@printf "\e[2K\r$(GREY)Execute clean MLX $(NAME)$(END)\n"
	@make clean -C $(MLX_DIR)
	@printf "\e[2K\r$(GREY)Execute clean LIBFT $(NAME)$(END)\n"
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(BUILD_DIR)

fclean: clean
	@printf "\e[2K\r$(RED)Cleaning executables from $(NAME)$(END)\n"
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(NAME_BNS)

re: fclean all

bonus: $(NAME_BNS)

# ------- EXTRA ------- 
run: all
	./$(NAME) scenes/manual.rt

brun: bonus
	./$(NAME_BNS) scenes/manual_bonus.rt

download:
	wget https://cdn.intra.42.fr/document/document/22621/minilibx-linux.tgz && \
	tar -xf minilibx-linux.tgz && rm -rf minilibx-linux.tgz

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME) scenes/manual.rt

bleak: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	./$(NAME_BNS) scenes/manual_bonus.rt

.PHONY: all clean fclean re bonus download run brun leak bleak

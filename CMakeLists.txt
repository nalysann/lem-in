# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 12:32:40 by nalysann          #+#    #+#              #
#    Updated: 2020/09/01 12:32:42 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.17)
project(lem-in C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -O2 -march=native -pipe")

include_directories(inc)
include_directories(libft/inc)

add_subdirectory(libft)

add_executable(lem-in
        inc/lem_in.h
        inc/parser.h
        inc/path.h
        inc/room.h
        inc/utils.h
        src/lem_in.c
        src/parse.c
        src/parse_ants.c
        src/parse_links.c
        src/parse_rooms.c
        src/utils.c)

target_link_libraries(lem-in ft)
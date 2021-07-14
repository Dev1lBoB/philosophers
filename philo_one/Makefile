# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 16:00:14 by wpersimm          #+#    #+#              #
#    Updated: 2021/04/18 16:15:28 by wpersimm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main2.c\
			philo_one_utils.c\
			problem.c\
			problem_2.c\
			utils.c

NAME	=	philo_one

HEAD	=	philo_one.h

FLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${SRCS} ${HEAD}
			gcc ${FLAGS} ${SRCS} -o ${NAME}

${SRCS}:	${HEAD}

clean:

fclean:
			rm -rf ${NAME}

re:			fclean all

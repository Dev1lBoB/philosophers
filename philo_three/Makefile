# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wpersimm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 16:00:14 by wpersimm          #+#    #+#              #
#    Updated: 2021/04/19 21:53:38 by wpersimm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main2.c\
			philo_three_utils.c\
			problem.c\
			problem_2.c\
			utils.c

NAME	=	philo_three

HEAD	=	philo_three.h

FLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${SRCS} ${HEAD}
			gcc ${FLAGS} ${SRCS} -o ${NAME}

${SRCS}:	${HEAD}

clean:

fclean:
			rm -rf ${NAME}

re:			fclean all

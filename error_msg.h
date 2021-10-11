/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:25:45 by daniel            #+#    #+#             */
/*   Updated: 2021/09/03 09:09:38 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define BAD_USAGE "\033[1;31mError: usage ./pipex file1 cmd1 cmd2 file2\n \033[0m"
# define NOT_MEMORY "\033[1;31mError: not memory\n \033[0m"
# define NOT_COMMAND ", \033[1;31mError: command not found\n\033[0m"
# define EMPTY_COMMAND "\033[1;31mError: empty command\n\033[0m"
# define NOT_PERMISSION " , \033[1;31mError: permission denied\033[0m"
# define NOT_FILE " ,\033[1;31mError: no such file\n \033[0m"
# define PIPE_ERROR "\033[1;31mError: pipe error \n \033[0m"
# define FORK_ERROR "\033[1;31mError: fork error \n \033[0m"

#endif
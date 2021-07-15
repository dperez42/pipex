# PIPEX

Objectives
Your objective is to code the Pipex program.

It should be executed in this way:
$> ./pipex file1 cmd1 cmd2 file2

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with
their parameters.

The execution of the pipex program should do the same as the next shell command:

$> < file1 cmd1 | cmd2 > file2

III.1 Examples

$> ./pipex infile "ls -l" "wc -l" outfile

should be the same as “< infile ls -l | wc -l > outfile”

$> ./pipex infile "grep a1" "wc -w" outfile

should be the same as “< infile grep a1 | wc -w > outfile”

# TEST:
In the same path of pipex executable

sh ./test.sh

# EXPLANATION:

I used a global variable to save all the parameters, g_pipex.
- in g_pipex.paths, save paths from the enviroment
...

The ft_pip funtion create a pipe with a file descriptor with -> "pipe(fd)"  then create a child process with fork. The pipe is for comunicate father and child process.
Because a pipe in only in one direction comunication, we have to close OUT fd[1] in child process and IN fd[0] in father process.

In each process we try to open infile and outfile with open funtion.
- father: only read permissions.open(g_pipex.filein, O_RDONLY).
- child: a lot of permissions. open(g_pipex.fileout, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
if error opening or not exist file EXIT.

In father process:
dup2(file, STDIN_FILENO);
close(file);
dup2(pipefd, STDOUT_FILENO);
close(pipefd);

In child process:
dup2(pipefd, STDIN_FILENO);
close(pipefd);
if (g_pipex.fileout)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
- 



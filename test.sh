#! /bin/bash

S1="================================================================================"
S2="--------------------------------------------------------------------------------"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"

comp() {
	printf "$RED"; diff -u $1 $2; printf "$RESET"
	if [ $? -eq 0 ]; then
		printf "$GREEN""OK !$RESET\n"
	fi
}

init () {
	echo -n "" > machine
	echo -n "" > user
}
initfiles () {
	echo "infile:"
	echo "
	hello
	hello world
	hell
	hello
	" > test1 
	cat test1

	echo "infile2:"
	echo "
	a1
	hello world
	a1
	b1
	a1
	" > test2
	cat test2
}

printf "$YELLOW$S1\n\n"
echo "██████╗ ██╗██████╗ ███████╗██╗  ██╗    ███╗   ███╗███████╗██████╗ ██╗ ██████╗"
echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ████╗ ████║██╔════╝██╔══██╗██║██╔════╝"
echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██╔████╔██║█████╗  ██║  ██║██║██║     "
echo "██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██║╚██╔╝██║██╔══╝  ██║  ██║██║██║     "
echo "██║     ██║██║     ███████╗██╔╝ ██╗    ██║ ╚═╝ ██║███████╗██████╔╝██║╚██████╗"
echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚══════╝╚═════╝ ╚═╝ ╚═════╝"
printf "\n$S1$RESET\n"
printf "$BLUE"; make -C ./ all; printf "$RESET"
norminette | grep Error! | wc -l
if [ "$(norminette | grep Error! | wc -l)" != "       0" ]; then
	printf "$RED Norminette: Errors in Norminette.$RESET \n"
else
	printf "$GREEN Norminette: OK.$RESET \n"
fi

initfiles

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile2 grep a1 | wc -w > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< test2 grep a1 | wc -w > machine 2> machine
./pipex test2 "grep a1" "wc -w" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | wc -w > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< test1 grep hello | wc -w > machine 2> machine
./pipex test1 "grep hello" "wc -w" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile2 ls -l | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< test2 ls -l | wc -l > machine 2> machine
./pipex test2 "ls -l" "wc -l" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile2 ls | grep pipex > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< test2 ls | grep pipex > machine 2> machine
./pipex test2 "ls" "grep pipex" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk '{count++} END {print count}' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk '{count++} END {print count}' > machine 2> machine
./pipex test1 "grep hello" "awk '{count++} END {print count}'" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk \"{count++} END {print count}\" > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk "{count++} END {print count}" > machine 2> machine
./pipex test1 "grep hello" "awk \"{count++} END {print count}\"" user 2> user
comp machine user
echo "Bash:"
cat machine
echo "User:"
cat user
rm -rf machine user

rm -rf test1 test2
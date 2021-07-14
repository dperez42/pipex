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
	echo -n "" > test2
	echo -n "" > user2
}
initfiles () {
	echo -n "hello
	hello world
	hell
	" > test1

	echo -n "hello
	hello world
	hell
	" > user1

	echo -n "a1
	hello world
	a1
	b1
	a1
	" > testA1

	echo -n "a1
	hello world
	a1
	b1
	a1
	" > userA1
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

initfiles

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep a1 | wc -w > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< testA1 grep a1 | wc -w > test2 2> test2
./pipex userA1 "grep a1" "wc -w" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | wc -w > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< test1 grep hello | wc -w > test2 2> test2
./pipex user1 "grep hello" "wc -w" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile ls -l | wc -l > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
init
< testA1 ls -l | wc -l > test2 2> test2
./pipex userA1 "ls -l" "wc -l" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk '{count++} END {print count}' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk '{count++} END {
	print count}' > test2 2> test2
./pipex user1 "grep hello" "awk \'{count++} END {print count}\'" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk \"{count++} END {print count}\" > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk "{count++} END {print count}" > test2 2> test2
./pipex user1 "grep hello" "awk \"{count++} END {print count}\"" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk '\"{count++} END {print count}\"' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk '"{count++} END {print count}"' > test2 2> test2
./pipex user1 "grep hello" "awk '\"{count++} END {print count}\"'" user2 2> user2
comp test2 user2
rm -rf test2 user2

printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk \"'{count++} END {print count}'\" > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk "'{count++} END {print count}'" > test2 2> test2
./pipex user1 "grep hello" "awk \"'{count++} END {print count}'\"" user2 2> user2
comp test2 user2
rm -rf test2 user2

rm -rf test1 user1
rm -rf testA1 userA1

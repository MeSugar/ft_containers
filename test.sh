
if [[ $1 = -v ]]
then
	make re
	valgrind --leak-check=full ./ft_containers
	./scripts/vector_test.sh
elif [[ $1 = -m ]]
then
	make re
	valgrind --leak-check=full ./ft_containers
	./scripts/map_test.sh
elif [[ $1 = -s ]]
then
	make re
	valgrind --leak-check=full ./ft_containers
	./scripts/stack_test.sh
elif [[ $1 = -c ]]
then
	make fclean
elif [[ $1 = '' ]]
then
	make re
	valgrind --leak-check=full ./ft_containers
	./scripts/vector_test.sh
	./scripts/map_test.sh
	./scripts/stack_test.sh
elif [[ $1 = -h ]]
then
	printf "Usage: ./test.sh [options]\n"
	printf "Options:\n"
	printf "\t[no option] run tests for all containers\n"
	printf "\t-v run tests for vector\n"
	printf "\t-m run tests for map\n"
	printf "\t-s run tests for stack\n"
	printf "\t-c run 'make fclean'\n"
else
	printf "Uknown command. Use -h for command list\n"
fi
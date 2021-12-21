RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[1;34m'

printf "${GREEN}STACK=================================================================\n"

printf "${BLUE}contructors: "
if [[ $(diff stack_tests/ft_constructor_test stack_tests/stl_constructor_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}empty: "
if [[ $(diff stack_tests/ft_empty_test stack_tests/stl_empty_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}size: "
if [[ $(diff stack_tests/ft_size_test stack_tests/stl_size_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}top: "
if [[ $(diff stack_tests/ft_top_test stack_tests/stl_top_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}push/pop: "
if [[ $(diff stack_tests/ft_push_pop_test stack_tests/stl_push_pop_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}relational_operators: "
if [[ $(diff stack_tests/ft_relational_operators_test stack_tests/stl_relational_operators_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

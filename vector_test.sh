RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[1;34m'

printf "${RED}VECTOR\n"

printf "${BLUE}contructors: "
if [[ $(diff vector_tests/ft_constructor_test vector_tests/stl_constructor_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}operator=: "
if [[ $(diff vector_tests/ft_operator_equals_test vector_tests/stl_operator_equals_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}begin/end: "
if [[ $(diff vector_tests/ft_begin_end_test vector_tests/stl_begin_end_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}rbegin/rend: "
if [[ $(diff vector_tests/ft_rbegin_rend_test vector_tests/stl_rbegin_rend_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}size: "
if [[ $(diff vector_tests/ft_size_test vector_tests/stl_size_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}max_size: "
if [[ $(diff vector_tests/ft_max_size_test vector_tests/stl_max_size_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}resize: "
if [[ $(diff vector_tests/ft_resize_test vector_tests/stl_resize_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}capacity: "
if [[ $(diff vector_tests/ft_capacity_test vector_tests/stl_capacity_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi
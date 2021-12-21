RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[1;34m'

printf "${RED}VECTOR=================================================================\n"

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

printf "${BLUE}empty: "
if [[ $(diff vector_tests/ft_empty_test vector_tests/stl_empty_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}reserve: "
if [[ $(diff vector_tests/ft_reserve_test vector_tests/stl_reserve_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}operator[]: "
if [[ $(diff vector_tests/ft_sq_brackets_operator_test vector_tests/stl_sq_brackets_operator_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi


printf "${BLUE}at: "
if [[ $(diff vector_tests/ft_at_test vector_tests/stl_at_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}front: "
if [[ $(diff vector_tests/ft_front_test vector_tests/stl_front_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}back: "
if [[ $(diff vector_tests/ft_back_test vector_tests/stl_back_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}assign: "
if [[ $(diff vector_tests/ft_assign_test vector_tests/stl_assign_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}push_back: "
if [[ $(diff vector_tests/ft_push_back_test vector_tests/stl_push_back_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}pop_back: "
if [[ $(diff vector_tests/ft_pop_back_test vector_tests/stl_pop_back_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}insert: "
if [[ $(diff vector_tests/ft_insert_test vector_tests/stl_insert_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}erase: "
if [[ $(diff vector_tests/ft_erase_test vector_tests/stl_erase_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}swap: "
if [[ $(diff vector_tests/ft_swap_test vector_tests/stl_swap_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}clear: "
if [[ $(diff vector_tests/ft_clear_test vector_tests/stl_clear_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}get_allocator: "
if [[ $(diff vector_tests/ft_get_allocator_test vector_tests/stl_get_allocator_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}relational_operators: "
if [[ $(diff vector_tests/ft_relational_operators_test vector_tests/stl_relational_operators_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}const_iterator_compare: "
if [[ $(diff vector_tests/ft_const_iterators_compare_test vector_tests/stl_const_iterators_compare_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}execution_time (10000 elements):\n"
    printf '\t'
    cat ./vector_tests/ft_execution_time_test
    printf '\t'
    cat ./vector_tests/stl_execution_time_test
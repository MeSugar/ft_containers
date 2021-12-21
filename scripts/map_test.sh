YELLOW='\033[1;33m'
GREEN='\033[0;32m'
BLUE='\033[1;34m'

printf "${YELLOW}MAP====================================================================\n"

printf "${BLUE}contructors: "
if [[ $(diff map_tests/ft_constructor_test map_tests/stl_constructor_test) ]]
then
    printf "${YELLOW}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}operator=: "
if [[ $(diff map_tests/ft_operator_equals_test map_tests/stl_operator_equals_test) ]]
then
    printf "${YELLOW}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}begin/end: "
if [[ $(diff map_tests/ft_begin_end_test map_tests/stl_begin_end_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}rbegin/rend: "
if [[ $(diff map_tests/ft_rbegin_rend_test map_tests/stl_rbegin_rend_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}empty: "
if [[ $(diff map_tests/ft_empty_test map_tests/stl_empty_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}size: "
if [[ $(diff map_tests/ft_size_test map_tests/stl_size_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}max_size: "
if [[ $(diff map_tests/ft_max_size_test map_tests/stl_max_size_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}operator[]: "
if [[ $(diff map_tests/ft_sq_brackets_operator_test map_tests/stl_sq_brackets_operator_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}insert: "
if [[ $(diff map_tests/ft_insert_test map_tests/stl_insert_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}erase: "
if [[ $(diff map_tests/ft_erase_test map_tests/stl_erase_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}swap: "
if [[ $(diff map_tests/ft_swap_test map_tests/stl_swap_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}clear: "
if [[ $(diff map_tests/ft_clear_test map_tests/stl_clear_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}key_compare: "
if [[ $(diff map_tests/ft_key_compare_test map_tests/stl_key_compare_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}value_compare: "
if [[ $(diff map_tests/ft_value_compare_test map_tests/stl_value_compare_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}find: "
if [[ $(diff map_tests/ft_find_test map_tests/stl_find_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}count: "
if [[ $(diff map_tests/ft_count_test map_tests/stl_count_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}lower/upper bound: "
if [[ $(diff map_tests/ft_lower_upper_bound_test map_tests/stl_lower_upper_bound_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}equal_range: "
if [[ $(diff map_tests/ft_equal_range_test map_tests/stl_equal_range_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}get_allocator: "
if [[ $(diff map_tests/ft_get_allocator_test map_tests/stl_get_allocator_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}elements_order: "
if [[ $(diff map_tests/ft_elements_order_test map_tests/stl_elements_order_test) ]]
then
    printf "${RED}KO\n"
else
    printf "${GREEN}OK\n"
fi

printf "${BLUE}execution_time (10000 elements):\n"
    printf '\t'
    cat ./map_tests/ft_execution_time_test
    printf '\t'
    cat ./map_tests/stl_execution_time_test
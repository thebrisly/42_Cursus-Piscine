make fclean
make
make

echo "\033[1;34mSubject tests : \033[0m"

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo ""

./RPN "7 7 * 7 -"

echo ""

./RPN "1 2 * 2 / 2 * 2 4 - +"

echo ""

./RPN "(1 + 1)"

echo ""

echo "\033[1;34mMore tests : \033[0m"

./RPN "9 9 9 9 9 9 9 9 9 * * * * * * * *"
echo ""

./RPN "9 9 / 1 + 3 -"
echo ""

./RPN "9 9 9 + + 2 / 3 *"
echo ""

./RPN "0 1 2 3 4 5 6 7 8 9 + + + + + + + + +"
echo ""

./RPN "0 1 2 3 4 5 6 7 8 9 + - + - + - + - +"
echo ""

./RPN "1 1 / 1 + 2 / 2 * 7 + 9 /"
echo ""

echo "\033[1;34mTests with unempty stack : \033[0m"

./RPN "9 9 9 9 9 9 9 9 9 * * * * * * *"
echo ""

./RPN "9 9 / 1 + 3"
echo ""

./RPN "9 9 9 + + 2 / 3"
echo ""

./RPN "0 1 2 3 4 5 6 7 8 9 + + + + + + + +"
echo ""

./RPN "0 1 2 3 4 5 6 7 8 9 + - + - + - + -"
echo ""

./RPN "1 1 / 1 + 2 / 2 * 7 + 9"
echo ""

echo "\033[1;34mError tests : \033[0m"

./RPN "42 0 /"

echo ""

./RPN "9 9 9 9 9 9 9 9 9 9 * * * * * * * * *"

echo ""

make fclean

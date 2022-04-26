clang++ -Wall -Wextra -Werror -fsanitize=address  -std=c++0x *.cpp
./a.out
rm a.out

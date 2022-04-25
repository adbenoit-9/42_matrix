clang++ -Wall -Wextra -Werror -fsanitize=address -stdlib=libc++ -std=c++0x *.cpp
./a.out
rm a.out

clang++ -Wall -Wextra -Werror -fsanitize=address -stdlib=libc++ -std=c++0x *.cpp ; ./a.out > matrix_display/proj
cd matrix_display
./display
rm proj
cd -
rm a.out

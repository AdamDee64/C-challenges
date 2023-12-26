export DIGITAL_SUM=digital_sum
export ALPHABET_POS=alphabet_position

export _FILENAME_=$ALPHABET_POS

gcc -Os $_FILENAME_.c -o ./bin/$_FILENAME_
if test -f ./bin/$_FILENAME_; then ./bin/$_FILENAME_; fi

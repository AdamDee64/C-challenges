export DIGITAL_SUM=digital_sum
export ALPHABET_POS=alphabet_position
export X_AND_O=x_and_o
export SUM_BETWEEN=sum_between
export SORT_ODD=sort_odd

export _FILENAME_=$SORT_ODD

gcc -Os -W $_FILENAME_.c -o ./bin/$_FILENAME_
if test -f ./bin/$_FILENAME_; then ./bin/$_FILENAME_; fi

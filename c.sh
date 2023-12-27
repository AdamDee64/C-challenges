export _DIR_=./bin/
if test -d $_DIR_; then continue; else mkdir -p $_DIR_; fi

export HELLO=hello

export DIGITAL_SUM=digital_sum
export ALPHABET_POS=alphabet_position
export X_AND_O=x_and_o
export SUM_BETWEEN=sum_between
export SORT_ODD=sort_odd
export BOUNCING_BALL=bouncing_ball
export SCRAMBLE=scramble

export _FILENAME_=$HELLO

if test -f $_DIR_$_FILENAME_; then rm $_DIR_$_FILENAME_; fi
gcc -Os -W $_FILENAME_.c -o $_DIR_$_FILENAME_
if test -f $_DIR_$_FILENAME_; then $_DIR_$_FILENAME_; fi

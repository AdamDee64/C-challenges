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
export SECONDS_TIME=seconds_time
export GREED_DICE=greed
export GROCERIES=groceries
export IP_ADDRESS=ip_address
export SNAKES_LADDERS=snakes_ladders
export BEER_PYRAMID=beer_pyramid
export NEXT_PERFECT_SQUARE=next_perfect_square
export MIDDLE_CHAR=middle_character
export INITIALS=initials
export CENTURY=century
export BAD_HELLO=bad_hello
export IS_ODD_STRING=is_odd_string
export LONG_TO_IP4=long_to_ip4
export HIGHEST=highest
export SUMTO=sumto
export PRINTER_ERROR=printer_error
export LIKES=likes
export STR_TO_INT=str_to_int
export REMOVE_VOWELS=remove_vowels
export REVERSE_STRING=reverse_string
export SUM_POSITIVES=sum_positives
export COUNT_BY=count_by
export READ_STATE=read_state

export _FILENAME_=$READ_STATE
if test -f $_DIR_$_FILENAME_; then rm $_DIR_$_FILENAME_; fi
gcc -Os -W $_FILENAME_.c -o $_DIR_$_FILENAME_
if test -f $_DIR_$_FILENAME_; then $_DIR_$_FILENAME_; fi

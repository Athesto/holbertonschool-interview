#!/usr/bin/env bash
[[ $1 =~ (out) ]] && { vim mains/output/"$2"-main; exit; }
[[ $1 =~ (main) ]] && { vim mains/"$2"-main.c; exit; }

if (( $#  == 0 )); then
    COUNT=$(( $(find mains/*.c | wc -w) -1 ))
    for INPUT in $(seq 0 "$COUNT"); do
        make "$INPUT"
        diff <(./0-sandpiles) mains/output/"$INPUT"-main
    done
else
    INPUT=${1:-0}
    make "$INPUT"
    diff <(./0-sandpiles) mains/output/"$INPUT"-main
fi

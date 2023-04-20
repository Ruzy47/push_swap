#!/bin/bash

args=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")

instruction_count=$(./push_swap $args | wc -l)
# test_ok=$(./push_swap $args | ./checker $args)
testok=$(./push_swap $args | ./checker $args)

echo $test_ok

echo "Number of instructions: $instruction_count"
# Is sorted?: '$testok'"
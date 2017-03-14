#! /bin/bash

for i in `seq -w 0 28`; do
    echo "test$i"
    diff "../rime-out/tests/03_random_$i.diff" <(./a.out < "../rime-out/tests/03_random_$i.in")
done

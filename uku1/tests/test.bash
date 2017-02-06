#! /bin/bash

s=1
t=10

if [ $# -eq 1 ]; then
    t=$1
elif [ $# -eq 2 ]; then
    s=$1
    t=$2
fi

for i in `seq $s $t`; do
    echo "test$i"
    if [ ! -e "test/in$i" ]; then
	echo "generate"
	g++ -std=c++11 generator.cpp
	./a.out > "test/in$i"
    fi
    g++ -std=c++11 comparator.cpp
    ./a.out < "test/in$i" > "test/cmp$i"
    g++ -std=c++11 solver.cpp
    ./a.out < "test/in$i" > "test/out$i"
    diff "test/cmp$i" "test/out$i"
done

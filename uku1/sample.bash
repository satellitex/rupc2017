#! /bin/bash

s=1
t=10
filename=""

if [ $# -eq 0 ]; then
    echo "./sample.bash <filename> [[start] end] "
    exit
fi

if [ $# -eq 1 ]; then
    filename=$1
elif [ $# -eq 2 ]; then
    filename=$1
    t=$2
elif [ $# -eq 3 ]; then
    filename=$1
    s=$2
    t=$3
fi

if [ ! -e $filename ]; then
    echo "$filename does not exist."
    exit
fi

for i in `seq $s $t`; do
    echo "test$i"
    if [ ! -e "tests/in$i" ]; then
	echo "generate"
	g++ -std=c++11 generator.cpp
	./a.out > "tests/in$i"
    fi
    g++ -std=c++11 bruteforce.cpp
    ./a.out < "tests/in$i" > "tests/cmp$i"
    g++ -std=c++11 $filename
    ./a.out < "tests/in$i" > "tests/out$i"
    diff "tests/cmp$i" "tests/out$i"
done

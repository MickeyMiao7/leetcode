#!/bin/bash

cat words.txt | tr " " "\n" | sort | uniq -c | awk '{print $2, $1}'


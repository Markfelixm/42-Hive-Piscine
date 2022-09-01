#!/bin/bash

for item in $@; do
	if [[ $item =~ ^[a-zA-Z]+ ]]; then
		echo "its a word"
	else
		echo "not a word"
	fi
done
		
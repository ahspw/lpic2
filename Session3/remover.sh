#!/bin/bash

path='/home/ahsp' # Change to whenever you want to delete old files and folders

while [[ 1 ]]
do
	if [[ $(date +%M) == "1" ]]
	then
		find $path -atime +30 -exec rm -rf {} \;
	fi
done

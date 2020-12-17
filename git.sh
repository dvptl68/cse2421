#!/bin/bash

if [ -d .git ]; then
	read -p "Enter the commit message: " message
	read -p "Would you like to stage and commit all changes with the following message: $(tput bold)${message}$(tput sgr0) (y/n)? " confirm
	if [ "$confirm" = "y" ]; then
        git pull
		git add --all
		git commit -m "$message"
		# Uncomment the following line for the script to push changes to a remote repository
		git push
		echo "$(tput bold)Staged and committed all changes!$(tput sgr0)"
	else
		echo "$(tput bold)Process terminated.$(tput sgr0)"
	fi
else
	echo "$(tput bold)You must run this script from a directory with an initialized Git repository!$(tput sgr0)"
fi


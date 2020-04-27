#!/bin/zsh

name=level$1

mkdir -p $name
touch $name/flag
mkdir -p $name/Ressources
touch $name/Ressources/explanations.txt
echo  "\e[32m $name created"


#!/bin/bash

while [ 1 ]
do
	rm -rf /tmp/f1
	touch /tmp/f1
	rm -rf /tmp/f1
	ln -s ~/token /tmp/f1
done

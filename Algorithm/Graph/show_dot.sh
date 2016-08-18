#!/bin/bash

dot -Tpng $1.dot -o $2.png
gnome-open $2.png

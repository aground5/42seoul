#!/bin/sh

data=`id -Gn $FT_USER`
echo $data | tr ' ' ',' | tr -d '\n'

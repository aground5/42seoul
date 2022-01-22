#!/bin/sh

data=`ifconfig | grep 'ether ' | cut -c 8-24`
echo "$data"

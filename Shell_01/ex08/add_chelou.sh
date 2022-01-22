#!/bin/sh

data1=`echo $FT_NBR1 | sed "s/'/0/g" | sed 's/\\\/1/g' | sed 's/"/2/g' | sed "s/\?/3/g" | sed "s/\!/4/g"`
data2=`echo $FT_NBR2 | tr "mrdoc" "0-4"`

data1=`echo "ibase=5; ${data1}" | bc`
data2=`echo "ibase=5; ${data2}" | bc`

data3=$data1+$data2
data3=`echo "obase=13; ${data3}" | bc`
echo $data3 | tr "0123456789ABC" "gtaio luSnemf"

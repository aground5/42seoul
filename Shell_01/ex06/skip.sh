#!/bin/sh

echo "`ls -l | awk 'NR % 2 == 1'`"

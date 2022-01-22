#!/bin/sh

git log -5 | grep "^commit" | cut -c 8-

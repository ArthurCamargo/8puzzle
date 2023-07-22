#! /bin/bash

ROOT='/home/guest/8puzzle'
FILENAME=$(find $ROOT -name '8*txt')
PROGRAM=$(find $ROOT/build -name 'main')

echo "Found $FILENAME"

echo "parallel -a $FILENAME $PROGRAM $1"
parallel -a $FILENAME $PROGRAM $1

#!/bin/bash

name=$1

grep -r $name ./DB.txt

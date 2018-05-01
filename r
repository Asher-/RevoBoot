#!/bin/bash

clear

if [ ! -z "$1" ];
  then
    make CONFIG_ID=$1
  else
    make CONFIG_ID=Default
fi

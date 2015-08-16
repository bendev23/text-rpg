#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[1;34m'
NC='\033[0m' # No Color

numerrors=0

printf "${BLUE}starting tests\n============================================\n${NC}"

for i in $( ls ./bin ); do
  if ! [ "$i" == "rpg" ]; then
    printf "${BLUE}running $i:\n-------------------------------------------\n${NC}"
    "./bin/$i"
    
    status=$?
    
    printf "${BLUE}return code: ${status}${NC}\n" 
    
    if [ $status -ne 0 ]; then
        printf "${RED}TEST NOT OK${NC}"
        numerrors=$((numerrors + 1))
      else
        printf "${GREEN}TEST OK${NC}"
      fi
    
    printf "\n"
    
    fi
  done
  
printf "${BLUE}done\n-------------------------------------------\n${NC}number of errors: $numerrors\n"
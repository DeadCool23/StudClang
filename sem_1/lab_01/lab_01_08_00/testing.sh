#!/bin/bash

key=$1
fail=0

names=("Adress" "Memory" "UndefinedBehavior")
sans="*san.sh"
scripts=()
for san in $sans; do
  scripts+=("$san")
done

for i in "${!names[@]}"; do
  san_fail=0
  if [[ "$key" == "-v" ]]; then
    echo "========================================"
    echo -e "\e[1;34m${names[$i]} sanitaizer\e[0m"
    echo "----------------------------------------"
  fi
  bash "${scripts[$i]}"
  bash func_tests/scripts/func_tests.sh
  exit_code=$?
  if [ $exit_code -ne 0 ]; then
    san_fail=1
  fi
  if [[ "$key" == "-v" ]]; then
    if [ $san_fail -eq 1 ]; then
      echo -e "${names[$i]} testing: \e[1;31mFAILED\e[0m"
    else
      echo -e "${names[$i]} testing: \e[1;32mPASS\e[0m"
    fi
  fi
  fail=$((fail + san_fail))
  bash clean.sh
done

if [[ "$key" == "-v" ]]; then
  echo "========================================"
  echo -e "\e[1;34mFunctional testing\e[0m"
  bash collect_coverage.sh -v
else
  bash collect_coverage.sh
fi
bash clean.sh

cov_exit=$?
if [ $fail -ne 0 ] || [ $cov_exit -ne 0 ]; then
  if [[ "$key" == "-v" ]]; then
    echo -e "\e[1;31mTesting failed\e[0m\e[1;33m:(\e[0m"
    echo -e "\e[1;33m****************************************\e[0m"
  fi
  exit 1
else
  if [[ "$key" == "-v" ]]; then
    echo -e "\e[1;32mTesting passed successfully\e[0m\e[1;33m:)\e[0m"
    echo -e "\e[1;33m****************************************\e[0m"
  fi
  exit 0
fi


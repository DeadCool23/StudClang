#!/bin/bash

success=0 #Положительный код возврата 
fail=1 #Негативный код возврата 

pos_count=0 #Кол-во позитивных тестов
pos_scs=0 #Кол-во пройденных позитивных тестов

key=$1 #Ключ -v

#Вывод при наличии ключа
if [[ "$key" == "-v" ]]; then
    echo "========================================"
    echo "Positive testing"
    echo "----------------------------------------"
fi

files="func_tests/data/pos_??_in.txt" #Маска входных позитивных данных

for file in $files; do
    num=$(echo "$file" | grep -o "[0-9]*") #Номер позитивного теста

    #Проверка на наличие номера
   if [ -z "$num" ]; then
		  break
	 fi

    test_out="func_tests/data/pos_""$num""_out.txt" #Выходные позитивные данные
    test_args="func_tests/data/pos_""$num""_args.txt" #Аргументы позитивных данных
    #Проверка на наличие файлов с выходными данными и аргументами
    if [ -f "$test_out" ] && [ -f "$test_args" ]; then
        cmd="./func_tests/scripts/pos_case.sh $test_out $test_args" #Команда запуска func_tests
    #При отсутствии файла
    else
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "POS TEST pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi
		pos_count=$((pos_count + 1)) #Подсчет кол-ва позитивных тестов
		continue
    fi

    $cmd #Запуск func_tests
    exit_code=$? #Код возврата программы

    #Проверка кода возврата программы
    if [[ $((exit_code % 2)) -eq 0 ]] && [[ $((exit_code % 3)) -eq 0 ]]; then
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "POS TEST pos_""$num""_in.txt: \e[1;32mPASSED\e[0m"
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;32mPASSED\e[0m"
        fi
        pos_count=$((pos_count + 1)) #Подсчет кол-ва позитивных тестов
        pos_scs=$((pos_scs + 1)) #Подсчет кол-ва пройденных позитивных тестов
    elif [[ $((exit_code % 2)) -ne 0 ]]; then
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "POS TEST pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi
        if [[ $((exit_code % 3)) -eq 0 ]]; then
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;32mPASSED\e[0m"
        else
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi   
	pos_count=$((pos_count + 1)) #Подсчет кол-ва позитивных тестов
    fi
done

#Проверка на наличие позитивных тестов
if [ $pos_count -eq 0 ]; then
    compl_pos=200 #Присваивание 200 при отсутствии позитивных тестов
    #Вывод при наличии ключа
    if [[ "$key" == "-v" ]]; then
        echo -e "\e[1;33mNo positives tests\e[0m"
    fi
else
    compl_pos=$((pos_scs * 100 / pos_count)) #Подсчет процента пройденных тестов
fi

#Вывод при наличии ключа
if [[ "$key" == "-v" ]]; then
    echo "----------------------------------------"
    if [ -n "$compl_pos" ]; then
        if [ $compl_pos -eq 100 ]; then
            echo -e "\e[1;32m$compl_pos% of positive tests PASSED\e[0m"
        elif [ $compl_pos -lt 100 ]; then
            echo -e "\e[1;31m$compl_pos% of positive tests PASSED\e[0m"
        fi
    fi

    echo "========================================"
    echo "Negative testing"
    echo "----------------------------------------"
fi

neg_count=0 #Кол-во негативных тестов
neg_scs=0 #Кол-во пройденных негативных тестов

files="func_tests/data/neg_??_in.txt" #Маска входных негативных данных
for file in $files; do
    num=$(echo "$file" | grep -o "[0-9]*") #Номер негативного теста

    #Проверка на наличие номера
    if [ -z "$num" ]; then
		  break
	  fi

    test_args="func_tests/data/neg_""$num""_args.txt" #Аргументы негативных данных
    #Проверка на наличие файлов с выходными данными и аргументами
    if [ -f "$test_args" ]; then
        cmd="./func_tests/scripts/neg_case.sh $test_args" #Команда запуска func_tests
    #При отсутствии файла
    else
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "NEG TEST neg_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi
		neg_count=$((neg_count + 1)) #Подсчет кол-ва негативных тестов
		continue
    fi

    $cmd #Запуск func_tests
    exit_code=$? #Код возврата программы

    #Проверка кода возврата программы
    if [[ $((exit_code % 2)) -eq 0 ]] && [[ $((exit_code % 3)) -eq 0 ]]; then
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "NEG TEST neg_""$num""_in.txt: \e[1;32mPASSED\e[0m"
            echo -e "MEMORY neg_""$num""_in.txt: \e[1;32mPASSED\e[0m"
        fi
        neg_count=$((neg_count + 1)) #Подсчет кол-ва негативных тестов
        neg_scs=$((neg_scs + 1)) #Подсчет кол-ва пройденных негативных тестов
    elif [[ $((exit_code % 2)) -ne 0 ]]; then
        #Вывод при наличии ключа
        if [[ "$key" == "-v" ]]; then
            echo -e "POS TEST pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi
        if [[ $((exit_code % 3)) -eq 0 ]]; then
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;32mPASSED\e[0m"
        else
            echo -e "MEMORY pos_""$num""_in.txt: \e[1;31mFAILED\e[0m"
        fi 
	neg_count=$((neg_count + 1)) #Подсчет кол-ва негативных тестов
    fi
done

if [ $neg_count -eq 0 ]; then
    compl_neg=200 #Присваивание 200 при отсутствии негативных тестов
    #Вывод при наличии ключа
    if [[ "$key" == "-v" ]]; then
        echo -e "\e[1;33mNo negatives tests\e[0m"
    fi
else
    compl_neg=$((neg_scs * 100 / neg_count)) #Подсчет процента пройденных тестов
fi

#Вывод при наличии ключа
if [[ "$key" == "-v" ]]; then
    echo "----------------------------------------"
    if [ -n "$compl_neg" ]; then
        if [ $compl_neg -eq 100 ]; then
            echo -e "\e[1;32m$compl_neg% of negative tests PASSED\e[0m"
        elif [ $compl_neg -lt 100 ]; then
            echo -e "\e[1;31m$compl_neg% of negative tests PASSED\e[0m"
        fi
    fi
    echo "========================================"
fi

#Определяем код возврата
if [ $compl_neg -ge 100 ] && [ $compl_pos -ge 100 ]; then
    exit 0 
else
    exit $((neg_count - neg_scs + pos_count - pos_scs))
fi

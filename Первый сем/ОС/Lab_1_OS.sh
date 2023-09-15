#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Использование: $0 <каталог> <файл_с_результатами>"
    exit 1
fi

directory="$1"
output_file="$2"

if [ ! -d "$directory" ]; then
    echo "Указанный каталог не существует."
    exit 1
fi

total_size=0
total_files=0

# Рекурсивная функция для подсчета размера и количества файлов в каталоге и его подкаталогах
calculate_directory_size() {

    for entry in "$1"/*; do
        if [ -f "$entry" ]; then
            total_size=$((total_size + $(stat -c %s "$entry")))
            total_files=$((total_files + 1))
        elif [ -d "$entry" ]; then
            calculate_directory_size "$entry"
        fi
    done
}

# Вызываем функцию для подсчета размера каталога
calculate_directory_size "$directory"


echo "$directory, $total_size, $total_files" >> "$output_file"
echo "Общий размер файлов: $total_size"
echo "Общее количество файлов: $total_files"
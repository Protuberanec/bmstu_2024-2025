#!/bin/bash

no_ext=()  # Инициализация массива

# Ищем файлы .c и .cpp в текущей директории (без подпапок)
find . -maxdepth 1 -type f \( -name "*.c" -o -name "*.cpp" \) -print0 | while IFS= read -r -d '' file; do
    filename="${file##*/}"  # Оставляем только имя файла (без ./)
    name_no_ext="${filename%.*}"  # Удаляем расширение
    echo "$name_no_ext"  # Выводим имя без расширения
    no_ext+=("$name_no_ext")  # Добавляем в массив
done

# Проверяем массив
echo "Массив no_ext:"
printf '%s\n' "${no_ext[@]}"

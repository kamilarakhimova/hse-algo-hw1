# hse-algo-hw1
---
# КДЗ №1 по АиСД, 2 курс ПИ, ФКН, НИУ ВШЭ
---

## *1. АиСД-2, 2023, задание 5*
## *2. Рахимова Камила Мухаммадовна, БПИ214*
## *3. Clion, PyCharm, Jupiter Notebook*
---
### Реализованы 13/13 (+1) сортировок, есть функция проверки корректности сортировок, есть генератор 4-ёх видов массивов, функция копирования эталонного массива в рабочий заданного размера, есть измерение времени выполнения, 2 вида размера массивов, есть функции вывода массива в файл input.txt (на случай необходимости), в коде есть много комментариев. Ещё есть очень-очень много графиков и табличек. Коротко: есть всё.
---
### Не реализовано: такого нет.
---

Что где есть:
- В файле [sorts.cpp](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/sorts.cpp) располагается чистый красивый код следующих 13-ти (+1) сортировок на языке C++:

```
1.    выбором   ✔ 
2.    пузырьком    ✔ 
3.    пузырьком с условием Айверсона 1    ✔ 
4.    пузырьком с условием Айверсона 2    ✔ 
5.    простыми вставками    ✔ 
6.    бинарными вставками    ✔ 
7.    подсчетом (устойчивая)    ✔
8.    цифровой    ✔
9.    слиянием    ✔
10.   быстрой (первый опорный)    ✔
10.2  быстрой (средний опорный)    ✔
11.   пирамидальной    ✔
12.   Шелла (последовательность Циура)    ✔
13.   Шелла (последовательность Шелла)    ✔
```
- В файле [sortsEO.cpp](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/sortsEO.cpp) находится похожий блок кода с 13-тью (+1) сортировками, но уже с подсчётом количества элементарных операций в них. 

> EO = Elementary Operation

Элементарными операциями считались:

```
1.   Сравнения ( < , <= , > , >= , ==, != )
2.   Присваивания ( = )
3.   Арифметические операции ( + , ++ , - , -- , * , / , ^ )
4.   Логические операции ( & , && , | , || )
5.   Обращение к элементу массива по индексу ( a[i] )
6.   Взятие содержимого по адресу ( i , j , т.п.)
```

Ещё немного важного-неважного:
```
В каждой функции сортировки:
@param array - массив чисел, которые надо отсортировать
@param size - размер массива чисел

Переменная elop = счетчик количества элементарных операций.

Также по умолчанию считается, что функция swap реализует 6 элементарных операций.
```

- В файле [utils.cpp](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/utils.cpp) находятся различные вспомогательные функции, такие, как генераторы 4-ёх различных видов массивов, функция проверки корректности сортировки и функция копирования эталонного массива в рабочий.

- 
- 

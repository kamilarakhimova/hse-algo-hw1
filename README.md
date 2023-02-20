# hse-algo-hw1
---
# КДЗ №1 по АиСД, 2 курс ПИ, ФКН, НИУ ВШЭ
---

## *1. АиСД-2, 2023, задание 5*
## *2. Рахимова Камила Мухаммадовна, БПИ214*
## *3. Clion, PyCharm, Jupiter Notebook*
---
### Реализованы 13/13 (+1) сортировок, есть функция проверки корректности сортировок, есть генератор 4-ёх видов массивов, функция копирования эталонного массива в рабочий заданного размера, есть измерение времени выполнения, 2 вида размера массивов, есть функции вывода массива в файл input.txt (на случай необходимости), в коде есть много комментариев. Ещё есть очень-очень много графиков и табличек. Коротко: есть всё. Даже собачка! (вид сбоку):

---![IMAGE 2023-02-20 03:32:49](https://user-images.githubusercontent.com/58568615/219984964-98ef48d7-b5f4-4809-831b-95ab4a724739.jpg)

### Не реализовано: такого нет.
---

Что где когда:
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

> +1, т.к. для наглядности я ещё реализовала быструю сортировку со средним опорным элементом (по условию задания она не требовалась)

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

- В непосредственно [main.cpp](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/main.cpp) располагается всё самое основное. Вся работа программы начинается здесь и заканчивается тоже здесь.

- В папке [TablesForGraphs](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/TablesForGraphs) можно увидеть результат работы [main.cpp](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/main.cpp). Тут в файлах формата ".csv" состоят все таблицы, необходимые для дальнейшего построения графиков.

- Всё вышеописанное было реализовано на языке программирования C++. Далее используется Python.

- В файле [drawGraphs.py](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/drawGraphs.py) имеется код программы, превращавшей ".csv" файлы сортировок из [TablesForGraphs](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/TablesForGraphs) в красивые графики. Таких файлов всего 14 * 4.

- В [drawBigGraphs.py](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/drawGraphs.py) лежит код программы, превращавшей ".csv" файлы различных видов массивов из [TablesForGraphs](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/TablesForGraphs) в графики. Таких файлов всего 4 * 4.

- Все графики можно найти в [Graphs](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/Graphs).

- Ну и, напоследок, отчёт представлен [тут](https://github.com/kamilarakhimova/hse-algo-hw1/blob/main/README.md)!

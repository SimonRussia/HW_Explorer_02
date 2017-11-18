[![Build Status](https://travis-ci.org/SimonRussia/HW_Explorer_02.svg?branch=master)](https://travis-ci.org/SimonRussia/HW_Explorer_02) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)
## Проект Explorer (II этап)

### Соответствие порядкового номера и комбинации:
- Порядковый номер: **20**
- Двоичное представление: **1 0 1 0 0**
- Комбинация: **0, 0, 1, 1**


## Задание
- [X] Заменить **std::filesystem** на **boost::filesystem**.
- [X] Обеспечить асинхронное получение информации с использованием **std::async** и **std::future**.
- [X] Оформить проект в виде готового пакета [ **DragNDrop** ].


## Пример
Для комбинации **1, 0, 1, 0**
```
$ ./explorer file.dat
path:	 /home/user/file.dat
size:	 2258 Kb
date:	 10/17/2017 8:43
```

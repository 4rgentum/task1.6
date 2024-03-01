# task1.6

Задание
Упорядочить слова в строке по алфавиту на основе списков»


Необходимо спроектировать и разработать на языке C программу, осуществляющую обработку строковых данных, на физическом уровне представленных в виде списков. Из входного потока вводится произвольное количество строк произвольной длины. Каждая строка в общем случае содержит одно или более слов, разделенных пробелами и/или знаками табуляции. Завершение ввода определяется концом файла. Каждая выходная строка формируется путем модификации исходной строки в соответствии с требованиями, предъявляемыми индивидуальным заданием. В полученной строке слова разделяются только одним пробелом. Исходная и полученная строки выводятся в кавычках на экран.


Примечания:
1. Каждая строка представлена списком. Элементы списка имеют по два поля, первое из которых содержит символ, а второе — указатель на следующий элемент списка или NULL. При необходимости возможно использование двусвязного списка.
2. Выходная строка должна формироваться путем модификации исходной строки (т.е. путем модификации исходного списка, без создания нового).
3. Перестановка элементов списка должна осуществляться с помощью манипуляций указателями или путем обмена значениями, лежащими в первом поле элементов списка. Выбор того или иного способа должен быть обоснован.
4. Ввод строк должен быть организован с помощью функции getchar(), каждый считываемый из входного потока символ должен сразу добавляться в формируемый список.
5. Логически законченные части алгоритма решения задачи должны быть оформлены в виде отдельных функций с параметрами. Использование глобальных переменных не допускается.
6. Программа должна корректным образом работать с памятью, для проверки необходимо использовать соответствующие программные средства, например: valgrind (при тестировании и отладке программы её необходимо запускать командой вида valgrind ./lab6).


Отчёт о выполнении лабораторной работы должен включать:
1. Блок-схемы основных алгоритмов работы программы.
2. Исходные коды программы.
3. Тестовые наборы для программы.

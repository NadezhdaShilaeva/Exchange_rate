# Exchange_rate
###### Лабораторная работа по программированию №2. 2 семестр.

Программа, которая на основании данных с сайта ЦБ РФ раз в 10 секунд
опрашивает данные о курсе валют и выводит текущие значения.
По окончании работы программа выводит среднее и медианное значение.
В рамках работы были использованы:
1. Данные от ЦБ. Публичное API (https://www.cbr-xml-daily.ru/#howto).
2. Способ им воспользоваться из С++. Была выбрана и использована библиотека [___libcurl___](https://curl.se/libcurl/).
3. Библиотека для работы с JSON (https://github.com/nlohmann/json).

#### Формат входных данных:
Необходимо нажать клавишу _Enter_ для остановки работы программы и вывода средних и медианных значений курса валют.

---
#### Примеры использования программы:
1. ___Входные аргументы:___ нажатие клавиши _Enter_ после первого вывода данных о курсе валют  
___Выходные данные:___  
| Valute | Nominal | Value |  
| --- | --- | --- |  
| AMD   |  100   |   21.0329 |  
| AUD   |  1     |   77.9943 |  
| AZN   |  1     |   62.2792 |  
BGN     1        59.1362
BRL     1        20.9012
BYN     1        34.1628
CAD     1        83.1074
CHF     1        115.427
CNY     1        16.7425
CZK     10       45.0428
DKK     1        15.5508
EUR     1        115.621
GBP     1        139.958
HKD     1        13.5419
HUF     100      29.8622
INR     10       13.8453
JPY     100      92.1751
KGS     10       10.8333
KRW     1000     86.8867
KZT     100      20.7345
MDL     10       58.6527
NOK     1        11.818
PLN     1        23.65
RON     1        23.371
SEK     1        10.7248
SGD     1        77.7746
TJS     10       93.6393
TMT     1        30.2754
TRY     10       74.5867
UAH     10       35.2121
USD     1        105.812
UZS     10000    96.9828
XDR     1        146.566
ZAR     10       68.7245

Valute  Arithmetic mean  Median value
AMD     21.0329          21.0329
AUD     77.9943          77.9943
AZN     62.2792          62.2792
BGN     59.1362          59.1362
BRL     20.9012          20.9012
BYN     34.1628          34.1628
CAD     83.1074          83.1074
CHF     115.4275         115.4275
CNY     16.7425          16.7425
CZK     45.0428          45.0428
DKK     15.5508          15.5508
EUR     115.6212         115.6212
GBP     139.9581         139.9581
HKD     13.5419          13.5419
HUF     29.8622          29.8622
INR     13.8453          13.8453
JPY     92.1751          92.1751
KGS     10.8333          10.8333
KRW     86.8867          86.8867
KZT     20.7345          20.7345
MDL     58.6527          58.6527
NOK     11.8180          11.8180
PLN     23.6500          23.6500
RON     23.3710          23.3710
SEK     10.7248          10.7248
SGD     77.7746          77.7746
TJS     93.6393          93.6393
TMT     30.2754          30.2754
TRY     74.5867          74.5867
UAH     35.2121          35.2121
USD     105.8124         105.8124
UZS     96.9828          96.9828
XDR     146.5660         146.5660
ZAR     68.7245          68.7245
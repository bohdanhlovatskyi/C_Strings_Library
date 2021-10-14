
# Lab work <mark>2</mark>: <mark>Strings library</mark>
   Authors: <mark>
   - Yaroslav Romanus: https://github.com/yarkoslav;
   -  Bohdan Hlovatskyi: https://github.com/bohdanhlovatskyi </mark>

### Usage

```
./compile.sh

// this will execte the main file with example of usage of the library
./bin/test_c_str 
```

### Results

<mark> Tested and efficient strings library implementatioon </mark>

### Example of execution:
```
--------------- Show default funcs -------------------
String from cstr: Hello there!
Size: 12
Capacity: 12
My str empty: false

-------------- Show get and put chars ----------------
Getc: H
String before puts: Hello there!
String after puts: fello there!

Second string after copying first string: fello there!
Second string after clear: 
-------------- Show inserts ----------------
Second string after append cstr: String that was appended
Second string after inserting f at third position: Strfing that was appended

Second string after inserting ffff at third position: Strfffffing that was appended
Second string after inserting first string at third position: Strfello there!fffffing that was appended

------------- Show appends ----------------
First string: fello there!
First string after f has been appended: fello there!f
First string after ffff has been appended: fello there!fffff
Second string appended to the first one: fello there!fffffStrfello there!fffffing that was appended

------------ Show find ---------------------
First string: fello there!fffffStrfello there!fffffing that was appended
Index of l: 2
Index of there starting from 7-th character: 6
Index of l (find if): 2

------------ show read write to file ----------------
String: "Hello there, this shows the write file func" was written to the fileRead test file that was written to: Hello there, this shows the write file func
Read the file up to delim, that is in this case 'i': 
The next message is the example of write to the stdout
Hello there, this shows the write file func

------------ Show substr ---------------------
Initiali string: fello there!fffffStrfello there!fffffing that was appended
Substr of str (from 0 to 2, my_str_substr is used): fe
Cstr substr of str: fe

------------ Show cmp ---------------------
Cmp with my_str: -1
String: fello there!fffffStrfello there!fffffing that was appended; my_str: sdhfdsannjdhv
Cmp with cstr: 1
String: fello there!fffffStrfello there!fffffing that was appended; my_str: dksbhgslsajdhj
Cmp with another cstr: -1

String: fello there!fffffStrfello there!fffffing that was appended; my_str: omg
------------ Show other ---------------------
String before popback: fello there!fffffStrfello there!fffffing that was appended
String after popback: fello there!fffffStrfello there!fffffing that was appende
Capacity before reserve: 80
Capacity after reserve: 160
My str before resize: fello there!fffffStrfello there!fffffing that was appende
My str after resize: fello there!fffffStrfello there!fffffing that was appende00000000000000000000000
Capacity before shrink to fit: 160
Capacity after shrink to fit: 80

Note here that string is filled with zeroes after the resizeMy str before erase: fello there!fffffStrfello there!fffffing that was appende00000000000000000000000
My str after erase: fello ther0000000000
```

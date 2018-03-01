## asc - ASCII code viewer
### Description
- asc can show you ASCII code you want or table from 0x20 to 0x7F.

### Installation
```
% cc -o asc asc.c
% cp asc /path/to/you/want
```

### Usage
#### Show ASCII code you want
```shell
% asc x Y z @ Z u R a . O r g
x: dec=120, hex=0x78
Y: dec=89, hex=0x59
z: dec=122, hex=0x7a
@: dec=64, hex=0x40
Z: dec=90, hex=0x5a
u: dec=117, hex=0x75
R: dec=82, hex=0x52
a: dec=97, hex=0x61
.: dec=46, hex=0x2e
O: dec=79, hex=0x4f
r: dec=114, hex=0x72
g: dec=103, hex=0x67
```

#### Show ASCII code you want
```shell
% asc
   0 1 2 3 4 5 6 7 8 9 A B C D E F
2    ! " # $ % & ' ( ) * + , - . /
3  0 1 2 3 4 5 6 7 8 9 : ; < = > ?
4  @ A B C D E F G H I J K L M N O
5  P Q R S T U V W X Y Z [ \ ] ^ _
6  ` a b c d e f g h i j k l m n o
7  p q r s t u v w x y z { | } ~
```

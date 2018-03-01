## asc - ASCII code viewer
### Description
- asc can show you ASCII code you want or table from 0x20 to 0x7F.

### Installation
```
% cc -o asc asc.c
% cp asc /path/to/where/you/want
```

### Usage
#### Show ASCII code you want
```shell
% asc x Y z @ Z u R a . O r g
x: hex=0x78, dec=120
Y: hex=0x59, dec=89
z: hex=0x7a, dec=122
@: hex=0x40, dec=64
Z: hex=0x5a, dec=90
u: hex=0x75, dec=117
R: hex=0x52, dec=82
a: hex=0x61, dec=97
.: hex=0x2e, dec=46
O: hex=0x4f, dec=79
r: hex=0x72, dec=114
g: hex=0x67, dec=103
```

#### Show ASCII code table
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

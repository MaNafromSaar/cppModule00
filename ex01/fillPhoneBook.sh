#!/bin/bash
# fill_phonebook.sh
# This script simulates input to the phonybook executable,
# adding seven contacts and then issuing a SEARCH command before exiting.

./phonybook <<EOF
ADD
Alice
Smith
Ali
111-1111-11
Loves pizza
ADD
Bob
Johnson
Bobby
22.22.222
Afraid of heights
ADD
Carol
Williams
Caz
333-3333
Hates spiders
ADD
Dave
Brown
Davy
+49444-4444
Secretly a superhero
ADD
Eva
Jones
Evie
(0033)555-5555
Can't stand chocolate
ADD
Frank
Garcia
Frankie
666-6666
Loves karaoke
ADD
Grace
Miller
Gracie
077/777-7777
Afraid of dogs
ADD
Slartisbartfast
Magrathea
Fjordmaster
123/4567442
Overly proud of Norway's coastline
SEARCH
7
EXIT
EOF
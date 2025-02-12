#!/bin/bash
# fill_phonebook.sh
# This script simulates input to the phonybook executable,
# adding seven contacts and then issuing a SEARCH command before exiting.

./phonybook <<EOF
ADD
Alice
Smith
Ali
111-1111
Loves pizza
ADD
Bob
Johnson
Bobby
222-2222
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
444-4444
Secretly a superhero
ADD
Eva
Jones
Evie
555-5555
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
777-7777
Afraid of dogs
SEARCH
5
EXIT
EOF
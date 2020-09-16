#!/bin/bash
touch ex.2.txt

if ln ex.2.txt file.lock
then
echo 1 >> ex.2.txt
rm file.lock
fi
while true
do
if ln ex.2.txt file.lock
then
end = $(tail -n 1 ex.2.txt)
let end = end + 1
echo $end >> ex.2.txt
rm file.lock
fi
done

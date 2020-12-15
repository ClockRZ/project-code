#!/usr/bin/bash
for file in `ls | grep '拷贝' | cut -d ' ' -f 1`
do
 oldfile=`echo $file | sed 's/\([0-9]\+\)/\1\\ 拷贝.bmp/'`
 newfile=`echo $file | sed 's/\([0-9]\+\)/\1.bmp/'`
 mv "$oldfile" $newfile
done

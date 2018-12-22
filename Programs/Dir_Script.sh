#!/bin/bash
# A simple bash script to move multiple files into 1 single folder.
# If more files nested inside other folders, then just run this script again until done.
# This script will also name them by puting folder name in which file was in 
# followed by a '-' and then the original file's name. Example:
#	folder1/file1.txt -> folder1-file1.txt
#	folder1/file2.txt -> folder1-file2.txt
# Make sure this script is in the same dir as the folders in which you are taking the
# files out of.

move_to=$1
for folder_dir in $(ls -d */) ; do
	folder_name=${folder_dir%%/}
	
	for file in `basename -a $folder_name/*` ; do
		echo moving $folder_name/$file...
		
		mv $folder_name/$file $move_to/$folder_name-$file
	done
done

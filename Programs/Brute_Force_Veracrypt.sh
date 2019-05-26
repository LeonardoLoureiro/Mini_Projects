#!/bin/bash

passes=(passwords_go_here)
vol_path=path_2_volume_goes_here
hash_algo=hash_algorithm_used_goes_here
pim_num=0 # 0 means its disabled and is not used...

for pass in ${passes[*]} ; do

        echo -e ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        echo Trying new password...

	# Needs to be sudo unfortunately...
        sudo veracrypt --text --verbose --non-interactive --pim=$pim_num --hash=$hash_algo --password=$pass $vol_path \
                && echo password Found! Its $pass && break

done

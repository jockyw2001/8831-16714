#!/bin/bash

cd ../../../
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH


exclude=""
filter=(    
BD_MST015B_*
BD_MST024B_*
BD_MST042B_*
BD_MST132*
BD_MST165*
FILES_COMMON_EULER*
FILES_MIPS_A7*
FILES_R2_EULER*
bootloader_A7.ld
target_A7.ld
target.ld
MIUSEL_A7_*
MIUSEL_EULER_*
MMAP_ATVMM_EULER*
MMAP_DTVMM_A7*
MMAP_DTVMM_EULER_*
sysinfo2_a7.h
sysinfo2_euler.h
SW_Config_Trunk_EULER*
a7_nos_mips
euler_nos*
a7
A7
euler
EULER
s7ld
S7LD
Bin_*
Obj_*
)
for i in "${filter[@]}" ; do
  exclude="$exclude --exclude=$i"
done

date=`date +%Y%m%d_%k%M`

targetDir="Chakra3"

zipFile="Chakra3_DVBT_$1.tar.gz"

echo -----
echo $zipFile
echo $exclude
echo -----
tar -zcvf $zipFile $exclude -C $targetDir/ `ls $targetDir`

exit 0


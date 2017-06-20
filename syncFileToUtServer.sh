#!/bin/bash

MSTAR_UT_SERVER="muters@swhcsvr23"

if [ "$1" == "" ]; then
	echo "Usage: $0 <your source code path, can be absolute path or relative path>"
	exit -1
fi

if [ ! -d "$1" ]; then
	echo "UT code path doesn't exist"
	exit -1
fi

cd $1
working_dir=$(pwd -P)

remote_working_dir="${MSTAR_UT_SERVER}:${working_dir}"

ssh $MSTAR_UT_SERVER mkdir -p -m 755 $working_dir

rsync --chmod=a+w --delete-before --compress --recursive --verbose --recursive ${working_dir}/* ${remote_working_dir}

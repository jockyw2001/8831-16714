export CC=/usr/bin/gcc

cd ../../
rm -r -f BIN_EDEN_ALL
mkdir BIN_EDEN_ALL

#===============================================================

BOARD_DIR=./project/boarddef

CFG_FILE=.config

VER_FILE=${BOARD_DIR}/Board

#=============================================================================

if [ "$1" == "" ]; then
	echo "No Version Number"
else
    cp ${VER_FILE}.h ${VER_FILE}.org
    sed -i 's/#define AUTO_BUILD_SW_VER.*/#define AUTO_BUILD_SW_VER                 '${1}'/g' ${VER_FILE}.h
fi

#==================================================================================================
iProjNumber=4
#-------------------------------------
iProjIndex=0
projName[iProjIndex]=R2_EDEN_ZUI_64MB_ATVMM
aBD_NAME[iProjIndex]=BD_MST042B_10BLU_12423
aTUNER_TYPE[iProjIndex]=MxL_661SI_TUNER
#-------------------------------------
iProjIndex=1
projName[iProjIndex]=R2_EDEN_64MB_ATSC
aBD_NAME[iProjIndex]=BD_MST165A_D01A_S_EDEN
aTUNER_TYPE[iProjIndex]=MxL_661SI_TUNER
#-------------------------------------
iProjIndex=2
projName[iProjIndex]=R2_EDEN_ZUI_64MB_ATVMM
aBD_NAME[iProjIndex]=BD_MST165A_D01A_S_EDEN
aTUNER_TYPE[iProjIndex]=MxL_661SI_TUNER
#-------------------------------------
iProjIndex=3
projName[iProjIndex]=R2_EDEN_ZUI_32MB_ATVMM
aBD_NAME[iProjIndex]=BD_MST165A_D01A_S_EDEN
aTUNER_TYPE[iProjIndex]=MxL_661SI_TUNER
#-------------------------------------

iProjIndex=0

while [ "$iProjIndex" != "$iProjNumber" ]
do

    echo "iProjIndex=$iProjIndex"

    # Get project name
    ProjName=${projName[$iProjIndex]}
    echo "ProjName=$ProjName"

    BD_NAME=${aBD_NAME[$iProjIndex]}
    echo "BD_NAME=$BD_NAME"

    BD_FILE=${BOARD_DIR}/$BD_NAME

    TUNER_TYPE=${aTUNER_TYPE[$iProjIndex]}
    echo "TUNER_TYPE=$TUNER_TYPE"


    cp config.tmpl ${CFG_FILE} -f

    # Backup BD_xxx.h
    echo "Backup ${BD_FILE}.h to ${BD_FILE}.org"
    cp ${BD_FILE}.h ${BD_FILE}.org


    # Change Tuner type ...
    sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h

    # Change Board type ...
    sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}

    # Get project name and make
    PROJ=${ProjName} make

    # Move bin folder to BIN_NASA_ALL
    PROJ=${ProjName}
    mv -v Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
    mv -v Bin_R2_EDEN_* ./BIN_EDEN_ALL/
    rm -r Obj_${PROJ}

    #recovery to original Board file
    cp ${BD_FILE}.org ${BD_FILE}.h
    rm -r ${BD_FILE}.org

    iProjIndex=$(($iProjIndex+1))
done


# Move all bin folder
#mv -v Bin_R2_NASA_* ./BIN_NASA_ALL/
#rm -r Bin_R2_NASA_*


cp config.tmpl .config -f

if [ "$1" == "" ]; then
	echo "No Version Number"
else
    # Recover board.h
    cp ${VER_FILE}.org ${VER_FILE}.h
    rm -r ${VER_FILE}.org
fi

exit 0

#==================================================================================================

BD_NAME=BD_MST165A_D01A_S_EDEN
BD_FILE=${BOARD_DIR}/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER

# Backup BD_xxx.h
echo "Backup ${BD_FILE}.h to ${BD_FILE}.org"
cp ${BD_FILE}.h ${BD_FILE}.org

sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}
PROJ=R2_EDEN_ZUI_64MB_ATVMM make
PROJ=R2_EDEN_ZUI_64MB_ATVMM
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

#recovery to original file
cp ${BD_FILE}.org ${BD_FILE}.h
rm -rf ${BD_FILE}.org

#==================================================================================================

BD_NAME=BD_MST165A_D01A_S_EDEN
BD_FILE=${BOARD_DIR}/$BD_NAME
TUNER_TYPE=SILAB_2158_TUNER

# Backup BD_xxx.h
echo "Backup ${BD_FILE}.h to ${BD_FILE}.org"
cp ${BD_FILE}.h ${BD_FILE}.org

sed -i 's/#define FRONTEND_TUNER_TYPE.*/#define FRONTEND_TUNER_TYPE             '${TUNER_TYPE}'/g' ${BD_FILE}.h
sed -i 's/BOARD_TYPE_SEL ?=.*/BOARD_TYPE_SEL ?= '${BD_NAME}'/g' ${CFG_FILE}
PROJ=R2_EDEN_ZUI_32MB_ATVMM make
PROJ=R2_EDEN_ZUI_32MB_ATVMM
cp -r Bin_${PROJ} Bin_${PROJ}_${BD_NAME}_${TUNER_TYPE}
rm -r Bin_${PROJ}
rm -r Obj_${PROJ}

#recovery to original file
cp ${BD_FILE}.org ${BD_FILE}.h
rm -r ${BD_FILE}.org

#==================================================================================================

# Move all bin folder
cp -r Bin_R2_EDEN_* ./BIN_EDEN_ALL
rm -r Bin_R2_EDEN_*


cp config.tmpl .config -f

if [ "$1" == "" ]; then
	echo "No Version Number"
else
# Recover board.h
cp ${VER_FILE}.org ${VER_FILE}.h
rm -r ${VER_FILE}.org
fi

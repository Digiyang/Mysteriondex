#!/bin/bash
HOMEDIR="/Users/$USER"
if [ ! -d "$HOMEDIR/Desktop/data" ]; then
   mkdir $HOMEDIR/Desktop/data
fi

if df | grep "//$USER@ds1.beuth-hochschule.de" >/dev/null; then
   echo "data alread mounted."
else
   mount -t smbfs //$USER@ds1.beuth-hochschule.de/home $HOMEDIR/Desktop/data
fi

if [ ! -d "$HOMEDIR/Desktop/data/$USER/IOS-UEBB" ]; then
   mkdir $HOMEDIR/Desktop/data/$USER/IOS-UEBB
fi
if [ ! -e "$HOMEDIR/Desktop/data/$USER/IOS-UEBB" ]; then
   ln -s $HOMEDIR/Desktop/data/$USER/IOS-UEBB $HOMEDIR/Desktop/IOS-UEBB
fi

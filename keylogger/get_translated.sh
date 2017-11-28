#!/bin/sh

TRANSLATORS_BINS='translators/bins'
KEY_MAP_PREFIXE='maps/keys_map_'
RUN_TRANSLATOR='./translator'
KEY_MAP_PREFIX='../../maps/key_map_'

if [ "$#" -eq 2 ]; then
	cd $TRANSLATORS_BINS && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 ../../$2
elif [ "$#" -eq 1 ]; then
	sudo rm -f io/.pressed_keys

	sudo cp /tmp/.pressed_keys $PWD/io/.pressed_keys

	if [ $? -ne 0 ]; then
	   echo 'There was a problem getting file /tmp/.pressed_keys'
	   exit 1 
	fi

	cd $TRANSLATORS_BINS && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 ../../io/.pressed_keys
else
	echo -e 'You should provide at least 1 parameter, the keyboard language. To check available options, look at the ending of names of files under directory maps. It must be all uppercase!\n'
	echo 'Also, you can provide 2, the language of keyboard and file to be translated'
	exit 1
fi

cd -

echo -e '\n'
cat io/results.txt
echo -e '\n'

echo -e '\nFinished!\nIf everything was ok, your result file is io/results.txt'

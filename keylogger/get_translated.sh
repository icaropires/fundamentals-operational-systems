#!/bin/sh

TRANSLATORS_BINS='translators/bins'
KEY_MAP_PREFIXE='maps/keys_map_'
RUN_TRANSLATOR='./translator'
KEY_MAP_PREFIX='../../maps/key_map_'
KERNEL_VERSION=$(uname -r)

if [ "$#" -eq 2 ]; then
	tail -n$2 /var/log/kern.log > $PWD/io/.pressed_keys
	if [ $? -ne 0 ]; then echo 'There was a problem loading kernel logs'; exit 1; fi

	cd $TRANSLATORS_BINS && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 ../../io/.pressed_keys
	if [ $? -ne 0 ]; then echo 'There was a problem running translator'; exit 1; fi

elif [ "$#" -eq 1 ]; then
	cat /var/log/kern.log > $PWD/io/.pressed_keys
	if [ $? -ne 0 ]; then echo 'There was a problem loading kernel logs'; exit 1; fi

	cd $TRANSLATORS_BINS && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 ../../io/.pressed_keys
	if [ $? -ne 0 ]; then echo 'There was a problem running translator'; exit 1; fi

else
	echo 'You should provide at least 1 parameter, the keyboard language. To check available options, look at the ending of names of files under directory maps. It must be all uppercase!\n'

	echo 'Also, you can provide 2, the language of keyboard and how much lines process from the kernel log'

	exit 1
fi

cd -

echo '\n'
cat io/results.txt
if [ $? -ne 0 ]; then echo 'There was a problem reading results file'; exit 1; fi
echo '\n'

echo '\nFinished!\nIf everything was ok, your result file is io/results.txt'

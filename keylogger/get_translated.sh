#!/bin/sh

TRANSLATOR_BIN='translator/'
KEY_MAP_PREFIXE='maps/keys_map_'
RUN_TRANSLATOR='./translator'
KEY_MAP_PREFIX='../maps/key_map_'
PRESSED_KEYS='../io/.pressed_keys'

KERNEL_VERSION=$(uname -r)
RETURN_CODE_KERNEL_VERISON=$(echo $KERNEL_VERSION | grep generic)


if [ "$#" -eq 2 ]; then
	if [ RETURN_CODE_KERNEL_VERISON -ne 0 ]; then
		journalctl > /tmp/.pressed_keys_tmp
		tail -n$2 /tmp/.pressed_keys_tmp > io/.pressed_keys
	else
		tail -n$2  > io/.pressed_keys
	fi

	if [ $? -ne 0 ]; then echo 'There was a problem loading kernel logs'; exit 1; fi

	cd $TRANSLATOR_BIN && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 $PRESSED_KEYS
	if [ $? -ne 0 ]; then echo 'There was a problem running translator'; exit 1; fi

elif [ "$#" -eq 1 ]; then
	if [ RETURN_CODE_KERNEL_VERISON -ne 0 ]; then
		journalctl > /tmp/.pressed_keys_tmp
		cat /tmp/.pressed_keys_tmp > io/.pressed_keys
	else
		cat /var/log/kern.log > io/.pressed_keys
	fi

	if [ $? -ne 0 ]; then echo 'There was a problem loading kernel logs'; exit 1; fi

	cd $TRANSLATOR_BIN && $RUN_TRANSLATOR $KEY_MAP_PREFIX$1 $PRESSED_KEYS
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

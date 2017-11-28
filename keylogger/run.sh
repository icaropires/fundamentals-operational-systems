#!/bin/sh

TRANSLATORS_BIN='translators/bins/translator'
PATH_BINS_RELATIVE='../..'
KEY_MAP_PREFIXE='maps/keys_map_'

if [ "$#" -eq 2 ]; then
	echo $KEY_MAP_PREFIXE$1
	echo $PATH_BINS_RELATIVE/$2
	./$TRANSLATORS_BIN $KEY_MAP_PREFIXE$1 $PATH_BINS_RELATIVE/$2
elif [ "$#" -eq 1 ]; then
	ln -fs /temp/.pressed_keys $PWD/io/.pressed_keys
	./$TRANSLATORS_BIN $KEY_MAP_PREFIXE$1  $PATH_BINS_RELATIVE/io/.pressed_keys
else
	echo "You should provide at least 1 parameter, the keyboard language. To check available options, look at the ending of names of files under maps/. It must be all uppercase!\n"
	echo "Also, you can provide 2, the language of keyboard and file to be translated"
	exit 1
fi

echo "\nFinished!\nIf everything was ok, your result file is io/results.txt"

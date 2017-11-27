#!/usr/bin/env python3

import os
import subprocess
from sys import argv, stderr

UNPRESS_INTERVAL = 128  # Unpress scancode will be +128 the press scancode

SPACE = '57'
ENTER = '28'

CAPS_LOCK = '58'
CAPS_LOCK_UNPRESS = '186'
CAPS_LOCK_EXTRA_CODE = '250'

BACK = '158'
HELP = '138'
CALC = '140'
SETUP = '141'
SLEEP = '142'
WAKEUP = '143'
PROG1 = '148'
PROG2 = '149'
WWW = '150'
MAIL = '155'
BOOKMARKS = '156'
COMPUTER = '157'
BACK = '158'
FORWARD = '159'
NEXTSONG = '163'
PLAYPAUSE = '164'
PREVIOUSSONG = '165'
STOPCD = '166'
REFRESH = '173'
F13 = '183'
F14 = '184'
F15 = '185'
F22 = '192'
F23 = '193'
SEARCH = '217'
BRIGHTNESSDOWN = '224'
BRIGHTNESSUP = '225'
MEDIA = '226'
SWITCHVIDEOMODE = '227'
BATTERY = '236'
BLUETOOTH = '237'

IGNORED_KEYS = [CAPS_LOCK_UNPRESS, CAPS_LOCK_EXTRA_CODE, BACK, HELP, CALC,
                SETUP, SLEEP, WAKEUP, PROG1, PROG2, WWW, MAIL, BOOKMARKS,
                COMPUTER, BACK, FORWARD, NEXTSONG, PLAYPAUSE, PREVIOUSSONG,
                STOPCD, REFRESH, F13, F14, F15, F22, F23, SEARCH,
                BRIGHTNESSDOWN, BRIGHTNESSUP, MEDIA, SWITCHVIDEOMODE,
                BATTERY, BLUETOOTH] # Collisions with unpress scancodes

def build_keymap_dict(key_map):
    print('Building keymap...')

    key_dict = {}
    for line in key_map:
        nick, _ , decimal, _ = line.split()
        key_dict[decimal] = nick

    print('Keymap builded...')
    return key_dict

def substitute_keys(key_dict, data):
    print('Starting to substitute keys...')

    new_data = []
    new_data += [key_dict[data[0]]]

    for i in range(1, len(data)):
        if not i%30: # Print status on 10's keys
            print('Substituted {:.2f}% of the keys...'.format(i/len(data)*100))

        key = data[i]
        prev_key = data[i - 1]

        try:
            if key == SPACE:
                new_data += ' '
            elif key == ENTER:
                new_data += '\n'
            elif key == CAPS_LOCK:
                new_data += key_dict[key]

                caps_key = key
                while caps_key == CAPS_LOCK:
                    i += 1
                    caps_key = data[i]
            elif (int(key) != int(prev_key) + UNPRESS_INTERVAL) and \
                key not in IGNORED_KEYS:
                new_data += key_dict[key]

        except KeyError:
            a = 2 + 2 # Nothing

    print('Keys substituted successfully!')
    return new_data

def write_result(data):
    print('Writing to file...')

    with open('translated.txt', 'w') as file:
       file.write(data) 
       file.write('\n')

    print('File written successfully!')

error = subprocess.call(['./translator_to_int', argv[2]])

if not error:
    with open('translated.txt') as file:
        data = file.read()

    with open(argv[1]) as file:
        key_map = file.readlines()
        key_map = [line.strip() for line in key_map][1:]
else:
    print('Is not possible translate the file, problem while translating' +
          ' from int.')
    exit(1)

key_dict = build_keymap_dict(key_map)

data = data.split()
translated_data = substitute_keys(key_dict, data)

translated_data = ''.join(translated_data)

write_result(translated_data)

print('Translation completed!!!')

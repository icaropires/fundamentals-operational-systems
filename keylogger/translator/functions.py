import subprocess
from sys import stderr
from scancode_constants import (UNPRESS_INTERVAL,
                                SPACE,
                                ENTER,
                                CAPS_LOCK,
                                IGNORED_KEYS,
                                SPECIAL_KEY)

RESULTS_FILE = '../io/results.txt'
SCANCODE_COLUMN = 3
PRINT_PERCENTAGE_INTERVAL = 5

def get_scancodes(file):
    lines = subprocess.Popen(['grep', '-a', 'Battery spent', file],
                              stdout=subprocess.PIPE)

    remove_leading = subprocess.Popen(['sed', 's/^[^B]*//'],
                                      stdin=lines.stdout,
                                      stdout=subprocess.PIPE)

    scancodes = subprocess.Popen(['cut', '-d', ' ', '-f',
                                 str(SCANCODE_COLUMN)],
                                 stdin=remove_leading.stdout,
                                 stdout=subprocess.PIPE)

    scancodes, _ = scancodes.communicate()
    scancodes = scancodes.decode('utf-8')[:-1]

    return scancodes


def build_keymap_dict(key_map):
    print('Building keymap...', file=stderr)

    key_dict = {}
    for line in key_map:
        nick, _ , decimal, _ = line.split()
        key_dict[decimal] = nick

    print('Keymap builded...', file=stderr)
    return key_dict

def substitute_keys(key_dict, data):
    print('Starting to substitute keys...')
    new_data = []

    if data[0] in key_dict.keys():
        new_data += [key_dict[data[0]]]

    if len(data) >= 100:
        interval_to_print = PRINT_PERCENTAGE_INTERVAL*(len(data)//100)
    else:
        interval_to_print = 10
    for i in range(1, len(data)):
        if not (i % interval_to_print):
            print('Substituted {:.2f}% of the keys...'
                  .format(i/len(data)*100)) # 100 because is percentage

        key = data[i]
        prev_key = data[i - 1]

        if key == SPACE:
            new_data += ' '
        elif key == ENTER:
            new_data += '\n'
        elif key == CAPS_LOCK:
            if key in key_dict.keys():
                new_data += key_dict[key]

            caps_key = key
            while caps_key == CAPS_LOCK:
                i += 1
                caps_key = data[i]
        elif (int(key) != int(prev_key) + UNPRESS_INTERVAL) and \
            key not in IGNORED_KEYS:

            if key in key_dict.keys():
                # Treating arrows
                if prev_key == SPECIAL_KEY:
                    if key == '75':
                        new_data += '[LEFTARROW]'
                    elif key == '77':
                        new_data += '[RIGHTARROW]'
                    elif key == '80':
                        new_data += '[DOWNARROW]'
                    elif key == '72':
                        new_data += '[UPARROW]'
                    else: 
                        continue
                else:
                    new_data += key_dict[key]

    print('Keys substituted successfully!')
    return new_data

def write_result(data):
    print('Writing to file...', file=stderr)

    with open(RESULTS_FILE, 'w') as file:
       file.write(data) 
       file.write('\n')

    print('File written successfully!', file=stderr)

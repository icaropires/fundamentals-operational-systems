from sys import stderr

INTERVAL_PRINT_STATUS = 30 # Print substituting status from each n keys
                           # processed   

RESULTS_FILE = '../../io/results.txt'

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

    try:
        new_data += [key_dict[data[0]]]
        for i in range(1, len(data)):
            if not i % INTERVAL_PRINT_STATUS:
                print('Substituted {:.2f}% of the keys...'
                      .format(i/len(data)*100)) # 100 because is percentage

            key = data[i]
            prev_key = data[i - 1]

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
        a = 2 + 2 # Do nothing, no problem

    print('Keys substituted successfully!')
    return new_data

def write_result(data):
    print('Writing to file...', file=stderr)

    with open(RESULTS_FILE, 'w') as file:
       file.write(data) 
       file.write('\n')

    print('File written successfully!', file=stderr)

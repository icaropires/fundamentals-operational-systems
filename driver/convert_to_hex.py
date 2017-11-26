keys = []
n = int(input())

for i in range(n):
    keys += [int(input())]

for key in keys:
    print("0x{:02x}".format(key))

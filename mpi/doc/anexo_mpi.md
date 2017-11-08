# Execuções do MPI local

## Computador 1:
### Informações:
	VM com 3 CPUs disponíveis.
	Sistema Operacional: Ubuntu
	Processador: Intel® Cor i7-7200U CPU @ 2.40GHz 4 
	Memória:5,120 GB
	Estado do computador antes das execuções: Anexo 2

### Execução

#### Comando
``` sh
$ time mpirun -np 5 -host localhost ./mpi 
```
### Saídas
#### Primeira:
```
Max: 500000000.000000
Min: 1.000000

real	0m9.683s
user	0m32.788s
sys	0m2.484s
```

#### Segunda:
```
Max: 500000000.000000
Min: 1.000000

real	0m9.372s
user	0m33.084s
sys	0m2.432s
```

#### Terceira:
```
Max: 500000000.000000
Min: 1.000000

real	0m9.155s
user	0m30.956s
sys	0m2.704s
```

## Computador 2:
### Informações:
	VM com 3 CPUs disponíveis.
	Sistema Operacional: Ubuntu
	Processador: Intel® Cor i7-7200U CPU @ 2.40GHz 4 
	Memória:5,120 GB
	Estado do computador antes das execuções: Anexo 2

### Execução

#### Comando
``` sh
$ time mpiexec -np 5 -host localhost ./mpi 
```
### Saídas

#### Primeira:
```
Max: 500000000.000000
Min: 0.000000

real	0m6.695s
user	0m13.993s
sys	0m2.884s
```

#### Segunda:
```
Max: 500000000.000000
Min: 0.000000

real	0m6.725s
user	0m13.717s
sys	0m3.112s
```

#### Terceira:
```
Max: 500000000.000000
Min: 1.000000

real	0m6.682s
user	0m13.857s
sys	0m2.952s
```

### Anexo 2
#### Comando
``` sh
$ top -b:
```

### Saída
```
top - 22:47:50 up 3 days, 20:32,  6 users,  load average: 1,63, 1,53, 1,54
Tasks: 260 total,   1 running, 259 sleeping,   0 stopped,   0 zombie
%Cpu(s): 16,7 us,  4,7 sy,  0,1 ni, 76,9 id,  1,4 wa,  0,0 hi,  0,2 si,  0,0 st
KiB Mem :  8063556 total,  3368004 free,  3807264 used,   888288 buff/cache
KiB Swap: 12182520 total, 11303796 free,   878724 used.  3606512 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 1437 root      20   0 1788540   4156   1164 S   5,9  0,1   0:07.80 nscd
20664 icaro     20   0 2819404 794164 108380 S   5,9  9,8  86:24.44 Web Content
    1 root      20   0  185576   3368   1396 S   0,0  0,0   0:04.86 systemd
    2 root      20   0       0      0      0 S   0,0  0,0   0:00.07 kthreadd
    3 root      20   0       0      0      0 S   0,0  0,0   0:01.85 ksoftirqd/0
    5 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/0:0H
    7 root      20   0       0      0      0 S   0,0  0,0   4:17.40 rcu_sched
    8 root      20   0       0      0      0 S   0,0  0,0   0:00.00 rcu_bh
    9 root      rt   0       0      0      0 S   0,0  0,0   0:00.21 migration/0
   10 root      rt   0       0      0      0 S   0,0  0,0   0:00.62 watchdog/0
   11 root      rt   0       0      0      0 S   0,0  0,0   0:00.50 watchdog/1
   12 root      rt   0       0      0      0 S   0,0  0,0   0:00.18 migration/1
   13 root      20   0       0      0      0 S   0,0  0,0   0:01.43 ksoftirqd/1
   15 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/1:0H
   16 root      rt   0       0      0      0 S   0,0  0,0   0:00.51 watchdog/2
   17 root      rt   0       0      0      0 S   0,0  0,0   0:00.30 migration/2
   18 root      20   0       0      0      0 S   0,0  0,0   0:02.86 ksoftirqd/2
   20 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/2:0H
   21 root      rt   0       0      0      0 S   0,0  0,0   0:00.50 watchdog/3
   22 root      rt   0       0      0      0 S   0,0  0,0   0:00.28 migration/3
   23 root      20   0       0      0      0 S   0,0  0,0   0:04.03 ksoftirqd/3
   25 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/3:0H
   26 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kdevtmpfs
   27 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 netns
   28 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 perf
   29 root      20   0       0      0      0 S   0,0  0,0   0:00.16 khungtaskd
   30 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 writeback
   31 root      25   5       0      0      0 S   0,0  0,0   0:00.00 ksmd
   32 root      39  19       0      0      0 S   0,0  0,0   0:21.22 khugepaged
   33 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 crypto
   34 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kintegrityd
   35 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   36 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kblockd
   37 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 ata_sff
   38 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 md
   39 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 devfreq_wq
   46 root      20   0       0      0      0 S   0,0  0,0   0:20.43 kswapd0
   47 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 vmstat
   48 root      20   0       0      0      0 S   0,0  0,0   0:00.00 fsnotify_mark
   49 root      20   0       0      0      0 S   0,0  0,0   0:00.00 ecryptfs-kthrea
   65 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kthrotld
   66 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 acpi_thermal_pm
   69 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   70 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   71 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   72 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   73 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   74 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   75 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   76 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
   80 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 ipv6_addrconf
   93 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 deferwq
   94 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 charger_manager
  142 root      20   0       0      0      0 S   0,0  0,0   0:00.01 scsi_eh_0
  143 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 scsi_tmf_0
  144 root      20   0       0      0      0 S   0,0  0,0   0:00.00 scsi_eh_1
  145 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 scsi_tmf_1
  146 root      20   0       0      0      0 S   0,0  0,0   0:00.00 scsi_eh_2
  147 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 scsi_tmf_2
  148 root      20   0       0      0      0 S   0,0  0,0   0:00.00 scsi_eh_3
  149 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 scsi_tmf_3
  153 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 rtsx_pci_sdmmc_
  158 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
  159 root      20   0       0      0      0 S   0,0  0,0   0:00.00 scsi_eh_4
  160 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 scsi_tmf_4
  161 root      20   0       0      0      0 S   0,0  0,0   0:03.19 usb-storage
  162 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
  165 root       0 -20       0      0      0 S   0,0  0,0   0:01.12 kworker/2:1H
  167 root       0 -20       0      0      0 S   0,0  0,0   0:01.87 kworker/3:1H
  168 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 bioset
  196 root       0 -20       0      0      0 S   0,0  0,0   0:01.15 kworker/1:1H
  198 root      20   0       0      0      0 S   0,0  0,0   0:09.95 jbd2/sda7-8
  199 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 ext4-rsv-conver
  235 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kauditd
  249 root      20   0   44040   3784   3500 S   0,0  0,0   0:04.82 systemd-journal
  275 root      20   0   45860   1056    668 S   0,0  0,0   0:01.57 systemd-udevd
  343 root     -51   0       0      0      0 S   0,0  0,0   8:38.05 irq/39-SYN1B7E:
  387 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kmemstick
  496 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 cfg80211
  527 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kvm-irqfd-clean
  614 root       0 -20       0      0      0 S   0,0  0,0   0:00.71 kworker/0:1H
  850 systemd+  20   0  102384      0      0 S   0,0  0,0   0:00.15 systemd-timesyn
  970 root      20   0   29012    464    380 S   0,0  0,0   0:00.15 cron
  975 message+  20   0   45416   3332    692 S   0,0  0,0   1:31.72 dbus-daemon
 1005 avahi     20   0   45232    748    280 S   0,0  0,0   0:04.46 avahi-daemon
 1012 root      20   0  276104   1352    672 S   0,0  0,0   0:03.25 accounts-daemon
 1017 root      20   0  166444   1308   1072 S   0,0  0,0   0:08.32 thermald
 1019 root      20   0    4400     28      0 S   0,0  0,0   0:19.88 acpid
 1022 root      20   0   32052   1212    988 S   0,0  0,0   0:00.04 bluetoothd
 1044 root      20   0   29880      0      0 S   0,0  0,0   0:00.00 cgmanager
 1048 syslog    20   0  256396    444    264 S   0,0  0,0   0:01.51 rsyslogd
 1051 root      20   0  729428   9216   5276 S   0,0  0,1   1:21.33 NetworkManager
 1072 root      20   0   20412    752    532 S   0,0  0,0   0:00.70 systemd-logind
 1074 root      20   0  305688   7368   1544 S   0,0  0,1   0:03.44 snapd
 1124 root      20   0  276680   1520   1012 S   0,0  0,0   0:00.16 lightdm
 1126 avahi     20   0   44788     24      0 S   0,0  0,0   0:00.00 avahi-daemon
 1141 root      20   0  282192   3544   1160 S   0,0  0,0   0:03.17 polkitd
 1262 colord    20   0  301420   1884   1392 S   0,0  0,0   0:00.32 colord
 1343 root      20   0   44160   2976   2448 S   0,0  0,0   0:18.32 wpa_supplicant
 1436 root      20   0  436580  96272  75600 S   0,0  1,2  72:04.38 Xorg
 1476 root      20   0   19472    524    444 S   0,0  0,0   0:06.25 irqbalance
 1503 root      20   0  947672   7212   4896 S   0,0  0,1   0:31.96 core
 1506 debian-+  20   0   77500  27824   2468 S   0,0  0,3   1:12.28 tor
 1514 mysql     20   0 1318760  28808      0 S   0,0  0,4   1:26.58 mysqld
 1533 root      20   0    7708      0      0 S   0,0  0,0   0:00.00 agetty
 1535 icaro     20   0 1602044  63056  22008 S   0,0  0,8   2:48.27 VBoxHeadless
 1556 tomcat8   20   0 3145776  63556      0 S   0,0  0,8   2:21.45 java
 1561 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 iprt-VBoxWQueue
 1565 root      20   0       0      0      0 S   0,0  0,0   0:00.06 iprt-VBoxTscThr
 1740 root      20   0  232828    924    732 S   0,0  0,0   0:00.14 lightdm
 1804 rtkit     21   1  175308    452    452 S   0,0  0,0   0:01.09 rtkit-daemon
 1813 root      10 -10       0      0      0 S   0,0  0,0   0:00.00 krfcommd
 1821 root      20   0  347644   2260   1032 S   0,0  0,0   0:03.47 upowerd
 1885 icaro     20   0   37012   1108    664 S   0,0  0,0   0:00.12 systemd
 1887 icaro     20   0  145680    160      0 S   0,0  0,0   0:00.00 (sd-pam)
 1892 icaro     20   0  353572   5740   2048 S   0,0  0,1   0:03.16 gnome-keyring-d
 1895 icaro     20   0  237272    184    184 S   0,0  0,0   0:00.01 kwalletd5
 1896 icaro     20   0   38588   1800    808 S   0,0  0,0   0:01.06 upstart
 2006 nobody    20   0   44848    344    240 S   0,0  0,0   0:08.43 dnsmasq
 2188 icaro     20   0   32864    136      0 S   0,0  0,0   0:00.26 upstart-udev-br
 2197 icaro     20   0   36464   2908   1128 S   0,0  0,0   0:46.78 dbus-daemon
 2209 icaro     20   0   86356   1728   1452 S   0,0  0,0   0:01.80 window-stack-br
 2233 icaro     20   0   32876    320    204 S   0,0  0,0   0:09.08 upstart-dbus-br
 2234 icaro     20   0   32800    460    300 S   0,0  0,0   0:07.99 upstart-dbus-br
 2242 icaro     20   0  389280  62336   1768 S   0,0  0,8   8:48.45 ibus-daemon
 2254 icaro     20   0   33056    124      0 S   0,0  0,0   0:00.06 upstart-file-br
 2266 icaro     20   0  348268    876    408 S   0,0  0,0   0:00.17 gvfsd
 2271 icaro     20   0  406864      0      0 S   0,0  0,0   0:00.00 gvfsd-fuse
 2282 icaro     20   0  264288   1116   1056 S   0,0  0,0   0:00.01 ibus-dconf
 2283 icaro     20   0  508220  26896   7932 S   0,0  0,3   2:24.20 ibus-ui-gtk3
 2285 icaro     20   0  429032   6872   5860 S   0,0  0,1   0:01.98 ibus-x11
 2295 icaro     20   0  338032   1044    908 S   0,0  0,0   0:00.01 at-spi-bus-laun
 2302 icaro     20   0   35000    940    536 S   0,0  0,0   0:01.25 dbus-daemon
 2304 icaro     20   0  206868   1528   1324 S   0,0  0,0   0:15.69 at-spi2-registr
 2307 icaro     20   0  166544    152      0 S   0,0  0,0   0:03.39 gpg-agent
 2314 icaro     20   0  527512  17072   9820 S   0,0  0,2   1:18.70 bamfdaemon
 2328 icaro     20   0  911084  47532  10632 S   0,0  0,6   0:29.03 hud-service
 2329 icaro     20   0  188528   1588   1216 S   0,0  0,0   2:11.50 ibus-engine-sim
 2331 icaro     20   0 1267400  15708   9084 S   0,0  0,2   0:10.36 unity-settings-
 2338 icaro     20   0  558668   2856   1864 S   0,0  0,0   0:01.95 gnome-session-b
 2344 icaro     20   0  654296  38624  11144 S   0,0  0,5   1:30.90 unity-panel-ser
 2359 icaro     20   0   22768    800    640 S   0,0  0,0   0:12.99 syndaemon
 2368 icaro      9 -11  650800   6292   4132 S   0,0  0,1  43:08.41 pulseaudio
 2382 icaro     20   0  179088   1496    692 S   0,0  0,0   0:00.51 dconf-service
 2396 icaro     20   0  346696   1516    528 S   0,0  0,0   0:00.37 indicator-messa
 2397 icaro     20   0  407288   1144    984 S   0,0  0,0   0:00.04 indicator-bluet
 2401 icaro     20   0  781672   9424   3532 S   0,0  0,1   0:01.11 indicator-power
 2404 icaro     20   0 1225380   2564   1384 S   0,0  0,0   0:01.66 indicator-datet
 2408 icaro     20   0  707492   8268   5672 S   0,0  0,1   0:03.24 indicator-keybo
 2410 icaro     20   0  805184   2624   1360 S   0,0  0,0   0:01.94 indicator-sound
 2411 icaro     20   0  540608   6852   5744 S   0,0  0,1   0:02.34 indicator-print
 2412 icaro     20   0  952916   1984   1140 S   0,0  0,0   0:00.92 indicator-sessi
 2437 icaro     20   0  403152   2448   2004 S   0,0  0,0   0:10.10 indicator-appli
 2466 icaro     20   0 1242928   2632   1988 S   0,0  0,0   0:00.07 evolution-sourc
 2481 icaro     20   0  629708  15132  10676 S   0,0  0,2   0:02.95 polkit-gnome-au
 2484 icaro     20   0  574672   6692   3048 S   0,0  0,1   0:14.45 core
 2487 icaro     20   0 1231988  36564  11520 S   0,0  0,5   1:13.76 nm-applet
 2488 icaro     20   0 1542968  29936  12432 S   0,0  0,4   2:47.32 nautilus
 2500 icaro     20   0  512548   6364   5452 S   0,0  0,1   0:02.52 unity-fallback-
 2505 icaro     20   0  511664   7616   6300 S   0,0  0,1   0:02.89 indicator-kdeco
 2506 icaro     20   0 1640684 249732  33728 S   0,0  3,1  61:58.24 compiz
 2522 icaro     20   0  350960   1312    212 S   0,0  0,0   0:00.59 gvfs-udisks2-vo
 2524 icaro     20   0  987740  19140  10768 S   0,0  0,2   0:55.74 kdeconnectd
 2535 root      20   0  424692   1868    736 S   0,0  0,0   0:19.23 udisksd
 2550 icaro     20   0  259532   1056    728 S   0,0  0,0   0:00.03 gvfs-mtp-volume
 2556 icaro     20   0  257544    824    620 S   0,0  0,0   0:00.02 gvfs-goa-volume
 2561 icaro     20   0  271856   1000    680 S   0,0  0,0   0:00.03 gvfs-gphoto2-vo
 2564 icaro     20   0  854836   2076   2076 S   0,0  0,0   0:00.12 evolution-calen
 2569 icaro     20   0  403612    988    708 S   0,0  0,0   0:00.02 gvfs-afc-volume
 2587 root      20   0  620416  18000    532 S   0,0  0,2   0:01.05 fwupd
 2595 icaro     20   0  348156    880    880 S   0,0  0,0   0:00.00 gvfsd-burn
 2610 icaro     20   0  350580   2788    192 S   0,0  0,0   0:00.12 gvfsd-trash
 2627 icaro     20   0  187508   2408    788 S   0,0  0,0   0:00.64 gvfsd-metadata
 2633 icaro     20   0  553868   6544   5740 S   0,0  0,1   0:02.19 telepathy-indic
 2639 icaro     20   0  427756   3732   2460 S   0,0  0,0   0:18.63 mission-control
 2646 icaro     20   0  873320   1372    768 S   0,0  0,0   0:02.06 evolution-calen
 2656 icaro     20   0  682368   1120   1120 S   0,0  0,0   0:00.03 evolution-addre
 2659 icaro     20   0 1054304   1896   1080 S   0,0  0,0   0:02.15 evolution-calen
 2692 icaro     20   0  757864   2512   1940 S   0,0  0,0   0:02.20 evolution-addre
 2734 icaro     20   0    4508      0      0 S   0,0  0,0   0:00.00 sh
 2738 icaro     20   0  410472   3364   2184 S   0,0  0,0   0:01.64 zeitgeist-daemo
 2745 icaro     20   0  319744   6340   2820 S   0,0  0,1   0:01.49 zeitgeist-fts
 2747 icaro     20   0  527016   3772   2508 S   0,0  0,0   0:04.83 zeitgeist-datah
 2875 icaro     20   0   53060   1300   1068 S   0,0  0,0   0:00.16 gconfd-2
 2914 icaro     20   0  516616   8852   6776 S   0,0  0,1   0:04.55 update-notifier
 3535 icaro     20   0  158200    244      0 S   0,0  0,0   0:36.49 VBoxXPCOMIPCD
 3540 icaro     20   0  897012   9628   4128 S   0,0  0,1   1:38.92 VBoxSVC
 3950 root      20   0   14216   2364   1500 S   0,0  0,0   0:00.00 dhclient
 4217 icaro     20   0  435484   1404    712 S   0,0  0,0   0:02.16 deja-dup-monito
 4692 icaro     20   0  492988  13912   8112 S   0,0  0,2   0:14.07 notify-osd
 5231 icaro     20   0 1824132  69180  23888 S   0,0  0,9  14:15.18 VBoxHeadless
 6166 icaro     20   0   37000   4100   3228 S   0,0  0,1   0:02.50 ssh
 6650 icaro     20   0  836448   3948   1004 S   0,0  0,0   0:00.05 gvfsd-network
 6673 icaro     20   0  361724    524    524 S   0,0  0,0   0:00.05 gvfsd-dnssd
 8187 icaro     20   0  639208   2388   1892 S   0,0  0,0   0:00.18 unity-files-dae
 8244 icaro     20   0 2734512 182576  33840 S   0,0  2,3  11:26.52 Telegram
 8807 icaro     20   0  500556  12400   2808 S   0,0  0,2   0:04.61 unity-scope-loa
 9042 root      20   0   15724    164      0 S   0,0  0,0   0:00.00 rpc.idmapd
 9043 root      20   0   39364   2528    812 S   0,0  0,0   0:00.01 rpc.mountd
 9050 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 nfsd4_callbacks
 9051 root      20   0       0      0      0 S   0,0  0,0   0:00.00 lockd
 9052 root      20   0       0      0      0 S   0,0  0,0   0:00.00 nfsd
 9053 root      20   0       0      0      0 S   0,0  0,0   0:00.00 nfsd
 9054 root      20   0       0      0      0 S   0,0  0,0   0:00.00 nfsd
 9055 root      20   0       0      0      0 S   0,0  0,0   0:00.00 nfsd
 9056 root      20   0       0      0      0 S   0,0  0,0   0:00.00 nfsd
 9057 root      20   0       0      0      0 S   0,0  0,0   0:00.04 nfsd
 9058 root      20   0       0      0      0 S   0,0  0,0   0:02.49 nfsd
 9059 root      20   0       0      0      0 S   0,0  0,0   0:19.91 nfsd
10622 icaro     20   0  563584   7676   2508 S   0,0  0,1   0:02.78 unity-scope-hom
10654 distrib+  20   0   11140    320      0 S   0,0  0,0   0:00.00 ssh-agent
10931 icaro     20   0  577704   5568    880 S   0,0  0,1   0:00.08 gvfsd-http
11089 root      20   0   86192   2244    604 S   0,0  0,0   0:00.08 cupsd
11091 root      20   0  267996   3740   1972 S   0,0  0,0   0:00.20 cups-browsed
14107 icaro     20   0  341904   3716   2864 S   0,0  0,0   0:13.15 geoclue-master
14112 icaro     20   0  430040   5960   2856 S   0,0  0,1   0:13.16 ubuntu-geoip-pr
15074 icaro     20   0   21848  11456   2096 S   0,0  0,1   0:00.26 bash
15371 lp        20   0   73036    672    440 S   0,0  0,0   0:00.00 dbus
17303 root      20   0  193856  19636   4836 S   0,0  0,2   0:00.39 python3
18453 root      20   0       0      0      0 S   0,0  0,0   0:00.00 jbd2/sda5-8
18454 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 ext4-rsv-conver
18462 root      20   0   12684    176     36 S   0,0  0,0   5:07.98 mount.ntfs
18580 icaro     20   0  395260   2976   2456 S   0,0  0,0   0:00.85 unity-video-len
18592 icaro     20   0  325628   1780   1608 S   0,0  0,0   0:00.02 unity-music-dae
19087 root      20   0       0      0      0 S   0,0  0,0   0:04.75 kworker/3:0
19737 icaro     20   0  795092  37228  15276 S   0,0  0,5   0:11.31 /usr/bin/x-term
19752 icaro     20   0    6848     20      0 S   0,0  0,0   0:00.00 gnome-pty-helpe
19753 icaro     20   0   21840   8596   1028 S   0,0  0,1   0:00.29 bash
20208 icaro     20   0   21840   9036   1096 S   0,0  0,1   0:00.12 bash
20592 icaro     20   0 9375708 713828 105664 S   0,0  8,9  21:18.29 firefox
21295 icaro     20   0 1819904 557052 548096 S   0,0  6,9  28:59.43 VBoxHeadless
21493 root      20   0   59644   3964   3268 S   0,0  0,0   0:00.18 sshd
22150 root      20   0       0      0      0 S   0,0  0,0   0:00.81 kworker/u16:3
22920 root      20   0       0      0      0 S   0,0  0,0   0:00.34 kworker/0:0
23774 root      20   0       0      0      0 S   0,0  0,0   0:01.28 kworker/2:1
24018 root      20   0       0      0      0 S   0,0  0,0   0:00.36 kworker/u16:2
24369 root      20   0       0      0      0 S   0,0  0,0   0:00.03 kworker/1:2
25854 root      20   0       0      0      0 S   0,0  0,0   0:00.13 kworker/0:2
25938 root      20   0       0      0      0 S   0,0  0,0   0:00.04 kworker/1:0
26056 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kworker/2:0
26062 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kworker/3:1
26101 root      20   0       0      0      0 S   0,0  0,0   0:00.15 kworker/u16:0
26469 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 dio/sda7
26807 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 rpciod
26826 root      20   0   47628   1324    912 S   0,0  0,0   0:00.03 rpcbind
26928 icaro     20   0 2498176  51964  17616 S   0,0  0,6   0:01.29 vim
26933 icaro     20   0 1182052  45196  14128 S   0,0  0,6   0:00.65 nodejs
26947 icaro     20   0 2430384  47412  21044 S   0,0  0,6   0:00.18 python2
27030 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kworker/0:1
27091 root      20   0       0      0      0 S   0,0  0,0   0:00.00 kworker/1:1
27188 icaro     20   0   33572   3372   2820 R   0,0  0,0   0:00.00 top
27816 root     -51   0       0      0      0 S   0,0  0,0   0:00.00 irq/48-mei_me
28104 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/u17:0
28105 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 hci0
28106 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 hci0
28108 root       0 -20       0      0      0 S   0,0  0,0   0:00.00 kworker/u17:2
28179 icaro     20   0  817636  49592  21220 S   0,0  0,6   1:40.83 /usr/bin/x-term
28190 icaro     20   0    6848     84      0 S   0,0  0,0   0:00.00 gnome-pty-helpe
28191 icaro     20   0   21848  10520   1164 S   0,0  0,1   0:00.97 bash
28561 icaro     20   0   30320  11804   2384 S   0,0  0,1   0:01.37 bash
```

### Anexo 2
#### Comando
``` sh
$ top -b:
```

### Saída
```
top - 10:19:56 up 6 min,  1 user,  load average: 0.10, 0.06, 0.03
Tasks:  82 total,   1 running,  81 sleeping,   0 stopped,   0 zombie
Cpu(s):  0.2%us,  0.3%sy,  0.0%ni, 99.4%id,  0.1%wa,  0.0%hi,  0.0%si,  0.0%st
Mem:   5081940k total,   183712k used,  4898228k free,    17380k buffers
Swap:   786428k total,        0k used,   786428k free,    53652k cached

  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND                                    
    1 root      20   0 24332 2224 1340 S    0  0.0   0:00.67 init                                       
    2 root      20   0     0    0    0 S    0  0.0   0:00.00 kthreadd                                   
    3 root      20   0     0    0    0 S    0  0.0   0:00.02 ksoftirqd/0                                
    6 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/0                                
    7 root      RT   0     0    0    0 S    0  0.0   0:00.00 watchdog/0                                 
    8 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/1                                
   10 root      20   0     0    0    0 S    0  0.0   0:00.01 ksoftirqd/1                                
   11 root      20   0     0    0    0 S    0  0.0   0:00.09 kworker/0:1                                
   12 root      RT   0     0    0    0 S    0  0.0   0:00.00 watchdog/1                                 
   13 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/2                                
   15 root      20   0     0    0    0 S    0  0.0   0:00.00 ksoftirqd/2                                
   16 root      RT   0     0    0    0 S    0  0.0   0:00.00 watchdog/2                                 
   17 root       0 -20     0    0    0 S    0  0.0   0:00.00 cpuset                                     
   18 root       0 -20     0    0    0 S    0  0.0   0:00.00 khelper                                    
   19 root      20   0     0    0    0 S    0  0.0   0:00.00 kdevtmpfs                                  
   20 root       0 -20     0    0    0 S    0  0.0   0:00.00 netns                                      
   22 root      20   0     0    0    0 S    0  0.0   0:00.00 sync_supers                                
   23 root      20   0     0    0    0 S    0  0.0   0:00.00 bdi-default                                
   24 root       0 -20     0    0    0 S    0  0.0   0:00.00 kintegrityd                                
   25 root       0 -20     0    0    0 S    0  0.0   0:00.00 kblockd                                    
   26 root       0 -20     0    0    0 S    0  0.0   0:00.00 ata_sff                                    
   27 root      20   0     0    0    0 S    0  0.0   0:00.00 khubd                                      
   28 root       0 -20     0    0    0 S    0  0.0   0:00.00 md                                         
   30 root      20   0     0    0    0 S    0  0.0   0:00.00 khungtaskd                                 
   31 root      20   0     0    0    0 S    0  0.0   0:00.00 kswapd0                                    
   32 root      25   5     0    0    0 S    0  0.0   0:00.00 ksmd                                       
   33 root      39  19     0    0    0 S    0  0.0   0:00.00 khugepaged                                 
   34 root      20   0     0    0    0 S    0  0.0   0:00.00 fsnotify_mark                              
   35 root      20   0     0    0    0 S    0  0.0   0:00.00 ecryptfs-kthrea                            
   36 root       0 -20     0    0    0 S    0  0.0   0:00.00 crypto                                     
   44 root       0 -20     0    0    0 S    0  0.0   0:00.00 kthrotld                                   
   45 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/u:2                                
   46 root      20   0     0    0    0 S    0  0.0   0:00.03 kworker/1:1                                
   47 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_0                                  
   48 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_1                                  
   49 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_2                                  
   51 root      20   0     0    0    0 S    0  0.0   0:00.06 kworker/2:1                                
   52 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/u:4                                
   71 root       0 -20     0    0    0 S    0  0.0   0:00.00 devfreq_wq                                 
   72 root      20   0     0    0    0 S    0  0.0   0:00.08 kworker/2:2                                
  119 root      20   0     0    0    0 S    0  0.0   0:00.04 kworker/2:3                                
  163 root      20   0     0    0    0 S    0  0.0   0:00.44 kworker/0:2                                
  252 root       0 -20     0    0    0 S    0  0.0   0:00.00 kdmflush                                   
  264 root       0 -20     0    0    0 S    0  0.0   0:00.00 kdmflush                                   
  273 root      20   0     0    0    0 S    0  0.0   0:00.00 jbd2/dm-0-8                                
  274 root       0 -20     0    0    0 S    0  0.0   0:00.00 ext4-dio-unwrit                            
  365 root      20   0 17240  632  452 S    0  0.0   0:00.04 upstart-udev-br                            
  368 root      20   0 21616 1436  816 S    0  0.0   0:00.04 udevd                                      
  471 root      20   0 21460  852  380 S    0  0.0   0:00.01 udevd                                      
  472 root      20   0 21540  876  328 S    0  0.0   0:00.00 udevd                                      
  473 root       0 -20     0    0    0 S    0  0.0   0:00.00 iprt                                       
  486 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/1:2                                
  540 root       0 -20     0    0    0 S    0  0.0   0:00.00 kpsmoused                                  
  602 root      20   0 15196  388  196 S    0  0.0   0:00.00 upstart-socket-                            
  614 root      20   0 19204 1024  740 S    0  0.0   0:00.00 rpcbind                                    
  669 root       0 -20     0    0    0 S    0  0.0   0:00.00 rpciod                                     
  684 root       0 -20     0    0    0 S    0  0.0   0:00.00 nfsiod                                     
  696 messageb  20   0 23824  704  456 S    0  0.0   0:00.01 dbus-daemon                                
  700 syslog    20   0  243m 1468 1088 S    0  0.0   0:00.04 rsyslogd                                   
  701 root      20   0 25544  436  212 S    0  0.0   0:00.00 rpc.idmapd                                 
  706 statd     20   0 21508 1360  900 S    0  0.0   0:00.00 rpc.statd                                  
  747 root      20   0  7268  588  104 S    0  0.0   0:00.00 dhclient3                                  
  794 root      20   0 50052 2908 2304 S    0  0.1   0:00.00 sshd                                       
  867 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                      
  875 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                      
  882 root      20   0 16028  960  800 S    0  0.0   0:00.00 getty                                      
  886 root      20   0 16028  968  800 S    0  0.0   0:00.00 getty                                      
  889 root      20   0 16028  956  800 S    0  0.0   0:00.00 getty                                      
  891 root      20   0 19116  880  688 S    0  0.0   0:00.00 cron                                       
  892 daemon    20   0 16912  376  216 S    0  0.0   0:00.00 atd                                        
  894 root      20   0 15988  696  516 S    0  0.0   0:00.05 irqbalance                                 
  912 root      20   0     0    0    0 S    0  0.0   0:00.00 flush-8:0                                  
  913 root      20   0     0    0    0 S    0  0.0   0:00.02 flush-252:0                                
 1132 ntp       20   0 37792 2208 1576 S    0  0.0   0:00.06 ntpd                                       
 1181 root      20   0  209m  556  252 S    0  0.0   0:00.13 VBoxService                                
 1235 root      20   0  7268  600  104 S    0  0.0   0:00.00 dhclient                                   
 1237 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                      
 1239 root      20   0 71376 3484 2700 S    0  0.1   0:00.03 sshd                                       
 1254 vagrant   20   0 71376 1964 1168 S    0  0.0   0:00.19 sshd                                       
 1255 vagrant   20   0 29444 8432 1720 S    0  0.2   0:00.29 bash                                       
 1427 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/2:0                                
 1528 vagrant   20   0 17356 1236  948 R    0  0.0   0:00.00 top                                        
```

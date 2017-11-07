Computador 1:
	Informações:
		Sistema Operacional: Ubuntu 16.04
		Processador: Intel® Core™ i5-4210U CPU @ 1.70GHz × 4 
		Memória: 7,7 GB
		Estado do computador antes das execuções: Anexo 1

	Execução - $ time ./bin:

		Primeira:

		Segunda:

		Terceira:


Computador 2:
	Informaçõe Este computador é uma VM com 3 CPUs disponíveis.
		Sistema Operacional: Ubuntu
		Processador: Intel® Cor i7-7200U CPU @ 2.40GHz 4 
		Memória:5,120 GB
		Estado do computador antes das execuções: Anexo 2

	Execução - $ time ./bin:

		Primeira:
			Max: 500000000.000000
			Min: 0.000000

			real	0m6.695s
			user	0m13.993s
			sys	0m2.884s

		Segunda:
			Max: 500000000.000000
			Min: 0.000000

			real	0m6.725s
			user	0m13.717s
			sys	0m3.112s


		Terceira:
			Max: 500000000.000000
			Min: 1.000000

			real	0m6.682s
			user	0m13.857s
			sys	0m2.952s

Anexo 1 - $ top -b:

Anexo 2: $ top -b:

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


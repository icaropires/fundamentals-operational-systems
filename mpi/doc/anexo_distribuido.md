Computador 1:
	Informaçõe Este computador é uma VM com 3 CPUs disponíveis.
		Sistema Operacional: Ubuntu
		Processador: Intel® Cor i7-7200U CPU @ 2.40GHz 4 
		Memória:5,120 GB
		Estado da VM antes das execuções: Anexo 1

	Execução - $ time ./bin:

		Apenas no master:
			$ time mpirun -np 4 -host localhost ./mpi 
			Max: 500000000.000000
			Min: 2.000000
			
			real	0m8.987s
			user	0m11.849s
			sys	0m3.992s
					Apenas no client:
			$ time mpirun -np 4 -host client ./mpi 
			Max: 500000000.000000
			Min: 1.000000
			
			real	0m10.091s
			user	0m0.012s
			sys	0m0.012s

		2 VMs:
			$ time mpirun -np 4 -host client,localhost ./mpi 
			^Cmpirun: killing job...
			
			--------------------------------------------------------------------------
			mpirun was unable to cleanly terminate the daemons on the nodes shown
			below. Additional manual cleanup may be required - please refer to
			the "orte-clean" tool for assistance.
			--------------------------------------------------------------------------
				client
			
			real	3m18.363s
			user	0m0.028s
			sys	0m0.036s


Anexo 1 - $ top -b:


top - 23:32:14 up  1:23,  2 users,  load average: 0.17, 0.07, 0.14
Tasks:  92 total,   1 running,  91 sleeping,   0 stopped,   0 zombie
Cpu(s): 14.1%us,  0.2%sy,  0.0%ni, 85.7%id,  0.0%wa,  0.0%hi,  0.0%si,  0.0%st
Mem:   5082052k total,   205080k used,  4876972k free,    19852k buffers
Swap:   786428k total,        0k used,   786428k free,    54128k cached

  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND                                                                                                                                               
 3027 vagrant   20   0 17336 1248  952 R    2  0.0   0:00.01 top                                                                                                                                                   
    1 root      20   0 24312 2224 1340 S    0  0.0   0:00.72 init                                                                                                                                                  
    2 root      20   0     0    0    0 S    0  0.0   0:00.00 kthreadd                                                                                                                                              
    3 root      20   0     0    0    0 S    0  0.0   0:00.13 ksoftirqd/0                                                                                                                                           
    6 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/0                                                                                                                                           
    7 root      RT   0     0    0    0 S    0  0.0   0:00.09 watchdog/0                                                                                                                                            
    8 root      RT   0     0    0    0 S    0  0.0   0:00.00 migration/1                                                                                                                                           
   10 root      20   0     0    0    0 S    0  0.0   0:00.13 ksoftirqd/1                                                                                                                                           
   12 root      RT   0     0    0    0 S    0  0.0   0:00.10 watchdog/1                                                                                                                                            
   13 root       0 -20     0    0    0 S    0  0.0   0:00.00 cpuset                                                                                                                                                
   14 root       0 -20     0    0    0 S    0  0.0   0:00.00 khelper                                                                                                                                               
   15 root      20   0     0    0    0 S    0  0.0   0:00.00 kdevtmpfs                                                                                                                                             
   16 root       0 -20     0    0    0 S    0  0.0   0:00.00 netns                                                                                                                                                 
   18 root      20   0     0    0    0 S    0  0.0   0:00.04 sync_supers                                                                                                                                           
   19 root      20   0     0    0    0 S    0  0.0   0:00.00 bdi-default                                                                                                                                           
   20 root       0 -20     0    0    0 S    0  0.0   0:00.00 kintegrityd                                                                                                                                           
   21 root       0 -20     0    0    0 S    0  0.0   0:00.00 kblockd                                                                                                                                               
   22 root       0 -20     0    0    0 S    0  0.0   0:00.00 ata_sff                                                                                                                                               
   23 root      20   0     0    0    0 S    0  0.0   0:00.00 khubd                                                                                                                                                 
   24 root       0 -20     0    0    0 S    0  0.0   0:00.00 md                                                                                                                                                    
   26 root      20   0     0    0    0 S    0  0.0   0:00.00 khungtaskd                                                                                                                                            
   27 root      20   0     0    0    0 S    0  0.0   0:00.00 kswapd0                                                                                                                                               
   28 root      25   5     0    0    0 S    0  0.0   0:00.00 ksmd                                                                                                                                                  
   29 root      39  19     0    0    0 S    0  0.0   0:00.00 khugepaged                                                                                                                                            
   30 root      20   0     0    0    0 S    0  0.0   0:00.00 fsnotify_mark                                                                                                                                         
   31 root      20   0     0    0    0 S    0  0.0   0:00.00 ecryptfs-kthrea                                                                                                                                       
   32 root       0 -20     0    0    0 S    0  0.0   0:00.00 crypto                                                                                                                                                
   40 root       0 -20     0    0    0 S    0  0.0   0:00.00 kthrotld                                                                                                                                              
   41 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/u:2                                                                                                                                           
   42 root      20   0     0    0    0 S    0  0.0   0:03.69 kworker/1:1                                                                                                                                           
   43 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_0                                                                                                                                             
   44 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_1                                                                                                                                             
   45 root      20   0     0    0    0 S    0  0.0   0:00.00 scsi_eh_2                                                                                                                                             
   66 root       0 -20     0    0    0 S    0  0.0   0:00.00 devfreq_wq                                                                                                                                            
  240 root       0 -20     0    0    0 S    0  0.0   0:00.00 kdmflush                                                                                                                                              
  253 root       0 -20     0    0    0 S    0  0.0   0:00.00 kdmflush                                                                                                                                              
  261 root      20   0     0    0    0 S    0  0.0   0:00.04 jbd2/dm-0-8                                                                                                                                           
  262 root       0 -20     0    0    0 S    0  0.0   0:00.00 ext4-dio-unwrit                                                                                                                                       
  354 root      20   0 17240  636  448 S    0  0.0   0:00.16 upstart-udev-br                                                                                                                                       
  356 root      20   0 21464 1280  816 S    0  0.0   0:00.16 udevd                                                                                                                                                 
  443 root       0 -20     0    0    0 S    0  0.0   0:00.00 iprt                                                                                                                                                  
  478 root      20   0 21460  844  376 S    0  0.0   0:00.15 udevd                                                                                                                                                 
  479 root      20   0 21460  832  364 S    0  0.0   0:00.00 udevd                                                                                                                                                 
  486 root       0 -20     0    0    0 S    0  0.0   0:00.00 rpciod                                                                                                                                                
  509 root       0 -20     0    0    0 S    0  0.0   0:00.00 nfsiod                                                                                                                                                
  513 messageb  20   0 23824  704  452 S    0  0.0   0:00.01 dbus-daemon                                                                                                                                           
  522 syslog    20   0  243m 1456 1132 S    0  0.0   0:00.11 rsyslogd                                                                                                                                              
  540 root      20   0 25544  844  616 S    0  0.0   0:00.00 rpc.idmapd                                                                                                                                            
  542 root       0 -20     0    0    0 S    0  0.0   0:00.00 kpsmoused                                                                                                                                             
  598 root      20   0 19300 1112  796 S    0  0.0   0:00.01 rpcbind                                                                                                                                               
  633 statd     20   0 21508 1356  900 S    0  0.0   0:00.00 rpc.statd                                                                                                                                             
  647 root      20   0 15196  400  196 S    0  0.0   0:00.00 upstart-socket-                                                                                                                                       
  731 root      20   0  7268  600  104 S    0  0.0   0:00.00 dhclient3                                                                                                                                             
  995 root      20   0 50052 2912 2308 S    0  0.1   0:00.00 sshd                                                                                                                                                  
 1069 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1075 root      20   0 16028  956  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1083 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1086 root      20   0 16028  960  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1090 root      20   0 16028  968  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1099 root      20   0 19116  884  688 S    0  0.0   0:00.00 cron                                                                                                                                                  
 1100 daemon    20   0 16912  372  216 S    0  0.0   0:00.00 atd                                                                                                                                                   
 1103 root      20   0 15988  692  516 S    0  0.0   0:00.72 irqbalance                                                                                                                                            
 1481 ntp       20   0 37792 2208 1580 S    0  0.0   0:00.83 ntpd                                                                                                                                                  
 1556 root      20   0  209m  556  252 S    0  0.0   0:01.64 VBoxService                                                                                                                                           
 1612 root      20   0  7268  600  104 S    0  0.0   0:00.00 dhclient                                                                                                                                              
 1614 root      20   0 16028  964  800 S    0  0.0   0:00.00 getty                                                                                                                                                 
 1865 mpiuser   20   0 12584  520  188 S    0  0.0   0:00.00 ssh-agent                                                                                                                                             
 2100 mpiuser   20   0 12584  516  184 S    0  0.0   0:00.00 ssh-agent                                                                                                                                             
 2129 root      20   0 71376 3484 2700 S    0  0.1   0:00.02 sshd                                                                                                                                                  
 2144 vagrant   20   0 71376 1948 1152 S    0  0.0   0:00.61 sshd                                                                                                                                                  
 2145 vagrant   20   0 29500 8508 1740 S    0  0.2   0:00.53 bash                                                                                                                                                  
 2544 root      20   0     0    0    0 S    0  0.0   0:00.00 lockd                                                                                                                                                 
 2545 root       0 -20     0    0    0 S    0  0.0   0:00.00 nfsd4                                                                                                                                                 
 2546 root       0 -20     0    0    0 S    0  0.0   0:00.00 nfsd4_callbacks                                                                                                                                       
 2547 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2548 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2549 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2550 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2551 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2552 root      20   0     0    0    0 S    0  0.0   0:00.01 nfsd                                                                                                                                                  
 2553 root      20   0     0    0    0 S    0  0.0   0:00.02 nfsd                                                                                                                                                  
 2554 root      20   0     0    0    0 S    0  0.0   0:00.00 nfsd                                                                                                                                                  
 2558 root      20   0 28324 1684 1000 S    0  0.0   0:00.00 rpc.mountd                                                                                                                                            
 2787 root      20   0     0    0    0 S    0  0.0   0:02.11 kworker/0:1                                                                                                                                           
 2804 root      20   0 71376 3484 2700 S    0  0.1   0:00.01 sshd                                                                                                                                                  
 2819 vagrant   20   0 71376 1960 1164 S    0  0.0   0:00.23 sshd                                                                                                                                                  
 2820 vagrant   20   0 29380 8324 1680 S    0  0.2   0:00.27 bash                                                                                                                                                  
 2996 root      20   0     0    0    0 S    0  0.0   0:00.00 kworker/u:1                                                                                                                                           
 3018 root      20   0     0    0    0 S    0  0.0   0:00.02 kworker/1:0                                                                                                                                           
 3019 root      20   0     0    0    0 S    0  0.0   0:00.02 kworker/0:2                                                                                                                                           
 3020 root      20   0     0    0    0 S    0  0.0   0:00.02 kworker/1:2                                                                                                                                           
 3021 root      20   0     0    0    0 S    0  0.0   0:00.01 kworker/0:0                                                                                                                                           


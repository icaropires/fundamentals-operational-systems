# Relatório sobre reprodução do experimento do Hadoop/Spark

**Alunos**:
* Arthur Temporim - 14/0016759 
* Ícaro Aragão    - 15/0129815 

## Introdução
Este relatório diz respeito a reprodução do experimento original realizado na disciplina de Fundamentos de Sistemas Distribuído, os detalhes de como feito e instruções para reprodução de seus resultados estão no repositório do github: https://github.com/arkye/fsd_spark_hadoop.

## Objetivo
O objetivo do experimento é o de utilizar técnicas e ferramentas relacionadas a instalação, manipulação e criação de sistemas distribuídos para a realização de uma tarefa simples à primeira vista, que é a de contar palavras. Os problemas e limitações aparecem devido ao fato do arquivo possuir 2 GB, o que limitam as opções de como fazer isso com computadores comuns. Para isso usaremos como ferramentas principais o hadoop e o spark.
Como este não é o experimento original, mas sim apenas uma reprodução, ao invés de várias máquinas trabalhando em conjunto, utilizaremos apenas um computador com uma máquina virtual (que simularará um computador "escravo").

## Equipamento

Foram utilizados um computador as seguintes configurações:

	Sistema Operacional: Ubuntu 16.04
	Processador: Intel® Core™ i5-4210U CPU @ 1.70GHz × 4 
	Memória: 7,7 GB
	Estado do computador antes das execuções: Anexo 1

E uma máquina virtual com as seguintes configurações:

	Sistema Operacional: Ubuntu 16.04
	Processador: Intel® Core™ i5-4210U CPU @ 1.70GHz × 2
	Memória: 1 GB
	Estado do computador antes das execuções: Anexo 2

* A máquina virtual está sendo executada no computador listado acima


## Instalação
Para facilitar a reprodução e execução em outros computadores, configuramos a máquina virtual para executar parte do processo de instalação durante o provisionamento. Basicamente o que foi feito foi a instalação da maioria dos pacotes, criação do perfil extra, que ao invés de hadoop chamamos de distributed, configurações de suas permissões e geração de sua chave SSH. Não são executados durante o provisionamento a adição dos hosts, cópia da chave ssh e instalação de pacotes .tar.gz.

Nem todos os passos foram executados conforme as intruções na wiki do repositório, pois alguns daqueles passos geraram problemas e precisaram de passos extras, por exemplo, a geração da chave ssh deve ser rodada sem `sudo` se não será salva no usuário root, algumas subdepêndencias não listadas também foram necessárias.

Além disso, o link para download da versão utilizada pelo grupo não está mais funcionando e no site oficial não encontrei a versão informada. Provavelmente ela foi retirada, pois se tratava de uma versão com final .0, ou seja, provavelmente instável. Ao invés dela, utilizamos a vesão 2.8.0. Como adaptações, foram necessárias apenas correções nos nomes durante a instalação.

## Preparação
Após as ferramentas instaladas apenas seguimos os passos descritos na wiki, aproveitamos para listar aqui os tempos necessários para cada etapa, o que não está na wiki do projeto:

 * gerar arquivo de 2GB com palavras: 45 min.

 * compilar o programa em scala: 308s.

 * gerar o package: aproximadamente 3s.

## Execução
Para a execução foram seguidos os passos descritos no github do grupo. O estado antes da execução era:

- [x] Hosts com ip's corretos na VM e no computador.

- [x] Mesmo usuário criado na VM e no computador.

- [x] Arquivos de configuração slaves e masters preenchidos no hadoop e no spark.

- [x] Variáveis de ambiente do hadoop e spark nos .bashrc da vm e do computador.

- [x] Palavras geradas atráves do script generate-words.

- [x] Dependências funcionando corretamente, de acordo com checkagem descrita no tutorial.

Na execução do script init.sh, tudo aconteceu normalmente sem warnings ou erros. O computador fica lendo enquanto o script está sendo executado, após a finalização é possível acessar o endereço master:50070 e ver o estado das coisas. Nessa etapa deveria acontecer:

- [x] Ser mostrado o computador como um datanode.

- [ ] Ser mostrado a VM como outro datanode.

A VM só foi mostrada como datanode da primeira vez que o código foi executado. Depois não conseguimos fazê-la aparecer novamente. Como outro problema, não localizamos o script `insert_data.sh` no repositório do projeto. A aplicação pôde ser ser empacotada sem problemas utilizando o sbt.

Depois disso foi rodado o script word-count, enquanto isso o computador ficou bastante lento, o script foi executado por aproximadamente 27 min antes de terminar sua execução. Aparentemente tudo ocorreu bem, não houve erros. Porém, não encontramos uma arquivo de saída e o que nos indica que tudo ocorreu bem são os seguites fatos:
- [x] A execução por um tempo razoável e alto uso da cpu.

- [x] A ausência de erros no shell.

- [x] A tela "data node information" na interface do browser.

## Conclusão
Os resultados não foram os esperados devido aos seguintes motivos:
* Houve o erro ainda não identificado sobre usar a máquina virtual como um datanode;
* Um scrip não foi encontrado e isso pode ter sido a origem do erro.
* Não foram gerados arquivos de saída;
* Não conhecemos os resultados do processamento.

Mas, apesar disso, foram acrescentados conhecimentos sobre a instalação dos ambientes hadoop/spark e também foi bastante notável o poder que essa estratégia pode ter para processamentos pesados, pois, à princípio, o computador não seria capaz nem de abrir o arquivo que foi processado, ele travaria até sua reinicialização.

Mas utilizando-se dessa estratégia, com o mesmo hardware e mesmo rodando softwares de emulação além de vários outros processos em execução, e utilizando apenas o próprio computador do master como escravo, aparentemente foi possível processar o todo o conteúdo do arquivo e num tempo razoável.
Lembrando também que não foram necessárias estratégias sofisticadas de codificação, o ambiente pronto faz quase tudo sozinho.

Além desse relatório, há imagens que estão nessa mesma pasta sobre o processo de execução, elas não estão nesse arquivo para evitar problemas na conversão para PDF. Esse relatório também pode ser melhor visualizado no repositório do github: https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/. Nesta pasta também contém o Vagrantfile utilizado para a máquina virtual.

## Anexo 1
### Comando
``` sh
$ top -b
```
### Saída
```
top - 19:42:03 up 26 min,  1 user,  load average: 0.00, 0.01, 0.05
Tasks: 136 total,   1 running, 135 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.1 us,  0.2 sy,  0.0 ni, 98.9 id,  0.8 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem :   758152 total,   463328 free,    46276 used,   248548 buff/cache
KiB Swap:   786428 total,   786428 free,        0 used.   679872 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
    1 root      20   0   37636   5736   4036 S   0.0  0.8   0:01.19 systemd
    2 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kthreadd
    3 root      20   0       0      0      0 S   0.0  0.0   0:00.02 ksoftirqd/0
    5 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/0:0H
    6 root      20   0       0      0      0 S   0.0  0.0   0:00.02 kworker/u4:0
    7 root      20   0       0      0      0 S   0.0  0.0   0:00.10 rcu_sched
    8 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcu_bh
    9 root      rt   0       0      0      0 S   0.0  0.0   0:00.02 migration/0
   10 root      rt   0       0      0      0 S   0.0  0.0   0:00.00 watchdog/0
   11 root      rt   0       0      0      0 S   0.0  0.0   0:00.00 watchdog/1
   12 root      rt   0       0      0      0 S   0.0  0.0   0:00.01 migration/1
   13 root      20   0       0      0      0 S   0.0  0.0   0:00.01 ksoftirqd/1
   14 root      20   0       0      0      0 S   0.0  0.0   0:00.29 kworker/1:0
   15 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/1:0H
   16 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kdevtmpfs
   17 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 netns
   18 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 perf
   19 root      20   0       0      0      0 S   0.0  0.0   0:00.00 khungtaskd
   20 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 writeback
   21 root      25   5       0      0      0 S   0.0  0.0   0:00.00 ksmd
   22 root      39  19       0      0      0 S   0.0  0.0   0:00.00 khugepaged
   23 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 crypto
   24 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kintegrityd
   25 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   26 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kblockd
   27 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ata_sff
   28 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 md
   29 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 devfreq_wq
   33 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kswapd0
   34 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 vmstat
   35 root      20   0       0      0      0 S   0.0  0.0   0:00.00 fsnotify_mark
   36 root      20   0       0      0      0 S   0.0  0.0   0:00.00 ecryptfs-kthrea
   51 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kthrotld
   52 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 acpi_thermal_pm
   53 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   54 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   55 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   56 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   57 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   58 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   59 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   60 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   61 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   62 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   63 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   64 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   65 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   66 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   67 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   68 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   70 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   71 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   72 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   73 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   74 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   75 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   76 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   77 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   78 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_0
   79 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_0
   80 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_1
   81 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_1
   86 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ipv6_addrconf
  100 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 deferwq
  101 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 charger_manager
  102 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  144 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kpsmoused
  173 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/1:1H
  197 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_2
  198 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_2
  199 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  273 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 raid5wq
  299 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kdmflush
  300 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  308 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kdmflush
  311 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  323 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  342 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/0:1H
  346 root      20   0       0      0      0 S   0.0  0.0   0:00.00 jbd2/dm-0-8
  347 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ext4-rsv-conver
  395 root      20   0       0      0      0 S   0.0  0.0   0:00.42 kworker/0:4
  409 root      20   0   28036   2796   2476 S   0.0  0.4   0:00.11 systemd-journal
  421 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kworker/1:2
  425 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iscsi_eh
  426 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kauditd
  444 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_addr
  445 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 rpciod
  447 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_mcast
  448 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_nl_sa_wq
  449 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_cm
  451 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iw_cm_wq
  454 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 rdma_cm
  462 root      20   0  102972   1624   1400 S   0.0  0.2   0:00.00 lvmetad
  477 root      20   0   42844   4288   3016 S   0.0  0.6   0:00.44 systemd-udevd
  511 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iprt-VBoxWQueue
  828 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ext4-rsv-conver
  899 root      20   0   23540    204      4 S   0.0  0.0   0:00.00 rpc.idmapd
 1009 root      20   0    4404   1308   1216 S   0.0  0.2   0:00.00 acpid
 1029 root      20   0   28552   3136   2828 S   0.0  0.4   0:00.01 systemd-logind
 1032 syslog    20   0  256400   3288   2608 S   0.0  0.4   0:00.02 rsyslogd
 1033 daemon    20   0   26048   2184   1984 S   0.0  0.3   0:00.00 atd
 1045 root      20   0   29012   2992   2716 S   0.0  0.4   0:00.00 cron
 1047 message+  20   0   42908   3884   3468 S   0.0  0.5   0:00.09 dbus-daemon
 1102 root      20   0   16128    876      0 S   0.0  0.1   0:00.00 dhclient
 1131 root      20   0  221028  24492  14024 S   0.0  3.2   0:00.04 snapd
 1201 root      20   0   13380    168     20 S   0.0  0.0   0:00.00 mdadm
 1329 root      20   0  248276   2448   2056 S   0.0  0.3   0:00.26 VBoxService
 1401 root      20   0   65524   5392   4696 S   0.0  0.7   0:00.03 sshd
 1416 root      20   0    5228    160     36 S   0.0  0.0   0:00.04 iscsid
 1417 root      10 -10    5728   3528   2436 S   0.0  0.5   0:00.22 iscsid
 1432 root      20   0   47632   3320   2912 S   0.0  0.4   0:00.01 rpcbind
 1434 root      20   0   37980    900    140 S   0.0  0.1   0:00.00 rpc.mountd
 1441 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 nfsd4_callbacks
 1442 root      20   0       0      0      0 S   0.0  0.0   0:00.00 lockd
 1444 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1445 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1446 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1447 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1448 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1449 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1450 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1451 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1480 root      20   0   15944   1780   1640 S   0.0  0.2   0:00.02 agetty
 1505 vagrant   20   0   45252   4716   4020 S   0.0  0.6   0:00.02 systemd
 1508 vagrant   20   0   61088   1816      4 S   0.0  0.2   0:00.00 (sd-pam)
 1777 root      20   0   16132    880      0 S   0.0  0.1   0:00.00 dhclient
 1860 root      20   0   95376   6812   5872 S   0.0  0.9   0:00.01 sshd
 1883 vagrant   20   0   95376   4880   3944 S   0.0  0.6   0:00.05 sshd
 1884 vagrant   20   0   21204   3800   3300 S   0.0  0.5   0:00.01 bash
 1991 root      20   0       0      0      0 S   0.0  0.0   0:00.08 kworker/u4:2
 2022 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kworker/0:0
 2106 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kworker/u4:1
 2110 root      20   0   52708   3920   3460 S   0.0  0.5   0:00.00 sudo
 2111 root      20   0   52288   3504   3080 S   0.0  0.5   0:00.00 su
 2112 distrib+  20   0   21240   3684   3244 S   0.0  0.5   0:00.00 bash
 2115 distrib+  20   0   41672   3640   3100 R   0.0  0.5   0:00.00 top
```
## Anexo 2
### Comando
``` sh
$ top -b
```
### Saída
```
top - 19:10:07 up  8:38,  1 user,  load average: 0.00, 0.01, 0.05
Tasks: 135 total,   1 running, 134 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.3 us,  0.2 sy,  0.0 ni, 94.7 id,  4.7 wa,  0.0 hi,  0.1 si,  0.0 st
KiB Mem :   758152 total,   314936 free,    31876 used,   411340 buff/cache
KiB Swap:   786428 total,   765580 free,    20848 used.   697696 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
    1 root      20   0   38072   4716   3348 S   0.0  0.6   0:01.51 systemd
    2 root      20   0       0      0      0 S   0.0  0.0   0:00.03 kthreadd
    3 root      20   0       0      0      0 S   0.0  0.0   0:01.95 ksoftirqd/0
    5 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/0:0H
    7 root      20   0       0      0      0 S   0.0  0.0   0:03.35 rcu_sched
    8 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcu_bh
    9 root      rt   0       0      0      0 S   0.0  0.0   0:00.08 migration/0
   10 root      rt   0       0      0      0 S   0.0  0.0   0:00.16 watchdog/0
   11 root      rt   0       0      0      0 S   0.0  0.0   0:00.15 watchdog/1
   12 root      rt   0       0      0      0 S   0.0  0.0   0:00.05 migration/1
   13 root      20   0       0      0      0 S   0.0  0.0   0:01.12 ksoftirqd/1
   15 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/1:0H
   16 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kdevtmpfs
   17 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 netns
   18 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 perf
   19 root      20   0       0      0      0 S   0.0  0.0   0:00.00 khungtaskd
   20 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 writeback
   21 root      25   5       0      0      0 S   0.0  0.0   0:00.00 ksmd
   22 root      39  19       0      0      0 S   0.0  0.0   0:00.56 khugepaged
   23 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 crypto
   24 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kintegrityd
   25 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   26 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kblockd
   27 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ata_sff
   28 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 md
   29 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 devfreq_wq
   32 root      20   0       0      0      0 S   0.0  0.0   0:06.30 kworker/1:1
   34 root      20   0       0      0      0 S   0.0  0.0   0:24.98 kswapd0
   35 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 vmstat
   36 root      20   0       0      0      0 S   0.0  0.0   0:00.00 fsnotify_mark
   37 root      20   0       0      0      0 S   0.0  0.0   0:00.00 ecryptfs-kthrea
   52 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kthrotld
   53 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 acpi_thermal_pm
   54 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   55 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   56 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   57 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   58 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   59 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   60 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   61 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   62 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   63 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   64 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   65 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   66 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   67 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   68 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   69 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   70 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   71 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   72 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   73 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   74 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   75 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   76 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   77 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
   78 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_0
   79 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_0
   80 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_1
   81 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_1
   87 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ipv6_addrconf
  100 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 deferwq
  101 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 charger_manager
  102 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  150 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kpsmoused
  151 root      20   0       0      0      0 S   0.0  0.0   0:00.00 scsi_eh_2
  157 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 scsi_tmf_2
  176 root       0 -20       0      0      0 S   0.0  0.0   0:00.16 kworker/1:1H
  199 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  274 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 raid5wq
  299 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kdmflush
  300 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  308 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kdmflush
  309 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  325 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 bioset
  344 root       0 -20       0      0      0 S   0.0  0.0   0:00.28 kworker/0:1H
  350 root      20   0       0      0      0 S   0.0  0.0   0:00.44 jbd2/dm-0-8
  351 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ext4-rsv-conver
  416 root      20   0   28176   2872   2672 S   0.0  0.4   0:00.24 systemd-journal
  420 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kauditd
  437 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iscsi_eh
  439 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 rpciod
  450 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_addr
  453 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_mcast
  455 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_nl_sa_wq
  457 root      20   0  102972    340    340 S   0.0  0.0   0:00.00 lvmetad
  461 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ib_cm
  463 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iw_cm_wq
  464 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 rdma_cm
  481 root      20   0   42844   2412   2256 S   0.0  0.3   0:01.03 systemd-udevd
  507 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 iprt-VBoxWQueue
  847 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 ext4-rsv-conver
  897 root      20   0   23540      0      0 S   0.0  0.0   0:00.00 rpc.idmapd
 1015 root      20   0   28624   2568   2400 S   0.0  0.3   0:00.08 systemd-logind
 1021 syslog    20   0  256400   2584   2212 S   0.0  0.3   0:00.06 rsyslogd
 1023 daemon    20   0   26048   1300   1300 S   0.0  0.2   0:00.00 atd
 1028 root      20   0    4404   1396   1328 S   0.0  0.2   0:00.08 acpid
 1034 root      20   0  223144   7192   4568 S   0.0  0.9   0:00.91 snapd
 1038 message+  20   0   42908    680    480 S   0.0  0.1   0:01.15 dbus-daemon
 1151 root      20   0   16128   1288   1236 S   0.0  0.2   0:00.00 dhclient
 1182 root      20   0   29012   1820   1740 S   0.0  0.2   0:00.13 cron
 1232 root      20   0   13380   1368   1324 S   0.0  0.2   0:00.00 mdadm
 1236 root      20   0  248276     60      0 S   0.0  0.0   0:05.12 VBoxService
 1422 root      20   0   65524   2176   2120 S   0.0  0.3   0:00.04 sshd
 1437 root      20   0    5228     36      0 S   0.0  0.0   0:00.84 iscsid
 1438 root      10 -10    5728   3524   2432 S   0.0  0.5   0:04.14 iscsid
 1449 root      20   0   47632   1780   1716 S   0.0  0.2   0:00.06 rpcbind
 1452 root      20   0   37980      4      0 S   0.0  0.0   0:00.00 rpc.mountd
 1459 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 nfsd4_callbacks
 1460 root      20   0       0      0      0 S   0.0  0.0   0:00.00 lockd
 1462 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1463 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1464 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1465 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1466 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1467 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1468 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1469 root      20   0       0      0      0 S   0.0  0.0   0:00.00 nfsd
 1503 root      20   0   15944   1268   1268 S   0.0  0.2   0:00.02 agetty
 1520 vagrant   20   0   45252   3352   2996 S   0.0  0.4   0:00.02 systemd
 1522 vagrant   20   0   61524      4      0 S   0.0  0.0   0:00.00 (sd-pam)
 1794 root      20   0   16132   2228   2016 S   0.0  0.3   0:00.02 dhclient
 4882 root      20   0       0      0      0 S   0.0  0.0   0:04.55 kworker/0:1
 4921 root      20   0       0      0      0 S   0.0  0.0   0:00.56 kworker/u4:0
 5186 root      20   0       0      0      0 S   0.0  0.0   0:00.04 kworker/u4:2
 5187 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kworker/0:2
 5204 root      20   0       0      0      0 S   0.0  0.0   0:00.52 kworker/1:3
 5444 root      20   0   95376   6888   5944 S   0.0  0.9   0:00.00 sshd
 5508 vagrant   20   0   95376   4912   3972 S   0.0  0.6   0:00.01 sshd
 5509 vagrant   20   0   21204   3788   3292 S   0.0  0.5   0:00.00 bash
 5521 root      20   0   52708   3860   3396 S   0.0  0.5   0:00.00 sudo
 5522 root      20   0   52288   3500   3076 S   0.0  0.5   0:00.00 su
 5523 distrib+  20   0   21252   3840   3296 S   0.0  0.5   0:00.00 bash
 5529 distrib+  20   0   41672   3632   3096 R   0.0  0.5   0:00.00 top
```

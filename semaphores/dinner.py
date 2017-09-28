import threading
import time

N = 5
THINKING = 0
HUNGRY = 1
EATING  = 2

mutex = threading.Semaphore()
philos = [threading.Semaphore() for i in range(N)]
philo_state=[HUNGRY for i in range(N)]

def left(i):
  return(i+N-1)%N

def right(i):
  return(i+1)%N

def think(i):
  print("{} Thinking...".format(i))
  time.sleep(0.25)

def take_forks(i):
  mutex.acquire()
  print("Região Crítica, entrando {}.".format(i))
  philo_state[i] = HUNGRY
  test(i)
  print("Região Crítica, fora{}.".format(i))
  mutex.release()
  philos[i].acquire()

def eat(i):
  print("{} Eating...".format(i))
  time.sleep(0.25)

def put_forks(i):
  mutex.acquire()
  print("Região Crítica, entrando {}.".format(i))
  philo_state[i] = THINKING
  test(left(i))
  test(right(i))
  print("Região Crítica, fora{}.".format(i))
  mutex.release()

def test(i):
  if philo_state[i] == HUNGRY and philo_state[left(i)] != EATING and philo_state[right(i)] != EATING:
    philo_state[i] = EATING
    philos[i].release()

def philosopher(i):
  while True:
    think(i)
    take_forks(i)
    eat(i)
    put_forks(i)

t=[threading.Thread(target = philosopher, args=[i]) for i in range(N)]
for philo in t:
  philo.start()
  time.sleep(1)



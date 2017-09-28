import threading
import time

CHAIRS = 5
waiting = 0

mutex = threading.Semaphore()
client_n = threading.Semaphore()
barber_n = threading.Semaphore()


def customer_queue():
  global waiting
  while(1):
    print("Novo cliente chegando. {}".format(waiting))
    t=threading.Thread(target=customer)
    t.start()
    time.sleep(0.10)

def barber():
  global waiting
  while(1):
    print("BARBEIRO")
    client_n.acquire()
    mutex.acquire()
    if waiting == 0:
      print("Vou dormir. {}".format(waiting))
    else :
      waiting -= 1 
      print("Cabelo cortado.")
    barber_n.release()
    mutex.release()
    time.sleep(0.25)


def customer():
  global waiting

  mutex.acquire()
  if waiting <= CHAIRS:
    print("Vou esperar")
    waiting += 1 
    client_n.release()
    mutex.release()
    barber_n.acquire()
    # Get hair cut
    print("Meu cabelo sendo cortado...")
    time.sleep(0.25)
  else :
    print("Vou embora")
    mutex.release()

t1=threading.Thread(target=barber)
t1.start()
time.sleep(1)

t2=threading.Thread(target=customer_queue)
t2.start()
time.sleep(1)

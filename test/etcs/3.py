import time
from itertools import count
from multiprocessing import Process

def inc_forever():
    print('Starting function inc_forever()...')
    while True:
        time.sleep(5)
        print(next(counter))

counter = count(0)
p1 = Process(target=inc_forever, name='Process_inc_forever')

if __name__ == '__main__':
    p1.start()
    p1.join(timeout=5)
    p1.terminate()

if p1.exitcode is None:
    print(f'Oops, {p1} timeouts!')




import time
import math
import sys
from utils import utils

n = int(input())
t_ = time.time()
print("Prime {0}: {1}".format(n,utils.nthprime(n)))
print('Time taken = ', time.time() - t_,' seconds.')
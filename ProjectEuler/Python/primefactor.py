import time
from utils import utils

N = 600851475143

t_ = time.time()
print(utils.prime_factors(N))
print('Time taken = ', time.time() - t_,' seconds.')

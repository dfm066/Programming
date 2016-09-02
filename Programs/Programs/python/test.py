import os
import string

def _pwd_gen(size=16):
    chars = string.letters
    chars_len = len(chars)
    return str().join(chars[int(ord(c) / 256. * chars_len)] for c in os.urandom(size))

_pwd_gen()

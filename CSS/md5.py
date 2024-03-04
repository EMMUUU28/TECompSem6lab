import hashlib
import time

st = time.time()
file = open("random.txt", "r")
inputstring = file.read()
file.close()

output = hashlib.md5(inputstring.encode())

print("Hash of the input string MD5 Algorithm:")
print(output.hexdigest())


# Get Time
et = time.time()
elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')
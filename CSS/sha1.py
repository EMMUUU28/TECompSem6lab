import hashlib
import time
st = time.time()
file = open("random.txt", "r")
inputstring = file.read()
file.close()

output = hashlib.sha1(inputstring.encode())
print("Hash of the input string using SHA1 Algorithm:")
print(output.hexdigest())



# Get Time
et = time.time()
elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')
import Linked_List as ll
import numpy as np
import time

l_list = ll.create()

for i in range(1,(10**7)+1):
    l_list.append(i)

array = np.array(range(1,(10**7)+1))

start_time = time.time() 
l_list.search(10**7)
print("--- [Linked List] Search Time : %s seconds ---" %(time.time() - start_time))

start_time = time.time() 
for i in range(len(array)):
    if 10**7==array[i]:
        break
print("--- [Array] Search Time : %s seconds ---" %(time.time() - start_time)) 
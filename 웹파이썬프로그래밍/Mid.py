def addInteger(a,b):
    return a+b

def sumList(a):
    b = sum(a)
    return b

def reverseList(a):
    a.reverse()

def doubleList(a):
    for i in range(0, len(a)):
        a[i] = 2*a[i]

def doubleListEnhanced(a):
    if type(a) == list:
        for i in range(0, len(a)):
            a[i] = 2*a[i]
        return True
    elif type(a) != list:
        return False

test=int(input("Enter test cases:"))
for i in range(test):
    size=int(input("Enter size"))
    arr=list(map(int,input("Enter elements:").split()))
    for j in range(size):
        for i in range(1,size-1):
            if arr[i-1]+arr[i+1]==4:
                if arr[i]>4-arr[i]:
                    arr[i]=4-arr[i]
    sum1=sum(arr)
print(sum1)

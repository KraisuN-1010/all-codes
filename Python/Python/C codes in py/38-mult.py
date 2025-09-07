matrix1=[[1,2,3],[3,4,5],[6,7,8]]
matrix2=[[1,2,3],[3,4,5],[6,7,8]]
matrix3=[[0 for _ in range(3)]for _ in range(3)]
for i in range(3):
    for j in range(3):
        for k in range(3):
            matrix3[i][j]+=matrix1[i][k]*matrix2[k][j]
for i in matrix3:
    print(i)

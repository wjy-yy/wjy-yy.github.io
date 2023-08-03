h, w, m = input().split()
h = int(h)
w = int(w)
m = int(m)
hh = []
mm = []
for i in range(h):
    H = input().split()
    M = []
    for j in range(w):
        H[j] = int(H[j])
        M.append(0)
    hh.append(H)
    mm.append(M)

x = [-1,0,1,0]
y = [0,1,0,-1]
cnt = 0
for i in range(h):
    for j in range(w):
        if not mm[i][j]:
            cnt+=1
            mm[i][j]=cnt
            q = []
            l = 0
            q.append([i,j])
            while l<len(q):
                #mm[q[l][0]][q[l][1]]=cnt
                for k in range(4):
                    nx = q[l][0]+x[k]
                    ny = q[l][1]+y[k]
                    if nx>=0 and nx<h and ny>=0 and q[l][1]+y[k]<w and mm[nx][ny]==0 and hh[nx][ny]-hh[q[l][0]][q[l][1]]>=-m and hh[nx][ny]-hh[q[l][0]][q[l][1]]<=m:
                        q.append([nx,ny])
                        mm[nx][ny]=cnt
                l+=1
print(cnt)
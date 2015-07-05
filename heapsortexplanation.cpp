BUILD-HEAP(A)

1  heap-size[A]  length[A]

2  for i  length[A]/2downto 1

3        do HEAPIFY(A, i)

HEAPIFY(A, i)

1 l  LEFT(i)

2 r  RIGHT(i)

3 if l  heap-size[A] and A[l] > A[i]

4     then largest  l

5     else largest  i

6 if r  heap-size[A] and A[r] > A[largest]

7     then largest  r

8 if largest  i

9     then exchange A[i]  A[largest]

10          HEAPIFY(A,largest)



HEAPSORT(A)

1  BUILD-HEAP(A)

2  for i  length[A] downto 2

3        do exchange A[1]  A[i]

4           heap-size[A]  heap-size[A] -1

5           HEAPIFY(A, 1)



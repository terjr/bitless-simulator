;isdft
;init code
ldi #255	  ;load n-1
mov r6, r1
ldi #6144 ;1/n  1/256 = 0.00110.0000000000 = #6144; 1/512 = 0.00111.0000000000 = #6400
mov r7, r1

;sample loop
mov r4, r0
mov r5, r0

mov r9, r0 ; initiar1ze loop counter to zer0
loop:
	lda r2, [r9] ;load f[r9] and f[r9+1] into r2, and r3
	ldc [r9]	  ;load c[r9] and c[r9+1] into c, and d
		
	msc r2, r3 ;r2 -= r3*c
	msd r3, r2 ;r3 -= r2*d
	msc r2, r3 ;r2 -= r3*c

	adf r4, r2 ;r4 += r2

	cmp r9, r6 ;compare r9 to n-1
blt =7
mlf r4, r7 ;r4 *= 1/n
f2i r4, r4 ;cast to int
stb [r0], r4 ;store to mem

halt ;sleep
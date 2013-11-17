;delay
lda r2, [r0];load sample to r2 from a mem
ldi #255	;load 255
mov r7, r1	;move 255 to r7

ldi #coeff	;load coeff  fraction dry
mov r4, r1	;move coeff to r4


ldi #delaytime	;load delaytime
mov r8, r1	;move delaytime to r8
lda r3, [r8];load sample to r3 from a mem

mr1 r2, r4	;r2 *= r4

ldi #1		;load 1
mov r5, r1	;move 1 to r5
sbi r5, r4	;r5 -= r4    fraction wet

mr1 r3, r5	;r3 *= r4
adi r2, r3	;r2 += r3

cmp r7, r2	;check r2 larger than 255
blt =17
mov r2, r7	;r2 = 255
stb r2, [r0];store r2

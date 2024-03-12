sizeof(a) = 36
1) True
S'ha fet l'assignacio p=&a[2][1]
adreces de la matriu a mem estatica
&a[0][0]=0x7ffc80b236a0 	 1.000000
&a[0][1]=0x7ffc80b236a4 	 2.000000
&a[0][2]=0x7ffc80b236a8 	 3.000000

&a[1][0]=0x7ffc80b236ac 	 3.000000
&a[1][1]=0x7ffc80b236b0 	 4.000000
&a[1][2]=0x7ffc80b236b4 	 5.000000

&a[2][0]=0x7ffc80b236b8 	 5.000000
&a[2][1]=0x7ffc80b236bc 	 6.000000
&a[2][2]=0x7ffc80b236c0 	 7.000000


adreces de la matriu b mem dinamica
&b[0][0]=0x5616beb022c0 	 0.000000
&b[0][1]=0x5616beb022c4 	 -2.000000
&b[0][2]=0x5616beb022c8 	 -4.000000

&b[1][0]=0x5616beb022e0 	 1.000000
&b[1][1]=0x5616beb022e4 	 -1.000000
&b[1][2]=0x5616beb022e8 	 -3.000000

&b[2][0]=0x5616beb02300 	 2.000000
&b[2][1]=0x5616beb02304 	 0.000000
&b[2][2]=0x5616beb02308 	 -2.000000

2) &a[2][1] = 0x7ffc80b236bc
3) &p = 0x7ffc80b23690  p = 0x7ffc80b236bc 
4) p-4 = 0x7ffc80b236ac  p+5= 0x7ffc80b236d0 
5) p = 0x7ffc80b236b8 p-&a[2][1]=-1
6) *p=5.000000
7) *(p)+1=6.000000 *(p)-1=4.000000
8) *(p+1)=6.000000 *(p-1)=5.000000
9) *(p+15)=UNKNOWN
10) b[0]=0x5616beb022c0 *b[0] = 0.000000
11) *(*(b+1)+2)=-3.000000 *(*(b+2))+1=3.000000


---------------------------------------
VALGRIND
---------------------------------------

==16374== HEAP SUMMARY:
==16374==     in use at exit: 36 bytes in 3 blocks
==16374==   total heap usage: 5 allocs, 2 frees, 1,084 bytes allocated
==16374== 
==16374== LEAK SUMMARY:
==16374==    definitely lost: 36 bytes in 3 blocks
==16374==    indirectly lost: 0 bytes in 0 blocks
==16374==      possibly lost: 0 bytes in 0 blocks
==16374==    still reachable: 0 bytes in 0 blocks
==16374==         suppressed: 0 bytes in 0 blocks
==16374== Rerun with --leak-check=full to see details of leaked memory
==16374== 
==16374== Use --track-origins=yes to see where uninitialised values come from
==16374== For lists of detected and suppressed errors, rerun with: -s
==16374== ERROR SUMMARY: 29 errors from 13 contexts (suppressed: 0 from 0)



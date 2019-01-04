Some sample inputs:

AI vs AI
c03f566655e999bceecb03fb00c82e2286244451118933b418ff7777ddddaa
rbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrbrb

10-ply score -  work 0  87 pos / 1 msec = 87 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451118933b418ff

12-ply score -  work 0  337 pos / 1 msec = 337 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451118933b418

14-ply score -  work 0  4177 pos / 1 msec = 4177 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451118933b4

16-ply score -  work 0  92529 pos / 16 msec = 5783 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451118933

17-ply score +  work 0  93624 pos / 16 msec = 5851 Kpos/sec
c03f566655e999bceecb03fb00c82e228624445111893

18-ply score -  work 0  3443833 pos / 329 msec = 10467 Kpos/sec
c03f566655e999bceecb03fb00c82e22862444511189

19-ply score +  work 0  2912644 pos / 298 msec = 9773 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451118

20-ply score -  work 0  100182271 pos / 8814 msec = 11366 Kpos/sec
c03f566655e999bceecb03fb00c82e228624445111

22-ply score -  work 0  522434112535 pos / 51557954 msec = 10132 Kpos/sec
c03f566655e999bceecb03fb00c82e2286244451

Example dab() evaluation for debugging:

Input your position!
c03f566655e999bceecb03fb00c82e2286244451118933b418ff7777ddd
O X X O . O X O O . O O . X . X . O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X . O . O O X X . 
O O X X . O X O X . O O . X . X X X O . 
Solving . . .    
Doing dab
Place Stone 10
O X X O . O X O O . O O . X . X . O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X . O . O O X X . 
O O X X . O X O X . O O O X . X X X O . 
Place Stone 10
O X X O . O X O O . O O . X . X . O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X X O . O O X X . 
O O X X . O X O X . O O O X . X X X O . 
Backmove, depth = 19
Backmove, depth = 20
Place Stone 13
O X X O . O X O O . O O . X . X O O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X . O . O O X X . 
O O X X . O X O X . O O . X . X X X O . 
Place Stone 10
O X X O . O X O O . O O . X . X O O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X . O . O O X X . 
O O X X . O X O X . O O X X . X X X O . 
Place Stone 10
O X X O . O X O O . O O . X . X O O O . 
X O O X . O O O X . X O . O . X X O X . 
X X X O . X X X O . X X O O . O O X X . 
O O X X . O X O X . O O X X . X X X O . 
Backmove, depth = 18
Backmove, depth = 19
Backmove, depth = 20
Finished dab
score +  work 0  6 pos / 1 msec = 6 Kpos/sec

O to play - always forces a win

parent(pam, bob). /*pam is parent of bob.*/
parent(tom, bob). /*tom is parent of bob.*/
parent(tom, liz). /*tom is parent of liz.*/
parent(bob, ann). /*bob is parent of ann.*/
parent(bob, pat). /*bob is parent of pat.*/
parent(pat, jim). /*pat is parent of jim.*/
female(pam). /*pam is female.*/
male(tom). /*tom is male.*/
male(bob). /*bob is male.*/
female(liz). /*liz is female.*/
female(pat). /*pat is female.*/
female(ann). /*ann is female.*/
male(jim). /*jim is male.*/

mother(X,Y):-parent(X,Y),female(X).
father(X,Y):-parent(X,Y),male(X).
haschild(X):-parent(X,_).
sister(X,Y):-parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):-parent(Z,X),parent(Z,Y),male(X),X\==Y.


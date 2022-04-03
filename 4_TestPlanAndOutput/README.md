## Table 1: High Level Test Plan
Test ID |	Description |	Exp I/P |	Exp O/P |	Type Of Test
---------- | ---------- |  -------------- | -------- | -------
H_01|	To test the functions of movements of snake|	enum |	struct pointer |	Technical
H_02|	To test the functions of generation of fruits|		int| struct	pointer|	Technical
H_03|	To test the functions for initializing the game| 		 struct pointer|int  |	Technical


## Table 2: Low Level Test Plan
Test ID |	Description |	Exp I/P |	Exp O/P |	Type Of Test
------- | ----|  -------------- | -------- | -------
L_01|	To test implementation of function <br/> test_move_corner, test_move_left, test_move_up |	enum command|	struct pointer *plist|	Technical
L_02|	To test the functions function <br/>test_add_new_fruit, test_create_random_point |		int ,int| struct pointer *plist|	Technical
L_03|	To test the functions test_game | 		 struct pointer *game|int, int  |	Technical


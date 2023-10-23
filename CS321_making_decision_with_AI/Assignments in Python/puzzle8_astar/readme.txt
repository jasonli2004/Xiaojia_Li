test1:[247860748]  
num_wrong_tiles = 0.00020503997802734375
manhattan_distance = 0.00012612342834472656
iterative_deepening = 0.00017905235290527344
test2:[253206748] 
num_wrong_tiles = 0.00033092498779296875
manhattan_distance = 0.0002770423889160156
iterative_deepening = 0.0036039352416992188
test3:[253780508]
num_wrong_tiles = 0.002235889434814453
manhattan_distance = 0.0004711151123046875
iterative_deepening = 0.10563492774963379
test4:[152293420] 
num_wrong_tiles = 0.030603885650634766
manhattan_distance = 0.003229856491088867
iterative_deepening = 1.6003289222717285
test5:[300501380] 
num_wrong_tiles = 0.22218823432922363
manhattan_distance = 0.02781081199645996
iterative_deepening = 12.75658392906189
test6:[108306836] 
num_wrong_tiles = 0.7447237968444824
manhattan_distance = 0.002527952194213867
iterative_deepening = 314.82702803611755 (this timing measurement is not included in the test, I ran iterative deepening on this state myself and got this number)

For A-star search, using heuristic of manhattan distance is more time efficient(faster) comparing to heuristic of number of wrong tiles. 
This consequently proves the point that if h1(n) dominates h2(n) (in other words, h1 is a better heuristic), h1(n) will generally expand fewer nodes.
A-star search is much more faster than iterative_deepening.
This shows that the heuritstic function h(n) and the cost function g(n) helps to guide the search to goal.
This comparison between a-star and iterative deepening demonstrates how informed search can be more time efficient comparing to uninformed search.


